#include "../includes/push_swap.h"

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
    }
}
