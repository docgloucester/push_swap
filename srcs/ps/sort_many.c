/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:35:35 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/11 17:35:36 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_minmax(t_list *c, int *minmax)
{
	minmax[1] = ft_atoi(c->next->content) - 1;
	minmax[0] = ft_atoi(c->content);
}

void	push_on_a(t_list **sa, t_list **sb, t_list **mvs, t_list *c)
{
	int	minmax[2];
	int	i;

	fill_minmax(c, minmax);
	while (ft_lstsize(*sb) > 0)
	{
		i = -1;
		while (++i < ft_lstsize(*sb) / 2 + 1)
		{
			if (is_minmax(get_rank(*sb, i), minmax))
			{
				while (i-- > 0 && ft_lstsize(*sb) > 1)
					add_move(RB, sa, sb, mvs);
				pushback_upd(sa, sb, mvs, minmax);
				break ;
			}
			else if (is_minmax(get_rank(*sb, ft_lstsize(*sb) - i - 1), minmax))
			{
				while (i-- >= 0 && ft_lstsize(*sb) > 1)
					add_move(RRB, sa, sb, mvs);
				pushback_upd(sa, sb, mvs, minmax);
				break ;
			}
		}
	}
}

void	roll_a_to_insert(t_list **s_a, t_list **moves, t_list *c)
{
	int	i;

	if (ft_atoi(c->content) == 0)
		return ;
	i = -1;
	while (++i < ft_lstsize(*s_a) / 2 + 1)
	{
		if (get_rank(*s_a, i) == ft_atoi(c->content) - 1)
		{
			while (i-- >= 0 && ft_lstsize(*s_a) > 1)
				add_move(RA, s_a, NULL, moves);
			return ;
		}
		else if (get_rank(*s_a, ft_lstsize(*s_a) - i - 1)
			== ft_atoi(c->content) - 1)
		{
			while (i-- > 0 && ft_lstsize(*s_a) > 1)
				add_move(RRA, s_a, NULL, moves);
			return ;
		}
	}
}

void	pb_chunk(t_list **s_a, t_list **s_b, t_list *c, t_list **moves)
{
	int	i;

	while (ft_lstsize(*s_b) < ft_atoi(c->next->content) - ft_atoi(c->content))
	{
		i = -1;
		while (++i < ft_lstsize(*s_a) / 2 + 1)
		{
			if (is_in_chunk(c, get_rank(*s_a, i)))
			{
				while (i-- > 0 && ft_lstsize(*s_a) > 1)
					add_move(RA, s_a, s_b, moves);
				break ;
			}
			else if (is_in_chunk(c, get_rank(*s_a, ft_lstsize(*s_a) - i - 1)))
			{
				while (i-- >= 0 && ft_lstsize(*s_a) > 1)
					add_move(RRA, s_a, s_b, moves);
				break ;
			}
		}
		push_rb(s_a, s_b, moves, c);
	}
}

void	sort_many(t_list **stack_a, t_list **moves)
{
	t_list	*stack_b;
	t_list	*chunk_limits;
	t_list	*curr_chunk;
	int		nb_chunks;

	stack_b = NULL;
	chunk_limits = NULL;
	nb_chunks = 2;
	if (ft_lstsize(*stack_a) >= 500)
		nb_chunks = 7;
	else if (ft_lstsize(*stack_a) >= 50)
		nb_chunks = 3;
	populate_chunk_limits(stack_a, &chunk_limits, nb_chunks);
	curr_chunk = chunk_limits;
	while (curr_chunk->next)
	{
		pb_chunk(stack_a, &stack_b, curr_chunk, moves);
		roll_a_to_insert(stack_a, moves, curr_chunk);
		push_on_a(stack_a, &stack_b, moves, curr_chunk);
		while (is_in_chunk(curr_chunk, (*stack_a)->rank)
			&& ft_lstsize(*stack_a) > 1)
			add_move(RA, stack_a, &stack_b, moves);
		curr_chunk = curr_chunk->next;
	}
	ft_lstclear(&chunk_limits, free);
}
