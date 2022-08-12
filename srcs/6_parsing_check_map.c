/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_parsing_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:53:39 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 23:36:47 by lrandria         ###   ########.fr       */
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

static void	get_player(t_game *zz, size_t i, size_t j)
{
	if (zz->depart)
		oops_crash(zz, ERROR_MAP_PLAYER);
	else if (zz->map[i][j] == 'N')
		zz->depart = 'N';
	else if (zz->map[i][j] == 'S')
		zz->depart = 'S';
	else if (zz->map[i][j] == 'W')
		zz->depart = 'W';
	else if (zz->map[i][j] == 'E')
		zz->depart = 'E';
	zz->dx = j;
	zz->dy = i;
}

void	check_map(t_game *zz)
{
	size_t	i;
	size_t	j;

	check_walls(zz);
	i = 0;
	while (zz->map[i])
	{
		j = 0;
		while (zz->map[i][j])
		{
			if (!ft_isset(zz->map[i][j], " 	01NSWE"))
				oops_crash(zz, ERROR_MAP_CHAR);
			if (zz->map[i][j] == 'N' || zz->map[i][j] == 'S'
				|| zz->map[i][j] == 'W' || zz->map[i][j] == 'E')
				get_player(zz, i, j);
			j++;
		}
		i++;
	}
	if (gathered_everything(zz) == false)
		oops_crash(zz, ERROR_DATA_MISSING);
}
