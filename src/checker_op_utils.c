/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:01:26 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 15:02:23 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rra_silent(t_node **a)
{
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = find_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
}

void	rrb_silent(t_node **b)
{
	rra_silent(b);
}

void	rrr_silent(t_node **a, t_node **b)
{
	rra_silent(a);
	rra_silent(b);
}

void	pa_silent(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
}

void	pb_silent(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	tmp->prev = NULL;
	*b = tmp;
}
