/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:55:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/10 15:32:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (*p1 == '\0')
			return (0);
		p1++;
		p2++;
	}
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < n && (s1[i] || s2[i]))
// 	{
// 		if (s1[i] != s2[i])
// 			// return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	while (n && *s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2)
// 	{
// 		s1++;
// 		s2++;
// 		n--;
// 	}
// 	if (n)
// 		return (*(unsigned char *)s1 - *(unsigned char *)s2);
// 	return (0);
// }

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	int		n;

	n = 7;
	s1 = "Hello There";
	s2 = "Hello *here";
	printf("\n'%s' vs '%s'\n", s1, s2);
	printf("\nwith 'n' set at : %d\n", n);
	printf("\nft_strncmp : %d\n", ft_strncmp(s1, s2, n));
	printf("strncmp		: %d\n", strncmp(s1, s2, n));
	return (0);
}
*/