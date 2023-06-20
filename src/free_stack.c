/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:01:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:39:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Frees all nodes of a stack
Frees the stack itself
Sets the stack pointer to NULL
*/
void	free_stack(t_stack *stack)
{
	t_list	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp->content);
		free(tmp);
	}
	free(stack);
}
