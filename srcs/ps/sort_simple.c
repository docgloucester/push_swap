/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:53:40 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/04 11:53:41 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_list **stack_a, t_list **moves)
{
	if (get_value(*stack_a, 1) > get_value(*stack_a, 0))
	{
		if (get_value(*stack_a, 2) < get_value(*stack_a, 0))
			add_move(RRA, stack_a, NULL, moves);
		else if (get_value(*stack_a, 2) < get_value(*stack_a, 1))
		{
			add_move(RRA, stack_a, NULL, moves);
			add_move(SA, stack_a, NULL, moves);
		}
	}
	else
	{
		if (get_value(*stack_a, 2) > get_value(*stack_a, 0))
			add_move(SA, stack_a, NULL, moves);
		else
		{
			if (get_value(*stack_a, 2) > get_value(*stack_a, 1))
				add_move(RA, stack_a, NULL, moves);
			else
			{
				add_move(SA, stack_a, NULL, moves);
				add_move(RRA, stack_a, NULL, moves);
			}
		}
	}
}

int	pos_of_closest(t_list *st_a, int to_insert)
{
	int		i;
	int		dist;
	int		tmp;
	int		closest;

	dist = to_insert - st_a->rank;
	if (dist < 0)
		dist = -dist;
	i = -1;
	closest = 0;
	while (st_a)
	{
		++i;
		tmp = to_insert - st_a->rank;
		if (tmp < 0)
			tmp = -tmp;
		if (tmp < dist)
		{
			dist = tmp;
			closest = i;
		}
		st_a = st_a->next;
	}
	return (closest);
}

void	rot_insert(t_list **st_a, t_list **st_b, int to_insert, t_list **moves)
{
	int		i;

	i = pos_of_closest(*st_a, to_insert);
	if (get_rank(*st_a, i) > to_insert)
	{
		if (i <= ft_lstsize(*st_a) / 2)
			while (i-- > 0 && ft_lstsize(*st_a) > 1)
				add_move(RA, st_a, st_b, moves);
		else
			while (++i <= ft_lstsize(*st_a) && ft_lstsize(*st_a) > 1)
				add_move(RRA, st_a, st_b, moves);
	}
	else
	{
		if (i <= ft_lstsize(*st_a) / 2)
			while (i-- >= 0 && ft_lstsize(*st_a) > 1)
				add_move(RA, st_a, st_b, moves);
		else
			while (++i < ft_lstsize(*st_a) && ft_lstsize(*st_a) > 1)
				add_move(RRA, st_a, st_b, moves);
	}
	add_move(PA, st_a, st_b, moves);
}

void	sort_5(t_list **stack_a, t_list **moves)
{
	t_list	*stack_b;
	int		size;
	int		pos;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
		add_move(PB, stack_a, &stack_b, moves);
	sort_3(stack_a, moves);
	while (stack_b)
		rot_insert(stack_a, &stack_b, get_rank(stack_b, 0), moves);
	pos = -1;
	while (++pos < ft_lstsize(*stack_a) && get_rank(*stack_a, pos) > 0)
		;
	if (pos <= ft_lstsize(*stack_a) / 2)
		while (pos-- > 0 && ft_lstsize(*stack_a) > 1)
			add_move(RA, stack_a, NULL, moves);
	else
		while (++pos <= ft_lstsize(*stack_a) && ft_lstsize(*stack_a) > 1)
			add_move(RRA, stack_a, NULL, moves);
}

void	sort_simple(t_list **stack_a, t_list **moves)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if (get_value(*stack_a, 1) < get_value(*stack_a, 0))
			add_move(SA, stack_a, NULL, moves);
	}
	else if (size == 3)
		sort_3(stack_a, moves);
	else
		sort_5(stack_a, moves);
}
