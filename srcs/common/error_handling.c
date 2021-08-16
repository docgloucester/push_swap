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

void	check_oob(char *arg)
{
	int		j;
	char	**split;

	if (is_russian_doll(arg))
	{
		j = -1;
		split = ft_split(arg, ' ');
		while (split[++j])
			ft_atoi(split[j]);
		free_split(split);
	}
	else
		ft_atoi(arg);
	if (errno)
	{
		ft_error("");
		exit(-1);
	}
}

void	sanitize_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		exit(0);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			{
				ft_error("");
				exit(-1);
			}
		}
		check_oob(argv[i]);
	}
}
