/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:35 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 16:13:17 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_double_char(char **lst)
{
	int	i;

	i = -1;
	if (lst)
	{
		while (lst[++i])
			free(lst[i]);
	}
	free(lst);
}

void	free_stack(t_node *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
