/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:16:13 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 15:16:47 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Silent operations for checker
void	sa_silent(t_node **a);
void	sb_silent(t_node **b);
void	ss_silent(t_node **a, t_node **b);
void	pa_silent(t_node **a, t_node **b);
void	pb_silent(t_node **a, t_node **b);
void	ra_silent(t_node **a);
void	rb_silent(t_node **b);
void	rr_silent(t_node **a, t_node **b);
void	rra_silent(t_node **a);
void	rrb_silent(t_node **b);
void	rrr_silent(t_node **a, t_node **b);

// Utility functions
int		ft_strcmp(char *s1, char *s2);
int		main(int ac, char **av);
