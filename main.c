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
	printf("%i | ", (int)(((t_cdllist *)lst)->content));
}

void printall(void *lst)
{
	printf("\n          %p\n", (t_cdllist *)lst);
	printf("%p - %i (%i) - %p\n", ((t_cdllist *)lst)->prev, (int)(((t_cdllist *)lst)->content), (int)(((t_cdllist *)lst)->index), ((t_cdllist *)lst)->next);
}

void bruh(void *bruh)
{
	return ;
}

void stackdisplay(t_cdllist *a_tail, t_cdllist *b_tail)
{
	/*t_cdllist	*a_head = a_tail->next;
	t_cdllist	*b_head = b_tail->next;
	int	ad = 0;
	int bd = 0;

	printf("========= current stack status =========\n");
	while (a_head != a_tail || b_head != b_tail)
	{
		printf("%i    %i\n", ((t_cdllist *)b_head)->content);
		if (a_head == a_tail && ad == 1)
			printf("%i", ((t_cdllist *)a_head)->content);
		else if (a_head == a_tail && ad == 0)

		if(a_head != a_tail)
			a_head = a_head->next;
		if(b_head != b_tail)
			b_head = b_head->next;
	}*/
	printf("stack A: | "); ft_cdlliter(a_tail, print); printf("\n");
	printf("stack B: | "); ft_cdlliter(b_tail, print); printf("\n\n");
	sleep(SLEEP);
	//system("clear"); 
}

void	getindexes(t_cdllist **tail)
{
	
}

int main(int argc, char **argv)
{
	t_cdllist	*stack_a;
	t_cdllist	*stack_b;

	//system("clear"); 
	stack_a = parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		ft_printf("[ERROR]: parsing error\n");

	printf("list of size %i has been given\n\n", ft_cdllsize(stack_a));
	sleep(1);
	//system("clear");
	printf("current stacks:\n");
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	stackdisplay(stack_a, stack_b);
	rb(&stack_b, 0);
	stackdisplay(stack_a, stack_b);

	printf("\n\n================\ncomplete stack dumps:\n================\nstack a:");
	ft_cdlliter(stack_a, printall);
	printf("\n\n================\nstack b:");
	ft_cdlliter(stack_b, printall);
	ft_cdlldrop(&stack_a, bruh);
	ft_cdlldrop(&stack_b, bruh);

	printf("UwU");
	return (0);
}


