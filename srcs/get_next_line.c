/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:07:42 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:07:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_fdz(int fd, char *buffer)
{
	char	*tmp;
	int		size;

	tmp = (char *)malloc(sizeof(char) * (10));
	if (tmp == NULL)
		return (NULL);
	size = 1;
	while (ft_strchrz(buffer) == NULL && size != 0)
	{
		size = read(fd, tmp, 10);
		if (size < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[size] = '\0';
		buffer = ft_strjoinz(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_the_linez(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_bufferz(char *buffer)
{
	int		n;
	int		m;
	int		i;
	char	*new_buffer;

	n = 0;
	m = ft_strlenz(buffer);
	while (buffer[n] && buffer[n] != '\n')
		n++;
	if (buffer[n] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (m - n + 1));
	if (new_buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[n++])
		new_buffer[i++] = buffer[n];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_linez(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = read_fdz(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_the_linez(buffer);
	buffer = new_bufferz(buffer);
	return (line);
}
