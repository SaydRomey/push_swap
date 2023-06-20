/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:16:06 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:30:53 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns reference to first occurence of 'pattern' in 'string'
//not more than 'len' number of char are matched
#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *pattern, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*pattern)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (pattern[j] == str[i + j] && i + j < len)
		{
			if (pattern [j + 1] == '\0')
			{
				return ((char *)str + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include "ft_strlen.c"

int	main(void)
{
	const char	*str;
	const char	*pattern;
	size_t		len;
	char		*result;


	str = "hello there";
	pattern = "here";
	len = ft_strlen(str);
	result = ft_strnstr(str, pattern, len);

	printf("\nft_stnstr ");
	if (result == NULL)
	{
		printf("could not find '%s' in '%s'\n", pattern, str);
	}
	else
	{
		printf("found '%s' in '%s'", pattern, str);
		printf(" at index %ld\n", result - str);
	}
	printf("\nWith %zu characters searched\n\n", len);
	return (0);
}
*/