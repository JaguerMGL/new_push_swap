/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:57:48 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:57:49 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	full_ra(t_node **a, int pos)
{
	while (pos > 0)
	{
		ra(a);
		pos--;
	}
}

void	full_rra(t_node **a, int pos)
{
	while (pos > 0)
	{
		rra(a);
		pos--;
	}
}

void	full_rb(t_node **b, int pos)
{
	while (pos > 0)
	{
		rb(b);
		pos--;
	}
}

void	full_rrb(t_node **b, int pos)
{
	while (pos > 0)
	{
		rrb(b);
		pos--;
	}
}
