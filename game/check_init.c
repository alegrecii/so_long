/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:41 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:28:44 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->map_lines = 0;
	game->g_n = 0;
	game->coins = 0;
	game->moves = 0;
	game->moved = 1;
	game->frame = 1;
	game->f = 0;
	game->marco = -1;
}

void	player_init(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				game->pp->x = x;
				game->pp->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	door_anim(t_images *images, void *mlx, int wdt)
{
	images->e1 = mlx_xpm_file_to_image(mlx, "./images/e1.xpm", &wdt, &wdt);
	images->e2 = mlx_xpm_file_to_image(mlx, "./images/e2.xpm", &wdt, &wdt);
	images->e3 = mlx_xpm_file_to_image(mlx, "./images/e3.xpm", &wdt, &wdt);
	images->e4 = mlx_xpm_file_to_image(mlx, "./images/e4.xpm", &wdt, &wdt);
	images->e5 = mlx_xpm_file_to_image(mlx, "./images/e5.xpm", &wdt, &wdt);
	images->e6 = mlx_xpm_file_to_image(mlx, "./images/e6.xpm", &wdt, &wdt);
	images->e7 = mlx_xpm_file_to_image(mlx, "./images/e7.xpm", &wdt, &wdt);
	images->e8 = mlx_xpm_file_to_image(mlx, "./images/e8.xpm", &wdt, &wdt);
	images->e9 = mlx_xpm_file_to_image(mlx, "./images/e9.xpm", &wdt, &wdt);
	images->e10 = mlx_xpm_file_to_image(mlx, "./images/e10.xpm", &wdt, &wdt);
	images->e11 = mlx_xpm_file_to_image(mlx, "./images/e11.xpm", &wdt, &wdt);
	images->e12 = mlx_xpm_file_to_image(mlx, "./images/e12.xpm", &wdt, &wdt);
	images->e13 = mlx_xpm_file_to_image(mlx, "./images/e13.xpm", &wdt, &wdt);
	images->e14 = mlx_xpm_file_to_image(mlx, "./images/e14.xpm", &wdt, &wdt);
	images->p1 = mlx_xpm_file_to_image(mlx, "./images/p1.xpm", &wdt, &wdt);
	images->p2 = mlx_xpm_file_to_image(mlx, "./images/p2.xpm", &wdt, &wdt);
	images->p3 = mlx_xpm_file_to_image(mlx, "./images/p3.xpm", &wdt, &wdt);
	images->p4 = mlx_xpm_file_to_image(mlx, "./images/p4.xpm", &wdt, &wdt);
	images->p5 = mlx_xpm_file_to_image(mlx, "./images/p5.xpm", &wdt, &wdt);
	images->p6 = mlx_xpm_file_to_image(mlx, "./images/p6.xpm", &wdt, &wdt);
	images->p7 = mlx_xpm_file_to_image(mlx, "./images/p7.xpm", &wdt, &wdt);
	images->black = mlx_xpm_file_to_image(mlx, "./images/b.xpm", &wdt, &wdt);
}

void	image_creator(t_images *images, void *mlx, int ww, int wh)
{
	int	wdt;

	wdt = 50;
	images->p = mlx_xpm_file_to_image(mlx, "./images/p.xpm", &wdt, &wdt);
	images->c = mlx_xpm_file_to_image(mlx, "./images/coin.xpm", &wdt, &wdt);
	images->w = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wdt, &wdt);
	images->t = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &wdt, &wdt);
	images->e = mlx_xpm_file_to_image(mlx, "./images/e.xpm", &wdt, &wdt);
	images->f = mlx_xpm_file_to_image(mlx, "./images/win.xpm", &ww, &wh);
	images->g1 = mlx_xpm_file_to_image(mlx, "./images/g1.xpm", &wdt, &wdt);
	images->g2 = mlx_xpm_file_to_image(mlx, "./images/g2.xpm", &wdt, &wdt);
	images->g3 = mlx_xpm_file_to_image(mlx, "./images/g3.xpm", &wdt, &wdt);
	images->g4 = mlx_xpm_file_to_image(mlx, "./images/g4.xpm", &wdt, &wdt);
	images->l = mlx_xpm_file_to_image(mlx, "./images/l.xpm", &ww, &wh);
	images->n = mlx_xpm_file_to_image(mlx,"./images/n.xpm", &wdt, &wdt);
	door_anim(images, mlx, wdt);
}

int	check_init(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (0);
	if (map_check(argv[1]) != 0)
	{
		ft_printf("Please insert a valid map!\n");
		return (0);
	}
	game_init(game);
	game->map = map_generator(argv[1], game);
	game->mlx = mlx_init();
	game->images = malloc(sizeof(t_images));
	game->pp = malloc (sizeof(t_vector));
	game->pp->x = 0;
	game->pp->y = 0;
	game->ghosts = ghost_creator(game);
	ghosts_init(game);
	image_creator(game->images, game->mlx, game->w_w, game->w_h);
	game->win = mlx_new_window(game->mlx, game->w_w, game->w_h, "so_long");
	player_init(game);
	return (1);
}
