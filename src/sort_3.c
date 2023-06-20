/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:35:04 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 19:13:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack *stack)
{
	int	x;
	int	y;
	int	z;

	x = *(int *)stack->top->content;
	y = *(int *)stack->top->next->content;
	z = *(int *)stack->top->next->next->content;
	if (x > y && y > z)
	{
		ra(stack);
		sa(stack);
	}
	else if (x > z && z > y)
		ra(stack);
	else if (y > x && x > z)
		rra(stack);
	else if (y > z && z > x)
	{
		sa(stack);
		ra(stack);
	}
	else if (z > x && x > y)
		sa(stack);
}
