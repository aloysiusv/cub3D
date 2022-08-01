/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:02:53 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 21:13:21 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define ERROR_NB_ARGS			"Error\nInvalid number of arguments\n"
# define ERROR_FORMAT			"Error\nInvalid file format or extension\n"
# define ERROR_OPEN				"Error\nOpen failed\n"
# define ERROR_MALLOC			"Error\nMalloc failed\n"
# define ERROR_MAP_CHAR			"Error\nmap: invalid char\n"
# define ERROR_MAP_SHAPE		"Error\nmap: invalid shape\n"
# define ERROR_MAP_WALLS		"Error\nmap: invalid walls\n"
# define ERROR_MAP_PLAYER		"Error\nmap: invalid nb of player\n"
# define ERROR_MAP_SIZE			"Error\nmap: invalid size\n"
# define ERROR_INIT_MAP			"Error\ninit: can't init map\n"
# define ERROR_INIT_MLX			"Error\ninit: can't init mlx\n"
# define ERROR_INIT_IMG			"Error\ninit: can't init img\n"
# define ERROR_INIT_COLOUR		"Error\ninit: can't init colour\n"
# define ERROR_DATA_CLONE		"Error\ndata: can't be set twice\n"
# define ERROR_DATA_MISSING		"Error\ndata: missing data\n"

#endif

/*
nb d'args (only 2);
when reading: check for non printable char, check for fdm, check for massive input;
check extension;
check that it's not /dev/null and dev/urandom;
handle all type of spaces inside the config file; info can be in any order, execpt map
which is always last; (\n is ok after map);
check if info is repeated;
check if info is correct or not (MO or SON, instead of SO);
check that map is not cut in two (no /n/n);
check for invalid chars in map (01NSEW);
parse colours: space is ok, only num, only 3 args, only 0-255, then convert colours into rgb;
check that map exists + exceeds 3 lines;
check for missing info;
check textures path ()
AND LAST BUT NOT LEAST:check that map is closed; (floodfill);
*/