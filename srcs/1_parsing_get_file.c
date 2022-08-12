/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing_get_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 04:01:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 06:17:37 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_if_ascii(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isascii(line[i]))
			return (false);
		i++;
	}
	return (true);;
}

void	get_file(t_game *zz)
{
	int		fd;
	int		ret;
	char	buffer[10000 + 1];

	buffer[0] = 0;
	fd = open(zz->map_name, O_RDONLY);
	if (fd == -1)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_OPEN);
	ret = read(fd, buffer, 10000);
	if (ret == 0)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_EMPTY);
	buffer[ret] = '\0';
	if (check_if_ascii(buffer) == false)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_ASCII);
	zz->my_file = ft_split_with_sep(buffer, '\n');
	if (zz->my_file == NULL)
		clean_error_exit(zz, NULL, fd, ERROR_MALLOC);
	close(fd);
}
