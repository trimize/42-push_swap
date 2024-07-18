/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:08:40 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 18:28:35 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_a(t_stack *stack, t_stack *stack2, t_use *use)
{
	int	i;

	i = 0;
	use->use_max = 2147483647;
	use->use_currmx = 0;
	while (stack2->len > 0)
		push_to_a_comp(stack, stack2, use, i);
	i = 0;
	use->use_max = 2147483647;
	while (i < stack->len)
	{
		if (stack->stack[i] <= use->use_max)
		{
			use->use_max = stack->stack[i];
			use->use_indice = i;
		}
		i++;
	}
	push_to_a_comp3(stack, use);
}

void	sort_comp3(t_use *use, t_stack *stack)
{
	if (use->use_nb_op2 == 1 && use->use_i2 == 0)
	{
		use->use_indice2 = use->use_i2;
		use->use_lowest = 1;
		use->use_i2 = stack->len - 1;
	}
	else if (use->use_nb_op2 < use->use_lowest)
	{
		use->use_lowest = use->use_nb_op2;
		use->use_indice2 = use->use_i2;
	}
}

void	sort_comp2(t_stack *stack, t_stack *stack2, t_use *use)
{
	if (stack->len > 3)
	{
		(pb(stack, stack2), pb(stack, stack2));
		while (stack->len > 3)
		{
			while (use->use_i2 < stack->len)
			{
				use->use_nb_op2 = check_nb_op(stack, stack2, use->use_i2, use);
				sort_comp3(use, stack);
				use->use_i2++;
			}
			push_to_b(stack, stack2, use->use_indice2, use);
			use->use_i2 = 0;
			use->use_lowest = 5000000;
		}
	}
}

void	sort(t_stack *stack, t_stack *stack2, t_use *use)
{
	sort_comp2(stack, stack2, use);
	if (stack->len == 3)
		switch_3(stack);
	else if (stack->len == 2)
	{
		if (stack->stack[1] < stack->stack[0])
			sa(stack);
	}
	if (stack2->len > 0)
		push_to_a(stack, stack2, use);
}
