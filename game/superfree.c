/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:09:55 by alegreci          #+#    #+#             */
/*   Updated: 2022/12/01 15:10:00 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_destroyer(t_images *i, void *m)
{
	mlx_destroy_image(m, i->e);
	mlx_destroy_image(m, i->e1);
	mlx_destroy_image(m, i->e2);
	mlx_destroy_image(m, i->e3);
	mlx_destroy_image(m, i->e4);
	mlx_destroy_image(m, i->e5);
	mlx_destroy_image(m, i->e6);
	mlx_destroy_image(m, i->e7);
	mlx_destroy_image(m, i->e8);
	mlx_destroy_image(m, i->e9);
	mlx_destroy_image(m, i->e10);
	mlx_destroy_image(m, i->e11);
	mlx_destroy_image(m, i->e12);
	mlx_destroy_image(m, i->e13);
	mlx_destroy_image(m, i->e14);
}

void	image_destroyer(t_images *i, void *m)
{
	mlx_destroy_image(m, i->black);
	mlx_destroy_image(m, i->c);
	mlx_destroy_image(m, i->f);
	mlx_destroy_image(m, i->g1);
	mlx_destroy_image(m, i->g2);
	mlx_destroy_image(m, i->g3);
	mlx_destroy_image(m, i->g4);
	mlx_destroy_image(m, i->l);
	mlx_destroy_image(m, i->p1);
	mlx_destroy_image(m, i->p);
	mlx_destroy_image(m, i->p2);
	mlx_destroy_image(m, i->p3);
	mlx_destroy_image(m, i->p4);
	mlx_destroy_image(m, i->p5);
	mlx_destroy_image(m, i->p6);
	mlx_destroy_image(m, i->p7);
	mlx_destroy_image(m, i->t);
	mlx_destroy_image(m, i->w);
	door_destroyer(i, m);
}

void	map_destroyer(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

void	free_check(int fd, char **map)
{
	int	i;

	i = 0;
	close(fd);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

int	superfree(t_game *game)
{
	int	i;

	i = 0;
	game->f = 1;
	free(game->pp);
	while (i < game->g_n)
	{
		free(game->ghosts[i]);
		i++;
	}
	map_destroyer(game->map);
	free(game->ghosts);
	image_destroyer(game->images, game->mlx);
	free(game->images);
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}
