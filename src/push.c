#include "../includes/push_swap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	temp = *src;
	(*src) = (*src)->next;
	if (dest == NULL || *dest == NULL)
		temp->next = NULL;
	else
	{
		temp->next = *dest;
		temp->next->prev = temp;
	}
	temp->prev = NULL;
	*dest = temp;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}