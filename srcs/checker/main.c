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

#include <checker.h>

void	verify_order(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) < ft_atoi(stack->content))
		{
			write(1,"KO\n",3);
			exit(0);
		}
		stack = stack->next;
	}
	write(1, "OK\n", 3);
}

t_list	*put_on_list(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (++i < argc)
		ft_lstadd_back(&stack, ft_lstnew(argv[i]));
	return (stack);
}

void	do_nothing(void *ptr)
{
	(void)ptr;
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	
	sanitize_input(argc, argv);
	stack_a = put_on_list(argc, argv);
	apply_sort(stack_a);
	verify_order(stack_a);
	ft_lstclear(&stack_a, do_nothing);
	return (0);
}
