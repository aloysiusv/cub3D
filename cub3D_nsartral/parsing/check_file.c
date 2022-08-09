/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 04:01:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/09 11:35:50 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

#include <stdio.h>

void	check_file(t_game *zz)
{
	int		fd;
	char	*line;

	fd = open(zz->map_name, O_RDONLY);
	if (fd == -1)
		clean_error_exit(zz, NULL, 0, ERROR_FILE_OPEN);
	line = custom_gnl(fd);
	if (!line)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_CRASH);
	while (line)
	{
		zz->my_file = add_next_node(zz->my_file, ft_strdup(line));
		if (!zz->my_file && line != NULL)
			clean_error_exit(zz, line, fd, ERROR_MALLOC);
		free(line);
		line = custom_gnl(fd);
	}
	free(line);
	close(fd);
}
