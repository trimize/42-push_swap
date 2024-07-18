/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:33:20 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/29 16:10:45 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_args(char *argv)
{
	int		i;
	int		count;
	double	nb;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-')
			return (-1);
		nb = ft_atof(&argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (-1);
		if (argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]) || count++ == -1)
			return (-1);
		while (ft_isdigit(argv[i]))
			i++;
		if ((argv[i] == ' ') && (argv[i + 1] != 0))
			i++;
		else if (!ft_isdigit(argv[i]) && argv[i] != 0)
			return (-1);
	}
	return (count);
}

int	count_all_args(int argc, char **argv)
{
	int	count;
	int	tmp;
	int	y;

	y = argc;
	count = 0;
	while (y > 1)
	{
		if (argv[y - 1][0] == 0)
			return (-1);
		tmp = count_args(argv[y - 1]);
		if (tmp == -1)
			return (-1);
		count += tmp;
		y--;
	}
	return (count);
}

void	put_arg(char *argv, t_stack *stack)
{
	int		i;
	double	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atof(&argv[i]);
		stack->stack[stack->index++] = (int)nb;
		if (argv[i] == '-')
			i++;
		while (ft_isdigit(argv[i]))
			i++;
		if ((argv[i] == ' ') && (argv[i + 1] != 0))
			i++;
	}
}

int	put_all_args(int argc, char **argv, t_stack *stack, int count)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 1;
	x = 1;
	while (x < argc)
		put_arg(argv[x++], stack);
	while (i < count)
	{
		while (y < count)
		{
			if (stack->stack[y] == stack->stack[i])
				return (free(stack->stack), ft_putstrerror("Error\n"), -1);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (0);
}

void	init(int argc, char **argv, t_stack *stack, t_stack *stack2)
{
	int	count;

	if (argc == 1)
		(exit(0));
	if (argv[1][0] == '\0')
		(ft_putstrerror("Error\n"), exit(-1));
	count = count_all_args(argc, argv);
	if (count == -1)
		(ft_putstrerror("Error\n"), exit(-1));
	stack->stack = (int *)malloc((count * sizeof(int)) + 1);
	if (!stack->stack)
		(ft_putstrerror("Malloc Error\n"), exit(-1));
	stack->index = 0;
	stack2->stack = (int *)ft_calloc(count + 1, sizeof(int));
	if (!stack2->stack)
		(ft_putstrerror("Malloc Error\n"), free(stack->stack), exit(-1));
	stack2->len = 0;
	if (put_all_args(argc, argv, stack, count) == -1)
		(free(stack2->stack), exit(-1));
	stack->len = count;
}
