/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:33:44 by aclarita          #+#    #+#             */
/*   Updated: 2021/10/22 20:11:36 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*new_str(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	line = (char *)malloc(ft_strlen(str) - i + 1);
	if (!line)
		return (0);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = 0;
	free (str);
	return (line);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*a;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	a = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!a)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j] != '\0')
		a[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		a[j++] = s2[i++];
	a[j] = '\0';
	free(s1);
	return (a);
}
