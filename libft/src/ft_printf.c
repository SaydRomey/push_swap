/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:51:47 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/17 14:51:51 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	check_format(va_list args, char *str, int i)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
	else if (str[i] == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[i] == 'p')
	{
		len = ft_putstr_fd("0x", 1);
		len += ft_putnbr_base_fd(va_arg(args, unsigned long long), 1, HEX_LO);
	}
	else if (str[i] == 'd' || str[i] == 'i')
		len = ft_putnbr_fd(va_arg(args, int), 1);
	else if (str[i] == 'u')
		len = ft_putnbr_base_fd(va_arg(args, unsigned int), 1, DECIMAL);
	else if (str[i] == 'x')
		len = ft_putnbr_base_fd(va_arg(args, unsigned int), 1, HEX_LO);
	else if (str[i] == 'X')
		len = ft_putnbr_base_fd(va_arg(args, unsigned int), 1, HEX_UP);
	else if (str[i] == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = -1;
	len = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += check_format(args, (char *)str, i + 1);
			i++;
		}
		else
			len += write(1, &str[i], 1);
	}
	va_end(args);
	return (len);
}
