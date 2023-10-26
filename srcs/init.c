/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:19:51 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/25 20:39:24 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// return the unindexed node with the lowest value
t_cdllist	*get_unindexed_min(t_cdllist *tail)
{
	t_cdllist	*head;
	t_cdllist	*min;

	head = tail->next;
	min = NULL;
	while (head != tail)
	{
		if (!min && head->index == -1)
			min = head;
		if (min)
			if ((int)(intptr_t)min->content > (int)(intptr_t)head->content
				&& head->index == -1)
				min = head;
		head = head->next;
	}
	if (min)
		if ((int)(intptr_t)min->content > (int)(intptr_t)head->content
			&& head->index == -1)
			min = head;
	return (min);
}

// initialize every node's indexes
void	init_index(t_cdllist *tail)
{
	int			i;
	int			size;
	t_cdllist	*min;

	i = 1;
	size = ft_cdllsize(tail);
	while (size >= i)
	{
		min = get_unindexed_min(tail);
		if (min)
			min->index = i;
		i++;
	}
}
