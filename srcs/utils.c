/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:19:27 by llegrand          #+#    #+#             */
/*   Updated: 2023/11/06 10:29:06 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sarra(t_cdllist **stack_a)
{
	sa(stack_a, 0);
	rra(stack_a, 0);
}

void	rasarra(t_cdllist **stack_a)
{
	ra(stack_a, 0);
	sa(stack_a, 0);
	rra(stack_a, 0);
}

int	get_min_index(t_cdllist *tail, int val)
{
	t_cdllist	*head;
	t_cdllist	*min;

	head = tail->next;
	min = tail;
	if (min->index == val)
		min = tail->next;
	while (head != tail)
	{
		if (min->index > head->index
			&& head->index != val)
			min = head;
		head = head->next;
	}
	if (min->index > head->index
		&& head->index != val)
		min = head;
	return (min->index);
}

int	get_distance(t_cdllist **stack, int index)
{
	t_cdllist	*head;
	int			distance;

	distance = 0;
	head = (*stack)->next;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
