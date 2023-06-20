/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:32:24 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/25 18:03:51 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Takes the destination's size as a parameter and will not write more than
** that many bytes, to prevent buffer overflow (assuming size is correct).
** Writes a single NULL byte to the destination (if size is not zero).
** The resulting string is guaranteed to be NULL-terminated even if truncated.
** Returns the length of the entire source string.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
void	test(int i)
{
	char		dst[i];
	const char	*src = "Hello there !";
	size_t		len;

	len = ft_strlcpy(dst, src, i);
	printf("\nString : %s\n", src);
	printf("\nString length : %zu\n", ft_strlen(src));
	printf("Buffer size : %d\n", i);
	if (i == 0)
		printf("\nCopied string : <empty>\n\n");
	else
		printf("\nCopied string : %s\n", dst);
}

#include "ft_strlen.c"
int	main(void)
{
	test(5);
	return (0);
}
*/

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	ft_strncpy(dst, src, size);
	dst[len] = '\0';
	return (len);
}
*/