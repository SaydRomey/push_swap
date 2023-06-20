/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:12:05 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:21:29 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Compares byte string s1 against byte string s2. Both strings are assumed
** to be n bytes long.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((int)(*str1 - *str2));
}

/*
int	main(void)
{
	char	str1[] = "hello T there";
	char	str2[] = "hello * there";
	int		result1;
	int		result2;
	int		result3;

	result1 = ft_memcmp(str1, str2, 6);
	result2 = ft_memcmp(str1, str2, 11);
	result3 = ft_memcmp(str2, str1, 11);
	printf("\nResult 1 (should be zero): %d\n", result1);
	printf("\nResult 1 (should be positive): %d\n", result2);
	printf("\nResult 1 (should be negative): %d\n", result3);
	return (0);
}
*/

/*
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	while ((i < n) && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i += 1;
	if (i == n)
		return (0);
	else
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
*/