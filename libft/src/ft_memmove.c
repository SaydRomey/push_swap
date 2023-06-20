/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:25 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/25 18:05:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*lastd;
	char	*lasts;
	char	*sourc;

	dest = (char *)dst;
	sourc = (char *)src;
	if (!dest && !sourc)
		return (dst);
	if (dest < sourc)
		while (len--)
			*dest++ = *sourc++;
	else
	{
		lastd = dest + (len - 1);
		lasts = sourc + (len - 1);
		while (len--)
		{
			*lastd-- = *lasts--;
		}
	}
	return (dst);
}

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned int			i;

// 	i = 0;
// 	if (((unsigned char *)src) < ((unsigned char *)dst))
// 		while (len-- > 0)
// 			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
// 	else
// 		while (i < len)
// 		{
// 			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 			i += 1;
// 		}
// 	return (((unsigned char *)dst));
// }

/*
** Copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
*/
// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*d;
// 	char	*s;

// 	d = (char *)dst;
// 	s = (char *)src;
// 	if (!dst && !src)
// 		return (dst);
// 	if (src < dst)
// 		while (len--)
// 			d[len] = s[len];
// 	else
// 		while (len--)
// 			*d++ = *s++;
// 	return ((char *)dst);
// }

/*
#include "ft_memcpy.c"
#include "ft_strlcpy.c"
#include "ft_strlen.c"

int	main(void)
{
	char	*dst;
	char	*src;
	size_t	len;

	dst = "Hello there";
	src = "Replaced";
	len = 5;
	printf("\nBefore function\n\tsrc : %s\n\tdst : %s\n", src, dst);
	// ft_memmove(&dst, &src, len);
	memmove(&dst, &src, len);
	printf("\nAfter function\n\tsrc : %s\n\tdst : %s\n", src, dst);
	return (0);
}
*/