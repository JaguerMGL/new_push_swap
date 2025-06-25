#include "../includes/push_swap.h"

int	ft_lstlen(t_node *lst)
{
	struct s_node	*ptr;
	int				i;

	if (lst == NULL)
		return (0);
	ptr = lst->next;
	i = 1;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	move_to_top(t_node **stack, t_node *target)
{
    int	len;
    int	pos;
    t_node	*current;

    len = ft_lstlen(*stack);
    pos = 0;
    current = *stack;
    while (current && current != target)
    {
        current = current->next;
        pos++;
    }
    if (pos <= len / 2)
    {
        while (pos-- > 0)
            ra(stack);
    }
    else
    {
        while (pos++ < len)
            rra(stack);
    }
}
