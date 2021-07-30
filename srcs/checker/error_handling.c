/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:10:37 by rgilles           #+#    #+#             */
/*   Updated: 2021/04/22 14:10:38 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_nothing(void *ptr)
{
	(void)ptr;
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
	}
}

void	raise_apply_error(int op, int status)
{
	if (status == -1)
	{
		ft_error("Unable to read on stdin\n");
		exit(-1);
	}
	if (op == -1)
	{
		ft_error("Invalid operation\n");
		exit(-1);
	}
}
