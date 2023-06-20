/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:06:07 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:31:12 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	len;

	if (!str || !set)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	return (ft_substr(str, 0, len + 1));
}

/*
#include "ft_memset.c"
#include "ft_strchr.c"
#include "ft_strlen.c"
#include "ft_substr.c"
#include "ft_calloc.c"
#include "ft_bzero.c"

int	main(void)
{
	char	*str;
	char	*set;
	char	*trimmed;

	str = "*!1!2!3!*";
	set = "*!*";
	printf("\nOriginal string : %s\n", str);	
	printf("\nChar to trim : %s\n", set);
	trimmed = ft_strtrim(str, set);
	printf("\nTrimmed string : %s\n", trimmed);
	free(trimmed);
	return (0);
}
*/

/*
char	*ft_strtrim(char const *str, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
		end--;
	trimmed = ft_substr(str, start, end - start);
	return (trimmed);
}
*/
