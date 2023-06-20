/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:01:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 18:20:21 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	index_of(t_stack *stack, int value)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (ERROR);
}

int	value_at_index(t_stack *stack, int index)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (i == index)
			return (*(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (ERROR);
}
