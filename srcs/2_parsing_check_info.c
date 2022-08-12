/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_check_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:17:44 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 16:15:48 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	gathered_everything(t_game *zz)
{
	if (zz->no && zz->so && zz->we && zz->ea && zz->so
		&& zz->ground_color != -1 && zz->sky_color != -1
		&& zz->depart && zz->dx && zz->dy)
		return (true);
	return (false);
}

static bool	gathered_settings(t_game *zz)
{
	if (zz->no && zz->so && zz->we && zz->ea && zz->so
		&& zz->ground_color != -1 && zz->sky_color != -1)
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
		if (gathered_settings(zz) == false && i == tab_len - 3)
			oops_crash(zz, ERROR_DATA_INVALID);
		else if (gathered_settings(zz) == true)
		{
			get_map(zz, i + 1);
			break ;
		}
		i++;
	}
	if (gathered_everything(zz) == false)
		oops_crash(zz, ERROR_DATA_MISSING);
}
