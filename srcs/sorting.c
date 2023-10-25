/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:35:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/25 18:38:31 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// decide if we shall perform simple sort or radix sort
void	compute_sort_ops(t_cdllist **stack_a, t_cdllist **stack_b)
{
	if (ft_cdllsize(*stack_a) <= 5)
		simple(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

// simple sort
void	simple(t_cdllist **stack_a, t_cdllist **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	printf("let's pretend like we re sorting shit here... (argc < 5)\n");
}

// radix sort
void	radix(t_cdllist **stack_a, t_cdllist **stack_b)
{
	int				size;
	static t_ivec2d	max = (t_ivec2d){.x = 0, .y = 0};
	static t_ivec2d	i = (t_ivec2d){.x = 0, .y = 0};
	t_cdllist		*a_head;

	size = ft_cdllsize(*stack_a);
	max.x = size;
	a_head = (*stack_a)->next;
	while ((max.x >> max.y) != 0)
		++max.y;
	while (i.x < max.y)
	{
		i.y = 0;
		while (i.y++ < size)
		{
			a_head = (*stack_a)->next;
			if (((a_head->index >> i.x) & 1) == 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b);
		}
		while (ft_cdllsize(*stack_b) != -1)
			pa(stack_a, stack_b);
		i.x++;
	}
}
