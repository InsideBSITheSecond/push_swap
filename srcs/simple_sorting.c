/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:57:16 by insidebsi         #+#    #+#             */
/*   Updated: 2023/11/06 10:24:09 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort_3(t_cdllist **stack_a)
{
	t_cdllist	*head;
	int			min;
	int			next_min;

	head = (*stack_a)->next;
	min = get_min_index(*stack_a, -1);
	next_min = get_min_index(*stack_a, min);
	if (issorted(*stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
		rasarra(stack_a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a, 0);
		else
			sarra(stack_a);
	}
}

void	sort_4(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int	distance;

	if (issorted(*stack_a))
		return ;
	distance = get_distance(stack_a, get_min_index(*stack_a, -1));
	if (distance == 1)
		ra(stack_a, 0);
	else if (distance == 2)
	{
		ra(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (distance == 3)
		rra(stack_a, 0);
	if (issorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min_index(*stack_a, -1));
	if (distance == 1)
		ra(stack_a, 0);
	else if (distance == 2)
	{
		ra(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (distance == 3)
	{
		rra(stack_a, 0);
		rra(stack_a, 0);
	}
	else if (distance == 4)
		rra(stack_a, 0);
	if (issorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
