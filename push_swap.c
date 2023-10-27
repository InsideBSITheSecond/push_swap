/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:53:08 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/27 16:23:05 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	stack_a = checkparse(argc, argv);
	stack_b = NULL;
	considersuicide(stack_a, &(t_heap ){.tmp = NULL});
	init_index(stack_a);
	if (issorted(stack_a))
		freeheap(&(t_heap){.stack_a = &stack_a});
	compute_sort_ops(&stack_a, &stack_b);
	if (PRINTSTACK)
		ft_cdlliter(stack_a, print);
	freeheap(&(t_heap){.stack_a = &stack_a});
	return (0);
}
