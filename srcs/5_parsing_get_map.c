/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_parsing_get_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:25:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 23:33:38 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_valid_map_size(t_game *zz)
{
	if (get_tab_size(zz->map) < 3)
		oops_crash(zz, ERROR_MAP_SIZE);
}

static size_t	skip_blank_lines(char **my_file, size_t	i)
{
	if (!my_file || !*my_file[i])
		return (i);
	while (is_only_blanks(my_file[i]) == true)
		i++;
	return (i);
}

void	get_map(t_game *zz, size_t i)
{
	size_t	j;
	size_t	size;

	size = get_tab_size(zz->my_file);
	zz->map = (char **)ft_calloc(size - i + 1, sizeof(char *));
	if (zz->map == NULL)
		oops_crash(zz, ERROR_MALLOC);
	i = skip_blank_lines(zz->my_file, i) + 1;
	j = 0;
	while (zz->my_file[i])
	{
		if (zz->my_file[i + 1] && is_only_blanks(zz->my_file[i]) == true
			&& is_only_blanks(zz->my_file[i + 1]) == false)
			oops_crash(zz, ERROR_MAP_SHAPE);
		zz->map[j] = ft_strdup(zz->my_file[i]);
		if (zz->map[j] == NULL)
			oops_crash(zz, ERROR_MALLOC);
		j++;
		i++;
	}
	if (!zz->map)
		oops_crash(zz, ERROR_DATA_MISSING);
	zz->map[j] = NULL;
	check_valid_map_size(zz);
}
