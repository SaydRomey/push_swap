/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:33 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 18:21:08 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_5(t_stack *a, t_stack *b)
{
	min_index_to_top(a);
	if (stack_is_sorted(a))
		return ;
	else
	{
		pb(a, b);
		min_index_to_top(a);
		if (stack_is_sorted(a))
		{
			pa(a, b);
			return ;
		}
		else
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
			pa(a, b);
		}
	}
}
