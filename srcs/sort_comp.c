/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:56:58 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 15:59:19 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	switch_3(t_stack *stack)
{
	if (stack->stack[0] > stack->stack[1] && stack->stack[1] > stack->stack[2]
		&& stack->stack[0] > stack->stack[2])
		(ra(stack), sa(stack));
	else if (stack->stack[1] > stack->stack[0]
		&& stack->stack[1] > stack->stack[2]
		&& stack->stack[0] > stack->stack[2])
		rra(stack);
	else if (stack->stack[1] > stack->stack[0]
		&& stack->stack[1] > stack->stack[2]
		&& stack->stack[2] > stack->stack[0])
		(rra(stack), sa(stack));
	else if (stack->stack[1] < stack->stack[2]
		&& stack->stack[1] < stack->stack[0])
	{
		if (stack->stack[0] > stack->stack[2])
			ra(stack);
		else
			sa(stack);
	}
	else if (stack->stack[2] < stack->stack[1]
		&& stack->stack[2] < stack->stack[0])
		rra(stack);
}

void	check_nb_op_comp2(t_use *use, t_stack *stack)
{
	use->use_y = use->use_indice;
	if (use->use_i + 1 > (stack->len / 2) + check_impair(stack))
		use->use_nb_op += use->use_y;
	else if (use->use_i + 1 <= (stack->len / 2) + check_impair(stack)
		&& use->use_nb_op <= use->use_y)
		use->use_nb_op = use->use_y;
	else if (use->use_i + 1 <= (stack->len / 2) + check_impair(stack)
		&& use->use_nb_op > use->use_y
		&& use->use_y != 0)
		use->use_nb_op = use->use_nb_op;
}

void	check_nb_op_comp3(t_stack *stack, t_stack *stack2, t_use *use)
{
	use->use_y = stack2->len - use->use_indice;
	if (use->use_i + 1 > (stack->len / 2) + check_impair(stack)
		&& use->use_nb_op <= use->use_y)
		use->use_nb_op = use->use_y;
	else if (use->use_i + 1 > (stack->len / 2) + check_impair(stack)
		&& use->use_nb_op > use->use_y)
		use->use_nb_op = use->use_nb_op;
	else if (use->use_i + 1 <= (stack->len / 2) + check_impair(stack))
		use->use_nb_op += use->use_y;
}

int	check_nb_op_comp4(t_stack *stack, t_stack *stack2, t_use *use, int max)
{
	while (use->use_y < stack2->len)
	{
		if (stack->stack[use->use_i] > stack2->stack[use->use_y]
			&& stack2->stack[use->use_y] > max)
		{
			max = stack2->stack[use->use_y];
			use->use_indice = use->use_y;
		}
		use->use_y++;
	}
	return (max);
}
