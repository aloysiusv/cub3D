/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:52:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_args(int ac, char **av)
{
	if (ac != 2)
		return(ft_putstr_fd(ERROR_NB_ARGS, 2), 1);
	if (ft_strlen(av[1]) < 5)
		return(ft_putstr_fd(ERROR_FORMAT, 2), 1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		return(ft_putstr_fd(ERROR_FORMAT, 2), 1);
	return (0);
}

}

static void	initialise(char **argv, t_game *root)
{
	ft_memset(root, 0, sizeof(t_game));
	ft_memset(root->texture, 0, sizeof());
	root->map_name = argv[1];
	root->ground_color = -1;
	root->sky_color = -1;
}

int		main(int argc, char **argv)
{
	t_game root;

	if (check_args(argc, argv) == 1)
		return (1);
	initialise(argv, &root);
	parsing(&root);
	launch_game(&root);
	free_all(&root);
	return (0);
}
