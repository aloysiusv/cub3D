/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:06:46 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/01 06:56:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	check_format(char *str, t_game *root)
{
	int i;
	int m;
	int n;
	i = 1;
	m = 0;
	n = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] < '0' && str[i] > '9'))
		exiting(root, "  ");
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
	{
		if (str[i] == ',')
			m++;
		i++;
	}
	if (str[i] && str[i] < '0' && str[i] > '9')
		exiting(root, "  ");
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
	{
		if (str[i] == ',')
			n++;
		i++;
	}
	if (str[i] && str[i] < '0' && str[i] > '9')
		exiting(root, "  ");
	if (m != 1 || n != 1)
		exiting(root, "  ");
	while (str[i])
		{
			if (str[i] == ',')
				exiting(root, "  ");
	
			i++;
		}
}	

int 	color_formating(char *str, t_game *root)
{
	int i;
	if (str[1] != ' ')
		exiting(root, "  ");
	check_format(str, root);
	i = 1;
	root->r = 0;
	root->g = 0;
	root->b = 0;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		root->r = (root->r * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		root->g = (root->g * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		root->b = (root->b * 10) + (str[i] - '0');
		i++;
	}
	if (root->r > 255 || root->g > 255 || root->b > 255)
		exiting(root, "  ");
	return ((root->r & 0xff) << 16) + ((root->g & 0xff) << 8) + (root->b & 0xff);
}
