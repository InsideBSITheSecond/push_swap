/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:39:58 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/14 15:39:58 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>

typedef struct	s_state{
	t_cdllist	stack_a;
	t_cdllist	stack_b;

}				t_state;

t_cdllist	*parse(int argc, char **argv);

void	sa(t_cdllist *a_tail, int silent);
void	sb(t_cdllist *a_tail, int silent);
void	ss(t_cdllist *a_tail, t_cdllist *b_tail);

void	pa(t_cdllist **a_tail, t_cdllist **b_tail);
void	pb(t_cdllist **a_tail, t_cdllist **b_tail);

void bruh(void *bruh);

#endif
