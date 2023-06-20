/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:15:34 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/25 18:04:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it.
*/
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (str)
		ft_memcpy(str, s1, len);
	return (str);
}

/*
#include "ft_memcpy.c"
#include "ft_strlen.c"

int	main(void)
{
	char	*str;
	char	*result;

	str = "Hello there !";
	// result = strdup(str);
	// printf("\nstrdup : %s\n", result);
	result = ft_strdup(str);
	printf("\nft_strdup : %s\n", result);
	free(result);
	return (0);
}
*/
/*
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i += 1;
	}
	s2[i] = '\0';
	return (s2);
}
*/