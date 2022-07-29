/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */s
/*   Created: 2022/07/29 17:40:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 17:40:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv, char **envp)
{
	// if (!envp)
	// 	return (1);
	// if (argc != 2)
	// 	return (1);
	// if (ft_strlenz(argv[1]) < 5)
	// 	return (1);
	if (ft_strncmp(&argv[1][ft_strlenz(argv[1]) - 4], ".cub", 5) != 1)
		rage_quit_error(INVALID_FORMAT);
}

int		main(int argc, char **argv, char **envp)
{
	t_game root;

	check_args(argc, argv, envp);
	init_parsing(argv, &root);
	ft_parsing(&root);
	return (0);
}

