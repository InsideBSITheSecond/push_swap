/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:45:45 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/07 18:35:16 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	exec(t_cdllist **stack_a, t_cdllist **stack_b, char *line)
{
	if (!(ft_strcmp(line, "pa\n")))
		pa(stack_a, stack_b);
	if (!(ft_strcmp(line, "pb\n")))
		pb(stack_a, stack_b);
	if (!(ft_strcmp(line, "ra\n")))
		ra(stack_a, 0);
}

int	main(int argc, char **argv)
{
	char		*line;
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	stack_a = parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		exit(ft_printf("[ERROR]: parsing error\n"));
	while (line = get_next_line(0))
	{
		exec(&stack_a, &stack_b, line);
	}
	if (PRINTSTACK)
	{
		ft_cdlliter(stack_a, print);
		ft_printf("\n");
	}
	if (issorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO!\n");
	return (!issorted(stack_a));
}
