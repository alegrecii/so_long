/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:32 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:28:36 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_updater(t_game *game)
{
	game->maxf = 105000 / ((game->w_h * game->w_w) / 1000);
	game->frame++;
	if (game->frame > game->maxf)
		game->frame = 1;
}

void	ghost_render(t_game *game, t_vector *ghost)
{
	int	x;
	int	y;
	int	u;

	u = game->maxf / 4;
	x = ghost->x * 50;
	y = ghost->y * 50;
	if (game->marco == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images->n, x, y);
		return ;
	}
	if (game->frame <= u)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g1, x, y);
	if (game->frame > u && game->frame <= u * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g2, x, y);
	if (game->frame > u * 2 && game->frame <= u * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g3, x, y);
	if (game->frame > u * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->images->g4, x, y);
}

void	player_render(t_game *game)
{
	int	x;
	int	y;
	int	u;

	u = game->maxf / 7;
	x = game->pp->x * 50;
	y = game->pp->y * 50;
	if (game->marco == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images->p, x, y);
		return ;
	}
	if (game->frame <= u)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p1, x, y);
	if (game->frame > u && game->frame <= u * 2)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p2, x, y);
	if (game->frame > u * 2 && game->frame <= u * 3)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p3, x, y);
	if (game->frame > u * 3 && game->frame <= u * 4)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p4, x, y);
	if (game->frame > u * 4 && game->frame <= u * 5)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p5, x, y);
	if (game->frame > u * 5 && game->frame <= u * 6)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p6, x, y);
	if (game->frame > u * 6)
		mlx_put_image_to_window(game->mlx, game->win, game->images->p7, x, y);
}

void	render(t_game *game)
{
	ghost_manager(game);
	player_render(game);
	moves_counter(game, game->images->black);
	if (game->coins <= 0 && game->map[game->pp->y][game->pp->x] == 'E')
		ft_close(game);
	frame_updater(game);
	ft_death(game);
}
