/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:16:44 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:21:26 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Locates the first occurrence of c (converted to an unsigned char)
** in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		if (*str++ == (unsigned char)c)
			return (str - 1);
	return (NULL);
}

/*
int	main(void)
{
	char	str[];
	char	c;
	void	*result;

    str[] = "Hello, there !";
    c = 'e';
    result = ft_memchr(str, c, strlen(str));
    if (result != NULL)
{
   		printf("\nFound char : %c\nAt index   : %ld\n", c, (char*)result - str);
    } else {
   		printf("\nCould not find %c in string.\n", c);
    }
    return (0);
}
*/
/*
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned const char *)s)[i]);
		i += 1;
	}
	return (NULL);
}
*/