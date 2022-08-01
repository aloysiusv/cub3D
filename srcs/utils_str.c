/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:14:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 21:02:54 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3D.h"

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

size_t	count_chars(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
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
