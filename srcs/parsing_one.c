/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:48 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/27 23:08:50 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_s *zz)
{
	char *str;
	int fd;
	int sxlines;
	int sylines;
	int tmp;

	zz->rx = 0;
	sxlines = 0;
	sylines = 0;
	str = NULL;
	if ((fd = open(zz->map_name, __O_DIRECTORY)) != -1)
		exiting(zz, "map name is a directory\n");
	if ((fd = open(zz->map_name, O_RDONLY)) == -1)
		exiting(zz, "map name .cub isn't treatable\n");
	str = get_next_linez(fd);
	tmp = 0;
	while (str != NULL)
	{
		//if there is empty lines after the map writes it wrong 
		if ((!ft_is_map(str) || empty_line(str)) && tmp == 1)
			exiting(zz, "wrong parsing");
		if (ft_is_map(str))
		{
			tmp = 1;
			if ((ft_strlenz(str)) > sxlines)
				sxlines = ft_strlenz(str);
			sylines = sylines + 1;
		}
		free(str);
		str = get_next_linez(fd);
	}
	zz->ylines = sylines;
	zz->xlines = sxlines;
	close(fd);
	if (zz->xlines == 0 || zz->ylines == 0)
		exiting(zz, "Map absente\n");
	return (fd);
}

int		pathing_texture(char *str, char **texture, t_s *zz, int j)
{
	zz->count = 0;
	if (*texture != NULL)
	{
		exiting(zz, "  ");
		return (0);
	}
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
			|| ft_strlen2(str) <= 2)
		exiting(zz, "  ");
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			exiting(zz, "  ");

		j++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)))))
		exiting(zz, "  ");
	while (str[j] != '\0')
	{
		(*texture)[zz->count] = str[j];
		zz->count++;
		j++;
	}
	(*texture)[zz->count] = '\0';
	return (0);
}

bool	line_type(char *line, t_s *zz)
{
	int i;
	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '\0')
		return (0);
	if (line[i] == 'R')
	{
		ft_resolution(line, zz);
		if (zz->rx == 0 || zz->ry == 0)
			exiting(zz, "wrong resolution");
	}
	if (line[i] == 'F')
		zz->ground_color = color_formating(line, zz);
	if (line[i] == 'C')
		zz->sky_color = color_formating(line, zz);
	i++;
	if (line[i] == '\0')
		return (0);
	if (line[i - 1] == 'S' && line[i] == 'O')
		pathing_texture(line, &zz->no, zz, 2);
	if (line[i - 1] == 'N' && line[i] == 'O')
		pathing_texture(line, &zz->so, zz, 2);
	if (line[i - 1] == 'E' && line[i] == 'A')
		pathing_texture(line, &zz->we, zz, 2);
	if (line[i - 1] == 'W' && line[i] == 'E')
		pathing_texture(line, &zz->ea, zz, 2);
	return (1);
	
}

bool	correct_map_infos(t_s *zz)
{
	if (zz->ground_color == -1 || zz->sky_color == -1 || zz->no == NULL ||
			zz->so == NULL || zz->we == NULL ||
			zz->ea == NULL)
				return (0);
	return (1);
}

bool	fill_map_line(char *line, int i, t_s *zz)
{
	int j;
	zz->map[i] = malloc(sizeof(char) * zz->xlines + 1);
	if (zz->map[i] == NULL)
		exiting(zz, "failed allocation");
	j = 0;
	while (line[j])
	{
		if (beginning(line[j], zz, i, j) == 1)
			zz->map[i][j] = '0';
		else if (line[j] == ' ')
			zz->map[i][j] = '1';
		else
			zz->map[i][j] = line[j];
		j++;
	}
	while (j <= (zz->xlines - 1))
	{
		zz->map[i][j] = '1';
		j++;
	}
	zz->map[i][j] = '\0';
	return (1);
}

int	ft_parsing(t_s *zz)
{
	char		*str;
	int fd;
	int	i;

	str = NULL;
	i = 0;
	fd = check_map(zz);
	if (fd == -1)
		return (0);
	if ((fd = open(zz->map_name, O_RDONLY)) == -1)
		exiting(zz, "map name .cub isn't treatable\n");	
	zz->map = malloc(sizeof(char*) * zz->ylines);
	if (zz->map == NULL)
		exiting(zz, "Can't malloc\n");
	str = get_next_linez(fd);
	while (str != NULL)
	{
		line_type(str, zz);
		if (ft_is_map(str))
		{
			if (correct_map_infos(zz) == 0)
				exiting(zz, "wrong parsing");
			fill_map_line(str, i, zz);
			i++;
		}
		str = get_next_linez(fd);
	}
	close(fd);
	check_map_infos(zz);
	ft_mlx(zz);
	return (1);
}
