/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:20 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:29:22 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghost_init(t_game *game, t_vector *ghost)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
			{
				game->map[y][x] = '0';
				ghost->x = x;
				ghost->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	ghost_mover(t_game *game, t_vector *ghost, int i)
{
	static int	*dir;

	if (!dir)
		dir = malloc(sizeof(int) * game->g_n);
	if (dir[i] != 1 && dir[i] != -1)
		dir[i] = -1;
	if (game->map[ghost->y + dir[i]][ghost->x] == '0')
	{
		if (dir[i] == -1)
			ghost->y--;
		else
			ghost->y++;
	}
	else if (game->map[ghost->y - dir[i]][ghost->x] == '0')
	{
		dir[i] = -dir[i];
		ghost_mover(game, ghost, i);
	}
}

void	ghosts_init(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->g_n)
	{
		ghost_init(game, game->ghosts[i]);
		i++;
	}
}

t_vector	**ghost_creator(t_game *game)
{
	t_vector	**temp;
	int			i;

	i = 0;
	temp = malloc(sizeof(t_vector *) * game->g_n);
	while (i < game->g_n)
	{
		temp[i] = malloc(sizeof(t_vector));
		temp[i]->x = 0;
		temp[i]->y = 0;
		i++;
	}
	return (temp);
}

void	ghost_manager(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->g_n)
	{
		if (game->frame == game->maxf)
			ghost_mover(game, game->ghosts[i], i);
		i++;
	}
	i = 0;
	while (i < game->g_n)
	{
		ghost_render(game, game->ghosts[i]);
		i++;
	}
}
