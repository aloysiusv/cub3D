/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_exec_init_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:46:23 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 16:26:02 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_moves(t_game *zz)
{
	zz->data.forward = 0;
	zz->data.back = 0;
	zz->data.left = 0;
	zz->data.right = 0;
	zz->data.rotate_right = 0;
	zz->data.rotate_left = 0;
	zz->ray.posx = (double)zz->dx + 0.5;
	zz->ray.posy = (double)zz->dy + 0.5;
	zz->ray.dirx = 0;
	zz->ray.diry = 0;
	zz->ray.planx = 0;
	zz->ray.plany = 0;
}
