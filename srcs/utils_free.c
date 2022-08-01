/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:07:12 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 22:36:41 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_game *root)
{
	size_t	i;

	i = 0;
	if (root->no)
		free(root->no);
	if (root->so)
		free(root->so);
	if (root->we)
		free(root->we);
	if (root->ea)
		free(root->ea);
	if (root->map)
	{
		while (i < root->ylines)
			free(root->map[i++]);
		free(root->map);
	}
}

void	free_all(t_game *root)
{
	if (!root)
		return ;
	free_map(root);
	if (root->data.img)
		mlx_destroy_image(root->data.mlx_ptr, root->data.img);
	if (root->texture[0].img)
		mlx_destroy_image(root->data.mlx_ptr, root->texture[0].img);
	if (root->texture[1].img)
		mlx_destroy_image(root->data.mlx_ptr, root->texture[1].img);
	if (root->texture[2].img)
		mlx_destroy_image(root->data.mlx_ptr, root->texture[2].img);
	if (root->texture[3].img)
		mlx_destroy_image(root->data.mlx_ptr, root->texture[3].img);
	if (root->data.mlx_win)
		mlx_destroy_window(root->data.mlx_ptr, root->data.mlx_win);
}

void	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	oops_crash(t_game *root, char *msg)
{
	const char	*err = "Error\n";

	if (root)
		free_all(root);
	write(2, err, ft_strlen(err));
	write(2, msg, ft_strlen(msg));
	exit(1)
}

void	clean_error_exit(t_game *root, char *line, char *error_msg)
{
	if (line)
		free(line);
	oops_crash(root, error_msg);
}