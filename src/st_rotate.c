/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:49:26 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:36:19 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Shifts up all elements of stack by 1.
Top node becomes last of the stack.
*/
void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack_size(stack) < 2)
		return ;
	first = stack->top;
	last = ft_lstlast(stack->top);
	stack->top = first->next;
	last->next = first;
	first->next = NULL;
}

/*
ra (rotate a): Shift up all elements of stack 'a' by 1
The first element becomes the last one
Also prints "ra" on the standard output
*/
void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

/*
rb (rotate b): Shift up all elements of stack 'b' by 1
The first element becomes the last one
Also prints "rb" on the standard output
*/
void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

/*
rrr : 'ra' and 'rb' at the same time
also prints "rr" on the standard output
*/
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
