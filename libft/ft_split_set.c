/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:14:05 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 17:04:57 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_words(char **new_arr, size_t nb_of_words)
{
	size_t	i;

	i = 0;
	while (i < nb_of_words)
		free(new_arr[i++]);
	free(new_arr);
	return (0);
}

static size_t	word_count(char const *s, char *seps)
{
	size_t	i;
	size_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (s[i])
	{
		while (ft_strchr(seps, s[i]))
			i++;
		if (s[i] != '\0')
			nb_of_words++;
		while (ft_strchr(seps, s[i]))
			i++;
	}
	return (nb_of_words);
}

static char	*word_cpy(char const **s, char *seps)
{
	char	*word;
	size_t	i;

	i = 0;
	while (**s && ft_strchr(seps, (*s)[i]))
		(*s)++;
	while ((*s)[i] && !ft_strchr(seps, (*s)[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == 0)
		return (0);
	ft_strlcpy(word, *s, i + 1);
	*s = *s + i;
	return (word);
}

char	**ft_split_set(char const *s, char *seps)
{
	char	**new_arr;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = word_count(s, seps);
	new_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (new_arr == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		new_arr[i] = word_cpy(&s, seps);
		if (new_arr[i] == 0)
			return (free_words(new_arr, i));
		i++;
	}
	new_arr[i] = 0;
	return (new_arr);
}
