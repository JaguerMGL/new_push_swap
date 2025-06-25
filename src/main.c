#include "../includes/push_swap.h"

int main (int ac, char **av)
{
    char **lst;
    t_node *a;
    t_node *b;

    a = NULL;
    b = NULL;

    if (ac == 1 || !av[1][0])
        return 0;
    lst = check_arg(ac, av);
    if (!lst)
        print_error("Error: invalid argument", 1);
    a = init_stack(lst);
    if (!is_sorted(a))
    push_swap(&a, &b);
    // print_stack(a);
    return 0;
}
