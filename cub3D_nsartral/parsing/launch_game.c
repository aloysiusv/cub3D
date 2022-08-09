/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:37:48 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/09 11:14:51 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	init_mlx(t_game *zz)
{
	init_moves(zz);	
	init_pov(zz);
	zz->data.mlx_ptr = mlx_init();
	if (!zz->data.mlx_ptr)
		exiting("error: cant initiate mlx\n", zz);
	init_screen(zz);
	init_textures(zz);
	init_images(zz);
}

static void	executing_mlx(t_game *zz)
{
	zz->data.mlx_win = mlx_new_window(zz->data.mlx_ptr, zz->rx,
			zz->ry, "Losange4D");
	mlx_hook(zz->data.mlx_win, 33, 1L << 17, exiting, zz);
	mlx_hook(zz->data.mlx_win, 2, 1L << 0, keying, zz);
	mlx_loop_hook(zz->data.mlx_ptr, raycasting, zz);
	mlx_hook(zz->data.mlx_win, 3, 1L << 1, releasing, zz);
	mlx_loop(zz->data.mlx_ptr);	
}

void	launch_game(t_game *zz)
{
	init_mlx(zz);
	executing_mlx(zz);
}