/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:49:44 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 16:55:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/// @brief Adds a new node to the top of the stack with the given content.
/// @param stack The stack to 'push' to.
/// @param content The content of the new node.
void	push(t_stack *stack, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_front(&stack->top, new);
}

/*
pa (push a): Take the first element at the top of 'b'
and put it at the top of 'a'
Does nothing if 'b' is empty
Also prints "pa" on the standard output
*/
void	pa(t_stack *a, t_stack *b)
{
	if (stack_size(b) > 0)
		push(a, pop(b));
	ft_printf("pa\n");
}

/*
pb (push b): Take the first element at the top of 'a'
and put it at the top of 'b'
Does nothing if 'a' is empty
Also prints "pb" on the standard output
*/
void	pb(t_stack *a, t_stack *b)
{
	if (stack_size(a) > 0)
		push(b, pop(a));
	ft_printf("pb\n");
}

/// @brief Adds a new node to the end of the stack with the given content.
/// @param stack The stack to push to.
/// @param content The content of the new node.
void	push_back(t_stack *stack, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_back(&stack->top, new);
}
