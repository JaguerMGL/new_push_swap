#include "../includes/checker.h"

void	sa_silent(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
		
	first = *a;
	second = (*a)->next;
	
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
		
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	
	*a = second;
}

void	sb_silent(t_node **b)
{
	sa_silent(b);
}

void	ss_silent(t_node **a, t_node **b)
{
	sa_silent(a);
	sa_silent(b);
}

void	ra_silent(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = find_last_node(*a);
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rb_silent(t_node **b)
{
	ra_silent(b);
}

void	rr_silent(t_node **a, t_node **b)
{
	ra_silent(a);
	ra_silent(b);
}

void	rra_silent(t_node **a)
{
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = find_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
}

void	rrb_silent(t_node **b)
{
	rra_silent(b);
}

void	rrr_silent(t_node **a, t_node **b)
{
	rra_silent(a);
	rra_silent(b);
}

void	pa_silent(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
}

void	pb_silent(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	tmp->prev = NULL;
	*b = tmp;
}
