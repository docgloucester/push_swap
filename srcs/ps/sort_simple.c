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

int	pos_where_to_insert(t_list **st_a, int to_insert)
{
	int		i;
	t_list	*curr;

	curr = *st_a;
	i = 0;
	while (++i < ft_lstsize(*st_a) && ft_atoi(curr->content) < to_insert)
		curr = curr->next;
	if (!(ft_atoi(curr->content) < to_insert))
		i--;
	return (i);
}

void	insert_back(t_list **st_a, t_list **st_b, int to_insert, t_list **moves)
{
	int		i;
	int		ret;

	i = pos_where_to_insert(st_a, to_insert);
	if (i <= ft_lstsize(*st_a) / 2)
	{
		ret = i;
		while (i-- > 0)
			add_move(RA, st_a, NULL, moves);
		add_move(PA, st_a, st_b, moves);
		while (++i < ret)
			add_move(RRA, st_a, NULL, moves);
	}
	else
	{
		ret = i;
		while (i++ < ft_lstsize(*st_a))
			add_move(RRA, st_a, NULL, moves);
		add_move(PA, st_a, st_b, moves);
		while (i-- > ret)
			add_move(RA, st_a, NULL, moves);
	}
}

void	sort_5(t_list **stack_a, t_list **moves)
{
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
		add_move(PB, stack_a, &stack_b, moves);
	if (size == 5 && get_value(stack_b, 1) > get_value(stack_b, 0))
		add_move(SB, NULL, &stack_b, moves);
	sort_3(stack_a, moves);
	while (stack_b)
		insert_back(stack_a, &stack_b, get_value(stack_b, 0), moves);
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
