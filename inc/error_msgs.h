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

# define INVALID_FORMAT	"Error\nInvalid file format or extension\n"
# define INVALID_SHAPE	"Error\nMap has an invalid shape\n"
# define INVALID_CHAR	"Error\nFound an invalid char pattern\n"
# define OPEN_FAILURE	"Error\nOpen failed\n"
# define INIT_FAILURE	"Error\nTroubles while reading or init Map\n"
# define MLX_FAILURE	"Error\nMlx initializaton failed\n"
# define IMG_FAILURE	"Error\nTroubles while loading or init image\n"
# define COLOUR_FAILURE	"Error\nTroubles while loading or init color\n"
# define HAS_CLONES		"Error\nData can't be set twice\n"
# define E_OPEN_MAP		"Error\nMap open\n"
# define E_BIG_MAP		"Error\nMap too big for the window\n"
# define E_SPAWN_ERR	"Error\nNumber of spawn required is one\n"
# define E_NO_DATA		"Error\nSome required data is missing\n"
# define E_MLC_ERR		"Error\nMalloc failed\n"

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