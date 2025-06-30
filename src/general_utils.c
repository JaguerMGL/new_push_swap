/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:53:19 by ndessard          #+#    #+#             */
/*   Updated: 2025/06/30 16:07:21 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

char	*ft_make_join(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	res = malloc(len1 + len2 + 1);
	if (!res)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
	while (++i < len1)
		res[i] = s1[i];
	while (++j < len2)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	res = ft_make_join(s1, s2, len1, len2);
	if (s1)
		free(s1);
	return (res);
}

int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	prependnode(t_node **lst, t_node *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
	(*lst)->prev = NULL;
}
