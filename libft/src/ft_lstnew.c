/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:00:31 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/17 15:03:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief Allocates and returns a new list node.
/// @param content The content of the new node.
/// @return The new node.
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int	main(void)
{
	char	*text;
	t_list	*list;

	text = "Hello there !";
	list = ft_lstnew(text);
	if (list)
	{
		printf("\nContent of the 'list' node : %s\n", (char *)list->content);
		printf("\nNext node pointer : %p\n", (void*)list->next);
	}
	else
	{
		printf("\nFailed to create a new list node.\n");
	}
	return (0);
}
*/