/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:04:02 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 18:11:56 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	execute_instruction(char *instruction, t_node **a, t_node **b)
{
	if (!ft_strcmp(instruction, "sa"))
		sa_silent(a);
	else if (!ft_strcmp(instruction, "sb"))
		sb_silent(b);
	else if (!ft_strcmp(instruction, "ss"))
		ss_silent(a, b);
	else if (!ft_strcmp(instruction, "pa"))
		pa_silent(a, b);
	else if (!ft_strcmp(instruction, "pb"))
		pb_silent(a, b);
	else if (!ft_strcmp(instruction, "ra"))
		ra_silent(a);
	else if (!ft_strcmp(instruction, "rb"))
		rb_silent(b);
	else if (!ft_strcmp(instruction, "rr"))
		rr_silent(a, b);
	else if (!ft_strcmp(instruction, "rra"))
		rra_silent(a);
	else if (!ft_strcmp(instruction, "rrb"))
		rrb_silent(b);
	else if (!ft_strcmp(instruction, "rrr"))
		rrr_silent(a, b);
	else
		return (0);
	return (1);
}

static char	*read_instruction(void)
{
	char	line[5];
	char	*instruction;
	int		i;

	i = 0;
	while (read(0, &line[i], 1) > 0 && line[i] != '\n' && i < 4)
		i++;
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	instruction = ft_strdup(line);
	return (instruction);
}

static int	read_and_execute(t_node **a, t_node **b)
{
	char	*instruction;

	instruction = read_instruction();
	while (instruction != NULL)
	{
		if (!execute_instruction(instruction, a, b))
		{
			free(instruction);
			print_error("Error", 1);
		}
		free(instruction);
		if (is_sorted(*a) && *b == NULL)
			return (1);
		instruction = read_instruction();
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**lst;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (0);
	lst = check_arg(ac, av);
	if (!lst)
		print_error("Error", 1);
	a = init_stack(lst);
	if (read_and_execute(&a, &b))
		print("OK\n");
	else
		print("KO\n");
	return (0);
}
