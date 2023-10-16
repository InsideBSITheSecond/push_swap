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

int	doillegalchecks(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcontsowpref(argv[i], "0123456789", '+')
			&& !ft_strcontsowpref(argv[i], "0123456789", '-'))
			suicide(NULL, NULL,
				"[CRIT]: some arguments contains illegal characters");
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			suicide(NULL, NULL,
				"[CRIT]: yeah dude u cant give me a single - as arg");
		if (argv[i][0] == '+' && !ft_isdigit(argv[i][1]))
			suicide(NULL, NULL,
				"[CRIT]: yeah dude u cant give me a single + as arg");
		i++;
	}
}

t_cdllist	*parse(int argc, char **argv, int splitted)
{
	t_cdllist	*stack;
	t_cdllist	*new;
	int			argiv;

	stack = NULL;
	argiv = ft_atoi(argv[1]);
	stack = ft_cdllnew((void *)(intptr_t)argiv);
	if (!stack)
		suicide(NULL, NULL, "[CRIT]: stack allocation failed");
	stack->index = -1;
	for (int i = 2; i <= argc - 1; i++)
	{
		argiv = ft_atoi(argv[i]);
		if (!ft_cdllfind(stack, (void *)(intptr_t)argiv))
		{
			new = ft_cdllnew((void *)(intptr_t)argiv);
			if (!new)
				suicide(&stack, NULL, "[CRIT]: node allocation failed");
			ft_cdlladd_back(&stack, new);
			stack->index = -1;
		}
		else
			suicide(&stack, NULL, "[CRIT]: duplicate argument");
	}
	if (splitted)
		suicide(NULL, NULL, "[INFO] working with split");
	return (stack);
}

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
		doillegalchecks(argc, argv);
		return (parse(argc, argv, splitted));
	}
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		considersuicide(&(t_stacks){.a = NULL, .b = NULL},
			tmp, "[CRIT]: parsing error - join failed");
		split = ft_split(tmp, ' ');
		if (!split)
			free(tmp);
		considersuicide(&(t_stacks){.a = NULL, .b = NULL},
			split, "[CRIT]: parsing error - split failed");
		free(tmp);
		while (split[i])
			i++;
		splitted = 1;
		return (checkparse(i, split));
	}
	else
		exit (0);
}
