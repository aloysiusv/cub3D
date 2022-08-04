/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/04 03:14:26 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_args(int ac, char **av)
{
	if (ac != 2)
		return(ft_putstr_fd(ERROR_NB_ARGS, 2), false);
	if (ft_strlen(av[1]) < 5)
		return(ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 5) != 0)
		return(ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	return (true);
}

static void	init_root(char **argv, t_game *root)
{
	ft_memset(root, 0, sizeof(t_game));
	ft_memset(root->texture, NULL, sizeof(t_data) * 4);
	root->map_name = argv[1];
	root->floor = -1;
	root->ceiling = -1;
}

static void	parsing(t_game *root)
{
	int fd;

	fd = 0;
	check_file(root, &fd);
	check_info(root, fd);
	check_map(root, fd);
}

int		main(int argc, char **argv)
{
	t_game root;

	if (check_args(argc, argv) == false)
		return (1);
	init_root(argv, &root);
	check_file();
	parsing(&root);
	launch_game(&root);
	free_all(&root);
	return (0);
}
