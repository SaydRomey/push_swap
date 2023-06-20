/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:40:12 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:31:23 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	char	lwrcase;
	char	uprcase;

	lwrcase = 'a';
	uprcase = 'Z';
	printf("\nLowercase char : %c\nUppercase char : %c\n", lwrcase, uprcase);
	printf("\nAfter function;\n");
	printf("\nLowercase char : %c\n", ft_toupper(lwrcase));
	printf("Uppercase char : %c\n", ft_toupper(uprcase));
	return (0);
}
*/