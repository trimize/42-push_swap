/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_comp2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:13:02 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/07 18:48:10 by trimize          ###   ########.fr       */
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

void	rra_no_p(t_stack *stack)
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

void	rrb_no_p(t_stack *stack2)
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
	rra_no_p(stack);
	rrb_no_p(stack2);
	ft_printf("rrr\n");
}
