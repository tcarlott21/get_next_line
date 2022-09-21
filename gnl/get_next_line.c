/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:38:15 by aclarita          #+#    #+#             */
/*   Updated: 2021/10/22 20:17:16 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		fl_bt;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	fl_bt = 1;
	while (!ft_strchr(str, '\n') && fl_bt)
	{
		fl_bt = read(fd, buff, BUFFER_SIZE);
		if (fl_bt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[fl_bt] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_line(fd, str);
	if (!str)
		return (0);
	line = get_line(str);
	str = new_str(str);
	return (line);
}
