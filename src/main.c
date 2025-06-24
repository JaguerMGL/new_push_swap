/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:11 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 14:32:06 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char **lst;


	a = NULL;
	b = NULL;
	if (argc == 1 || !argv[1][0])
		return (0);
	lst = check_arg(argc, argv);
	if (!lst)
		print_error("Error: Invalid arguement", 1, 1);
	init_stack(&a, lst);
	if (!is_sorted(a))
		push_swap(&a, &b);
	ft_free_all(&a);
	return (0);
}
