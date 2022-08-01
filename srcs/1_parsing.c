/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:58:28 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 15:42:16 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D"

void    parsing(t_game *root)
{
    int fd;

    fd = 0;
    check_file(root, &fd);
    check_info(root, fd);
    check_map(root, fd);
}
