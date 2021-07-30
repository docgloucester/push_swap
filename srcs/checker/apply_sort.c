/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:20:53 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/29 14:20:55 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_op(char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		return (SA);
	if (ft_strncmp(str, "sb", 2) == 0)
		return (SB);
	if (ft_strncmp(str, "ss", 2) == 0)
		return (SS);
	if (ft_strncmp(str, "pa", 2) == 0)
		return (PA);
	if (ft_strncmp(str, "pb", 2) == 0)
		return (PB);
	if (ft_strncmp(str, "ra", 2) == 0)
		return (RA);
	if (ft_strncmp(str, "rb", 2) == 0)
		return (RB);
	if (ft_strncmp(str, "rra", 3) == 0)
		return (RRA);
	if (ft_strncmp(str, "rrb", 3) == 0)
		return (RRB);
	if (ft_strncmp(str, "rrr", 3) == 0)
		return (RRR);
	if (ft_strncmp(str, "rr", 2) == 0)
		return (RR);
	return (-1);
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

void	apply_sort(t_list **stack_a, t_ops *ops)
{
	t_list	*stack_b;
	char	*line;
	int		status;
	int		op;

	stack_b = NULL;
	status = get_next_line(0, &line);
	while (status != -1)
	{
		if (status)
		{
			op = is_op(line);
			if (op >= 0)
				ops[op](stack_a, &stack_b);
		}
		if (line)
			free(line);
		if (status == 0 || op == -1)
			break ;
		status = get_next_line(0, &line);
	}
	if (stack_b)
		ft_lstclear(&stack_b, do_nothing);
	raise_apply_error(op, status);
}
