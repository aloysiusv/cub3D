/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:55 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:08:57 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_infos(t_s *zz)
{
	if (check_walls(zz) == 1)
		exiting(zz, "Map non entouree de 1\n");
	if (zz->depart == 'Z')
		exiting(zz, "Pas de joueur\n");
}
