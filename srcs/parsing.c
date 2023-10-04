/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:51 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/26 14:19:51 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_cdllist	*parse(int argc, char **argv)
{
	t_cdllist	*stack;
	t_cdllist	*newnode;
	int			argiv;

	if (argc > 2)
	{
		argiv = ft_atoi(argv[1]);
		stack = ft_cdllnew((void *)(intptr_t)argiv);
		stack->index = -1;
		for (int i = 2; i <= argc - 1; i++)
		{
			argiv = ft_atoi(argv[i]);
			if (!ft_cdllfind(stack, (void *)(intptr_t)argiv))
			{
				newnode = ft_cdllnew((void *)(intptr_t)argiv);
				newnode->index = -1;
				ft_cdlladd_back(&stack, newnode);
			}
			else
				return (NULL);
		}
	}
	return (stack);
}

