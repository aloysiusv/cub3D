/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycasting_loop(t_game *root)
{
	root->ray.x = 0;
	while (root->ray.x < root->rx)
	{
		updating_ray(root);
		  stepsidedist(root);
		coloring_wall(root);
		root->ray.x++;
	}
	mlx_put_image_to_window(root->data.mlx_ptr, root->data.mlx_win,
			root->data.img, 0, 0);
	moving_front_back(root);
	moving_left_right(root);
	rotating_left_right(root);
	change_frame(root);
	return (0);
}

int		ft_mlx(t_game *root)
{
	init_moves(root);
	if (!(root->data.mlx_ptr = mlx_init()))
		exiting(root, "Mlx init impossible\n");
	mlx_get_screen_size(root->data.mlx_ptr, &root->screenx, &root->screeny);
	root->rx = (root->rx > root->screenx) ? root->screenx : root->rx;
	root->ry = (root->ry > root->screeny) ? root->screeny : root->ry;
	get_texture(root);
	root->data.img = mlx_new_image(root->data.mlx_ptr, root->rx, root->ry);
	root->data.addr = (int *)mlx_get_data_addr(root->data.img, &root->data.
			bits_per_pixel, &root->data.line_length, &root->data.endian);
	root->data.mlx_win = mlx_new_window(root->data.mlx_ptr, root->rx,
			root->ry, "Hello world!");
	root->data.img2 = mlx_new_image(root->data.mlx_ptr, root->rx, root->ry);
	root->data.addr2 = (int *)mlx_get_data_addr(root->data.img2, &root->
			data.bits_per_pixel, &root->data.line_length, &root->data.endian);
	mlx_hook(root->data.mlx_win, 33, 1L << 17, exiting, root);
	mlx_hook(root->data.mlx_win, 2, 1L << 0, keying, root);
	mlx_loop_hook(root->data.mlx_ptr, raycasting_loop, root);
	mlx_hook(root->data.mlx_win, 3, 1L << 1, key_releasing, root);
	mlx_loop(root->data.mlx_ptr);
	return (0);
}
