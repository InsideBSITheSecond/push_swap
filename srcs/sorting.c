/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:35:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/11/06 10:23:20 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/// @brief decide if we shall perform simple sort or radix sort
/// @param stack_a 
/// @param stack_b 
void	compute_sort_ops(t_cdllist **stack_a, t_cdllist **stack_b)
{
	if (ft_cdllsize(*stack_a) <= 5)
		simple(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

/// @brief sorts base2 indexes using radix algorithm
/// @param stack_a 
/// @param stack_b 
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
