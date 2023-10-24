/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:17 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:52:17 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_cdllist **a_tail, t_cdllist **b_tail)
{
	t_cdllist	*tmp;

	tmp = ft_cdllnew((*b_tail)->next->content);
	tmp->index = (*b_tail)->next->index;
	if (ft_cdllsize(*b_tail) == 1)
		ft_cdlldrop(b_tail, bruh);
	else
		ft_cdlldelone((*b_tail)->next, bruh);
	if (*a_tail)
		ft_cdlladd_front(*a_tail, tmp);
	else
		*a_tail = tmp;
	if (!SILENT)
		ft_printf("pa\n");
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_cdllist **a_tail, t_cdllist **b_tail)
{
	t_cdllist	*tmp;

	tmp = ft_cdllnew((*a_tail)->next->content);
	tmp->index = (*a_tail)->next->index;
	if (ft_cdllsize(*a_tail) == 1)
		ft_cdlldrop(a_tail, bruh);
	else
		ft_cdlldelone((*a_tail)->next, bruh);
	if (*b_tail)
		ft_cdlladd_front(*b_tail, tmp);
	else
		*b_tail = tmp;
	if (!SILENT)
		ft_printf("pb\n");
}
