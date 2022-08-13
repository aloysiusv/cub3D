/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_parsing_get_colours.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:20:02 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/13 02:23:27 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	convert_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	stock_colours(t_game *zz, char *line)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 1;
	while (line[i])
	{
		i = skip_blanks(line, i);
		if (!ft_isdigit(line[i]))
			oops_crash(zz, ERROR_NON_DIGIT_COLOUR);
		while (ft_isdigit(line[i]))
		{
			zz->rgb[j] = zz->rgb[j] * 10 + line[i++] - 48;
			if (zz->rgb[j] > 255)
				oops_crash(zz, ERROR_COLOUR_SIZE);
		}
		i = skip_blanks(line, i);
		if (j < 2 && line[i] != ',')
			oops_crash(zz, ERROR_COLOUR_COMMA);
		else if (j < 2 && line[i] == ',')
			i++;
		i = skip_blanks(line, i);
		j++;
	}
}

void	get_colours(t_game *zz, char *line)
{
	size_t	i;

	i = 0;
	zz->rgb[0] = 0;
	zz->rgb[1] = 0;
	zz->rgb[2] = 0;
	i = skip_blanks(line, i);
	if (line[i] == 'F' && line[i + 1])
	{
		if (zz->ground_color != -1)
			oops_crash(zz, ERROR_DATA_CLONE);
		line = line + i;
		stock_colours(zz, line);
		zz->ground_color = convert_rgb(0, zz->rgb[0], zz->rgb[1], zz->rgb[2]);
	}
	else if (line[i] == 'C' && line[i + 1])
	{
		if (zz->sky_color != -1)
			oops_crash(zz, ERROR_DATA_CLONE);
		line = line + i;
		stock_colours(zz, line);
		zz->sky_color = convert_rgb(0, zz->rgb[0], zz->rgb[1], zz->rgb[2]);
	}
}
