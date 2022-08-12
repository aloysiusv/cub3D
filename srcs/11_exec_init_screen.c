/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:46:40 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/11 08:07:04 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_screen(t_game *zz)
{
	mlx_get_screen_size(zz->data.mlx_ptr, &zz->screenx, &zz->screeny);
	if (zz->rx > zz->screenx)
		zz->rx = zz->screenx;
	if (zz->ry > zz->screeny)
		zz->ry = zz->screeny;
}
