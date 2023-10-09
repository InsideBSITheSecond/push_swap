/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/18 22:40:08 by insidebsi         #+#    #+#             */
/*   Updated: 2023/09/18 22:40:08 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	stack_a = parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		suicide(&stack_a, &stack_b, "[CRIT]: parsing error\n");
	init_index(stack_a);
	if (issorted(stack_a))
		suicide(&stack_a, &stack_b, "[INFO]: stack is already sorted");
	compute_sort_ops(&stack_a, &stack_b);
	suicide(&stack_a, &stack_b, NULL);
	return (0);
}
