/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:35:16 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/12 15:08:31 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief Returns the last element of the list
/// @param lst The beginning of the list
/// @return Pointer to the last element of the list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_node;

	current_node = lst;
	if (current_node)
	{
		while (current_node->next)
		{
			current_node = current_node->next;
		}
	}
	return (current_node);
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*second;
// 	t_list	*third;

// 	head = malloc(sizeof(t_list));
// 	second = malloc(sizeof(t_list));
// 	third = malloc(sizeof(t_list));
// 	head->content = "Node 1";
// 	head->next = second;
// 	second->content = "Node 2";
// 	second->next = third;
// 	third->content = "Node 3";
// 	third->next = NULL;
// 	t_list *last_node = ft_lstlast(head);
// 	printf("\nContent of the last node : %s\n", (char*)last_node->content);
// 	free(head);
// 	free(second);
// 	free(third);
// 	return (0);
// }

/*
traverse linked list until las node is found

lst : beginnig of the list

check if 'current_node' is not a null pointer

if not, enters a while loop wich continues
	until 'current_node->next' is a null pointer

for each iteration, 'current_node' is updated
	to point to the next element in the list

returns 'current_node' : pointer to the last node / element of the list
*/