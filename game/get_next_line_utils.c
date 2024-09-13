/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:42:31 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/27 17:42:36 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		total;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	s = (char *) malloc(sizeof(char) * (total +1));
	if (!s)
		return (NULL);
	while (s1[j] != '\0')
	{
		s[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}
