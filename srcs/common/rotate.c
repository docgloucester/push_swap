/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:12:32 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 13:12:34 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_ra(t_list **stack_a, t_list **stack_b)
{
	int	size;
	t_list	*tmp_a1;
	t_list	*curr;

	(void)stack_b;
	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	tmp_a1 = *stack_a;
	*stack_a = (*stack_a)->next;
	curr = *stack_a;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp_a1;
	curr->next->next = NULL;
}

void	do_rb(t_list **stack_a, t_list **stack_b)
{
	do_ra(stack_b, stack_a);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	do_ra(stack_a, stack_b);
	do_ra(stack_b, stack_a);
}