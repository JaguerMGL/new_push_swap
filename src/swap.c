#include "../includes/push_swap.h"

static void	swap(t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
		
	first = *lst;
	second = (*lst)->next;
	
	// Échanger les deux premiers nœuds
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
		
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	
	*lst = second;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}