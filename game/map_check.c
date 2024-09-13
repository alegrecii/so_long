/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:48 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:29:49 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_counter(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				n++;
			i++;
		}
		j++;
	}
	return (n);
}

int	char_checker(char **map)
{
	if (char_counter(map, 'P') != 1)
		return (1);
	if (char_counter(map, 'E') != 1)
		return (1);
	if (char_counter(map, 'C') == 0)
		return (1);
	return (0);
}

int	border_check(char **map, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] != '\n')
		return (1);
	j = i - 1;
	i = 0;
	while (map[lines - 1][i] == '1')
		i++;
	if (map[lines - 1][i] != '\0' && map[lines - 1][i] != '\n')
		return (1);
	i = 0;
	while (i < lines)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (1);
		i++;
	}
	i = echar_check(map);
	return (i);
}

int	easy_line_counter(char *file)
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
		if (c == '\n' && c_read)
			lines++;
	}
	if (c != '\n')
		lines++;
	close(fd);
	return (lines);
}

int	map_check(char *file)
{
	int		fd;
	int		lines;
	char	**map;
	int		i;
	int		error;

	error = 0;
	i = 0;
	fd = open(file, O_RDWR);
	if (read(fd, 0, 0) == -1 || fd < 0)
		return (1);
	lines = easy_line_counter(file);
	map = malloc(sizeof(char *) * (lines + 1));
	map[lines] = NULL;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	error += border_check(map, lines);
	error += char_checker(map);
	if (error == 0)
		error += path_finder(map);
	free_check(fd, map);
	return (error);
}
