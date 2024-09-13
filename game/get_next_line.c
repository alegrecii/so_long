/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:42:12 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/27 17:42:17 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *storage)
{
	int		line_len;
	int		i;
	char	*new_storage;

	line_len = 0;
	while (storage[line_len] && storage[line_len] != '\n')
		line_len++;
	if (!storage[line_len])
	{
		free(storage);
		return (NULL);
	}
	if (storage[line_len])
		line_len++;
	new_storage = malloc(sizeof(char) * (ft_strlen(storage) - line_len + 1));
	new_storage[ft_strlen(storage) - line_len] = '\0';
	i = 0;
	while (storage[line_len])
	{
		new_storage[i] = storage[line_len];
		i++;
		line_len++;
	}
	free(storage);
	return (new_storage);
}

char	*ft_get_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_freejoin(char *buffer, char *storage)
{
	char	*ret;

	if (!storage)
	{
		storage = malloc(1);
		storage[0] = '\0';
	}
	ret = ft_strjoin(storage, buffer);
	free (storage);
	return (ret);
}

char	*ft_reader(char *storage, int fd)
{
	char	*buffer;
	int		flag;
	int		c_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	flag = 1;
	c_read = 1;
	while (flag && c_read)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[c_read] = '\0';
		storage = ft_freejoin(buffer, storage);
		if (ft_strchr(storage, '\n'))
			flag = 0;
	}
	free (buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_reader(storage, fd);
	if (!storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = ft_clean(storage);
	return (line);
}
