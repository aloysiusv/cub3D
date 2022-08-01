/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_raycasting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	updating_delta(t_game *root)
{
	if (root->ray.raydiry == 0)
		root->ray.deltadistx = 0;
	else if (root->ray.raydirx == 0)
		root->ray.deltadistx = 1;
	else
		root->ray.deltadistx = sqrt(1 + (root->ray.raydiry
			* root->ray.raydiry) / (root->ray.raydirx *
			root->ray.raydirx));
	if (root->ray.raydirx == 0)
		root->ray.deltadisty = 0;
	else if (root->ray.raydiry == 0)
		root->ray.deltadisty = 1;
	else
		root->ray.deltadisty = sqrt(1 + (root->ray.raydirx *
			root->ray.raydirx) / (root->ray.raydiry *
			root->ray.raydiry));
}

void	updating_ray(t_game *root)
{
	root->ray.hit = 0;
	root->ray.perpwalldist = 0;
	root->ray.camerax = 2 * root->ray.x / (double)root->rx - 1;
	root->ray.raydirx = root->ray.dirx + root->ray.planx * \
						root->ray.camerax;
	root->ray.raydiry = root->ray.diry + root->ray.plany * \
						root->ray.camerax;
	root->ray.mapx = (int)root->ray.posx;
	root->ray.mapy = (int)root->ray.posy;
	root->ray.movespeed = 0.1;
	root->ray.rotspeed = 0.033 * 1.8;
	updating_delta(root);
}
