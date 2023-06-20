/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:16:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/26 13:15:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
static int	ft_int_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
*/

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		int_length;

	num = (long)n;
	int_length = ft_intlen(n);
	str = (char *)malloc(int_length + 1);
	if (!str)
		return (NULL);
	if (num < 0)
		num = -num;
	str[int_length] = '\0';
	while (int_length--)
	{
		str[int_length] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
#include "ft_strdup.c"
#include "ft_strlen.c"
#include "ft_memcpy.c"

int	main(void)
{
	int		num = 12345;
	char	*str = ft_itoa(num);

	if (str == NULL)
	{
		printf("\nMemory allocation failed\n");
		return(1);
	}
	printf("\n%d as a string : %s\n", num, str);
	free(str);
	return (0);
}
*/
