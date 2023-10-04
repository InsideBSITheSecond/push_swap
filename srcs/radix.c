/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:35:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/04 23:39:24 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void radix(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int	size = ft_cdllsize(*stack_a);
	int max = size - 1;
	int max_bits = 0;
	t_cdllist	*a_head = (*stack_a)->next;

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
			//stackdisplay(*stack_a, *stack_b);
		}
		while (ft_cdllsize(*stack_b) != -1)
		{
			pa(stack_a, stack_b);
			//stackdisplay(*stack_a, *stack_b);
		}
	}
}