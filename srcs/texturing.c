/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:16 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *root)
{
	if (root->ray.side == 0 && root->ray.raydirx < 0)
		root->t.texdir = 0;
	if (root->ray.side == 0 && root->ray.raydirx >= 0)
		root->t.texdir = 1;
	if (root->ray.side == 1 && root->ray.raydiry < 0)
		root->t.texdir = 2;
	if (root->ray.side == 1 && root->ray.raydiry >= 0)
		root->t.texdir = 3;
	if (root->ray.side == 0)
		root->t.wallx = root->ray.posy + root->ray.perpwalldist \
						* root->ray.raydiry;
	else
		root->t.wallx = root->ray.posx + root->ray.perpwalldist \
						* root->ray.raydirx;
	root->t.wallx -= floor((root->t.wallx));
}

void		coloring_wall(t_game *root)
{
	int j;
	int i;

	j = -1;
	root->ray.drawend = root->ry - root->ray.drawstart;
	i = root->ray.drawend;
	while (++j < root->ray.drawstart)
		root->data.addr[j * root->data.line_length / 4 +
			root->ray.x] = root->sky_color;
	if (j <= root->ray.drawend)
		displaying_texture(root, root->ray.x, j);
	j = i;
	while (++j < root->ry)
		root->data.addr[j * root->data.line_length / 4 +
			root->ray.x] = root->ground_color;
}

void	displaying_texture(t_game *root, int x, int y)
{
	y = root->ray.drawstart - 1;
	init_texture(root);
	root->t.step = 1.0 * root->texture[0].height / root->ray.lineheight;
	root->t.texx = (int)(root->t.wallx * (double)root->texture
			[root->t.texdir].width);
	if (root->ray.side == 0 && root->ray.raydirx > 0)
		root->t.texx = root->texture[root->t.texdir].width -
			root->t.texx - 1;
	if (root->ray.side == 1 && root->ray.raydiry < 0)
		root->t.texx = root->texture[root->t.texdir].width -
			root->t.texx - 1;
	root->t.texpos = (root->ray.drawstart - root->ry / 2 +
			root->ray.lineheight / 2) * root->t.step;
	while (++y <= root->ray.drawend)
	{
		root->t.texy = (int)root->t.texpos &
			(root->texture[root->t.texdir].height - 1);
		root->t.texpos += root->t.step;
		if (y < root->ry && x < root->rx)
			root->data.addr[y * root->data.line_length / 4 + x] =
				root->texture[root->t.texdir].addr[root->t.texy *
					root->texture[root->t.texdir].line_length /
					4 + root->t.texx];
	}
}

void	get_texture(t_game *root)
{
	if (!(root->texture[0].img = mlx_xpm_file_to_image(root->data.mlx_ptr,
					root->no, &(root->texture[0].width),
					&(root->texture[0].height))))
		exiting(root, "Texture SO\n");
	if (!(root->texture[1].img = mlx_xpm_file_to_image(root->data.mlx_ptr,
					root->so, &(root->texture[1].width),
					&(root->texture[1].height))))
		exiting(root, "Texture NO\n");
	if (!(root->texture[2].img = mlx_xpm_file_to_image(root->data.mlx_ptr,
					root->we, &(root->texture[2].width),
					&(root->texture[2].height))))
		exiting(root, "Texture EA\n");
	if (!(root->texture[3].img = mlx_xpm_file_to_image(root->data.mlx_ptr,
					root->ea, &(root->texture[3].width),
					&(root->texture[3].height))))
		exiting(root, "Texture WE\n");
	get_adress_texture(root);
}

void	get_adress_texture(t_game *root)
{
	root->texture[0].addr = (int *)mlx_get_data_addr(root->texture[0].img,
			&root->texture[0].bits_per_pixel,
			&root->texture[0].line_length, &root->texture[0].endian);
	root->texture[1].addr = (int *)mlx_get_data_addr(root->texture[1].img,
			&root->texture[1].bits_per_pixel,
			&root->texture[1].line_length, &root->texture[1].endian);
	root->texture[2].addr = (int *)mlx_get_data_addr(root->texture[2].img,
			&root->texture[2].bits_per_pixel,
			&root->texture[2].line_length, &root->texture[2].endian);
	root->texture[3].addr = (int *)mlx_get_data_addr(root->texture[3].img,
			&root->texture[3].bits_per_pixel,
			&root->texture[3].line_length, &root->texture[3].endian);
}
