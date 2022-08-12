/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_parsing_check_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:19:23 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 07:23:56 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_inside(t_game *zz, size_t i, size_t j)
{
	const char	prev_char = zz->map[i][j - 1];
	const char	next_char = zz->map[i][j + 1];
	char		up_char;
	char		down_char;

	if (j < ft_strlen(zz->map[i - 1]))
		up_char = zz->map[i - 1][j];
	else
		return ;
	if (i == get_tab_size(zz->map) - 1)
		return ;
	else
	{
		if (j < ft_strlen(zz->map[i + 1]))
			down_char = zz->map[i + 1][j];
		else 
			return ;
	}
	if (zz->map[i][j] == '0' && j != ft_strlen(zz->map[i]) - 1)
	{
		if (!prev_char || ft_isset(prev_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
		if (!next_char || ft_isset(next_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
		if (!up_char || ft_isset(up_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
		if (!down_char || ft_isset(down_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
	}
}

// if (j < ft_strlen(zz->map[i - 1]))
// 		up_char = zz->map[i - 1][j];
// 	else 
// 		return ;
// 	if (i == get_tab_size(zz->map) - 1)
// 		return ;
// 	else
// 	{
// 		if (j < ft_strlen(zz->map[i + 1]))
// 			down_char = zz->map[i + 1][j];
// 		else 
// 			return ;
// 	}

static void	check_outside(t_game *zz, size_t i, size_t j)
{
	const size_t	top_line = 0;
	const size_t	top_char = 0;
	const size_t	last_line = get_tab_size(zz->map) - 1;
	const size_t	last_char = ft_strlen(zz->map[i]) - 1;

	if ((i == top_line || i == last_line) && !ft_isset(zz->map[i][j], " 	1"))
		oops_crash(zz, ERROR_MAP_EDGES);
	else if (j == top_char && zz->map[i][j] != '1')
	{
		j = skip_blanks(zz->map[i], j);
		if (zz->map[i][j] != '1')
			oops_crash(zz, ERROR_MAP_EDGES);
	}
	else if (j == last_char && zz->map[i][j] != '1')
	{
		j = skip_rev_blanks(zz->map[i], j);
		if (zz->map[i][j] != '1')
			oops_crash(zz, ERROR_MAP_EDGES);
	}
}

void	check_walls(t_game *zz)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (zz->map[++i])
	{
		j = 0;
		while (zz->map[i][j])
		{
			check_outside(zz, i, j);
			j++;
		}
	}
	i = 1;
	while (zz->map[i])
	{
		j = 1;
		printf("line = [%s]\n", zz->map[i]);
		while (zz->map[i][j])
		{
			check_inside(zz, i, j);
			j++;
		}
		i++;
	}
}
