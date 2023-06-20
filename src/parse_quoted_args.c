/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quoted_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:51:30 by cdumais           #+#    #+#             */
/*   Updated: 2023/06/19 16:57:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
Applies ft_isdigit to all characters of the argument
*/
static int	quoted_arg_is_digits(const char *arg)
{
	int	j;

	j = 0;
	if (arg[j] == '-')
		j++;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (FALSE);
		j++;
	}
	return (TRUE);
}

/*
Returns TRUE if ft_itoa and ft_atoi return different values
*/
static int	quoted_arg_flow_check(const char *arg)
{
	char	*output;

	output = ft_itoa(ft_atoi(arg));
	if (ft_strncmp(arg, output, ft_strlen(arg)) != SAME)
	{
		free(output);
		return (TRUE);
	}
	free(output);
	return (FALSE);
}

/*
Checks if the quoted argument is valid (only digits, no overflow)
*/
static int	validate_quoted_arg(const char *arg)
{
	if (quoted_arg_is_digits(arg) == FALSE)
		return (FALSE);
	if (quoted_arg_flow_check(arg) == TRUE)
		return (FALSE);
	return (TRUE);
}

/*
Checks if the quoted arguments are unique
*/
static int	quoted_args_are_unique(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_strncmp(split[i], split[j], ft_strlen(split[i])) == SAME
				&& ft_strlen(split[i]) == ft_strlen(split[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
Parses the quoted argument
*/
void	parse_quoted_args(char *argv)
{
	char	**split;
	int		j;

	split = ft_split(argv, ' ');
	if (!split)
		exit_error("Error");
	if (quoted_args_are_unique(split) == FALSE)
	{
		free_split(split);
		exit_error("Error");
	}
	j = 0;
	while (split[j])
	{
		if (validate_quoted_arg(split[j]) == FALSE)
		{
			free_split(split);
			exit_error("Error");
		}
		j++;
	}
	free_split(split);
}
