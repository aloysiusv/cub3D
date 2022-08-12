/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_check_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:17:44 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 06:17:42 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	gathered_all_data(t_game *zz)
{
	if (zz->no && zz->so && zz->we && zz->ea && zz->so
		&& zz->ground_color > -1 && zz->sky_color > -1)
		return (true);
	return (false);
}

void	check_info(t_game *zz)
{
	size_t	i;
	size_t	tab_len;

	tab_len = get_tab_size(zz->my_file);
	i = 0;
	while (zz->my_file[i])
	{
		get_paths(zz, zz->my_file[i]);
		get_colours(zz, zz->my_file[i]);
		if (gathered_all_data(zz) == false && i == tab_len)
			oops_crash(zz, ERROR_DATA_INVALID);
		else if (gathered_all_data(zz) == true)
		{
			get_map(zz, i + 1);
			break ;
		}
		i++;
	}
}
