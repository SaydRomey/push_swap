/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:23:50 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 20:53:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		*array;
	int		i;
	t_list	*tmp;

	array = malloc(sizeof(int) * stack_size(stack));
	if (!array)
		return (NULL);
	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		array[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
