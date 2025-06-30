/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:46:14 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 15:32:03 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	print_error(char *msg, int flag)
{
	(void)msg;
	write(2, "Error\n", 6);
	if (flag)
		exit(1);
}

void	print_error_free(char **lst, char *msg)
{
	ft_free_double_char(lst);
	print_error(msg, 1);
}
