/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:08 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 14:30:47 by ndessard         ###   ########.fr       */
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

static void	append_node(t_node **a, int nbr)
{
	t_node	*node;
	t_node	*last;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->value = nbr;
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

void	init_stack(t_node **a, char **lst)
{
	long	nbr;
	int		i;

	i = 0;
	while (lst[i])
	{
		if (ft_strlen(lst[i]) > 12)
			ft_check_free(*a, lst, "not a integer");
		nbr = ft_atoi(lst[i]);
		if (is_repeat(*a, (int)nbr))
			ft_check_free(*a, lst, "nbr repeat");
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_check_free(*a, lst, "not a integer");
		append_node(a, (int)nbr);
		i++;
	}
	ft_free_argv(lst);
}
