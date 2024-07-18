/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:14:41 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/16 14:47:59 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->len > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	sb(t_stack *stack2)
{
	int	tmp;

	if (stack2->len > 1)
	{
		tmp = stack2->stack[0];
		stack2->stack[0] = stack2->stack[1];
		stack2->stack[1] = tmp;
	}
}

void	ss(t_stack *stack, t_stack *stack2)
{
	sa(stack);
	sb(stack2);
}

void	pa(t_stack *stack, t_stack *stack2)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = -1;
	if (stack2->len != 0)
	{
		tmp2 = stack2->stack[0];
		while (++i < stack2->len)
			stack2->stack[i] = stack2->stack[i + 1];
		i = 1;
		stack->len++;
		stack2->len--;
		tmp = stack->stack[0];
		stack->stack[0] = tmp2;
		while (i < stack->len)
		{
			tmp2 = stack->stack[i];
			stack->stack[i++] = tmp;
			tmp = tmp2;
		}
	}
}

void	pb(t_stack *stack, t_stack *stack2)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (stack->len != 0)
	{
		i = -1;
		tmp2 = stack->stack[0];
		while (++i < stack->len)
			stack->stack[i] = stack->stack[i + 1];
		i = 1;
		stack2->len++;
		tmp = stack2->stack[0];
		stack2->stack[0] = tmp2;
		stack->len--;
		while (i < stack2->len)
		{
			tmp2 = stack2->stack[i];
			stack2->stack[i++] = tmp;
			tmp = tmp2;
		}
	}
}
