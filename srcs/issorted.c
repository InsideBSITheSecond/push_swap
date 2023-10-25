/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:59 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/25 17:10:44 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// check if the given stack is sorted
int	issorted(t_cdllist *tail)
{
	t_cdllist	*head;
	int			sorted;

	head = NULL;
	if (tail)
		head = tail->next;
	sorted = 1;
	while (head && head->next != tail)
	{
		if (!((int)head->content < (int)head->next->content))
			sorted = 0;
		head = head->next;
	}
	if (head)
		if (!((int)head->content < (int)head->next->content))
			sorted = 0;
	return (sorted);
}
