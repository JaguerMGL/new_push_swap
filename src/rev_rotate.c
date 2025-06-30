/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:41:53 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:41:54 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	rev_rotate(t_node **lst)
{
	t_node	*last;
	int		i;

	i = ft_lstlen(*lst);
	last = find_last_node(*lst);
	if (i == 1)
		return ;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	prependnode(lst, last);
}

void	rra(t_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
