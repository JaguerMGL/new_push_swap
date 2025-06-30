/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:41:42 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:41:43 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_node **lst)
{
	t_node	*last;
	int		len;

	len = ft_lstlen(*lst);
	if (lst == NULL || *lst == NULL || len == 1)
		return ;
	last = find_last_node(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
