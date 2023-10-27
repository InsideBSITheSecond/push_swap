/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suicide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:29:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/27 16:33:22 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/// @brief free an allocated split
/// @param split
void	splitfree(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

/// @brief free the heap.
/// @param heap 
void	freeheap(t_heap *heap)
{
	if (heap->splitted)
		splitfree(heap->split);
	ft_cdlldrop(heap->stack_a, bruh);
	ft_cdlldrop(heap->stack_b, bruh);
	free(heap->tmp);
}



/// @brief this function will consider suicide and do it if all hopes are lost
/// the function suicide in a clean way and don't
/// leave a mess of allocated stuff behind
/// @param check 
/// @param heap 
void	considersuicide(void *check, t_heap *heap)
{
	if (!check)
	{
		freeheap(heap);
		ft_putstr_fd("Error\n", 2);
		exit(2);
	}
}
