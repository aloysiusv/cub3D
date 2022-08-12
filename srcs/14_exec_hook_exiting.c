/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_exec_hook_exiting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:44:05 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 23:12:14 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void	free_parsing(t_game *zz)
// {
// 	size_t	i;

// 	i = 0;
// 	if (zz->no)
// 		free(zz->no);
// 	if (zz->so)
// 		free(zz->so);
// 	if (zz->we)
// 		free(zz->we);
// 	if (zz->ea)
// 		free(zz->ea);
// 	if (zz->map)
// 		while (i++ < zz->ylines)
// 			free(zz->map[i]);
// 	if (zz->map)
// 		free(zz->map);
// }

// static void	free_mlx(t_game *zz)
// {
// 	if (zz->data.img)
// 		mlx_destroy_image(zz->data.mlx_ptr, zz->data.img);
// 	if (zz->texture[0].img)
// 		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[0].img);
// 	if (zz->texture[1].img)
// 		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[1].img);
// 	if (zz->texture[2].img)
// 		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[2].img);
// 	if (zz->texture[3].img)
// 		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[3].img);
// 	if (zz->data.mlx_win)
// 		mlx_destroy_window(zz->data.mlx_ptr, zz->data.mlx_win);
// }

int	exiting(char *str, t_game *zz)
{
	// free_parsing(zz);
	// free_mlx(zz);
	free_all(zz);
	write(1, str, ft_strlen(str));
	exit(0);
}
