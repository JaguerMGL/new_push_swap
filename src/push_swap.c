#include "../includes/push_swap.h"

void	last_manip(t_node **a)
{
	t_node	*smallest;
	int		la;

	la = ft_lstlen(*a);
	set_index(*a);
	is_median(*a);
	smallest = find_smallest(*a);
	if (smallest->index == 0)
		return ;
	else
	{
		if (smallest->above_median)
			full_rra(a, la - smallest->index);
		else
			full_ra(a, smallest->index);
	}
}

void	little_sort(t_node **a, t_node **b)
{
    int	len;

    len = ft_lstlen(*a);
    if (len == 4)
        little_sort_4(a, b);
    else if (len == 5)
        little_sort_5(a, b);
}

void push_b(t_node **a, t_node **b)
{
    float   average;
	int	rotations;
	int	max_rotations;
    
	while (ft_lstlen(*a) > 5)
	{
		average = calculate_average(*a);
		rotations = 0;
		max_rotations = ft_lstlen(*a);
		while ((*a)->value >= average && rotations < max_rotations)
		{
            ra(a);
			rotations++;
		}
		pb(a, b);
        set_size(a, ft_lstlen(*a));
        set_size(b, ft_lstlen(*b));
	}
    if (!is_sorted(*a))
        little_sort_5(a, b);
    
}

void set_nodes(t_node **a, t_node **b)
{
    set_index(*a);
    set_index(*b);
    is_median(*a);
    is_median(*b);
    set_target(a, b);
    set_price(a, b);
}

void  push_swap(t_node **a, t_node **b)
{
    (void)b;
    
    if (!a || !*a)
        return;
    if ((*a)->size <= 3)
        tiny_sort(a);
    else if ((*a)->size < 6)
        little_sort(a, b);
    else
    {
        push_b(a, b);
        while (ft_lstlen(*b) > 0)
        {
            set_nodes(a, b);
            set_top(a, b, find_cheapest(b));
            pa(a, b);
        }
        last_manip(a);
    }
}
