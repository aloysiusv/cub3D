/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 01:53:37 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 02:24:54 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_only_blanks(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (true);
	while (str && str[i])
	{
		if (ft_isset(str[i], ALL_SPACES) == 1)
			count++;
		i++;
	}
	if (count == i)
		return (true);
	return (false);
}

char	*trim_spaces(char *str)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && ft_isset(str[i], ALL_SPACES) == 1)
		i++;
	j = ft_strlen(str) - 1;
	while (ft_isset(str[j], ALL_SPACES) == 1)
		j--;
	new_s = ft_substr(str, i, j + 1 - i);
	return (new_s);
}

size_t	skip_blanks(char *line, size_t i)
{
	while (line[i] && ft_isset(line[i], SPACE_TAB))
		i++;
	return (i);
}

size_t	skip_rev_blanks(char *line, size_t i)
{
	i = ft_strlen(line) - 1;
	if (line[i] && ft_isset(line[i], SPACE_TAB))
		while (line[i] && ft_isset(line[i], SPACE_TAB))
			i--;
	return (i);
}
