/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:05:56 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/09 11:45:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

size_t	ft_lstsize2(t_node *lst)
{
	size_t	size;

	if (lst == 0)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}


t_node	*create_node(char *line)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->stock = line;
	new->next = NULL;
	return (new);
}

t_node	*add_next_node(t_node *current_last, char *line)
{
	t_node	*bottom;

	bottom = create_node(line);
	if (!bottom)
		return (NULL);
	if (current_last)
	{
		current_last->next = bottom;
		bottom->next = NULL;
	}
	return (bottom);
}

void	delete_node(t_node *to_del)
{
	if (!to_del)
		return ;
	if (to_del->stock)
		free(to_del->stock);
	free(to_del);
}

void	delete_lst(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		printf("tmp = [%s]\n", tmp->stock);
		delete_node(tmp);
	}
}
