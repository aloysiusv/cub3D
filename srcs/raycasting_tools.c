/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:03 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	  stepsidedist(t_game *root)
{
	if (root->ray.raydirx < 0)
	{
		root->ray.stepx = -1;
		root->ray.sidedistx = (root->ray.posx - root->ray.mapx) \
							* root->ray.deltadistx;
	}
	else
	{
		root->ray.stepx = 1;
		root->ray.sidedistx = (root->ray.mapx + 1.0 - root->ray.posx) \
							* root->ray.deltadistx;
	}
	if (root->ray.raydiry < 0)
	{
		root->ray.stepy = -1;
		root->ray.sidedisty = (root->ray.posy - root->ray.mapy) \
							* root->ray.deltadisty;
	}
	else
	{
		root->ray.stepy = 1;
		root->ray.sidedisty = (root->ray.mapy + 1.0 - root->ray.posy) \
							* root->ray.deltadisty;
	}
	incrementing_ray(root);
}

void	incrementing_ray(t_game *root)
{
	while (root->ray.hit == 0)
	{
		if (root->ray.sidedistx < root->ray.sidedisty)
		{
			root->ray.sidedistx += root->ray.deltadistx;
			root->ray.mapx += root->ray.stepx;
			root->ray.side = 0;
		}
		else
		{
			root->ray.sidedisty += root->ray.deltadisty;
			root->ray.mapy += root->ray.stepy;
			root->ray.side = 1;
		}
		if (root->map[root->ray.mapx][root->ray.mapy] == '1')
			root->ray.hit = 1;
	}
	wall_limit(root);
}

void	wall_limit(t_game *root)
{
	if (root->ray.side == 0)
		root->ray.perpwalldist = ((double)root->ray.mapx - \
				root->ray.posx + (1 - (double)root->ray.
				stepx) / 2) / root->ray.raydirx;
	else
		root->ray.perpwalldist = ((double)root->ray.mapy - \
				root->ray.posy + (1 - (double)root->ray.
				stepy) / 2) / root->ray.raydiry;
	root->ray.lineheight = (int)(root->ry / root->ray.perpwalldist);
	root->ray.drawstart = -root->ray.lineheight / 2 + root->ry / 2;
	if (root->ray.drawstart < 0)
		root->ray.drawstart = 0;
	root->ray.drawend = root->ray.lineheight / 2 + root->ry / 2;
	if (root->ray.drawend >= root->ry || root->ray.drawend < 0)
		root->ray.drawend = root->ry - 1;
}

void	change_frame(t_game *root)
{
	void *tmp;

	tmp = root->data.img;
	root->data.img = root->data.img2;
	root->data.img2 = tmp;
	tmp = root->data.addr;
	root->data.addr = root->data.addr2;
	root->data.addr2 = tmp;
}
