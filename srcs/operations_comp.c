/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_comp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teorimize <teorimize@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:12:13 by teorimize         #+#    #+#             */
/*   Updated: 2023/12/27 06:12:30 by teorimize        ###   ########.fr       */
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	ra_no_p(t_stack *stack)
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

void	rb_no_p(t_stack *stack2)
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
	ra_no_p(stack);
	rb_no_p(stack2);
	ft_printf("rr\n");
}
