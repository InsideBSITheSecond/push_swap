/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:37:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/24 08:45:33 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// function that does literally nothing
void	bruh(void *bruh)
{
	return ;
}

// print the content of a cdll node using putnbr_base (for b2radix debugging purposes)
void	print(void *lst)
{
	ft_putnbr_base((int)(((t_cdllist *)lst)->content), "0123456789");
	write(1, " | ", 3);
}

// print all attributes of a cdll node
void	printall(void *lst)
{
	printf("\n          %p\n", (t_cdllist *)lst);
	printf("%p - %i (%i) - %p\n", ((t_cdllist *)lst)->prev,
		(int)(((t_cdllist *)lst)->content), (int)(((t_cdllist *)lst)->index),
		((t_cdllist *)lst)->next);
}

//print 2 entire stacks
void	stackdisplay(t_cdllist *a_tail, t_cdllist *b_tail)
{
	write(1, "A: | ", 5);
	ft_cdlliter(a_tail, print);
	write(1, "\n", 1);
	write(1, "B: | ", 5);
	ft_cdlliter(b_tail, print);
	write(1, "\n\n", 2);
}
