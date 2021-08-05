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

void	sort_3(t_list **s_a, t_list **moves)
{
	if (get_value(*s_a, 1) > get_value(*s_a, 0))
	{
		if (get_value(*s_a, 2) < get_value(*s_a, 1))// 1 3 2
		{
			add_move(RRA, s_a, NULL, moves);
			add_move(SA, s_a, NULL, moves);
		}
		else if (get_value(*s_a, 2) < get_value(*s_a, 0))// 2 3 1
			add_move(RRA, s_a, NULL, moves);
	}
	else
	{
		if (get_value(*s_a, 2) > get_value(*s_a, 0))// 2 1 3
			add_move(SA, s_a, NULL, moves);
		else
		{
			if (get_value(*s_a, 2) > get_value(*s_a, 1))//312
				add_move(RA, s_a, NULL, moves);
			else//321
			{
				add_move(SA, s_a, NULL, moves);
				add_move(RRA, s_a, NULL, moves);
			}
		}
	}
}

/*void	sort_5(t_list *s_a, t_list **moves)
{
	t_list *s_b;

	while (ft_lstsize(s_a) > 3)
		add_move(PB, s_a, s_b);

}*/

void	sort_simple(t_list **s_a, t_list **moves)
{
	int size;

	size = ft_lstsize(*s_a); 
	if (size == 2)
	{
		if (get_value(*s_a, 1) < get_value(*s_a, 0))
			add_move(SA, s_a, NULL, moves);
	}
	else if (size == 3)
		sort_3(s_a, moves);
/*	else
		sort_5(s_a, moves);*/
}
