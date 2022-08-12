/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:07:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 16:18:10 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_textures(t_game *zz)
{
	if (zz->no)
		free(zz->no);
	if (zz->so)
		free(zz->so);
	if (zz->we)
		free(zz->we);
	if (zz->ea)
		free(zz->ea);
}

void	free_all(t_game *zz)
{
	free_textures(zz);
	free_tab(zz->map);
	free_tab(zz->my_file);
	if (zz->data.img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->data.img);
	if (zz->texture[0].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[0].img);
	if (zz->texture[1].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[1].img);
	if (zz->texture[2].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[2].img);
	if (zz->texture[3].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[3].img);
	if (zz->data.mlx_win)
		mlx_destroy_window(zz->data.mlx_ptr, zz->data.mlx_win);
}

void	good_exit(t_game *zz, char *str)
{
	if (zz)
		free_all(zz);
	if (str)
		write(1, str, ft_strlen(str));
	exit(0);
}

void	oops_crash(t_game *zz, char *msg)
{
	if (zz)
		free_all(zz);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	clean_error_exit(t_game *zz, char *line, int fd, char *error_msg)
{
	if (line)
		free(line);
	if (fd)
		close(fd);
	oops_crash(zz, error_msg);
}
