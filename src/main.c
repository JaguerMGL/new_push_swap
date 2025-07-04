/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:46:33 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 16:11:42 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**lst;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && !av[1][0])
		print_error("Error: empty argument", 1);
	lst = check_arg(ac, av);
	if (!lst)
		print_error("Error: invalid argument", 1);
	a = init_stack(lst);
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
