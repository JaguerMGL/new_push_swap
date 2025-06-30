/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:59:49 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 14:59:50 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static unsigned int	ft_nbr_word(char const *str, char c)
{
	unsigned int	i;

	while (*str == c)
		str++;
	if (*str)
		i = 1;
	else
		i = 0;
	while (*str)
	{
		if (*str == c)
		{
			while (*str == c)
				str++;
			if (*str)
				i++;
		}
		if (*str)
			str++;
	}
	return (i);
}

static char	**ft_do_it(char const *s, char c, unsigned int i, char **ptr)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < i && *s)
	{
		y = 0;
		ptr[x] = ft_calloc(ft_chain_len(s, c) + 1, sizeof(char));
		if (!ptr[x])
			return (ft_free(ptr));
		while (ft_chain_len(s, c))
		{
			ptr[x][y] = *s;
			y++;
			s++;
		}
		while (*s == c && *s)
			s++;
		x++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	i = ft_nbr_word(s, c);
	ptr = ft_calloc(i + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_do_it(s, c, i, ptr);
	return (ptr);
}
