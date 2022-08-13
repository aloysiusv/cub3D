/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_exec_raycast_raycasting.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:49:24 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/13 22:11:38 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	change_frame(t_game *zz)
{
	void	*tmp;

	tmp = zz->data.img;
	zz->data.img = zz->data.img2;
	zz->data.img2 = tmp;
	tmp = zz->data.addr;
	zz->data.addr = zz->data.addr2;
	zz->data.addr2 = tmp;
}

static void	sending_ray(t_game *zz)
{
	init_ray(zz);
	init_deltadist(zz);
	init_sidedist(zz);
	incrementing(zz);
	calculating(zz);
}

int	raycasting(t_game *zz)
{
	zz->ray.x = 0;
	while (zz->ray.x < zz->rx)
	{
		sending_ray(zz);
		texturing_scene(zz);
		zz->ray.x++;
	}
	mlx_put_image_to_window(zz->data.mlx_ptr, zz->data.mlx_win,
		zz->data.img, 0, 0);
	moving_front_back(zz);
	moving_left_right(zz);
	rotating_left_right(zz);
	change_frame(zz);
	return (0);
}
