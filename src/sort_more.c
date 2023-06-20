/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:15:33 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/16 20:21:08 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	loop_counter;
	int	digit_divider;
	int	i;
	int	size;
	int	value;

	stack_to_simplified_binary(a);
	loop_counter = ft_intlen(max_value(a));
	digit_divider = 1;
	while (loop_counter--)
	{
		i = 0;
		size = stack_size(a);
		while (i++ < size)
		{
			value = value_at_index(a, 0);
			if ((value / digit_divider) % 2 == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (stack_is_empty(b) == FALSE)
			pa(a, b);
		digit_divider *= 10;
	}
}
