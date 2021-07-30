/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:00:17 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 12:00:18 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_sa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp_a1;
	t_list *tmp_a3;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	(void)stack_b;
	tmp_a1 = *stack_a;
	tmp_a3 = (*stack_a)->next->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp_a1;
	(*stack_a)->next->next = tmp_a3;
}

void	do_sb(t_list **stack_a, t_list **stack_b)
{
	do_sa(stack_b, stack_a);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	do_sa(stack_a, stack_b);
	do_sb(stack_a, stack_b);
}