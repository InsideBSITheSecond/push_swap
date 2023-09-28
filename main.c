/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:40:08 by insidebsi         #+#    #+#             */
/*   Updated: 2023/09/18 22:40:08 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"
#include <stdio.h> 

void print(void *lst)
{
	printf("%i | ", ((t_cdllist *)lst)->content);
}

void printall(void *lst)
{
	printf("\n          %p\n", (t_cdllist *)lst);
	printf("%p - %i - %p\n", ((t_cdllist *)lst)->prev, ((t_cdllist *)lst)->content, ((t_cdllist *)lst)->next);
}

void stackdisplay(t_cdllist *a_tail, t_cdllist *b_tail)
{
	
}


int main(int argc, char **argv)
{
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	stack_a = parse(argc, argv);
	if (!stack_a)
		ft_printf("[ERROR]: parsing error\n");
	printf("list of size %i has been given\n\n", ft_cdllsize(stack_a));
	ft_cdlliter(stack_a, print); printf("\n");
	ft_cdlldrop(stack_a);
	ft_printf("size: %i", ft_cdllsize(stack_a));
	return (0);
}
