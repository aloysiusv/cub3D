/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:23:01 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/12 05:04:02 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	get_tab_size(char **tab)
{
	size_t	i;

	if (!tab)
		return (0);
	i = 0;
	if (tab[i])
		while (tab[i])
			i++;
	return (i);
}

size_t	get_max_len(char **tab)
{
	size_t	i;
	size_t	len;
	size_t	len_cmp;

	len = 0;
	i = 0;
	while (tab[i])
	{
		len_cmp = ft_strlen(tab[i]);
		if (len_cmp > len)
			len = len_cmp;
		i++;
	}
	return (len);
}

void	print_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i++;
	}
}

void	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	if (tab[i])
		while (tab[i])
			free(tab[i++]);
	free(tab);
}
