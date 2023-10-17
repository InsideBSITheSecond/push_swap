/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suicide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:29:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/09 07:29:30 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	splitfree(char **split)
{
	int i;

	i = 0;
	/*if (!split)
		return (0);
	if (!split[i])
		return (0);*/
	while (split[i])
	{
		free(split[i]);
		i++;
	}
}

void	considersuicide(t_stacks *stacks, void *check, char *reason)
{
	if (!check)
		suicide(stacks->a, stacks->b, reason);
}

void	suicide(t_cdllist **stack_a, t_cdllist **stack_b, char *reason)
{
	if (stack_a && *stack_a)
		ft_cdlldrop(stack_a, bruh);
	if (stack_b && *stack_b)
		ft_cdlldrop(stack_b, bruh);
	if (reason)
		ft_printf("[ERR]: Program ended:\n  %s\n", reason);
	exit(1);
}
