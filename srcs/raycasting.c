/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 18:08:20 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycasting_loop(t_game *zz)
{
	zz->ray.x = 0;
	while (zz->ray.x < zz->rx)
	{
		updating_ray(zz);
		  stepsidedist(zz);
		coloring_wall(zz);
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

int		ft_mlx(t_game *zz)
{
	init_moves(zz);
	if (!(zz->data.mlx_ptr = mlx_init()))
		exiting(zz, "Mlx init impossible\n");
	mlx_get_screen_size(zz->data.mlx_ptr, &zz->screenx, &zz->screeny);
	zz->rx = (zz->rx > zz->screenx) ? zz->screenx : zz->rx;
	zz->ry = (zz->ry > zz->screeny) ? zz->screeny : zz->ry;
	get_texture(zz);
	zz->data.img = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	zz->data.addr = (int *)mlx_get_data_addr(zz->data.img, &zz->data.
			bits_per_pixel, &zz->data.line_length, &zz->data.endian);
	zz->data.mlx_win = mlx_new_window(zz->data.mlx_ptr, zz->rx,
			zz->ry, "Hello world!");
	zz->data.img2 = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	zz->data.addr2 = (int *)mlx_get_data_addr(zz->data.img2, &zz->
			data.bits_per_pixel, &zz->data.line_length, &zz->data.endian);
	mlx_hook(zz->data.mlx_win, 33, 1L << 17, exiting, zz);
	mlx_hook(zz->data.mlx_win, 2, 1L << 0, keying, zz);
	mlx_loop_hook(zz->data.mlx_ptr, raycasting_loop, zz);
	mlx_hook(zz->data.mlx_win, 3, 1L << 1, key_releasing, zz);
	mlx_loop(zz->data.mlx_ptr);
	return (0);
}
