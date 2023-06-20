/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:48:41 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 20:50:16 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Counts the number of nodes in the stack.
*/
int	stack_size(t_stack *stack)
{
	return (ft_lstsize(stack->top));
}
