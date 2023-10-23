/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/28 15:25:00 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:00 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
			if ((int)min->content > (int)head->content && head->index == -1)
				min = head;
		head = head->next;
	}
	if (min)
		if ((int)min->content > (int)head->content && head->index == -1)
			min = head;
	return (min);
}

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
	//ft_cdlliter(tail, print); printf("\n\n");
}
