/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suicide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:29:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/09 07:29:30 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	suicide(t_cdllist **stack_a, t_cdllist **stack_b, char *reason)
{
	if (stack_a && *stack_a)
		ft_cdlldrop(stack_a, bruh);
	if (stack_b && *stack_b)
		ft_cdlldrop(stack_b, bruh);
	ft_printf("[ERR]: Program ended:\n  %s\n", reason);
}
