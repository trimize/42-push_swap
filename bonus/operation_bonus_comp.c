/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus_comp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:55:35 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/16 14:48:56 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->stack[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}

void	rb(t_stack *stack2)
{
	int	tmp;
	int	i;

	tmp = stack2->stack[0];
	i = 0;
	while (i < stack2->len - 1)
	{
		stack2->stack[i] = stack2->stack[i + 1];
		i++;
	}
	stack2->stack[i] = tmp;
}

void	rr(t_stack *stack, t_stack *stack2)
{
	ra(stack);
	rb(stack2);
}
