/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:30 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 16:12:19 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct s_node
{
	int				index;
	int				value;
	int				size;
	struct s_node	*target;
	int				price;
	int				above_median;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// general_utils - general_utils2//
int				ft_strlen(char *str);
char			*ft_make_join(char *s1, char *s2, size_t len1, size_t len2);
char			*ft_strjoin(char *s1, char *s2);
int				is_sorted(t_node *lst);
void			prependnode(t_node **lst, t_node *new);
int				ft_lstlen(t_node *lst);
void			move_to_top(t_node **stack, t_node *target);
float			calculate_average(t_node *a);
int				ft_strcmp(char *s1, char *s2);
t_node			*find_last_node(t_node *lst);
int				ft_strcmp(char *s1, char *s2);

// print //
void			print(char *msg);
void			print_error(char *msg, int flag);
void			print_error_free(char **lst, char *msg);

// free //
void			ft_free_double_char(char **lst);
void			free_stack(t_node *stack);

// check_arg - check_arg_utils //
char			**check_arg(int ac, char **av);
int				check_space(char *str);
int				is_digit(char c);
char			*ft_strdup(char *str);
char			*ft_join_all(int ac, char **av);

// ft_split - ft_split_utils //
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
char			**ft_free(char **ptr);
unsigned int	ft_chain_len(char const *s, char c);

// init_stack //
t_node			*init_stack(char **lst);
t_node			*find_last_node(t_node *lst);
void			set_size(t_node **lst, int i);

// push_swap - push_swap_utils- push_swap_utils2 //
void			push_swap(t_node **a, t_node **b);
int				ft_lstlen(t_node *lst);
void			set_target(t_node **a, t_node **b);
void			set_index(t_node *lst);
void			is_median(t_node *lst);
void			set_price(t_node **a, t_node **b);
t_node			*find_cheapest(t_node **b);
void			set_top(t_node **a, t_node **b, t_node *cheapest);

//swap //
void			sa(t_node **a);
void			sb(t_node **b);
void			ss(t_node **a, t_node **b);

// rotate - rev_rotate - full_rot - top_rot //
void			ra(t_node **a);
void			rb(t_node **b);
void			rr(t_node **a, t_node **b);
void			rra(t_node **a);
void			rrb(t_node **b);
void			rrr(t_node **a, t_node **b);
void			full_ra(t_node **a, int pos);
void			full_rra(t_node **a, int pos);
void			full_rb(t_node **b, int pos);
void			full_rrb(t_node **b, int pos);
void			rrr_amedian(t_node **a, t_node **b, t_node *cheapest);
void			rr_bmedian(t_node **a, t_node **b, t_node *cheapest);
void			top_rrr(t_node **a, t_node **b, int pos);
void			top_rr(t_node **a, t_node **b, int pos);

// push //
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);

// tiny_sort - little_sort //
void			tiny_sort(t_node **a);
void			little_sort_4(t_node **a, t_node **b);
void			little_sort_5(t_node **a, t_node **b);
t_node			*find_biggest(t_node *lst);
t_node			*find_smallest(t_node *lst);
