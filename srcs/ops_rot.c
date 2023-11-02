/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/11/02 17:31:46 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_cdllist **a_tail, int silent)
{
	*a_tail = (*a_tail)->next;
	if (!silent && !SILENT)
		ft_printf("ra\n");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_cdllist **b_tail, int silent)
{
	*b_tail = (*b_tail)->next;
	if (!silent && !SILENT)
		ft_printf("rb\n");
}

// ra and rb at the same time.
void	rr(t_cdllist **a_tail, t_cdllist **b_tail)
{
	ra(a_tail, 1);
	rb(b_tail, 1);
	if (!SILENT)
		ft_printf("rr\n");
}
