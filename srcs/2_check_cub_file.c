/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_cub_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:58:01 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 13:43:40 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_fd(char *filename, int *fd)
{
	fd = open(root->map_name, O_DIRECTORY)
	if (fd != -1)
		oops_crash(NULL, ERROR_FILE_FORMAT);
	fd = open(root->map_name, O_RDONLY)
	if (fd == -1)
		oops_crash(NULL, ERROR_FILE_OPEN);
}

static void	check_if_ascii(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		if (!ft_isascii(line[i++]))
		{
			free(line);
			oops_crash(NULL, ERROR_FILE_ASCII);
		}
}

void	check_file(t_game *root, int *fd)
{
	char	*line;

	line = NULL;
	check_fd(root->map_name, fd);
	line = get_next_linez(*fd);
	if (!line)
		oops_crash(NULL, ERROR_FILE_EMPTY);
	while (line)
	{
		check_if_ascii(line);
		root->nb_lines++;
		free(line);
		line = get_next_linez(*fd);
	}
	if (root->nb_lines > 10000)
		oops_crash(NULL, ERROR_FILE_SIZE);
}
