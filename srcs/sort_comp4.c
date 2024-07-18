/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comp4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:29 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 16:02:25 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b_comp9(t_stack *stack, t_stack *stack2, int i, t_use *use)
{
	while (use->use_y < stack2->len)
	{
		if (stack->stack[i] > stack2->stack[use->use_y]
			&& stack2->stack[use->use_y] > use->use_max)
		{
			use->use_max = stack2->stack[use->use_y];
			use->use_indice = use->use_y;
		}
		use->use_y++;
	}
}

void	push_to_b(t_stack *stack, t_stack *stack2, int i, t_use *use)
{
	use->use_y = 0;
	use->use_max = -2147483648;
	use->use_nb_op = 0;
	push_to_b_comp9(stack, stack2, i, use);
	use->use_y = 0;
	if (use->use_max == -2147483648)
		use->use_indice = check_max(stack2);
	if (i + 1 > (stack->len / 2) + check_impair(stack))
		use->use_nb_op += stack->len - i;
	else if (i + 1 <= (stack->len / 2) + check_impair(stack))
	{
		use->use_nb_op += i;
		use->use_y = stack->len - i;
	}
	if (use->use_indice + 1 > (stack2->len / 2) + check_impair(stack2))
		push_to_b_comp(stack, stack2, use, i);
	else if (use->use_indice + 1 <= (stack2->len / 2) + check_impair(stack2))
		push_to_b_comp3(stack, stack2, use, i);
	pb(stack, stack2);
}

void	push_to_a_comp2(t_stack *stack, t_stack *stack2, t_use *use)
{
	if (use->use_max == 2147483647 && use->use_currmx != 70)
		use->use_indice = check_min(stack);
	if (use->use_indice + 1 <= (stack->len / 2) + check_impair(stack))
	{
		while (use->use_indice > 0)
			(ra(stack), use->use_indice--);
		pa(stack, stack2);
	}
	else if (use->use_indice + 1 > (stack->len / 2) + check_impair(stack))
	{
		use->use_max = stack->len - use->use_indice;
		while (use->use_max > 0)
			(rra(stack), use->use_max--);
		pa(stack, stack2);
	}
	use->use_max = 2147483647;
}

void	push_to_a_comp(t_stack *stack, t_stack *stack2, t_use *use, int i)
{
	while (i < stack->len)
	{
		if (stack2->stack[0] < stack->stack[i]
			&& stack->stack[i] <= use->use_max)
		{
			use->use_currmx = 70;
			use->use_max = stack->stack[i];
			use->use_indice = i;
		}
		i++;
	}
	push_to_a_comp2(stack, stack2, use);
	use->use_currmx = 0;
}

void	push_to_a_comp3(t_stack *stack, t_use *use)
{
	if (use->use_indice != 0)
	{
		if (use->use_indice + 1 >= (stack->len / 2) + check_impair(stack))
		{
			use->use_max = stack->len - use->use_indice;
			while (use->use_max > 0)
				(rra(stack), use->use_max--);
		}
		else if (use->use_indice + 1 < (stack->len / 2) + check_impair(stack))
		{
			while (use->use_indice > 0)
				(ra(stack), use->use_indice--);
		}
	}
}
