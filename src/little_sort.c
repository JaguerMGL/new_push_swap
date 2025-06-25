#include "../includes/push_swap.h"

t_node	*find_biggest(t_node *lst)
{
    t_node	*biggest;

    biggest = lst;
    while (lst)
    {
        if (lst->value > biggest->value)
            biggest = lst;
        lst = lst->next;
    }
    return (biggest);
}

t_node	*find_smallest(t_node *lst)
{
	t_node	*smallest;

	smallest = lst;
	while (lst)
	{
		if ((lst)->value < smallest->value)
			smallest = lst;
		lst = (lst)->next;
	}
	return (smallest);
}

void	little_sort_4(t_node **a, t_node **b)
{
    t_node	*biggest;

    biggest = find_biggest(*a);
    move_to_top(a, biggest);
    pb(a, b);
    tiny_sort(a);
    pa(a, b);
    ra(a);
}

static t_node	*find_second_smallest(t_node *a, int min_val)
{
	t_node	*second_smallest;
	t_node	*current;
	int		second_min_val;

	second_smallest = a;
	second_min_val = INT_MAX;
	current = a;
	while (current)
	{
		if (current->value < second_min_val && current->value > min_val)
		{
			second_min_val = current->value;
			second_smallest = current;
		}
		current = current->next;
	}
	return (second_smallest);
}

void	little_sort_5(t_node **a, t_node **b)
{
	t_node	*smallest;
	t_node	*second_smallest;

	smallest = find_smallest(*a);
	second_smallest = find_second_smallest(*a, smallest->value);
	move_to_top(a, smallest);
	pb(a, b);
	move_to_top(a, second_smallest);
	pb(a, b);
	tiny_sort(a);
	pa(a, b);
	pa(a, b);
}
