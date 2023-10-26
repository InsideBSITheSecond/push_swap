/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suicide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:29:30 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/26 18:10:42 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// free a split
void	splitfree(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// this function will consider suicide and do it if all hopes are lost
// the function suicide in a clean way and don't
// leave a mess of allocated stuff behind
void	considersuicide(void *check, char *reason, int cleancount, ...)
{
	int		i;
	va_list	list;
	void	*ptr;

	i = 0;
	if (!check)
	{
		va_start(list, cleancount);
		while (i < cleancount)
		{
			ptr = va_arg(list, void *);
			if (!ft_strcmp(((char **)ptr)[0], "./push_swap"))
				splitfree(ptr);
			else if (((t_cdllist *)ptr)->content)
				ft_cdlldrop((t_cdllist **)ptr, bruh);
			else
				free(ptr);
			i++;
		}
		va_end(list);
		if (!PRINTERROR)
			ft_putstr_fd("Error\n", 2);
		else
			ft_putstr_fd(reason, 2);
		exit(2);
	}
}
