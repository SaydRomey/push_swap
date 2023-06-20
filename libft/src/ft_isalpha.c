/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:42:38 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:21:07 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
int	main(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = '8';
	c = '$';
	if (ft_isalpha(a))
		printf("\n%c is alpha.\n", a);
	else
		printf("\n%c is not alpha.\n", a);
	if (ft_isalpha(b))
		printf("\n%c is alpha.\n", b);
	else
		printf("\n%c is not alpha.\n", b);
	if (ft_isalpha(c))
		printf("\n%c is alpha.\n", c);
	else
		printf("\n%c is not alpha.\n", c);
}
*/