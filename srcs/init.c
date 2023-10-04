/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:25:00 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:00 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_cdllist	*get_unindexed_min(t_cdllist *tail)
{
	t_cdllist *head = tail->next;
	t_cdllist *min = NULL;
	
	while(head != tail)
	{
		if (!min && head->index == -1)
			min = head;
		if (min)
			if (min->content > head->content && head->index == -1)
				min = head;
		head = head->next;
	}
	if (min)
		if (min->content > head->content && head->index == -1)
			min = head;
	return (min);
}

void	init_index(t_cdllist *tail)
{
	int size = ft_cdllsize(tail);
	t_cdllist	*min;

	for (int i = 1; size >= i; i++)
	{
		min = get_unindexed_min(tail);
		if (min)
			min->index = i;
	}
}