/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:24:20 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/14 00:31:36 by nsartral         ###   ########.fr       */
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
	ft_memset(zz->texture, 0, sizeof(t_data));
	zz->map_name = argv[1];
	zz->no = 0;
	zz->so = 0;
	zz->ea = 0;
	zz->we = 0;
	zz->map = NULL;
	zz->my_file = NULL;
	zz->ground_color = -1;
	zz->sky_color = -1;
	zz->rx = 2565;
	zz->ry = 2048;
}

static void	parsing(char **argv, t_game *zz)
{	
	init(argv, zz);
	get_file(zz);
	check_info(zz);
	check_map(zz);
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
