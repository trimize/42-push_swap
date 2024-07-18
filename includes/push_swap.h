/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:15:06 by teorimize         #+#    #+#             */
/*   Updated: 2024/03/22 14:16:25 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	index;
	int	len;
	int	impair;
}	t_stack;

typedef struct s_use
{
	int	use_i;
	int	use_y;
	int	use_indice;
	int	use_nb_op;
	int	use_max;
	int	use_max2;
	int	use_currmx;
	int	use_lowest;
	int	use_i2;
	int	use_indice2;
	int	use_nb_op2;
}	t_use;

int		count_all_args(int argc, char **argv);
int		check_nb_op_comp4(t_stack *stack, t_stack *stack2, t_use *use, int max);
int		check_nb_op(t_stack *stack, t_stack *stack2, int i, t_use *use);
int		check_max(t_stack *stack);
int		check_min(t_stack *stack);
int		check_impair(t_stack *stack);
int		put_all_args(int argc, char **argv, t_stack *stack, int count);
int		count_args(char *argv);
char	*utils(int argc, char **argv, t_stack *stack, t_stack *stack2);
void	init(int argc, char **argv, t_stack *stack, t_stack *stack2);
void	sa(t_stack *stack);
void	sb(t_stack *stack2);
void	ss(t_stack *stack, t_stack *stack2);
void	pa(t_stack *stack, t_stack *stack2);
void	pb(t_stack *stack, t_stack *stack2);
void	ra(t_stack *stack);
void	rb(t_stack *stack2);
void	rr(t_stack *stack, t_stack *stack2);
void	rra(t_stack *stack);
void	rrb(t_stack *stack2);
void	rrr(t_stack *stack, t_stack *stack2);
void	free_stacks(t_stack *stack, t_stack *stack2);
void	sort(t_stack *stack, t_stack *stack2, t_use *use);
void	ra_no_p(t_stack *stack);
void	rb_no_p(t_stack *stack2);
void	check_nb_op_comp2(t_use *use, t_stack *stack);
void	check_nb_op_comp3(t_stack *stack, t_stack *stack2, t_use *use);
void	switch_3(t_stack *stack);
void	check_nb_op_comp5(t_use *use);
void	push_to_b_comp2(t_stack *stack, t_stack *stack2, t_use *use, int i);
void	push_to_b_comp(t_stack *stack, t_stack *stack2, t_use *use, int i);
void	push_to_b_comp4(t_stack *stack, t_stack *stack2, t_use *use);
void	push_to_b_comp3(t_stack *stack, t_stack *stack2, t_use *use, int i);
void	push_to_b_comp9(t_stack *stack, t_stack *stack2, int i, t_use *use);
void	push_to_b(t_stack *stack, t_stack *stack2, int i, t_use *use);
void	push_to_a_comp2(t_stack *stack, t_stack *stack2, t_use *use);
void	push_to_a_comp(t_stack *stack, t_stack *stack2, t_use *use, int i);
void	push_to_a_comp3(t_stack *stack, t_use *use);
void	push_to_b_comp6(t_stack *stack, t_stack *stack2, t_use *use, int i);
void	put_arg(char *argv, t_stack *stack);
void	ft_putstrerror(char *s);

#endif