/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:31:19 by trimize           #+#    #+#             */
/*   Updated: 2024/03/22 14:16:47 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*utils(int argc, char **argv, t_stack *stack, t_stack *stack2)
{
	char	*buff;

	buff = (char *)malloc(2 * sizeof(char));
	buff[0] = 0;
	buff[1] = 0;
	stack->index = 1;
	while (argv[stack->index])
	{
		if (argv[stack->index][0] == 0)
			return (free(buff), ft_putstrerror("Error\n"), exit(0), NULL);
		stack->index++;
	}
	stack->index = 0;
	init(argc, argv, stack, stack2);
	if (argc == 1)
		return (0);
	return (buff);
}
