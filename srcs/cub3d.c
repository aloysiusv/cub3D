/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:36:26 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 22:36:28 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

bool	check_arguments(int argc, char **argv, char **envp)
{
	if (envp[0] == NULL)
		return (0);
	if (argc != 2)
		return (0);
	if (ft_strlenz(argv[1]) < 5)
		return (0);
	if (ft_strncmp(&argv[1][ft_strlenz(argv[1]) - 4], ".cub", 5) != 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	t_s zz;

	if (check_arguments(argc, argv, envp) == 0)
		return (printf("write a valid map name"), 0);
	initing_parsing(argv, &zz);
	ft_parsing(&zz);
	return (0);
}
