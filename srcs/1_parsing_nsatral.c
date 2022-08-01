/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:53:30 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/31 17:53:33 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_game *root)
{
	char *str;
	int fd;
	int sxlines;
	int sylines;
	int tmp;

	root->rx = 0;
	sxlines = 0;
	sylines = 0;
	str = NULL;
	if ((fd = open(root->map_name, __O_DIRECTORY)) != -1)
		exiting(root, "map name is a directory\n");
	if ((fd = open(root->map_name, O_RDONLY)) == -1)
		exiting(root, "map name .cub isn't treatable\n");
	str = get_next_linez(fd);
	tmp = 0;
	while (str != NULL)
	{
		//if there is empty lines after the map writes it wrong 
		if ((!ft_is_map(str) || empty_line(str)) && tmp == 1)
			exiting(root, "wrong parsing");
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
	root->ylines = sylines;
	root->xlines = sxlines;
	close(fd);
	if (root->xlines == 0 || root->ylines == 0)
		exiting(root, "Map absente\n");
	return (fd);
}

int		pathing_texture(char *str, char **texture, t_game *root, int j)
{
	root->count = 0;
	if (*texture != NULL)
	{
		exiting(root, "  ");
		return (0);
	}
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
			|| ft_strlen2(str) <= 2)
		exiting(root, "  ");
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			exiting(root, "  ");

		j++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)))))
		exiting(root, "  ");
	while (str[j] != '\0')
	{
		(*texture)[root->count] = str[j];
		root->count++;
		j++;
	}
	(*texture)[root->count] = '\0';
	return (0);
}

bool	line_type(char *line, t_game *root)
{
	int i;
	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '\0')
		return (0);
	if (line[i] == 'R')
	{
		ft_resolution(line, root);
		if (root->rx == 0 || root->ry == 0)
			exiting(root, "wrong resolution");
	}
	if (line[i] == 'F')
		root->ground_color = color_formating(line, root);
	if (line[i] == 'C')
		root->sky_color = color_formating(line, root);
	i++;
	if (line[i] == '\0')
		return (0);
	if (line[i - 1] == 'S' && line[i] == 'O')
		pathing_texture(line, &root->no, root, 2);
	if (line[i - 1] == 'N' && line[i] == 'O')
		pathing_texture(line, &root->so, root, 2);
	if (line[i - 1] == 'E' && line[i] == 'A')
		pathing_texture(line, &root->we, root, 2);
	if (line[i - 1] == 'W' && line[i] == 'E')
		pathing_texture(line, &root->ea, root, 2);
	return (1);
	
}

bool	correct_map_infos(t_game *root)
{
	if (root->ground_color == -1 || root->sky_color == -1 || root->no == NULL ||
			root->so == NULL || root->we == NULL ||
			root->ea == NULL)
				return (0);
	return (1);
}

bool	fill_map_line(char *line, int i, t_game *root)
{
	int j;
	root->map[i] = malloc(sizeof(char) * root->xlines + 1);
	if (root->map[i] == NULL)
		exiting(root, "failed allocation");
	j = 0;
	while (line[j])
	{
		if (beginning(line[j], root, i, j) == 1)
			root->map[i][j] = '0';
		else if (line[j] == ' ')
			root->map[i][j] = '1';
		else
			root->map[i][j] = line[j];
		j++;
	}
	while (j <= (root->xlines - 1))
	{
		root->map[i][j] = '1';
		j++;
	}
	root->map[i][j] = '\0';
	return (1);
}

void	parsing(t_game *root)
{
	char	*str;
	int	fd;
	int	i;

	str = NULL;
	i = 0;
	fd = check_map(root);
	if (fd == -1)
		return (0);
	if ((fd = open(root->map_name, O_RDONLY)) == -1)
		exiting(root, "map name .cub isn't treatable\n");	
	root->map = malloc(sizeof(char*) * root->ylines);
	if (root->map == NULL)
		exiting(root, "Can't malloc\n");
	str = get_next_linez(fd);
	while (str != NULL)
	{
		line_type(str, root);
		if (ft_is_map(str))
		{
			if (correct_map_infos(root) == 0)
				exiting(root, "wrong parsing");
			fill_map_line(str, i, root);
			i++;
		}
		str = get_next_linez(fd);
	}
	close(fd);
	check_map_infos(root);
	ft_mlx(root);
	return (1);
}
