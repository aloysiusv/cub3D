/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:09:19 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/31 18:03:21 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D"

void    rage_quit_error(t_game *root, char *msg)
{
    if (root)
        free_all(root);
    write(2, msg, ft_strlen(msg));
    exit(1)
}
