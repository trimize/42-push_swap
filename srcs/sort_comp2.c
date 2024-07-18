/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comp2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:40:46 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 15:59:27 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_nb_op_comp5(t_use *use)
{
	use->use_nb_op += use->use_i;
}

int	check_nb_op(t_stack *stack, t_stack *stack2, int i, t_use *use)
{
	use->use_y = 0;
	use->use_nb_op = 0;
	use->use_i = i;
	use->use_indice = 0;
	use->use_max2 = check_nb_op_comp4(stack, stack2, use, -2147483648);
	if (use->use_max2 == -2147483648)
		use->use_indice = check_max(stack2);
	use->use_y = 0;
	if (use->use_i + 1 > (stack->len / 2) + check_impair(stack))
		use->use_nb_op += stack->len - use->use_i;
	else if (i + 1 <= (stack->len / 2) + check_impair(stack))
		use->use_nb_op += use->use_i;
	if (use->use_indice + 1 > (stack2->len / 2) + check_impair(stack2))
		check_nb_op_comp3(stack, stack2, use);
	else if (use->use_indice + 1 <= (stack2->len / 2) + check_impair(stack2))
		check_nb_op_comp2(use, stack);
	return (use->use_nb_op++, use->use_nb_op);
}

void	push_to_b_comp2(t_stack *stack, t_stack *stack2, t_use *use, int i)
{
	use->use_currmx = stack2->len - use->use_indice;
	use->use_max = stack->len - i;
	while (use->use_max > 0)
	{
		if (use->use_max > 0 && use->use_currmx > 0)
			rrr(stack, stack2);
		else if (use->use_max > 0 && use->use_currmx == 0)
			rra(stack);
		if (use->use_currmx > 0)
			use->use_currmx--;
		use->use_max--;
	}
}

void	push_to_b_comp(t_stack *stack, t_stack *stack2, t_use *use, int i)
{
	if (i + 1 > (stack->len / 2) + check_impair(stack)
		&& stack->len - i < stack2->len - use->use_indice)
		push_to_b_comp6(stack, stack2, use, i);
	else if (i + 1 > (stack->len / 2) + check_impair(stack)
		&& stack->len - i >= stack2->len - use->use_indice)
		push_to_b_comp2(stack, stack2, use, i);
	else
	{
		use->use_currmx = stack2->len - use->use_indice;
		while (use->use_currmx > 0)
			(rrb(stack2), use->use_currmx--);
		use->use_currmx = i;
		while (use->use_currmx > 0)
			(ra(stack), use->use_currmx--);
	}
}

void	push_to_b_comp4(t_stack *stack, t_stack *stack2, t_use *use)
{
	while (use->use_indice > 0)
	{
		if (use->use_indice > 0 && use->use_nb_op > 0)
			rr(stack, stack2);
		else if (use->use_indice > 0 && use->use_nb_op == 0)
			rb(stack2);
		if (use->use_nb_op > 0)
			use->use_nb_op--;
		use->use_indice--;
	}
}
