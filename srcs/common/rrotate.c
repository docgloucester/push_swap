/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:39:06 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 13:39:08 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_rra(t_list **stack_a, t_list **stack_b)
{
	int	size;
	t_list	*tmp_a1;
	t_list	*curr;

	(void)stack_b;
	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	tmp_a1 = *stack_a;
	curr = *stack_a;
	while (curr->next->next)
		curr = curr->next;
	*stack_a = curr->next;
	(*stack_a)->next = tmp_a1;
	curr->next = NULL;
}

void	do_rrb(t_list **stack_a, t_list **stack_b)
{
	do_rra(stack_b, stack_a);
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	do_rra(stack_a, stack_b);
	do_rra(stack_b, stack_a);
}
