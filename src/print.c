#include "../includes/push_swap.h"

void print(char *msg)
{
    write(1, msg, ft_strlen(msg));
}

void print_error(char *msg, int flag)
{
    write(2, msg, ft_strlen(msg));
    if (flag)
        exit(1);
}