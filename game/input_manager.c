/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:30 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:29:31 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	md(t_game *game, int y, int x)
{
	if (game->coins <= 0)
		return (1);
	if (game->map[game->pp->y + y][game->pp->x + x] != 'E')
		return (1);
	return (0);
}

int	input_manager(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->pp->x;
	old_y = game->pp->y;
	if (keycode == 100)
		if (game->map[game->pp->y][game->pp->x + 1] != '1' && md(game, 0, 1))
			game->pp->x += 1;
	if (keycode == 119)
		if (game->map[game->pp->y - 1][game->pp->x] != '1' && md(game, -1, 0))
			game->pp->y -= 1;
	if (keycode == 97)
		if (game->map[game->pp->y][game->pp->x - 1] != '1' && md(game, 0, -1))
			game->pp->x -= 1;
	if (keycode == 115)
		if (game->map[game->pp->y + 1][game->pp->x] != '1' && md(game, 1, 0))
			game->pp->y += 1;
	if (old_x != game->pp->x || old_y != game->pp->y)
	{
		game->moves++;
		game->moved = 1;
	}
	if (keycode == 109)
		game->marco *= -1;
	if (keycode == 65307)
		superfree(game);
	return (0);
}
