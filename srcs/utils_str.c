/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:14:10 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/13 21:54:14 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

char	*replace_word(char *word, char fill)
{
	size_t			i;
	char			*new_word;
	const size_t	len = ft_strlen(word);

	new_word = (char *)malloc(sizeof(char) * (len + 2));
	if (new_word == NULL)
		return (NULL);
	i = 0;
	new_word[i] = fill;
	i = 1;
	while (i < len)
	{
		new_word[i] = word[i];
		i++;
	}
	new_word[i] = fill;
	new_word[i + 1] = '\0';
	return (new_word);
}
