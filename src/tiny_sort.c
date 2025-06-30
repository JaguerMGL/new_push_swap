/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:40:30 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:40:45 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_node **a)
{
	t_node	*last;

	last = find_last_node(*a);
	if ((*a)->size == 2)
		sa(a);
	if ((*a)->value > (*a)->next->value && (*a)->value > last->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value && (*a)->next->value > last->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
