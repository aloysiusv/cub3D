/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:02:53 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 06:29:22 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define ERROR_NB_ARGS			"invalid number of arguments\n"
# define ERROR_FILE_FORMAT		"invalid file format or extension\n"
# define ERROR_FILE_CRASH		"file: unexpected crash\n"
# define ERROR_FILE_OPEN		"file: can't open file\n"
# define ERROR_FILE_EMPTY		"file: is empty\n"
# define ERROR_FILE_ASCII		"file: has non-ascii characters\n"
# define ERROR_FILE_SIZE		"file: invalid file size\n"
# define ERROR_MALLOC			"malloc failed\n"
# define ERROR_MAP_CHAR			"map: invalid char\n"
# define ERROR_MAP_SHAPE		"map: invalid shape\n"
# define ERROR_MAP_EDGES		"map: missing '1' on the edges\n"
# define ERROR_MAP_OPEN			"map: is not fully closed\n"
# define ERROR_MAP_PLAYER		"map: invalid nb of player\n"
# define ERROR_MAP_SIZE			"map: invalid size\n"
# define ERROR_INIT_MAP			"init: can't init map\n"
# define ERROR_INIT_MLX			"init: can't init mlx\n"
# define ERROR_INIT_IMG			"init: can't init img\n"
# define ERROR_INIT_IMG_ADD		"init: can't init img address\n"
# define ERROR_INIT_COLOUR		"init: can't init colour\n"
# define ERROR_BAD_ID		    "invalid identifier\n"
# define ERROR_BAD_PATH		    "invalid path\n"
# define ERROR_BAD_COLOUR	    "invalid colour\n"
# define ERROR_NON_DIGIT_COLOUR	"colour: contains non-digit characters\n"
# define ERROR_COLOUR_SIZE		"colour: value is too high or too low\n"
# define ERROR_COLOUR_COMMA		"colour: invalid formatting\n"
# define ERROR_NO_PATH		    "missing path\n"
# define ERROR_NO_COLOUR	    "missing colour\n"
# define ERROR_DATA_CLONE		"data: can't be set twice\n"
# define ERROR_DATA_INVALID		"data: invalid data\n"
# define ERROR_DATA_MISSING		"data: missing data\n"

#endif

/*
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