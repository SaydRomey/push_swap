/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_index_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:15:33 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 17:03:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	min_4_to_top(t_stack *a)
{
	int	min_index;

	min_index = index_of(a, min_value(a));
	if (min_index == 0)
		return ;
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		sa(a);
	}
	else if (min_index == 3)
		rra(a);
}

static void	min_5_to_top(t_stack *a)
{
	int	min_index;

	min_index = index_of(a, min_value(a));
	if (min_index == 0)
		return ;
	else if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		sa(a);
	}
	else if (min_index == 3)
	{
		rra(a);
		rra(a);
	}
	if (min_index == 4)
		rra(a);
}

void	min_index_to_top(t_stack *stack)
{
	if (stack_size(stack) == 4)
		min_4_to_top(stack);
	else if (stack_size(stack) == 5)
		min_5_to_top(stack);
	return ;
}
