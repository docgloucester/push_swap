/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:58:11 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 12:58:13 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a1;
	t_list	*tmp_b2;

	if (ft_lstsize(*stack_b))
	{
		tmp_a1 = *stack_a;
		tmp_b2 = (*stack_b)->next;
		*stack_a = *stack_b;
		(*stack_a)->next = tmp_a1;
		*stack_b = tmp_b2;
	}
}

void	do_pb(t_list **stack_a, t_list **stack_b)
{
	do_pa(stack_b, stack_a);
}
