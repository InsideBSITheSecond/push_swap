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
		exit(ft_printf("[ERROR]: parsing error\n"));
	init_index(stack_a);
	if (issorted(stack_a))
	{
		ft_cdlldrop(stack_a, bruh);
		ft_cdlldrop(stack_b, bruh);
	}
	sort(&stack_a, &stack_b);
	return (0);
}
