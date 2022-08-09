/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 03:08:38 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/04 10:34:03 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	convert_rgb_to_int(int rgb[3])
{
	int	t;

	i = 0;
	return (t << 24 | rgb[0] << 16 | rgb[1] << 8 | rbg[2]);
}

static void	ft_atoi_colour(t_root *root, char *line, size_t *i, size_t *j)
{
	while (line[*i] && ft_isset(line[*i], SPACE_TAB))
		*i++;
	if (!ft_isdigit(line[*i]))
		clean_error_exit(root, line, ERROR_COLOUR_INVALID);
	root->rgb[*j] = 0;
	while (ft_isdigit(line[*i]))
	{
		root->rgb[*j] = root->rgb[*j] * 10 + line[*i] - 48;
		*i++;
	}
	if (root->rgb[*j] > 255)
		clean_error_exit(root, line, ERROR_COLOUR_INVALID);
	while (line[*i] && ft_isset(line[*i], SPACE_TAB))
		*i++;
	if (*j < 2 && line[*i + 1] != ',')
		clean_error_exit(root, line, ERROR_COLOUR_INVALID);
	while (line[*i] && ft_isset(line[*i], SPACE_TAB))
		*i++;
}

static void	stock_colours(t_root *root, char *line, int txtr)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (line[i])
	{
		while (j < 3)
		{
			ft_atoi_colour(root, line, &i, &j);
			j++;
		}
		i++;
	}
	txtr = convert_rgb_to_int(rgb);
}

bool	get_colours(t_game *root, char *line)
{
	size_t	i;

	i = 0;
	if (line[i] == 'C' && line[i + 1])
	{
		if (root->ceiling != -1)
			clean_error_exit(root, line, ERROR_DATA_CLONE);
		stock_colours(root, line, root->ceiling);
		return (true);
	}
	else if (line[i] == 'F' && line[i + 1])
	{
		if (root->floor != -1)
			clean_error_exit(root, line, ERROR_DATA_CLONE);
		stock_colours(root, line, root->floor);
		return (true);
	}
	return (false);
}
