/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:46:31 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/12 14:46:32 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	populate_chunk_limits(t_list **stack_a, t_list **cl, int nbchunks)
{
	int	i;
	int	step;


	i = -1;
	step = ft_lstsize(*stack_a) / nbchunks;
	while (++i < nbchunks)
		ft_lstadd_back(cl, ft_lstnew(ft_itoa(i * step)));
	ft_lstadd_back(cl, ft_lstnew(ft_itoa(ft_lstsize(*stack_a))));
}

int		is_in_chunk(t_list *chunk, int number)
{
	return (ft_atoi(chunk->content) <= number
		&& number < ft_atoi(chunk->next->content));
}

void	push_rb(t_list **sa, t_list **sb, t_list **mvs, t_list *chunk)
{
	int	moy;

	moy = (ft_atoi(chunk->next->content) + ft_atoi(chunk->content)) / 2;
	add_move(PB, sa, sb, mvs);
	if ((*sb)->rank > moy && ft_lstsize(*sb) > 1)
		add_move(RB, sa, sb, mvs);
}

int		is_minmax(int number, int *minmax)
{
	return (number == minmax[0] || number == minmax[1]);
}

void	pushback_upd(t_list **s_a, t_list **s_b, t_list **moves, int *minmax)
{
	add_move(PA, s_a, s_b, moves);

	if ((*s_a)->rank == minmax[0] && ft_lstsize(*s_a) > 1)
	{
		add_move(RA, s_a, s_b, moves);
		minmax[0]++;
	}
	else
		minmax[1]--;
}