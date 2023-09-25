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

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
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


int main(int argc, char **argv)
{
	t_cdllist	*stack_a;
	int			argiv;

	if (argc >= 2)
	{
		argiv = atoi(argv[1]);
		stack_a = ft_cdllnew(argiv);
		for (int i = 2; i <= argc - 1; i++)
		{
			argiv = atoi(argv[i]);
			if (!ft_cdllfind(stack_a, argiv))
				ft_cdlladd_front(stack_a, ft_cdllnew(argiv));
			else
				return (ft_printf("[ERROR]: duplicate parameters...\n"));
		}
	}
	ft_cdlliter(stack_a, print);
	//ft_cdlliter(stack_a, printall);
	return (0);
}
