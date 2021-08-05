/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:05:10 by rgilles           #+#    #+#             */
/*   Updated: 2021/04/21 14:05:11 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>

typedef void	(*t_ops)(t_list **stack_a, t_list **stack_b);
enum			{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

t_list	*put_on_list(int argc, char **argv);
void	sanitize_input(int argc, char **argv);
int		is_in_order(t_list *stack);
void	do_nothing(void *ptr);
void	do_sa(t_list **stack_a, t_list **stack_b);
void	do_sb(t_list **stack_a, t_list **stack_b);
void	do_ss(t_list **stack_a, t_list **stack_b);
void	do_pa(t_list **stack_a, t_list **stack_b);
void	do_pb(t_list **stack_a, t_list **stack_b);
void	do_ra(t_list **stack_a, t_list **stack_b);
void	do_rb(t_list **stack_a, t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);
void	do_rra(t_list **stack_a, t_list **stack_b);
void	do_rrb(t_list **stack_a, t_list **stack_b);
void	do_rrr(t_list **stack_a, t_list **stack_b);

void	sort_simple(t_list **stack_a, t_list **moves);
int		get_value(t_list *stack, int pos);
void	add_move(int move, t_list **sa, t_list **sb, t_list **moves);

void	apply_sort(t_list **stack_a, t_ops *ops);
void	raise_apply_error(int status, int op);

#endif
