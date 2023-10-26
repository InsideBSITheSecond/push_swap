/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:51 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/26 18:23:37 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// hmmm sussy arguments show me ur papers
void	doillegalchecks(int argc, char **argv, int splttd)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		considersuicide((void *)(intptr_t)
			!(!ft_strcontsowpref(argv[i], "0123456789", '+')
				&& !ft_strcontsowpref(argv[i], "0123456789", '-')),
			"[ERROR]: some args contains illegal characters", splttd, argv);
		considersuicide((void *)(intptr_t)
			!(argv[i][0] == '-' && !ft_isdigit(argv[i][1])),
			"[ERROR]: bro u cant give me a single - as arg", splttd, argv);
		considersuicide((void *)(intptr_t)
			!(argv[i][0] == '+' && !ft_isdigit(argv[i][1])),
			"[ERROR]: some args contains illegal characters", splttd, argv);
		considersuicide((void *)(intptr_t)(ft_atoi(argv[i]) == ft_atol(argv[i])
				&& ft_strlen(argv[i]) < 12),
			"[ERROR]: arg exceeding limit", splttd, argv);
		i++;
	}
}

// parser
t_cdllist	*parse(int argc, char **argv, int splitted)
{
	static t_cdllist		*stack = NULL;
	t_cdllist				*new;
	int						argiv;
	static int				i = 2;

	argiv = ft_atoi(argv[1]);
	stack = ft_cdllnew((void *)(intptr_t)argiv);
	considersuicide(stack, "[ERROR]: stack allocation failed", 0);
	stack->index = -1;
	while (i <= argc - 1)
	{
		argiv = ft_atoi(argv[i++]);
		if (!ft_cdllfind(stack, (void *)(intptr_t)argiv))
		{
			new = ft_cdllnew((void *)(intptr_t)argiv);
			considersuicide(new, "[ERROR]: node allocation failed", 1, &stack);
			ft_cdlladd_back(&stack, new);
			stack->index = -1;
		}
		else
			considersuicide(NULL, "[ERROR]: duplicate argument", 1, &stack);
	}
	if (splitted)
		splitfree(argv);
	return (stack);
}

// pre-parsing (split check)
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
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		considersuicide(tmp, "[ERROR]: parsing error - join failed", 0);
		split = ft_split(tmp, ' '); // sigsegv error if this is null (in strcomp)
		considersuicide(split, "[ERROR]: parsing error - split failed", 1, tmp);
		free(tmp);
		while (split[++i])
			splitted = 1;
		if (i == 2)
			considersuicide(NULL, "[INFO]: more than 1 arg needed", 0);
		return (checkparse(i, split));
	}
	else
		exit (0);
}
