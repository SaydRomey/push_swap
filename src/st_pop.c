/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:48:18 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 16:58:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Removes the top node of the stack and returns its content
*/
void	*pop(t_stack *stack)
{
	t_list	*tmp;
	void	*content;

	if (stack->top == NULL)
		return (NULL);
	tmp = stack->top;
	stack->top = stack->top->next;
	content = tmp->content;
	free(tmp);
	return (content);
}
