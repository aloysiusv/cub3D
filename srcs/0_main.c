/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:24:20 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 23:38:31 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd(ERROR_NB_ARGS, 2), false);
	if (ft_strlen(argv[1]) < 5)
		return (ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		return (ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	return (true);
}

static void	init(char **argv, t_game *zz)
{
	ft_memset(zz, 0, sizeof(t_game));
	ft_memset(zz->texture, 0, sizeof(t_data) * 4);
	zz->map_name = argv[1];
	zz->no = NULL;
	zz->so = NULL;
	zz->ea = NULL;
	zz->we = NULL;
	zz->map = NULL;
	zz->my_file = NULL;
	zz->ground_color = -1;
	zz->sky_color = -1;
	zz->rx = 21471;
	zz->ry = 21471;
}

static void	parsing(char **argv, t_game *zz)
{	
	init(argv, zz);
	get_file(zz);
	check_info(zz);
	check_map(zz);
	// printf("====================================\n");
	// printing_parsing(zz);
	// printf("====================================\n");
}

int	main(int argc, char **argv)
{
	t_game	zz;

	if (check_args(argc, argv) == false)
		return (1);
	parsing(argv, &zz);
	launch_game(&zz);
	free_all(&zz);
	return (0);
}
