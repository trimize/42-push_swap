/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus_comp2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:01:48 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/16 14:48:30 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->stack[stack->len - 1];
	i = stack->len - 1;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = tmp;
}

void	rrb(t_stack *stack2)
{
	int	tmp;
	int	i;

	tmp = stack2->stack[stack2->len - 1];
	i = stack2->len - 1;
	while (i > 0)
	{
		stack2->stack[i] = stack2->stack[i - 1];
		i--;
	}
	stack2->stack[0] = tmp;
}

void	rrr(t_stack *stack, t_stack *stack2)
{
	rra(stack);
	rrb(stack2);
}
