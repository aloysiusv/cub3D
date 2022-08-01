/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:30 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keying(int keycode, t_game *root)
{
	if (keycode == FORWARD_W_Z)
		root->data.forward = 1;
	else if (keycode == BACK_S_S)
		root->data.back = 1;
	else if (keycode == LEFT_A_Q)
		root->data.left = 1;
	else if (keycode == RIGHT_D_D)
		root->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		root->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		root->data.rotate_right = 1;
	else if (keycode == 65307)
		exiting(root, "\n");
	return (1);
}

int		key_releasing(int keycode, t_game *root)
{
	if (keycode == FORWARD_W_Z)
		root->data.forward = 0;
	else if (keycode == BACK_S_S)
		root->data.back = 0;
	else if (keycode == LEFT_A_Q)
		root->data.left = 0;
	else if (keycode == RIGHT_D_D)
		root->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		root->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		root->data.rotate_right = 0;
	return (1);
}
