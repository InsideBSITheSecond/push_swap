/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:47:32 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:47:32 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//https://www.autodraw.com/share/3VRCONR71FE8
//1-2 node A
//3-4 node B
//5-6 node C via A pointers
void	sa(t_cdllist *a_tail, int silent)
{
	ft_cdllswap(a_tail);
	if (!silent)
		ft_printf("sa\n");
}

void	sb(t_cdllist *b_tail, int silent)
{
	ft_cdllswap(b_tail);
	if (!silent)
		ft_printf("sb\n");
}

void	ss(t_cdllist *a_tail, t_cdllist *b_tail)
{
	sa(a_tail, 1);
	sb(b_tail, 1);
	ft_printf("ss\n");
}
