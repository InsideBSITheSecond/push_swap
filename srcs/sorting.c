/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:35:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/10 15:42:36 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	compute_sort_ops(t_cdllist **stack_a, t_cdllist **stack_b)
{
	//if (ft_cdllsize(*stack_a) <= 5)
	//	simple(stack_a, stack_b);
	//else
		radix(stack_a, stack_b);
}

void	simple(t_cdllist **stack_a, t_cdllist **stack_b)
{
	printf("let's pretend like we re sorting shit here... (argc < 5)\n");
}

void	radix(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int			size;
	int			max;
	int			max_bits;
	t_cdllist	*a_head;

	size = ft_cdllsize(*stack_a);
	max = size;
	max_bits = 0;
	a_head = (*stack_a)->next;
	while ((max >> max_bits) != 0)
		++max_bits;
	for (int i = 0; i < max_bits; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			a_head = (*stack_a)->next;
			if (((a_head->index >> i) & 1) == 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b);
		}
		while (ft_cdllsize(*stack_b) != -1)
			pa(stack_a, stack_b);
	}
}
