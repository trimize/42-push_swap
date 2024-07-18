/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comp3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:52:34 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 15:59:32 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b_comp3(t_stack *stack, t_stack *stack2, t_use *use, int i)
{
	if (i + 1 <= (stack->len / 2) + check_impair(stack) && i <= use->use_indice)
		push_to_b_comp4(stack, stack2, use);
	else if (i + 1 <= (stack->len / 2) + check_impair(stack)
		&& i > use->use_indice)
	{
		while (use->use_nb_op > 0)
		{
			if (use->use_nb_op > 0 && use->use_indice > 0)
				rr(stack, stack2);
			else if (use->use_nb_op > 0 && use->use_indice == 0)
				ra(stack);
			if (use->use_indice > 0)
				use->use_indice--;
			use->use_nb_op--;
		}
	}
	else
	{
		while (use->use_indice > 0)
			(rb(stack2), use->use_indice--);
		while (use->use_nb_op > 0)
			(rra(stack), use->use_nb_op--);
	}
}

int	check_max(t_stack *stack)
{
	int	i;
	int	max;
	int	indice;

	i = 0;
	max = -2147483648;
	while (i < stack->len)
	{
		if (stack->stack[i] > max)
		{
			max = stack->stack[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}

int	check_min(t_stack *stack)
{
	int	i;
	int	max;
	int	indice;

	i = 0;
	max = 2147483647;
	while (i < stack->len)
	{
		if (stack->stack[i] < max)
		{
			max = stack->stack[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}

int	check_impair(t_stack *stack)
{
	if (stack->len % 2 == 0)
		return (stack->impair = 0, stack->impair);
	else
		return (stack->impair = 1, stack->impair);
}

void	push_to_b_comp6(t_stack *stack, t_stack *stack2, t_use *use, int i)
{
	use->use_currmx = stack2->len - use->use_indice;
	use->use_max = stack->len - i;
	while (use->use_currmx > 0)
	{
		if (use->use_currmx > 0 && use->use_max > 0)
			rrr(stack, stack2);
		else if (use->use_currmx > 0 && use->use_max == 0)
			rrb(stack2);
		if (use->use_max > 0)
			use->use_max--;
		use->use_currmx--;
	}
}
