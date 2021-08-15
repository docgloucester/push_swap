/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:27:39 by rgilles           #+#    #+#             */
/*   Updated: 2020/04/09 21:27:42 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdio.h>

int	ft_lstsize(t_list *lst)
{
//printf("BEGIN LSTSIZE\n");
	int	i;

	i = 0;
	while (lst)
	{
//printf("Current counted stack element is %s\n", lst->content);
		i++;
		lst = lst->next;
	}
	return (i);
}
