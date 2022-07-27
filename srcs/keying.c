/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:30 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:08:32 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keying(int keycode, t_s *zz)
{
	if (keycode == FORWARD_W_Z)
		zz->data.forward = 1;
	else if (keycode == BACK_S_S)
		zz->data.back = 1;
	else if (keycode == LEFT_A_Q)
		zz->data.left = 1;
	else if (keycode == RIGHT_D_D)
		zz->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		zz->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		zz->data.rotate_right = 1;
	else if (keycode == 65307)
		exiting(zz, "\n");
	return (1);
}

int		key_releasing(int keycode, t_s *zz)
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
