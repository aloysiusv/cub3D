/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:07:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/09 11:26:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	free_map(t_game *zz)
{
	size_t	i;

	i = 0;
	if (zz->no)
		free(zz->no);
	if (zz->so)
		free(zz->so);
	if (zz->we)
		free(zz->we);
	if (zz->ea)
		free(zz->ea);
	if (zz->map)
	{
		while (i < (size_t)zz->ylines)
			free(zz->map[i++]);
		free(zz->map);
	}
}

void	free_all(t_game *zz)
{
	if (!zz)
		return ;
	if (zz->my_file)
		delete_lst(zz->my_file);
	free_map(zz);
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

void	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	oops_crash(t_game *zz, char *msg)
{
	char	err[] = "Error\n";

	if (zz)
		free_all(zz);
	ft_putstr_fd(err, 2);
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