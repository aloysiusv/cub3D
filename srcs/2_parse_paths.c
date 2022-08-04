/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:57:16 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/04 10:39:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	stock_path(t_game *root, char *line, char *root_path)
{
	char	**path;

	if (root_path)
		clean_error_exit(root, line, ERROR_DATA_CLONE);
	path = ft_split_set(line, SPACE_TAB);
	if (!path)
		clean_error_exit(root, line, ERROR_MALLOC);
	if (get_tab_size(path) != 2 || ft_strcmp("NO", path[0])
		|| ft_strcmp("SO", path[0]) || ft_strcmp("EA", path[0])
		|| ft_strcmp("EA", path[0]))
	{
		free_tab(path);
		clean_error_exit(root, line, ERROR_BAD_ID);
	}
	root_path = ft_strdup(path[1]);
	if (!root_path)
	{
		free_tab(path);
		clean_error_exit(root, line, ERROR_MALLOC);
	}
	free_tab(path);
	return (true);
}

static bool	get_paths(t_game *root, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (stock_path(root, line, root->no));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return(stock_path(root, line, root->so));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return(stock_path(root, line, root->ea));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return(stock_path(root, line, root->we));
	return (false);
}

static bool	gathered_all_data(t_game *root)
{
	if (root->no && root->so && root->we && root->ea && root->so
		&& root->ceiling && root->floor)
		return (true);
	return (false);
}

void	check_info(t_game *root, int fd)
{
	char	*line;
	size_t	line_number;

	line = get_next_linez(fd);
	line_number = 0;
	while (line)
	{
		line_number++;
		if (is_only_blanks(line) == false)
		{
			trim_spaces(line);
			if (get_paths(root, line) == false
				&& get_colours(root, line) == false)
				clean_error_exit(root, line, ERROR_DATA_INVALID);
			if (gathered_all_data(root) == true)
			{
				free(line);
				get_map(root, line_number);
				return ;
			}
		}
		free(line);
		line = get_next_linez(fd);
	}
}
