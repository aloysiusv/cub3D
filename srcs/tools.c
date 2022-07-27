/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:09:23 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:09:25 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen2(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

bool		ft_charinstr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

bool		beginning(char c, t_s *zz, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (zz->depart != 0)
			exiting(zz, "Plus d'un joueur\n");
		zz->depart = c;
		zz->dx = i;
		zz->dy = j;
		return (1);
	}
	return (0);
}

bool		check_walls(t_s *zz)
{
	int i;

	i = 0;
	while (zz->map[0][i])
	{
		if (zz->map[0][i] != '1')
			return (1);
		if (zz->map[zz->ylines - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < zz->ylines)
	{
		if (zz->map[i][0] != '1')
			return (1);
		if (zz->map[i][zz->xlines - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

bool	is_whitespace(char c)
{
	if (c == '\t' || c == ' ' || c == '\0' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

bool		empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '\n')
		return (1);
	return (0);
}

bool	ft_is_map(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0' || str[0] == '\n')
		return (0);
	while (str[i])
		{
			if (!is_map_char(str[i]))
				return (0);
			i++;
		}
	return (1);
}

bool		ft_check_resolution(const char *str)
{
	int i;

	i = 1;
	if (str[0] == '\0')
		return (0);
	if (str[1] != ' ')
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void		ft_resolution(const char *str, t_s *zz)
{
	int		x;
	int		i;

	x = 0;
	i = 1;
	if (!ft_check_resolution(str))
		exiting(zz, "  ");
	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && x < 21474636)
	{
		x = (x * 10) + (str[i] - '0');
		i++;
	}
	zz->rx = x;
	x = 0;
	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && x < 21474636)
	{
		x = (x * 10) + (str[i] - '0');
		i++;
	}
	zz->ry = x;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (one[i] && two[i] && one[i] == two[i] && i < n - 1)
		i++;
	return (one[i] - two[i]);
}
