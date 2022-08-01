/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:18 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 17:44:11 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_moves(t_game *root)
{
	root->data.forward = 0;
	root->data.back = 0;
	root->data.left = 0;
	root->data.right = 0;
	root->data.rotate_right = 0;
	root->data.rotate_left = 0;
	root->ray.posx = (double)root->dx + 0.5;
	root->ray.posy = (double)root->dy + 0.5;
	root->ray.dirx = 0;
	root->ray.diry = 0;
	root->ray.planx = 0;
	root->ray.plany = 0;
	init_pov(root);
}

void	init_pov(t_game *root)
{
	if (root->depart == 'N')
		root->ray.dirx = -1;
	if (root->depart == 'S')
		root->ray.dirx = 1;
	if (root->depart == 'E')
		root->ray.diry = 1;
	if (root->depart == 'W')
		root->ray.diry = -1;
	if (root->depart == 'N')
		root->ray.plany = 0.66;
	if (root->depart == 'S')
		root->ray.plany = -0.66;
	if (root->depart == 'E')
		root->ray.planx = 0.66;
	if (root->depart == 'W')
		root->ray.planx = -0.66;
}
