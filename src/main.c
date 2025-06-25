#include "../includes/push_swap.h"

int main (int ac, char **av)
{
    char **lst;

    if (ac == 1 || !av[1][0])
        return 0;
    lst = check_arg(ac, av);
    if (!lst)
        print_error("Error: invalid argument", 1);
    return 0;
}
