/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:33:06 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/17 14:50:37 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
Writes len bytes of value c
(converted to an unsigned char) to the string s.
*/
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}

/*
int	main(void)
{
	char	str[50];

	strcpy(str, "Hello there");
	printf("\nWith memset : %s\n", memset(str, '#', 5));
	printf("\nWith ft_memset : %s\n", ft_memset(str, '#', 5));
	return (0);
}
*/

/*
void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char		*p;
	unsigned long long	*q;
	unsigned char		value;
	unsigned long long	lvalue;
	size_t				i;

	p = dest;
	value = (unsigned char)c;
	lvalue = 0;
	// Set 8 bytes at a time
	q = (unsigned long long *)dest;
	lvalue |= value;
	lvalue |= lvalue << 8;
	lvalue |= lvalue << 16;
	lvalue |= lvalue << 32;
	while (len >= sizeof(unsigned long long))
	{
		*q++ = lvalue;
		len -= sizeof(unsigned long long);
	}
	// Set remaining bytes
	p = (unsigned char *)q;
	i = 0;
	while (i < len)
	{
		*p = value;
		p++;
		i++;
	}
	return (dest);
}

*/