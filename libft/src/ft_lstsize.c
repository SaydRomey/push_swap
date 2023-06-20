/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:22 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 20:49:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	int		size;

	head = (t_list*)malloc(sizeof(t_list));
	second = (t_list*)malloc(sizeof(t_list));
	third = (t_list*)malloc(sizeof(t_list));
	head->content = "Node 1";
	head->next = second;
	second->content = "Node 2";
	second->next = third;
	third->content = "Node 3";
	third->next = NULL;
	size = ft_lstsize(head);
	printf("\nThe size of the linked list is : %d\n", size);
	free(head);
	free(second);
	free(third);
	return (0);
}
*/