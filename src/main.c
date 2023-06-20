/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:29:35 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 16:51:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_quoted_args_to_stack(t_stack *stack, char *quoted_args)
{
	char	**args;
	int		i;
	int		*num;

	args = ft_split(quoted_args, ' ');
	if (!args)
		exit_error("Error: split failed");
	i = 0;
	while (args[i])
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
		{
			free_split(args);
			free_stack(stack);
			exit_error("Error");
		}
		*num = ft_atoi(args[i]);
		push_back(stack, num);
		i++;
	}
	free_split(args);
}

static void	push_args_to_stack(t_stack *stack, char **argv)
{
	int	i;
	int	*num;

	i = 1;
	while (argv[i])
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
		{
			while (i-- > 1)
				free_stack(stack);
			exit_error("Error");
		}
		*num = ft_atoi(argv[i]);
		push_back(stack, num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
		parse_quoted_args(argv[1]);
	else
		parse_args(argc, argv);
	a = new_stack();
	b = new_stack();
	if (argc == 2)
		push_quoted_args_to_stack(a, argv[1]);
	else if (argc > 2)
		push_args_to_stack(a, argv);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
