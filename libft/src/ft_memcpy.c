/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:25:46 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 17:14:13 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n--)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}

// int main(void)
// {
// 	char dest[20] = "abcdefghij";
// 	// char src[] = "Mickey";
// 	int len = 6;
// 	// int len = strlen(src);
// 	ft_memcpy(dest + 4, dest + 2, len);
// 	printf("\nResult: %s\n", dest);
// 	return (0);
// }

/*
int	main(void)
{
	char	dst[100];
	char	src[100];
	size_t	n;

	n = 5;
	strcpy(src, "1234567890");
	strcpy(dst, " ");
	printf("\nParameters;\n");
	printf("\tDst : %s\n\tSrc : %s\n", dst, src);
	printf("\tn : %lu\n", n);
	printf("\nft_memcpy;\n\tDst : %s\n\tSrc : %s\n",dst, ft_memcpy(dst, src, n));
	printf("\nmemcpy;\n\tDst : %s\n\tSrc : %s\n",dst, memcpy(dst, src, n));
	return (0);
}
*/

/*
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;

	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
*/
/*
void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	int  i;
	
	s = src;
	d = dest;
	i = 0;
	// if (!dest || !src)
	// 	return (dest);
	// if (dest == src)
		// return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
*/
/*
int main(void)
{
	char dest[20] = "pamplemousse";
	char src[] = "Mickey";
	int len = 6;
	// int len = strlen(src);
	
	ft_memcpy(dest, src, len);
	printf("\nResult: %s\n", dest);
	return (0);
}
*/