/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:51 by llegrand          #+#    #+#             */
/*   Updated: 2023/11/15 17:14:54 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/// @brief check if all the arguments pass the checks before actually
///	using them. stop program execution and throw error if anything fails
/// @param argc 
/// @param argv 
/// @param splttd 
void	doillegalchecks(int argc, char **argv, int splttd)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		considersuicide((void *)(intptr_t)
			!(!ft_strcontsowpref(argv[i], "0123456789", '+')
				&& !ft_strcontsowpref(argv[i], "0123456789", '-')),
			&(t_heap){.split = argv, .splitted = splttd});
		considersuicide((void *)(intptr_t)
			!(argv[i][0] == '-' && !ft_isdigit(argv[i][1])),
			&(t_heap){.split = argv, .splitted = splttd});
		considersuicide((void *)(intptr_t)
			!(argv[i][0] == '+' && !ft_isdigit(argv[i][1])),
			&(t_heap){.split = argv, .splitted = splttd});
		considersuicide((void *)(intptr_t)(ft_atoi(argv[i]) == ft_atol(argv[i])
				&& ft_strlen(argv[i]) < 12),
			&(t_heap){.split = argv, .splitted = splttd});
		i++;
	}
}

/// @brief parsing system the input and allocate the stack
/// @param argc 
/// @param argv 
/// @param splitted 
/// @return the allocated stack
t_cdllist	*parse(int argc, char **argv, int splitted)
{
	static t_cdllist		*stack = NULL;
	t_cdllist				*new;
	int						argiv;
	static int				i = 2;

	argiv = ft_atoi(argv[1]);
	stack = ft_cdllnew((void *)(intptr_t)argiv);
	considersuicide(stack, &(t_heap){.tmp = NULL});
	stack->index = -1;
	while (i <= argc - 1)
	{
		argiv = ft_atoi(argv[i++]);
		if (!ft_cdllfind(stack, (void *)(intptr_t)argiv))
		{
			new = ft_cdllnew((void *)(intptr_t)argiv);
			considersuicide(new, &(t_heap){.stack_a = &stack});
			ft_cdlladd_back(&stack, new);
			stack->index = -1;
		}
		else
			considersuicide(NULL, &(t_heap){.stack_a = &stack});
	}
	if (splitted)
		splitfree(argv);
	return (stack);
}

/// @brief checks if we should split the input or not.
/// if yes, it splits and call itself with the splitted input.
/// if no, the input is splitted already so we hand it to the parser
/// @param argc 
/// @param argv 
/// @return parsed stack
t_cdllist	*checkparse(int argc, char **argv)
{
	static char	**split = NULL;
	static char	*tmp = NULL;
	static int	i = 0;
	static int	splitted = 0;

	if (argc > 2)
	{
		doillegalchecks(argc, argv, splitted);
		return (parse(argc, argv, splitted));
	}
	else if (argc == 2 && !splitted)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		considersuicide(tmp, &(t_heap){});
		split = ft_split(tmp, ' ');
		considersuicide(split, &(t_heap){.tmp = tmp});
		free(tmp);
		while (split[++i])
			splitted = 1;
		if (i == 2)
			checkparse(argc - 1, argv);
		return (checkparse(i, split));
	}
	doillegalchecks(2, argv, 0);
	exit(0);
}
