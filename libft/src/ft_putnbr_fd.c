/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:06:02 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/12 16:18:25 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief Outputs the integer ’n’ to the given file descriptor.
/// @param n integer to output
/// @param fd file descriptor on which to write
/// @return number of bytes written
size_t	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
	return (ft_intlen(n));
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 	{
// 		ft_putstr_fd("-2147483648", fd);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		n = -n;
// 	}
// 	if (n < 10)
// 	{
// 		c = n + '0';
// 		ft_putchar_fd(c, fd);
// 		return ;
// 	}
// 	ft_putnbr_fd(n / 10, fd);
// 	ft_putnbr_fd(n % 10, fd);
// }

/*
#include "ft_putstr_fd.c"
#include "ft_putchar_fd.c"
#include "ft_strlen.c"

int	main(void)
{
	int	n = 12345;

	ft_putnbr_fd(n, 1);
	return (0);
}
*/
