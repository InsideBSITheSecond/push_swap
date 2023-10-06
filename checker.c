/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:45:45 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/06 22:00:20 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	issorted(t_cdllist *tail)
{
	t_cdllist *head = tail->next;
	int sorted = 1;
	
	while (head->next != tail)
	{
		if (!((int)head->content < (int)head->next->content))
			sorted = 0;
		head = head->next;
	}
	if (!((int)head->content < (int)head->next->content))
		sorted = 0;
	return (sorted);
}

int main(int argc, char **argv)
{
	char *line;
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	stack_a = parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		ft_printf("[ERROR]: parsing error\n");
	while (line = get_next_line(0))
	{
		if (!(ft_strcmp(line, "pa\n")))
			pa(&stack_a, &stack_b);
		if (!(ft_strcmp(line, "pb\n")))
			pb(&stack_a, &stack_b);
		if (!(ft_strcmp(line, "ra\n")))
			ra(&stack_a, 0);
	}
	if (PRINTSTACK)
	{
		ft_cdlliter(stack_a, print);
		ft_printf("\n");
	}
	if (issorted(stack_a))
	{
		ft_printf("OK\n");
		return (0);
	}
	else
	{
		ft_printf("KO!\n");
		return (1);
	}
}