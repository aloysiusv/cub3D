/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_hook_releasing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:44:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/11 08:07:04 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		releasing(int keycode, t_game *zz)
{
	if (keycode == FORWARD_W_Z)
		zz->data.forward = 0;
	else if (keycode == BACK_S_S)
		zz->data.back = 0;
	else if (keycode == LEFT_A_Q)
		zz->data.left = 0;
	else if (keycode == RIGHT_D_D)
		zz->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		zz->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		zz->data.rotate_right = 0;
	return (1);
}
