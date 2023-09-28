/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:25:00 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:00 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	cleanup(t_state *vars)
{

}

void	suicide(int retval, char *reason, t_state *vars)
{
	ft_printf("Program exited: %s\nreturn code: %i\n", reason, retval);
	exit(retval);
}
