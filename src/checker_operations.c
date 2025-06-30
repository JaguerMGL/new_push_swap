/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:01:02 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 15:03:53 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	sa_silent(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*a = second;
}

void	sb_silent(t_node **b)
{
	sa_silent(b);
}

void	ss_silent(t_node **a, t_node **b)
{
	sa_silent(a);
	sa_silent(b);
}

void	ra_silent(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = find_last_node(*a);
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rb_silent(t_node **b)
{
	ra_silent(b);
}
