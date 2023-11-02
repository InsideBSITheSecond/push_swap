/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:57:16 by insidebsi         #+#    #+#             */
/*   Updated: 2023/11/02 23:07:23 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

/*
1 2 3
3 2 1 sa rra
3 1 2 ra
1 3 2 ra sa rra
2 1 3 sa
2 3 1 rra
*/

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
	{
		ra(stack_a, 0);
		sa(stack_a, 0);
		rra(stack_a, 0);
	}
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
		{
			sa(stack_a, 0);
			rra(stack_a, 0);
		}
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

void	simple(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int	size;

	size = ft_cdllsize(*stack_a);
	if (size == 2)
		sa(stack_a, 0);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}