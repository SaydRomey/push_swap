/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:02:10 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/22 13:51:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Converts the initial portion of a string pointed to the variable string, to
** an int representation (type).
*/
int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (num * sign);
}

/*
int ft_atoi(const char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
*/

int	ft_atoi_incr(char *s)
{
	int		sign;
	long	r;

	r = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (sign * (int)r);
}

/*
takes a pointer to a pointer to a string as input.
parses the string for an integer
and returns the integer value.
handles the signs of the integer 
and can handle input with leading whitespace.
*/
int	ft_atoi_parse(char **s)
{
	int	sign;
	int	r;

	r = 0;
	sign = 1;
	if (**s == '-' || **s == '+')
		sign = 44 - *(*s)++;
	while (**s >= '0' && **s <= '9')
		r = r * 10 + *(*s)++ - '0';
	return (sign * r);
}

/*
** Converts a string of characters to integer. An arbitrary amount
** of white spaces can be added at string start, followed by any
** amount of '+' or '-' signals. An even number of '-' cancels each
** other. The conversion is then made while the following chars are
** numeric, stopping at any other char identified. If no numeric char
** os identified, the function returns 0 (zero).
*/
// int	ft_atoi(const char *str)
// {
// 	int	n;
// 	int	aux;
// 	int	signal;

// 	n = 0;
// 	aux = 0;
// 	signal = -1;
// 	while (ft_isspace(*str))
// 		str++;
// 	if (*str == '+' || *str == '-')
// 		if (*str++ == '-')
// 			signal = 1;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		n = n * 10 - (*str++ - '0');
// 		if (aux < n)
// 		{
// 			if (signal < 0)
// 				return (-1);
// 			return (0);
// 		}
// 		aux = n;
// 	}
// 	return (n * signal);
// }
