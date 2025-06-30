/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:52:38 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:55:37 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstlen(t_node *lst)
{
	struct s_node	*ptr;
	int				i;

	if (lst == NULL)
		return (0);
	ptr = lst->next;
	i = 1;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	move_to_top(t_node **stack, t_node *target)
{
	int		len;
	int		pos;
	t_node	*current;

	len = ft_lstlen(*stack);
	pos = 0;
	current = *stack;
	while (current && current != target)
	{
		current = current->next;
		pos++;
	}
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		while (pos++ < len)
			rra(stack);
	}
}

float	calculate_average(t_node *a)
{
	t_node	*current;
	int		sum;
	int		count;

	sum = 0;
	count = 0;
	current = a;
	while (current)
	{
		sum += current->value;
		count++;
		current = current->next;
	}
	if (count == 0)
		return (0);
	return ((float)sum / count);
}

t_node	*find_last_node(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
