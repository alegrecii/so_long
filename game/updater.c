/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:14 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:28:19 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_updater_2(t_game *game, int x, int y, int u)
{
	if (game->frame > u * 4 && game->frame <= u * 5)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e5, x, y);
	if (game->frame > u * 5 && game->frame <= u * 6)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e6, x, y);
	if (game->frame > u * 6 && game->frame <= u * 7)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e7, x, y);
	if (game->frame > u * 7 && game->frame <= u * 8)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e8, x, y);
	if (game->frame > u * 8 && game->frame <= u * 9)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e9, x, y);
	if (game->frame > u * 9 && game->frame <= u * 10)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e10, x, y);
	if (game->frame > u * 10 && game->frame <= u * 11)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e11, x, y);
	if (game->frame > u * 11 && game->frame <= u * 12)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e12, x, y);
	if (game->frame > u * 12 && game->frame <= u * 13)
		mlx_put_image_to_window(game->mlx, game->win, game->images->e13, x, y);
	if (game->frame > u * 13)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images->e14, x, y);
		game->coins = -1;
	}
}

void	door_updater(t_game *game, int x, int y, t_images *images)
{
	static int	start;
	int			u;

	u = game->maxf / 14;
	if (game->coins > 0)
		mlx_put_image_to_window(game->mlx, game->win, images->e, x, y);
	if (game->coins == 0 && game->frame == 1)
		start = 1;
	if (game->coins == 0 && start == 1)
	{
		if (game->frame <= u)
			mlx_put_image_to_window(game->mlx, game->win, images->e1, x, y);
		if (game->frame > u && game->frame <= u * 2)
			mlx_put_image_to_window(game->mlx, game->win, images->e2, x, y);
		if (game->frame > u * 2 && game->frame <= u * 3)
			mlx_put_image_to_window(game->mlx, game->win, images->e3, x, y);
		if (game->frame > u * 3 && game->frame <= u * 4)
			mlx_put_image_to_window(game->mlx, game->win, images->e4, x, y);
		if (game->frame > u * 4)
			door_updater_2(game, x, y, u);
	}
	if (game->coins == -1)
		mlx_put_image_to_window(game->mlx, game->win, images->e14, x, y);
}

void	moves_counter(t_game *game, void *b)
{
	char	*m;

	m = ft_itoa_base("0123456789", game->moves);
	if (game->moved == 1)
		mlx_put_image_to_window(game->mlx, game->win, b, game->w_w - 50, 0);
	mlx_string_put(game->mlx, game->win, game->w_w - 50, 25, 255000000, m);
	game->moved = 0;
	free(m);
}

void	image_updater(char c, int x, int y, t_game *game)
{
	void	*p;

	p = game->mlx;
	x = x * 50;
	y = y * 50;
	if (!(x / 50 == game->pp->x && y / 50 == game->pp->y))
	{
		if (c == '0')
			mlx_put_image_to_window(p, game->win, game->images->t, x, y);
		if (c == '1')
			mlx_put_image_to_window(p, game->win, game->images->w, x, y);
		if (c == 'C')
			mlx_put_image_to_window(p, game->win, game->images->c, x, y);
		if (c == 'E')
			door_updater(game, x, y, game->images);
	}
}

int	updater(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (game->f)
		return (0);
	if (game->map[game->pp->y][game->pp->x] == 'C')
	{
		game->map[game->pp->y][game->pp->x] = '0';
		game->coins--;
	}
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			image_updater(game->map[y][x], x, y, game);
			x++;
		}
		y++;
	}
	render(game);
	return (0);
}
