/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:12:28 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/04 12:12:29 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_move(int move, t_list **sa, t_list **sb, t_list **moves)
{
	t_ops	ops[11];

	ops[SA] = &do_sa;
	ops[SB] = &do_sb;
	ops[SS] = &do_ss;
	ops[PA] = &do_pa;
	ops[PB] = &do_pb;
	ops[RA] = &do_ra;
	ops[RB] = &do_rb;
	ops[RR] = &do_rr;
	ops[RRA] = &do_rra;
	ops[RRB] = &do_rrb;
	ops[RRR] = &do_rrr;
	ops[move](sa, sb);
	ft_lstadd_back(moves, ft_lstnew(ft_itoa(move)));
}

int	get_value(t_list *stack, int pos)
{
	int	i;

	i = -1;
	if (ft_lstsize(stack) >= pos)
	{
		while (++i < pos)
			stack = stack->next;
		return (ft_atoi(stack->content));
	}
	ft_error("Stack index out of bounds !\n");
	exit(-1);
}

int	get_rank(t_list *stack, int pos)
{
	int	i;

	i = -1;
	if (ft_lstsize(stack) >= pos)
	{
		while (++i < pos)
			stack = stack->next;
		return (stack->rank);
	}
	ft_error("Stack index out of bounds !\n");
	exit(-1);
}
