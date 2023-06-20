/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:03:58 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/14 20:04:07 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Returns the largest integer value in the stack
*/
int	max_value(t_stack *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack->top;
	max = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}
