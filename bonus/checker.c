/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:38:57 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/22 14:16:31 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	issorted(t_stack *stack, t_stack *stack2)
{
	int	i;
	int	y;

	i = 0;
	y = i + 1;
	while (i < stack->len)
	{
		while (y < stack->len)
		{
			if (stack->stack[y] < stack->stack[i])
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	if (stack2->len != 0)
		return (0);
	return (1);
}

int	sort_bonus_comp(t_stack *stack, t_stack *stack2, char *str, int i)
{
	if (str[i] == 'r' && str[i + 1] == 'a' && str[i + 2] == 10)
		(ra(stack), i += 2);
	else if (str[i] == 'r' && str[i + 1] == 'b' && str[i + 2] == 10)
		(rb(stack2), i += 2);
	else if (str[i] == 'r' && str[i + 1] == 'r' && str[i + 2] == 10)
		(rr(stack, stack2), i += 2);
	else if (str[i] == 'r' && str[i + 1] == 'r'
		&& str[i + 2] == 'a' && str[i + 3] == 10)
		(rra(stack), i += 3);
	else if (str[i] == 'r' && str[i + 1] == 'r'
		&& str[i + 2] == 'b' && str[i + 3] == 10)
		(rrb(stack2), i += 3);
	else if (str[i] == 'r' && str[i + 1] == 'r'
		&& str[i + 2] == 'r' && str[i + 3] == 10)
		(rrr(stack, stack2), i += 3);
	else
	{
		free_stacks(stack, stack2);
		free(str);
		ft_printf("Error\n");
		exit(-1);
	}
	return (i);
}

void	sort_bonus(t_stack *stack, t_stack *stack2, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == 's' && str[i + 1] == 'a' && str[i + 2] == 10)
			(sa(stack), i += 2);
		else if (str[i] == 's' && str[i + 1] == 'b' && str[i + 2] == 10)
			(sb(stack2), i += 2);
		else if (str[i] == 's' && str[i + 1] == 's' && str[i + 2] == 10)
			(ss(stack, stack2), i += 2);
		else if (str[i] == 'p' && str[i + 1] == 'a' && str[i + 2] == 10)
			(pa(stack, stack2), i += 2);
		else if (str[i] == 'p' && str[i + 1] == 'b' && str[i + 2] == 10)
			(pb(stack, stack2), i += 2);
		else
			i = sort_bonus_comp(stack, stack2, str, i);
		i++;
	}
}

void	free_stacks(t_stack *stack, t_stack *stack2)
{
	free(stack->stack);
	free(stack2->stack);
}

int	main(int argc, char **argv)
{
	int				first;
	char			*buff;
	char			*str;
	t_stack			stack;
	t_stack			stack2;

	buff = utils(argc, argv, &stack, &stack2);
	first = 1;
	while (read(0, buff, 1) > 0)
	{
		(str = ft_strjoin(str, buff, first));
		first = 0;
	}
	if (buff[0] == '\0' && issorted(&stack, &stack2) == 1)
		return (free_stacks(&stack, &stack2), free(buff), ft_printf("OK\n"), 0);
	else if (buff[0] == '\0' && issorted(&stack, &stack2) == 0)
		return (free_stacks(&stack, &stack2), free(buff), ft_printf("KO\n"), 0);
	str[ft_strlen(str)] = 0;
	(free(buff), sort_bonus(&stack, &stack2, str));
	free(str);
	if (issorted(&stack, &stack2) == 1)
		return (free_stacks(&stack, &stack2), ft_printf("OK\n"), 0);
	return (free_stacks(&stack, &stack2), ft_printf("KO\n"), 0);
}
