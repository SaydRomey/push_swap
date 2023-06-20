/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:46:10 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/17 14:53:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	length;

	length = 0;
	if (!str)
	{
		length = write (fd, "(null)", 6);
		return (length);
	}
	length = write(fd, str, ft_strlen(str));
	return (length);
}

// void	ft_putstr_fd(const char *str, int fd)
// {
// 	if (!str || !fd)
// 		return ;
// 	while (*str)
// 		write(fd, str++, sizeof(char));
// }

/*
#include "ft_strlen.c"

int	main(void)
{
	char	*string = "Hello there !";

	ft_putstr_fd(string, 1);
	return (0);
}
*/