/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:16:37 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 15:53:12 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Applies ft_isdigit to all characters of all arguments
*/
static int	args_are_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
returns TRUE if ft_itoa and ft_atoi return different values
*/
static int	flow_check(char *input)
{
	char	*output;

	output = ft_itoa(ft_atoi(input));
	if (ft_strncmp(input, output, ft_strlen(input)) != SAME)
		return (free(output), TRUE);
	return (free(output), FALSE);
}

/*
Applies flow_check to all arguments
*/
static int	args_are_int(int argc, char **argv)
{
	int	i;
	int	bad_flow;

	i = 1;
	while (i < argc)
	{
		bad_flow = flow_check(argv[i]);
		if (bad_flow == TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
Compares each element of argv to all other elements
*/
static int	args_are_unique(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
Checks if arguments are valid
(only digits, no duplicates, no overflow)
*/
void	parse_args(int argc, char **argv)
{
	if (argc < 2)
		exit(ERROR);
	if (argc == 2)
		parse_quoted_args(*argv);
	else if (args_are_digits(argc, argv) == FALSE)
		exit_error("Error");
	else if (args_are_int(argc, argv) == FALSE)
		exit_error("Error");
	else if (args_are_unique(argc, argv) == FALSE)
		exit_error("Error");
	else
		return ;
}
