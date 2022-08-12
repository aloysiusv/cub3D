/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:46:52 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 05:10:40 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_adress_texture(t_game *zz)
{
	zz->texture[0].addr = (int *)mlx_get_data_addr(zz->texture[0].img,
			&zz->texture[0].bits_per_pixel,
			&zz->texture[0].line_length, &zz->texture[0].endian);
	if (zz->texture[0].addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[1].addr = (int *)mlx_get_data_addr(zz->texture[1].img,
			&zz->texture[1].bits_per_pixel,
			&zz->texture[1].line_length, &zz->texture[1].endian);
	if (zz->texture[1].addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[2].addr = (int *)mlx_get_data_addr(zz->texture[2].img,
			&zz->texture[2].bits_per_pixel,
			&zz->texture[2].line_length, &zz->texture[2].endian);
	if (zz->texture[2].addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[3].addr = (int *)mlx_get_data_addr(zz->texture[3].img,
			&zz->texture[3].bits_per_pixel,
			&zz->texture[3].line_length, &zz->texture[3].endian);
	if (zz->texture[3].addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
}

static void	get_textures(t_game *zz)
{
	zz->texture[0].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
		zz->no, &(zz->texture[0].width), &(zz->texture[0].height));
	if (zz->texture[0].img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[1].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
		zz->so, &(zz->texture[1].width), &(zz->texture[1].height));
	if (zz->texture[1].img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[2].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
		zz->ea, &(zz->texture[2].width), &(zz->texture[2].height));
	if (zz->texture[2].img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[3].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
		zz->we, &(zz->texture[3].width), &(zz->texture[3].height));
	if (zz->texture[3].img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	get_adress_texture(zz);
}

void	init_textures(t_game *zz)
{
	get_textures(zz);
	get_adress_texture(zz);
}