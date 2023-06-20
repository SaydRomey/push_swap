/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:36:17 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/25 18:05:13 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Appends the NULL-terminated string src to the end of dst.
** It will append at most size - strlen(dst) - 1 bytes, NULL-terminating
** the result.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/*
void	test(int i)
{
	char	dst[20] = "Hello";
	char	src[] = " there !";
	size_t	size = i;
	size_t	len;

	len = ft_strlen(dst);
	printf("\nSrc : %s\nDst : %s\n", src, dst);
	printf("'Dst' length : %zu\n", len);
	len = ft_strlcat(dst, src, size);
	printf("\nWith ft_strlcat set at : %zu\n", size);
	printf("\nSrc : %s\nDst : %s\n",src, dst);
	printf("'Dst' length becomes : %zu\n", len);
}
#include "ft_strlen.c"

int	main(void)
{
	test(12);
	return (0);
}
*/

//version pisscine a comparer

// size_t	ft_strlcat(char *dest, char *src, size_t size)
// {
// 	char	*d;
// 	char	*s;
// 	int		n;
// 	int		dlen;

// 	d = dest;
// 	s = src;
// 	n = size;
// 	while (n-- != '\0' && *d != '\0')
// 		d++;
// 	dlen = d - dest;
// 	n = size - dlen;
// 	if (n == 0)
// 		return (dlen + s);
// 	while (*s != '\0')
// 	{
// 		if (n != 1)
// 		{
// 			*d++ = *s;
// 			n--;
// 		}
// 		s++;
// 	}
// 	*d = '\0';
// 	return (dlen + (s - src));
// }

/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dst[len] = src[len - i];
		len += 1;
	}
	if (i < size)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
*/