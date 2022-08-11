/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_custom_gnlz.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:33:51 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/11 08:07:04 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*read_fdz(int fd, char *buffer)
{
	char	tmp[4024 + 1];
	int		size;

	size = 1;
	while (ft_strchrz(buffer) == NULL && size != 0)
	{
		size = read(fd, tmp, 50);
		if (size < 0)
			return (NULL);
		tmp[size] = '\0';
		buffer = ft_strjoinz(buffer, tmp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

static char	*get_the_linez(char *buffer)
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

char	*custom_gnl(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0)
		return (NULL);
	buffer = read_fdz(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_the_linez(buffer);
	buffer = new_bufferz(buffer);
	return (line);
}
