/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:44:39 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 16:57:53 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Simplifies the stack values to their desired sorted index
*/
int	*rank_stack_values(t_stack *stack)
{
	int	*array;
	int	*ranked;
	int	i;
	int	j;

	array = stack_to_array(stack);
	ranked = ft_calloc(stack_size(stack), sizeof(int));
	i = 0;
	while (i < stack_size(stack))
	{
		j = 0;
		while (j < stack_size(stack))
		{
			if (array[i] > array[j])
				ranked[i]++;
			j++;
		}
		i++;
	}
	free(array);
	return (ranked);
}
