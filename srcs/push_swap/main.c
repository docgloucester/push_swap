/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:50:32 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 15:50:35 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_moves(t_list *moves)
{
	while (moves)
	{
		if (ft_atoi(moves->content) == SA)
			write(1, "sa\n", 3);
		if (ft_atoi(moves->content) == SB)
			write(1, "sb\n", 3);
		if (ft_atoi(moves->content) == SS)
			write(1, "ss\n", 3);
		if (ft_atoi(moves->content) == PA)
			write(1, "pa\n", 3);
		if (ft_atoi(moves->content) == PB)
			write(1, "pb\n", 3);
		if (ft_atoi(moves->content) == RA)
			write(1, "ra\n", 3);
		if (ft_atoi(moves->content) == RB)
			write(1, "rb\n", 3);
		if (ft_atoi(moves->content) == RR)
			write(1, "rr\n", 3);
		if (ft_atoi(moves->content) == RRA)
			write(1, "rra\n", 4);
		if (ft_atoi(moves->content) == RRB)
			write(1, "rrb\n", 4);
		if (ft_atoi(moves->content) == RRR)
			write(1, "rrr\n", 4);
		moves = moves->next;
	}
}

void	lets_sort(t_list *stack_a, t_list **moves)
{
	if (ft_lstsize(stack_a) <= 5)
		sort_simple(stack_a, moves);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*moves;

	sanitize_input(argc, argv);
	stack_a = put_on_list(argc, argv);
	moves = NULL;
	if (!is_in_order(stack_a))
		lets_sort(stack_a, &moves);
	print_moves(moves);
	ft_lstclear(&stack_a, do_nothing);
	ft_lstclear(&moves, free);
	return (0);
}
