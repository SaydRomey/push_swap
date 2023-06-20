/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:38:51 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 22:21:03 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int	main(void)
{
	char	val1;
	char	val2;
	char	val3;

	val1 = 's';
	val2 = '8';
	val3 = '$';
	if (ft_isalnum(val1))
		printf("\n%c is alphanumeric\n", val1);
	else
		printf("\n%c is not alphanumeric\n", val1);
	if (ft_isalnum(val2))
		printf("\n%c is alphanumeric\n", val2);
	else
		printf("\n%c is not alphanumeric\n", val2);
	if (ft_isalnum(val3))
		printf("\n%c is alphanumeric\n", val3);
	else
		printf("\n%c is not alphanumeric\n", val3);
	return (0);
}
*/