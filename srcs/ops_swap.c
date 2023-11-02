/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:47:32 by llegrand          #+#    #+#             */
/*   Updated: 2023/11/02 20:40:58 by insidebsi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//https://www.autodraw.com/share/3VRCONR71FE8
//1-2 node A
//3-4 node B
//5-6 node C via A pointers

//Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements
void	sa(t_cdllist **a_tail, int silent)
{
	ft_cdllswap(a_tail);
	if (!silent && !SILENT)
		ft_printf("sa\n");
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_cdllist **b_tail, int silent)
{
	ft_cdllswap(b_tail);
	if (!silent && !SILENT)
		ft_printf("sb\n");
}

// sa and sb at the same time.
void	ss(t_cdllist **a_tail, t_cdllist **b_tail)
{
	sa(a_tail, 1);
	sb(b_tail, 1);
	if (!SILENT)
		ft_printf("ss\n");
}
