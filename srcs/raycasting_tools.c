/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:03 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:09:05 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	  stepsidedist(t_s *zz)
{
	if (zz->ray.raydirx < 0)
	{
		zz->ray.stepx = -1;
		zz->ray.sidedistx = (zz->ray.posx - zz->ray.mapx) \
							* zz->ray.deltadistx;
	}
	else
	{
		zz->ray.stepx = 1;
		zz->ray.sidedistx = (zz->ray.mapx + 1.0 - zz->ray.posx) \
							* zz->ray.deltadistx;
	}
	if (zz->ray.raydiry < 0)
	{
		zz->ray.stepy = -1;
		zz->ray.sidedisty = (zz->ray.posy - zz->ray.mapy) \
							* zz->ray.deltadisty;
	}
	else
	{
		zz->ray.stepy = 1;
		zz->ray.sidedisty = (zz->ray.mapy + 1.0 - zz->ray.posy) \
							* zz->ray.deltadisty;
	}
	incrementing_ray(zz);
}

void	incrementing_ray(t_s *zz)
{
	while (zz->ray.hit == 0)
	{
		if (zz->ray.sidedistx < zz->ray.sidedisty)
		{
			zz->ray.sidedistx += zz->ray.deltadistx;
			zz->ray.mapx += zz->ray.stepx;
			zz->ray.side = 0;
		}
		else
		{
			zz->ray.sidedisty += zz->ray.deltadisty;
			zz->ray.mapy += zz->ray.stepy;
			zz->ray.side = 1;
		}
		if (zz->map[zz->ray.mapx][zz->ray.mapy] == '1')
			zz->ray.hit = 1;
	}
	wall_limit(zz);
}

void	wall_limit(t_s *zz)
{
	if (zz->ray.side == 0)
		zz->ray.perpwalldist = ((double)zz->ray.mapx - \
				zz->ray.posx + (1 - (double)zz->ray.
				stepx) / 2) / zz->ray.raydirx;
	else
		zz->ray.perpwalldist = ((double)zz->ray.mapy - \
				zz->ray.posy + (1 - (double)zz->ray.
				stepy) / 2) / zz->ray.raydiry;
	zz->ray.lineheight = (int)(zz->ry / zz->ray.perpwalldist);
	zz->ray.drawstart = -zz->ray.lineheight / 2 + zz->ry / 2;
	if (zz->ray.drawstart < 0)
		zz->ray.drawstart = 0;
	zz->ray.drawend = zz->ray.lineheight / 2 + zz->ry / 2;
	if (zz->ray.drawend >= zz->ry || zz->ray.drawend < 0)
		zz->ray.drawend = zz->ry - 1;
}

void	change_frame(t_s *zz)
{
	void *tmp;

	tmp = zz->data.img;
	zz->data.img = zz->data.img2;
	zz->data.img2 = tmp;
	tmp = zz->data.addr;
	zz->data.addr = zz->data.addr2;
	zz->data.addr2 = tmp;
}
