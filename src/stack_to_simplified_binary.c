/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_simplified_binary.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:42:05 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/16 17:49:53 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Converts stack values to simplified positive value
(their rank) then converts the ranks to binary
*/
void	stack_to_simplified_binary(t_stack *stack)
{
	int	*ranked;
	int	*binary;

	ranked = rank_stack_values(stack);
	replace_stack_values(stack, ranked);
	free(ranked);
	binary = convert_to_binary(stack);
	replace_stack_values(stack, binary);
	free(binary);
}
