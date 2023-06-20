/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:31:08 by cdumais           #+#    #+#             */
/*   Updated: 2023/05/31 12:41:58 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
Contiguously allocates enough space for count objects
that are size bytes of memory each 
and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t total_size;
// 	void* ptr;
// 	int	i;

// 	total_size = count * size;
// 	ptr = malloc(total_size);
// 	if (ptr != NULL)
// 	{
// 		i = 0;
// 		while (i < total_size)
// 		{
// 			((char*)ptr)[i] = 0;
// 			i++;	
// 		}
// 	}
// 	return (ptr);
// }

/*
#include "ft_bzero.c"
#include "ft_memset.c"

int	main(void)
{
	int	i;
	int	n;
	int	*a;

	i = 0;
	printf("Number of elements to be entered: ");
	scanf("%d", &n);
	a = (int *) calloc(n, sizeof(int));
	printf("Enter %d numbers:\n", n);
	while (i < n)
	{
		scanf("%d", &a[i]);
		i++;
	}
	printf("The numbers entered are: ");
	i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
	free(a);
	return (0);
}
*/

/*
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_memset(ptr, 0, count);
	return ((void *)ptr);
}
*/

/*
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*byte_ptr;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	byte_ptr = ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
*/

/*
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
*/