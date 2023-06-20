/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:48:09 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 17:10:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	else if (stack_size(a) == 2)
		sort_2(a);
	else if (stack_size(a) == 3)
		sort_3(a);
	else if (stack_size(a) == 4)
		sort_4(a, b);
	else if (stack_size(a) == 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}
