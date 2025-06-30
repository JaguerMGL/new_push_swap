/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:42:06 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:42:07 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_top(t_node **a, t_node **b, t_node *cheapest)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(*a);
	len_b = ft_lstlen(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rrr_amedian(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rr_bmedian(a, b, cheapest);
	else if (!cheapest->above_median && cheapest->target->above_median)
	{
		full_rb(b, cheapest->index);
		full_rra(a, len_a - cheapest->target->index);
	}
	else if (cheapest->above_median && !cheapest->target->above_median)
	{
		full_rrb(b, len_b - cheapest->index);
		full_ra(a, cheapest->target->index);
	}
}
