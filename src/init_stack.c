/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:48:28 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:51:37 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_repeat(t_node *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static long	ft_atoi(const char *str)
{
	int		i;
	long	val;

	i = 1;
	val = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val += *str - '0';
		str++;
	}
	return (val * i);
}

static void	append_node(t_node **a, int nbr, int i)
{
	t_node	*node;
	t_node	*last;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->value = nbr;
	node->index = i;
	node->next = NULL;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*a);
		last->next = node;
		node->prev = last;
	}
}

void	set_size(t_node **lst, int i)
{
	t_node	*current;

	current = *lst;
	while (current)
	{
		current->size = i;
		current = current->next;
	}
}

t_node	*init_stack(char **lst)
{
	t_node	*tmp;
	long	nbr;
	int		i;

	i = -1;
	tmp = NULL;
	while (lst[++i])
	{
		if (ft_strlen(lst[i]) > 12)
			print_error_free(lst, "Error: not a interger\n");
		nbr = ft_atoi(lst[i]);
		if (is_repeat(tmp, (int)nbr))
			print_error_free(lst, "Error: nbr repeat\n");
		if (nbr > INT_MAX || nbr < INT_MIN)
			print_error_free(lst, "Error: not a interger\n");
		append_node(&tmp, (int)nbr, i);
	}
	set_size(&tmp, i);
	ft_free_double_char(lst);
	return (tmp);
}
