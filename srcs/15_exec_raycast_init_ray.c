/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycast_init_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:49:04 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 05:12:32 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_ray(t_game *zz)
{
	zz->ray.hit = 0;
	zz->ray.perpwalldist = 0;
	zz->ray.camerax = 2 * zz->ray.x / (double)zz->rx - 1;
	zz->ray.raydirx = zz->ray.dirx + zz->ray.planx * zz->ray.camerax;
	zz->ray.raydiry = zz->ray.diry + zz->ray.plany * zz->ray.camerax;
	zz->ray.mapx = (int)zz->ray.posx;
	zz->ray.mapy = (int)zz->ray.posy;
	zz->ray.movespeed = 0.1;
	zz->ray.rotspeed = 0.033 * 1.8;	
}

void	init_deltadist(t_game *zz)
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

void	init_sidedist(t_game *zz)
{
	if (zz->ray.raydirx < 0)
	{
		zz->ray.stepx = -1;
		zz->ray.sidedistx = (zz->ray.posx - zz->ray.mapx) * zz->ray.deltadistx;
	}
	else
	{
		zz->ray.stepx = 1;
		zz->ray.sidedistx =
			(zz->ray.mapx + 1.0 - zz->ray.posx) * zz->ray.deltadistx;
	}
	if (zz->ray.raydiry < 0)
	{
		zz->ray.stepy = -1;
		zz->ray.sidedisty = (zz->ray.posy - zz->ray.mapy) * zz->ray.deltadisty;
	}
	else
	{
		zz->ray.stepy = 1;
		zz->ray.sidedisty =
			(zz->ray.mapy + 1.0 - zz->ray.posy) * zz->ray.deltadisty;
	}
}
