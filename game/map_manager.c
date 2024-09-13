/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:30:02 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:30:04 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	echar_check(char **map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			c = map[j][i];
			if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E'
				&& c != 'G' && c != '\n')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static int	line_counter(char *file, t_game *game)
{
	char	c;
	int		c_read;
	int		fd;
	int		lines;

	c_read = 1;
	lines = 0;
	fd = open(file, O_RDWR);
	while (c_read)
	{
		c_read = read(fd, &c, 1);
		if (c == 'C')
			game->coins++;
		if (c == '\n' && c_read)
			lines++;
		if (c == 'G')
			game->g_n++;
	}
	if (c != '\n')
		lines++;
	close(fd);
	return (lines);
}

int	w_counter(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i * 50);
}

char	**map_generator(char *file, t_game *game)
{
	int		fd;
	int		lines;
	char	**map;
	int		i;

	i = 0;
	lines = line_counter(file, game);
	fd = open(file, O_RDWR);
	map = malloc(sizeof(char *) * (lines + 1));
	map[lines] = NULL;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	game->map_lines = lines;
	game->w_h = lines * 50;
	game->w_w = w_counter(map[0]);
	return (map);
}
