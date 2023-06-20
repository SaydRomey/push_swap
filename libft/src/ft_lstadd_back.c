/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:38:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/12 15:39:26 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief Adds a new node to the end of the list.
/// @param lst The address of a pointer to the first node of a list.
/// @param new Node to add to the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
#include "ft_lstnew.c"
#include "ft_lstlast.c"

int	main(void)
{
	char	*content1;
	char	*content2;
	char	*content3;
	char	*new_content;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*new_node;
	t_list	*current;

	content1 = "Node 1";
	content2 = "Node 2";
	content3 = "Node 3";
	new_content = "New node added to the end";
	list1 = ft_lstnew(content1);
	list2 = ft_lstnew(content2);
	list3 = ft_lstnew(content3);
	list1->next = list2;
	list2->next = list3;
	new_node = ft_lstnew(new_content);
	ft_lstadd_back(&list1, new_node);
	current = list1;
	while (current)
	{
		printf("\nContent of 'current' node : %s\n", (char*)current->content);
		printf("Next node pointer : %p\n", (void*)current->next);
		current = current->next;
	}
	return (0);
}
*/
