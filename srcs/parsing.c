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
	char		**split;
	int			argiv;
	char		*tmp;

	stack = NULL;
	split = NULL;
	argiv = 0;
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
				ft_cdlladd_front(stack, ft_cdllnew((void *)(intptr_t)argiv));
				stack->next->index = -1;
			}
			else
				suicide(&stack, NULL, "[CRIT]: duplicate argument");
		}
	}
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		split = ft_split(tmp, ' ');
		free(tmp);
		while (split[argiv])
			argiv++;
		return (parse(argiv, split));
	}
	else
		suicide(NULL, NULL, "[CRIT]: Invalid arguments");
	return (stack);
}
