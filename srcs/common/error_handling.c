/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:03:08 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/16 01:03:19 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_oob(char **argv, int i)
{
	ft_atoi(argv[i]);
	if (errno)
	{
		ft_error("Arguments should be within int limits.\n");
		exit(-1);
	}
}

void	sanitize_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
	{
		ft_error("Stack A has to be provided as args, as a list of integers\n");
		exit(0);
	}
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(ft_isdigit(argv[i][j])
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			{
				ft_error("Arguments should be a list of integers only\n");
				exit(-1);
			}
		}
		check_oob(argv, i);
	}
}
