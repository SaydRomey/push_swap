/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:49:44 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:36:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Shifts down all elements of stack by 1.
Last node becomes top of the stack.
*/
void	reverse_rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (stack_size(stack) < 2)
		return ;
	first = stack->top;
	last = ft_lstlast(stack->top);
	tmp = stack->top;
	while (tmp->next != last)
		tmp = tmp->next;
	stack->top = last;
	last->next = first;
	tmp->next = NULL;
}

/*
rra (reverse rotate a): Shift down all elements of stack 'a' by 1
The last element becomes the first one
Also prints "rra" on the standard output
*/
void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

/*
rrb (reverse rotate b): Shift down all elements of stack 'b' by 1
The last element becomes the first one
Also prints "rrb" on the standard output
*/
void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

/*
rrr : 'rra' and 'rrb' at the same time
Also prints "rrr" on the standard output
*/
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
