/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:16 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 18:08:20 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *zz)
{
	if (zz->ray.side == 0 && zz->ray.raydirx < 0)
		zz->t.texdir = 0;
	if (zz->ray.side == 0 && zz->ray.raydirx >= 0)
		zz->t.texdir = 1;
	if (zz->ray.side == 1 && zz->ray.raydiry < 0)
		zz->t.texdir = 2;
	if (zz->ray.side == 1 && zz->ray.raydiry >= 0)
		zz->t.texdir = 3;
	if (zz->ray.side == 0)
		zz->t.wallx = zz->ray.posy + zz->ray.perpwalldist \
						* zz->ray.raydiry;
	else
		zz->t.wallx = zz->ray.posx + zz->ray.perpwalldist \
						* zz->ray.raydirx;
	zz->t.wallx -= floor((zz->t.wallx));
}

void		coloring_wall(t_game *zz)
{
	int j;
	int i;

	j = -1;
	zz->ray.drawend = zz->ry - zz->ray.drawstart;
	i = zz->ray.drawend;
	while (++j < zz->ray.drawstart)
		zz->data.addr[j * zz->data.line_length / 4 +
			zz->ray.x] = zz->sky_color;
	if (j <= zz->ray.drawend)
		displaying_texture(zz, zz->ray.x, j);
	j = i;
	while (++j < zz->ry)
		zz->data.addr[j * zz->data.line_length / 4 +
			zz->ray.x] = zz->ground_color;
}

void	displaying_texture(t_game *zz, int x, int y)
{
	y = zz->ray.drawstart - 1;
	init_texture(zz);
	zz->t.step = 1.0 * zz->texture[0].height / zz->ray.lineheight;
	zz->t.texx = (int)(zz->t.wallx * (double)zz->texture
			[zz->t.texdir].width);
	if (zz->ray.side == 0 && zz->ray.raydirx > 0)
		zz->t.texx = zz->texture[zz->t.texdir].width -
			zz->t.texx - 1;
	if (zz->ray.side == 1 && zz->ray.raydiry < 0)
		zz->t.texx = zz->texture[zz->t.texdir].width -
			zz->t.texx - 1;
	zz->t.texpos = (zz->ray.drawstart - zz->ry / 2 +
			zz->ray.lineheight / 2) * zz->t.step;
	while (++y <= zz->ray.drawend)
	{
		zz->t.texy = (int)zz->t.texpos &
			(zz->texture[zz->t.texdir].height - 1);
		zz->t.texpos += zz->t.step;
		if (y < zz->ry && x < zz->rx)
			zz->data.addr[y * zz->data.line_length / 4 + x] =
				zz->texture[zz->t.texdir].addr[zz->t.texy *
					zz->texture[zz->t.texdir].line_length /
					4 + zz->t.texx];
	}
}

void	get_texture(t_game *zz)
{
	if (!(zz->texture[0].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
					zz->no, &(zz->texture[0].width),
					&(zz->texture[0].height))))
		exiting(zz, "Texture SO\n");
	if (!(zz->texture[1].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
					zz->so, &(zz->texture[1].width),
					&(zz->texture[1].height))))
		exiting(zz, "Texture NO\n");
	if (!(zz->texture[2].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
					zz->we, &(zz->texture[2].width),
					&(zz->texture[2].height))))
		exiting(zz, "Texture EA\n");
	if (!(zz->texture[3].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
					zz->ea, &(zz->texture[3].width),
					&(zz->texture[3].height))))
		exiting(zz, "Texture WE\n");
	get_adress_texture(zz);
}

void	get_adress_texture(t_game *zz)
{
	zz->texture[0].addr = (int *)mlx_get_data_addr(zz->texture[0].img,
			&zz->texture[0].bits_per_pixel,
			&zz->texture[0].line_length, &zz->texture[0].endian);
	zz->texture[1].addr = (int *)mlx_get_data_addr(zz->texture[1].img,
			&zz->texture[1].bits_per_pixel,
			&zz->texture[1].line_length, &zz->texture[1].endian);
	zz->texture[2].addr = (int *)mlx_get_data_addr(zz->texture[2].img,
			&zz->texture[2].bits_per_pixel,
			&zz->texture[2].line_length, &zz->texture[2].endian);
	zz->texture[3].addr = (int *)mlx_get_data_addr(zz->texture[3].img,
			&zz->texture[3].bits_per_pixel,
			&zz->texture[3].line_length, &zz->texture[3].endian);
}
