/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:20:53 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/29 14:20:55 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	apply_sort(t_list *stack_a)
{
	t_list	*stack_b;
	char	*line;

	if (get_next_line(0, &line) >= 0)
	{
		
	}
	else
	{
		ft_error("Unable to read on stdin\n");
		exit(-1);
	}
}
