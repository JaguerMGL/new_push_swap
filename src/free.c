#include "../includes/push_swap.h"

void ft_free_double_char(char **lst)
{
    int i;

    i = -1;
    if (lst)
    {
        while (lst[++i])
            free(lst[i]);
    }
    free(lst);
}