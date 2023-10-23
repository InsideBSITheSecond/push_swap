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
# include "../libft/includes/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

# ifndef SLEEP
#  define SLEEP 1
# endif

# ifndef SILENT
#  define SILENT 0
# endif

# ifndef PRINTSTACK
#  define PRINTSTACK 0
# endif

typedef struct s_stacks
{
	t_cdllist	**a;
	t_cdllist	**b;
}				t_stacks;

t_cdllist	*parse(int argc, char **argv, int splitted);
t_cdllist	*checkparse(int argc, char **argv);

void		sa(t_cdllist *a_tail, int silent);
void		sb(t_cdllist *a_tail, int silent);
void		ss(t_cdllist *a_tail, t_cdllist *b_tail);

void		pa(t_cdllist **a_tail, t_cdllist **b_tail);
void		pb(t_cdllist **a_tail, t_cdllist **b_tail);

void		ra(t_cdllist **a_tail, int silent);
void		rb(t_cdllist **a_tail, int silent);
void		rr(t_cdllist **a_tail, t_cdllist **b_tail);

void		bruh(void *bruh);

void		print(void *lst);
void		printall(void *lst);
void		stackdisplay(t_cdllist *a_tail, t_cdllist *b_tail);
t_cdllist	*get_unindexed_min(t_cdllist *tail);
void		init_index(t_cdllist *tail);
int			check_base(char *base);
void		ft_putnbr_base(int nbr, char *base);
void		radix(t_cdllist **stack_a, t_cdllist **stack_b);
void		compute_sort_ops(t_cdllist **stack_a, t_cdllist **stack_b);
void		simple(t_cdllist **stack_a, t_cdllist **stack_b);
int			issorted(t_cdllist *tail);
void		considersuicide(t_stacks *stacks, void *check, char *reason);
void		suicide(t_cdllist **stack_a, t_cdllist **stack_b, char *reason);
void		splitfree(char **split);
#endif
