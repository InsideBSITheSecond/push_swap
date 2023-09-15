/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:41:21 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/14 15:41:21 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	p(void *content)
{
	if (content)
		printf("%i\n", content);
}

t_list	parse(int argc, char **argv)
{
	int i = 1;
	t_list *a;

	while (i < argc)
	{
		if (!a)
			a = ft_lstnew(ft_atoi(argv[i]));
		else
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		printf("a%i:%i\n", i, ft_atoi(argv[i]));
		i++;
	}
	printf("\nsize: %i\n\n", ft_lstsize(a));
	ft_lstiter(a, p);
}

int	main(int argc, char **argv)
{
	parse(argc, argv);
}
