/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:38 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/11 08:07:04 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*find_path(t_game *zz, char *line, char *zz_path, char *dir)
{
	char	*path;
	char	**tmp_path;

	if (zz_path)
		oops_crash(zz, ERROR_DATA_CLONE);
	tmp_path = ft_split_set(line, SPACE_TAB);
	if (!tmp_path)
		oops_crash(zz, ERROR_MALLOC);
	if (get_tab_size(tmp_path) != 2 || ft_strcmp(dir, tmp_path[0]))
	{
		free_tab(tmp_path);
		oops_crash(zz, ERROR_BAD_ID);
	}
	path = ft_strdup(tmp_path[1]);
	if (path == NULL)
	{
		free_tab(tmp_path);
		oops_crash(zz, ERROR_MALLOC);
	}
	free_tab(tmp_path);
	return (path);
}

static void	stock_path(t_game *zz, char *line, char **zz_path, char *dir)
{
	char	*path;

	path = find_path(zz, line, *zz_path, dir);
	*zz_path = ft_strdup(path);
	free(path);
	if (*zz_path == NULL)
		oops_crash(zz, ERROR_MALLOC);
}

void	get_paths(t_game *zz, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		stock_path(zz, line, &zz->no, "NO");
	else if (ft_strncmp(line, "SO", 2) == 0)
		stock_path(zz, line, &zz->so, "SO");
	else if (ft_strncmp(line, "EA", 2) == 0)
		stock_path(zz, line, &zz->ea, "EA");
	else if (ft_strncmp(line, "WE", 2) == 0)
		stock_path(zz, line, &zz->we, "WE");
}
