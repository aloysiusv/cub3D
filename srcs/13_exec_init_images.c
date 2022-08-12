/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_exec_init_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:46:11 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 16:21:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_images(t_game *zz)
{
	zz->data.img = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	if (zz->data.img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->data.addr = (int *)mlx_get_data_addr(zz->data.img,
			&zz->data.bits_per_pixel,
			&zz->data.line_length, &zz->data.endian);
	if (zz->data.addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG_ADD);
	zz->data.img2 = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	if (zz->data.img2 == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->data.addr2 = (int *)mlx_get_data_addr(zz->data.img2,
			&zz->data.bits_per_pixel,
			&zz->data.line_length, &zz->data.endian);
	if (zz->data.addr2 == NULL)
		oops_crash(zz, ERROR_INIT_IMG_ADD);
}
