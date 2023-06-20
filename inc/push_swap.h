/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:43:26 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/16 19:30:44 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct s_stack
{
	t_list	*top;
}			t_stack;

int		main(int argc, char **argv);
//
void	parse_args(int argc, char **argv);
void	parse_quoted_args(char *argv);
//
t_stack	*new_stack(void);
//
void	push_swap(t_stack *a, t_stack *b);
//
void	push_back(t_stack *stack, void *content);
void	push(t_stack *stack, void *content);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
//
void	*pop(t_stack *stack);
//
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
//
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
//
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
//
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	min_index_to_top(t_stack *stack);
//
void	radix_sort(t_stack *a, t_stack *b);
//
int		stack_size(t_stack *stack);
int		stack_is_empty(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
//
int		index_of(t_stack *stack, int value);
int		value_at_index(t_stack *stack, int index);
int		max_value(t_stack *stack);
int		min_value(t_stack *stack);
//
void	replace_stack_values(t_stack *stack, int *array);
void	stack_to_simplified_binary(t_stack *stack);
//
int		*stack_to_array(t_stack *stack);
int		*rank_stack_values(t_stack *stack);
int		*convert_to_binary(t_stack *stack);
//
void	free_stack(t_stack *stack);
void	free_split(char **split);
void	exit_error(char *msg);
//
#endif
