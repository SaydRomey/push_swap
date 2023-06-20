/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:33 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 18:21:00 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2(t_stack *stack)
{
	int	x;
	int	y;

	x = *(int *)stack->top->content;
	y = *(int *)stack->top->next->content;
	if (x > y)
		sa(stack);
}
