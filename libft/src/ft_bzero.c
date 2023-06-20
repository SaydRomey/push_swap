/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:22:24 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/24 18:30:58 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Overwrites the bytes of a string (*s) to zeroes bytes, depending on the
** value of the variable n. If the variable n is zero (0), then nothing
** will happen.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include "ft_memset.c"

int	main(void)
{
	char	str[50];
	size_t	len;

	strcpy(str, "Hello there");
	len = strlen(str);
	printf("\nbefore ft_bzero : %s\n", str);
	ft_bzero(str, len);
	// bzero(str, len);
	printf("\nafter ft_bzero : %s\n", str);
	return (0);
}
*/

/*
void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = 0;
}


void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
*/