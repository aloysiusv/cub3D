/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:02:05 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/23 06:17:06 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_file(int fd, char **stock)
{
	char	buf[1024 + 1];
	int		nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, buf, 1024);
		if (nbytes == -1)
			return (-1);
		buf[nbytes] = 0;
		if (*stock == 0)
			*stock = ft_strdup(buf);
		else
		{
			tmp = *stock;
			*stock = ft_strjoin(tmp, buf);
			free(tmp);
		}
		if (*stock == NULL)
			return (-1);
		if (ft_strchr(*stock, '\n') != 0)
			break ;
	}
	return (1);
}

static int	create_one_line(char **line, char **stock)
{
	char	*tmp;
	size_t	line_size;

	if (ft_strchr(*stock, '\n') == 0)
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = 0;
		if (*line == NULL)
			return (-1);
		return (0);
	}
	else
	{
		line_size = ft_strclen(*stock, '\n');
		*line = ft_substr(*stock, 0, line_size);
		tmp = *stock;
		*stock = ft_strdup(tmp + line_size + 1);
		free(tmp);
		if (*line == NULL || *stock == NULL)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*stock;
	int				read_status;

	read_status = read_file(fd, &stock);
	if (read_status == -1 || !line)
		return (-1);
	if (read_status == 0 && stock == 0)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
	return (create_one_line(line, &stock));
}
