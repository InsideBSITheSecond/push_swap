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

void	pa(t_cdllist **a_tail, t_cdllist **b_tail)
{
	t_cdllist	*tmp;

	tmp = ft_cdllnew((*b_tail)->next->content);
	if (ft_cdllsize(*b_tail) == 1)
		ft_cdlldrop(b_tail, bruh);
	else
		ft_cdlldelone((*b_tail)->next, bruh);
	if (*a_tail)
		ft_cdlladd_front(*a_tail, tmp);
	else
		*a_tail = tmp;
	ft_printf("exec: pa\n");
}

void	pb(t_cdllist **a_tail, t_cdllist **b_tail)
{
	t_cdllist	*tmp;

	tmp = ft_cdllnew((*a_tail)->next->content);
	if (ft_cdllsize(*a_tail) == 1)
		ft_cdlldrop(a_tail, bruh);
	else
		ft_cdlldelone((*a_tail)->next, bruh);
	if (*b_tail)
		ft_cdlladd_front(*b_tail, tmp);
	else
		*b_tail = tmp;
	ft_printf("exec: pb\n");
}
