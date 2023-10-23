/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:37:22 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/20 00:26:26 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//useless
void	bruh(void *bruh)
{
	return ;
}

//print the content of a stack item
void	print(void *lst)
{
	ft_putnbr_base((int)(((t_cdllist *)lst)->content), "0123456789");
	write(1, " | ", 3);
	//printf("%i | ", (int)(((t_cdllist *)lst)->content));
}

//print the details of a stack item
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
	// printf("stack A: | "); ft_cdlliter(a_tail, print); printf("\n");
	// printf("stack B: | "); ft_cdlliter(b_tail, print); printf("\n\n");
	write(1, "A: | ", 5);
	ft_cdlliter(a_tail, print);
	write(1, "\n", 1);
	write(1, "B: | ", 5);
	ft_cdlliter(b_tail, print);
	write(1, "\n\n", 2);
}
