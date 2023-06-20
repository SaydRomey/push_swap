/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:44:20 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 21:24:27 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates the first occurrence of c (converted to a char) in the string
** pointed to by s.  The terminating null character is considered to be part
** of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
*/

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s != '\0')
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }

/*
int	main(void)
{
	char	str[] = "Hello there !";
	char	*result1 = ft_strchr(str, 'e');
	char	*result2 = ft_strchr(str, 'z');

	printf("\nStr : %s\n", str);
	printf("\nResult 1 (should be 'e') : %c\n", *result1);
	printf("\nFound at %p\n", result1);
	printf("\nResult 2 (should be null) : %p\n", result2);
	return (0);
}
*/
/*
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
*/

/*
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}
*/
/*
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
*/