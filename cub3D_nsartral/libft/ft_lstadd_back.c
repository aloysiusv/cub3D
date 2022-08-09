/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:16:32 by lrandria          #+#    #+#             */
/*   Updated: 2022/08/09 04:09:45 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*new_alst;

	if (alst == 0 || new == 0)
		return ;
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	new_alst = *alst;
	while (new_alst->next != NULL)
		new_alst = new_alst->next;
	new_alst->next = new;
}
