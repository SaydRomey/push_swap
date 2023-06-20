/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:42:54 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 17:07:19 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
converts stack's (positive) values to binary
(values must be ranked before conversion)
*/
int	*convert_to_binary(t_stack *stack)
{
	int	*array;
	int	*binary;
	int	i;
	int	value;
	int	base;

	array = stack_to_array(stack);
	binary = malloc(sizeof(int) * stack_size(stack));
	i = 0;
	while (i < stack_size(stack))
	{
		value = array[i];
		binary[i] = 0;
		base = 1;
		while (value > 0)
		{
			binary[i] += (value % 2) * base;
			value /= 2;
			base *= 10;
		}
		i++;
	}
	free(array);
	return (binary);
}
