/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:26:41 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 18:55:10 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stack *stack, t_stack *stack2)
{
	free(stack->stack);
	free(stack2->stack);
}

int	issorted(t_stack *stack, t_stack *stack2)
{
	int	i;
	int	y;

	i = 0;
	y = i + 1;
	while (i < stack->len)
	{
		while (y < stack->len)
		{
			if (stack->stack[y] < stack->stack[i])
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	if (stack2->len != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_stack	stack2;
	t_use	use;

	use.use_i2 = 0;
	use.use_lowest = 5000000;
	use.use_indice2 = 0;
	use.use_nb_op2 = 0;
	use.use_currmx = 0;
	use.use_max = 0;
	use.use_max2 = -2147483648;
	init(argc, argv, &stack, &stack2);
	if (issorted(&stack, &stack2) == 1)
		return (free_stacks(&stack, &stack2), 0);
	sort(&stack, &stack2, &use);
	free_stacks(&stack, &stack2);
	return (0);
}
