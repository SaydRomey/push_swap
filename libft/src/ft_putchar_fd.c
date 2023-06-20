/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:10 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/17 14:52:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

// void    ft_putchar_fd(char c, int fd)
// {
//     write(fd, &c, 1);
// }

/*
int	main(void)
{
	char	c = 'Z';

	ft_putchar_fd(c, 1);
	return (0);
}
*/

/*
to test in terminal :
	./a.out > output.txt
	cat output.txt
*/