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
			ft_printf("KO\n");
			exit(0);
		}
		stack = stack->next;
	}
	ft_printf("OK\n");
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

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	
	sanitize_input(argc, argv);
	stack_a = put_on_list(argc, argv);
	verify_order(stack_a);
	return (0);
}
