/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:49:08 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:36:09 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/// @brief Swaps the two top nodes of the stack.
/// @param stack The stack to 'swap'.
void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack_size(stack) < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

/*
sa (swap a): Swap the fist 2 elements at the top of stack 'a'.
Do nothing it there is only 'one' or 'no' elements.
also prints "sa" on the standard output
*/
void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

/*
sb (swap b): Swap the fist 2 elements at the top of stack 'b'.
Do nothing it there is only 'one' or 'no' elements.
also prints "sb" on the standard output
*/
void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

/*
ss : 'sa' and 'sb' at the same time.
also prints "ss" on the standard output
*/
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
