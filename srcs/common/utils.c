/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:52:33 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 15:52:35 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	is_in_order(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) < ft_atoi(stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	detect_duplicate(t_list *stack)
{
	t_list	*curr;
	t_list	*curr2;
	int		rank;

	curr = stack;
	while (curr)
	{
		curr2 = stack;
		rank = 0;
		while (curr2)
		{
			if (ft_atoi(curr2->content) < ft_atoi(curr->content))
				rank++;
			if (curr != curr2
				&& ft_atoi(curr2->content) == ft_atoi(curr->content))
			{
				ft_error("");
				exit(-1);
			}
			curr2 = curr2->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}

int	is_russian_doll(char *curr_arg)
{
	while (*curr_arg)
	{
		if ((*curr_arg == ' ') && ft_isdigit(curr_arg[1]))
			return (1);
		curr_arg++;
	}
	return (0);
}

t_list	*put_on_list(int argc, char **argv)
{
	int		i;
	t_list	*stack;
	char	**split;
	int		j;

	i = 0;
	stack = NULL;
	while (++i < argc)
	{
		if (is_russian_doll(argv[i]))
		{
			j = -1;
			split = ft_split(argv[i], ' ');
			while (split[++j])
				ft_lstadd_back(&stack, ft_lstnew(ft_strdup(split[j])));
			free_split(split);
		}
		else
			ft_lstadd_back(&stack, ft_lstnew(ft_strdup(argv[i])));
	}
	detect_duplicate(stack);
	return (stack);
}
