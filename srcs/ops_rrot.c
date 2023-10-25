/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:39 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/25 17:24:56 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_cdllist **a_tail, int silent)
{
	*a_tail = (*a_tail)->prev;
	if (!silent && !SILENT)
		ft_printf("rra\n");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_cdllist **b_tail, int silent)
{
	*b_tail = (*b_tail)->prev;
	if (!silent && !SILENT)
		ft_printf("rrb\n");
}

// rra and rrb at the same time.
void	rrr(t_cdllist **a_tail, t_cdllist **b_tail)
{
	rra(a_tail, 1);
	rrb(b_tail, 1);
	if (!SILENT)
		ft_printf("rrr\n");
}
