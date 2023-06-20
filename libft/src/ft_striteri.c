/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:24:29 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/12 17:14:34 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/libft.h"

/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument. Each character is passed by
** address to f to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = -1;
	if (s && f)
		while (*(s + ++i))
			f(i, s + i);
}

// int	ft_toupper(int c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

// void to_upper(unsigned int index, char *c)
// {
// 	*c = ft_toupper(*c);
// 	printf("Character at index %u: %c\n", index, *c);
// }

// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "hello world";
// 	printf("Before: %s\n", str);

// 	ft_striteri(str, to_upper);

// 	printf("After: %s\n", str);

// 	return (0);
// }

// void	print_char_index(unsigned int index, char *c)
// {
// 	printf("\nChar at index %d is %c", index, *c);
// }

// int	main(void)
// {
// 	char	str[] = "Hello there !";

// 	ft_striteri(str, &print_char_index);
// 	return (0);
// }

/*
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i += 1;
		}
	}
}
*/

//?to check
/*
void	ft_striter(char *s, void (*f)(char*))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}
*/