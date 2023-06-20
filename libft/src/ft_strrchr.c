/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:47:50 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 21:25:47 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s.  The terminating null character is considered to be part
** of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	while (s >= str)
		if (*s-- == (char)c)
			return ((char *)s + 1);
	return (NULL);
}

/*
#include "ft_strchr.c"

int	main(void)
{
	char	str[] = "Hello there !";
	char	*result1 = ft_strrchr(str, 'e');
	char	*esult1 = ft_strchr(str, 'e');
	char	*result2 = ft_strrchr(str, 'z');

	printf("\nStr : %s\n", str);
	printf("\nResult 1 (should be 'e') : %c\n", *result1);
	printf("\nft_strrchr finds at %p\n", result1);
	printf("ft_strchr  finds at %p\n", esult1);
	printf("\nResult 2 (should be null) : %p\n", result2);
	return (0);
}
*/
/*
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	while (i >= j)
		if (s[i - j++] == c)
			return ((char *)&s[i - (j - 1)]);
	return (NULL);
}
*/
/*
char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) + 1;
	while (--i >= 0)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
*/
/*
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
*/