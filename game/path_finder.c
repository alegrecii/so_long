/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:30:17 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:30:20 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood(map, x + 1, y);
	flood(map, x - 1, y);
	flood(map, x, y + 1);
	flood(map, x, y - 1);
}

t_vector	char_finder(char **map, char c)
{
	int			i;
	int			j;
	t_vector	e;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				e.x = i;
				e.y = j;
			}
			i++;
		}
		j++;
	}
	return (e);
}

int	path_finder(char **map)
{
	t_vector	exit;
	t_vector	p;

	p = char_finder(map, 'P');
	exit = char_finder(map, 'E');
	flood(map, exit.x, exit.y);
	if (map[p.y][p.x] != '1')
		return (1);
	if (char_counter(map, 'C') != 0)
		return (1);
	return (0);
}
