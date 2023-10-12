/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/12 17:47:19 by llegrand          #+#    #+#             */
/*   Updated: 2023/10/12 17:47:19 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_for(int *i, int cond)
{
	if (cond)
		return (1);
	else
		return (0);
}

int	main(void)
{
	static int	i = 0;

	while (ft_for(&i, i <= 5))
	{
		printf("%i\n", i++);
	}
	printf("\n======\n\n");
	for (int j = 0; j <= 5;)
	{
		printf("%i\n", j++);
	}

}
