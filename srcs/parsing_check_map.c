/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:01 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/11 17:26:00 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	lili_check_map(t_game *zz)
{
	size_t	i;
	size_t	j;

	zz->ylines = get_tab_size(zz->map) - 1;
	i = 0;
	while (zz->map[i])
	{
		j = 0;
		while (zz->map[i][j])
		{
			if ((i == 0 || i == zz->ylines)
				&& !ft_isset(zz->map[i][j], " 	1"))
				oops_crash(zz, ERROR_MAP_WALLS);
			if (j == 0 && zz->map[i][j] != '1')
			{
				j = skip_blanks(zz->map[i], j);
				if (zz->map[i][j] != '1')
					oops_crash(zz, ERROR_MAP_WALLS);
			}
			if (j == ft_strlen(zz->map[i])
				&& zz->map[i][j] != '1')
			{
				j = skip_rev_blanks(zz->map[i], j);
				if (zz->map[i][j] != '1')
					oops_crash(zz, ERROR_MAP_WALLS);
			}
			// if (!ft_isset(zz->map[i][j], " 	01NSEW"))
			// 	oops_crash(zz, ERROR_MAP_CHAR);
			j++;
		}
		if (i != 0 && i != zz->ylines && j != 0
			&& j != ft_strlen(zz->map[i]) && zz->map[i][j] == '0')
		{
			if (!zz->map[i][j - 1] || ft_isset(zz->map[i][j - 1], SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
			if (!zz->map[i][j + 1] || ft_isset(zz->map[i][j + 1], SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
			if (!zz->map[i - 1][j] || ft_isset(zz->map[i - 1][j], SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
			if (!zz->map[i + 1][j] || ft_isset(zz->map[i + 1][j], SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
		}
		i++;
	}
}
