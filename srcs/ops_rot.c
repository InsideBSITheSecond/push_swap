/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:52:30 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ra(t_cdllist **a_tail, int silent)
{
	*a_tail = (*a_tail)->next;
	if (!silent)
		ft_printf("ra\n");
}

void	rb(t_cdllist **b_tail, int silent)
{
	*b_tail = (*b_tail)->next;
	if (!silent)
		ft_printf("rb\n");
}

void	rr(t_cdllist **a_tail, t_cdllist **b_tail)
{
	ra(a_tail, 1);
	rb(b_tail, 1);
	ft_printf("rr\n");
}
