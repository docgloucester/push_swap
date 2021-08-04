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

void	sort_simple(t_list *stack_a, t_list **moves)
{
	if (ft_lstsize(stack_a) == 2)
	{
		if (get_stacked_value(stack_a, 1) < get_stacked_value(stack_a, 0))
			add_move(SA, stack_a, NULL, moves);
	}
}
