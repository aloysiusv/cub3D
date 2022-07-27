/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:39 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:08:42 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving_front_back(t_s *zz)
{
	if (zz->data.forward == 1)
	{
		if (zz->map[(int)(zz->ray.posx + (zz->ray.dirx * zz->
						ray.movespeed * 2))][(int)zz->ray.posy] == '0')
			zz->ray.posx += zz->ray.dirx * zz->ray.movespeed;
		if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy +
					(zz->ray.diry * zz->ray.movespeed * 2))] == '0')
			zz->ray.posy += zz->ray.diry * zz->ray.movespeed;
	}
	if (zz->data.back == 1)
	{
		if (zz->map[(int)(zz->ray.posx - (zz->ray.dirx * zz->
						ray.movespeed * 2))][(int)(zz->ray.posy)] == '0')
			zz->ray.posx -= zz->ray.dirx * zz->ray.movespeed;
		if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy -
					(zz->ray.diry * zz->ray.movespeed * 2))] == '0')
			zz->ray.posy -= zz->ray.diry * zz->ray.movespeed;
	}
}

void	moving_left_right(t_s *zz)
{
	if (zz->data.right == 1)
	{
		if (zz->map[(int)(zz->ray.posx + zz->ray.diry *
					(zz->ray.movespeed * 2))][(int)zz->ray.posy] == '0')
			zz->ray.posx += zz->ray.diry * zz->ray.movespeed;
		if (zz->map[(int)zz->ray.posx][(int)(zz->ray.posy -
					zz->ray.dirx *
					(zz->ray.movespeed * 2))] == '0')
			zz->ray.posy -= zz->ray.dirx * zz->ray.movespeed;
	}
	if (zz->data.left == 1)
	{
		if (zz->map[(int)(zz->ray.posx - zz->ray.diry *
					(zz->ray.movespeed * 2))][(int)zz->ray.posy] == '0')
			zz->ray.posx -= zz->ray.diry * zz->ray.movespeed;
		if (zz->map[(int)zz->ray.posx][(int)(zz->ray.posy +
					zz->ray.dirx *
					(zz->ray.movespeed * 2))] == '0')
			zz->ray.posy += zz->ray.dirx * zz->ray.movespeed;
	}
}


void	rotating_left_right(t_s *zz)
{
	double oldplanx;
	double olddirx;

	oldplanx = zz->ray.planx;
	olddirx = zz->ray.dirx;
	if (zz->data.rotate_right == 1)
	{
		zz->ray.dirx = zz->ray.dirx * cos(-zz->ray.rotspeed / 2) -
			zz->ray.diry * sin(-zz->ray.rotspeed / 2);
		zz->ray.diry = olddirx * sin(-zz->ray.rotspeed / 2) +
			zz->ray.diry * cos(-zz->ray.rotspeed / 2);
		zz->ray.planx = zz->ray.planx * cos(-zz->ray.rotspeed / 2)
			- zz->ray.plany * sin(-zz->ray.rotspeed / 2);
		zz->ray.plany = oldplanx * sin(-zz->ray.rotspeed / 2) +
			zz->ray.plany * cos(-zz->ray.rotspeed / 2);
	}
	rotating_left(zz, olddirx);
}

void	rotating_left(t_s *zz, double olddirx)
{
	double oldplanex;

	if (zz->data.rotate_left == 1)
	{
		olddirx = zz->ray.dirx;
		oldplanex = zz->ray.planx;
		zz->ray.dirx = zz->ray.dirx * cos(zz->ray.rotspeed / 2) -
			zz->ray.diry * sin(zz->ray.rotspeed / 2);
		zz->ray.diry = olddirx * sin(zz->ray.rotspeed / 2) + zz->
			ray.diry * cos(zz->ray.rotspeed / 2);
		zz->ray.planx = zz->ray.planx * cos(zz->ray.rotspeed / 2) -
			zz->ray.plany * sin(zz->ray.rotspeed / 2);
		zz->ray.plany = oldplanex * sin(zz->ray.rotspeed / 2) +
			zz->ray.plany * cos(zz->ray.rotspeed / 2);
	}
}
