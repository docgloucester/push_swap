/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:08:48 by rgilles           #+#    #+#             */
/*   Updated: 2021/04/21 14:08:49 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void DebugPrintStack(t_list *stack_a)
{
	printf("The supposedly sorted stack a is constitued of :");
	while(stack_a)
	{
		printf("%s, ", stack_a-> content);
		stack_a = stack_a->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_ops	ops[11];

	ops[SA] = &do_sa;
	ops[SB] = &do_sb;
	ops[SS] = &do_ss;
	ops[PA] = &do_pa;
	ops[PB] = &do_pb;
	ops[RA] = &do_ra;
	ops[RB] = &do_rb;
	ops[RR] = &do_rr;
	ops[RRA] = &do_rra;
	ops[RRB] = &do_rrb;
	ops[RRR] = &do_rrr;
	sanitize_input(argc, argv);
	stack_a = put_on_list(argc, argv);
	apply_sort(&stack_a, ops);
//DebugPrintStack(stack_a);
	if (!is_in_order(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&stack_a, do_nothing);
	return (0);
}
