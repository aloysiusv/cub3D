/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:39 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving_front_back(t_game *root)
{
	if (root->data.forward == 1)
	{
		if (root->map[(int)(root->ray.posx + (root->ray.dirx * root->
						ray.movespeed * 2))][(int)root->ray.posy] == '0')
			root->ray.posx += root->ray.dirx * root->ray.movespeed;
		if (root->map[(int)(root->ray.posx)][(int)(root->ray.posy +
					(root->ray.diry * root->ray.movespeed * 2))] == '0')
			root->ray.posy += root->ray.diry * root->ray.movespeed;
	}
	if (root->data.back == 1)
	{
		if (root->map[(int)(root->ray.posx - (root->ray.dirx * root->
						ray.movespeed * 2))][(int)(root->ray.posy)] == '0')
			root->ray.posx -= root->ray.dirx * root->ray.movespeed;
		if (root->map[(int)(root->ray.posx)][(int)(root->ray.posy -
					(root->ray.diry * root->ray.movespeed * 2))] == '0')
			root->ray.posy -= root->ray.diry * root->ray.movespeed;
	}
}

void	moving_left_right(t_game *root)
{
	if (root->data.right == 1)
	{
		if (root->map[(int)(root->ray.posx + root->ray.diry *
					(root->ray.movespeed * 2))][(int)root->ray.posy] == '0')
			root->ray.posx += root->ray.diry * root->ray.movespeed;
		if (root->map[(int)root->ray.posx][(int)(root->ray.posy -
					root->ray.dirx *
					(root->ray.movespeed * 2))] == '0')
			root->ray.posy -= root->ray.dirx * root->ray.movespeed;
	}
	if (root->data.left == 1)
	{
		if (root->map[(int)(root->ray.posx - root->ray.diry *
					(root->ray.movespeed * 2))][(int)root->ray.posy] == '0')
			root->ray.posx -= root->ray.diry * root->ray.movespeed;
		if (root->map[(int)root->ray.posx][(int)(root->ray.posy +
					root->ray.dirx *
					(root->ray.movespeed * 2))] == '0')
			root->ray.posy += root->ray.dirx * root->ray.movespeed;
	}
}


void	rotating_left_right(t_game *root)
{
	double oldplanx;
	double olddirx;

	oldplanx = root->ray.planx;
	olddirx = root->ray.dirx;
	if (root->data.rotate_right == 1)
	{
		root->ray.dirx = root->ray.dirx * cos(-root->ray.rotspeed / 2) -
			root->ray.diry * sin(-root->ray.rotspeed / 2);
		root->ray.diry = olddirx * sin(-root->ray.rotspeed / 2) +
			root->ray.diry * cos(-root->ray.rotspeed / 2);
		root->ray.planx = root->ray.planx * cos(-root->ray.rotspeed / 2)
			- root->ray.plany * sin(-root->ray.rotspeed / 2);
		root->ray.plany = oldplanx * sin(-root->ray.rotspeed / 2) +
			root->ray.plany * cos(-root->ray.rotspeed / 2);
	}
	rotating_left(root, olddirx);
}

void	rotating_left(t_game *root, double olddirx)
{
	double oldplanex;

	if (root->data.rotate_left == 1)
	{
		olddirx = root->ray.dirx;
		oldplanex = root->ray.planx;
		root->ray.dirx = root->ray.dirx * cos(root->ray.rotspeed / 2) -
			root->ray.diry * sin(root->ray.rotspeed / 2);
		root->ray.diry = olddirx * sin(root->ray.rotspeed / 2) + root->
			ray.diry * cos(root->ray.rotspeed / 2);
		root->ray.planx = root->ray.planx * cos(root->ray.rotspeed / 2) -
			root->ray.plany * sin(root->ray.rotspeed / 2);
		root->ray.plany = oldplanex * sin(root->ray.rotspeed / 2) +
			root->ray.plany * cos(root->ray.rotspeed / 2);
	}
}
