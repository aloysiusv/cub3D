/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_raycasting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:09:32 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	updating_delta(t_s *zz)
{
	if (zz->ray.raydiry == 0)
		zz->ray.deltadistx = 0;
	else if (zz->ray.raydirx == 0)
		zz->ray.deltadistx = 1;
	else
		zz->ray.deltadistx = sqrt(1 + (zz->ray.raydiry
			* zz->ray.raydiry) / (zz->ray.raydirx *
			zz->ray.raydirx));
	if (zz->ray.raydirx == 0)
		zz->ray.deltadisty = 0;
	else if (zz->ray.raydiry == 0)
		zz->ray.deltadisty = 1;
	else
		zz->ray.deltadisty = sqrt(1 + (zz->ray.raydirx *
			zz->ray.raydirx) / (zz->ray.raydiry *
			zz->ray.raydiry));
}

void	updating_ray(t_s *zz)
{
	zz->ray.hit = 0;
	zz->ray.perpwalldist = 0;
	zz->ray.camerax = 2 * zz->ray.x / (double)zz->rx - 1;
	zz->ray.raydirx = zz->ray.dirx + zz->ray.planx * \
						zz->ray.camerax;
	zz->ray.raydiry = zz->ray.diry + zz->ray.plany * \
						zz->ray.camerax;
	zz->ray.mapx = (int)zz->ray.posx;
	zz->ray.mapy = (int)zz->ray.posy;
	zz->ray.movespeed = 0.1;
	zz->ray.rotspeed = 0.033 * 1.8;
	updating_delta(zz);
}
