/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stack_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:33 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 16:46:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
assumes array size is equal to stack size
*/
void	replace_stack_values(t_stack *stack, int *array)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		*(int *)tmp->content = array[i];
		tmp = tmp->next;
		i++;
	}
}
