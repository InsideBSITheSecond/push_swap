/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:19:51 by llegrand          #+#    #+#             */
/*   Updated: 2023/09/26 14:19:51 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// Check for illegal characters
int	doillegalchecks(int argc, char **argv, int splitted)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		considersuicide(!(!ft_strcontsowpref(argv[i], "0123456789", '+')
			&& !ft_strcontsowpref(argv[i], "0123456789", '-')),
			"[CRIT]: some arguments contains illegal characters", splitted, argv);
		considersuicide(!(argv[i][0] == '-' && !ft_isdigit(argv[i][1])),
			"[CRIT]: yeah dude u cant give me a single - as arg", splitted, argv);
		considersuicide(!(argv[i][0] == '+' && !ft_isdigit(argv[i][1])),
			"[CRIT]: some arguments contains illegal characters", splitted, argv);
		i++;
	}
}

// parser
t_cdllist	*parse(int argc, char **argv, int splitted)
{
	t_cdllist	*stack;
	t_cdllist	*new;
	int			argiv;

	stack = NULL;
	argiv = ft_atoi(argv[1]);
	stack = ft_cdllnew((void *)(intptr_t)argiv);
	considersuicide(stack, "[CRIT]: stack allocation failed", 0);
	stack->index = -1;
	for (int i = 2; i <= argc - 1; i++)
	{
		argiv = ft_atoi(argv[i]);
		if (!ft_cdllfind(stack, (void *)(intptr_t)argiv))
		{
			new = ft_cdllnew((void *)(intptr_t)argiv);
			considersuicide(new, "[CRIT]: node allocation failed", 1, &stack);
			ft_cdlladd_back(&stack, new);
			stack->index = -1;
		}
		else
			considersuicide(NULL, "[CRIT]: duplicate argument", 1, &stack);
	}
	if (splitted)
		splitfree(argv);
	return (stack);
}

// pre-parsing (split check)
t_cdllist	*checkparse(int argc, char **argv)
{
	char		**split;
	char		*tmp;
	int			i;
	static int	splitted = 0;

	split = NULL;
	tmp = NULL;
	if (argc > 2)
	{
		doillegalchecks(argc, argv, splitted);
		return (parse(argc, argv, splitted));
	}
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		considersuicide(tmp, "[CRIT]: parsing error - join failed", 0);
		split = ft_split(tmp, ' ');
		considersuicide(split, "[CRIT]: parsing error - split failed", 1, tmp);
		free(tmp);
		while (split[i++])
		splitted = 1;
		if (i == 2)
			considersuicide(NULL, "[INFO]: you must provide more than 1 arg", 0);
		return (checkparse(i, split));
	}
	else
		exit (0);
}
