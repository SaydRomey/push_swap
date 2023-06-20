/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:49:42 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:50:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_4(t_stack *a, t_stack *b)
{
	min_index_to_top(a);
	if (stack_is_sorted(a))
		return ;
	else
	{
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}
