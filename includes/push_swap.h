/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:30 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:38:48 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>



// general_utils //
int ft_strlen(char *str);
char *ft_make_join(char *s1, char *s2, size_t len1, size_t len2);
char *ft_strjoin(char *s1, char *s2);

// print //
void print(char *msg);
void print_error(char *msg, int flag);

// check_arg - check_arg_utils //
char **check_arg(int ac, char **av);
int check_space(char *str);
int is_digit(char c);
char *ft_strdup(char *str);
char *ft_join_all(int ac, char **av);

// ft_split - ft_split_utils //
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free(char **ptr);
unsigned int	ft_chain_len(char const *s, char c);
