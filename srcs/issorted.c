/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:59 by insidebsi         #+#    #+#             */
/*   Updated: 2023/10/07 16:30:14 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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