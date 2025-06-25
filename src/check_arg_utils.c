#include "../includes/push_swap.h"

void ft_free_reorg(char *str)
{
    if (str)
        free(str);
    print_error("Error: malloc failed", 1);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

char *ft_strdup(char *str)
{
    int i;
    char *res;

    i = -1;
    res = NULL;
    res = malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!res)
        return NULL;
    while (++i < ft_strlen(str))
        res[i] = str[i];
    res[i] = '\0';
    return res;
}

char *ft_join_all(int ac, char **av)
{
    int i;
    char *res;

    i = 0;
    res = NULL;
    while (++i < ac)
    {
        res = ft_strjoin(res, av[i]);
        if (res == NULL)
            ft_free_reorg(res);
        res = ft_strjoin(res, " ");
        if (res == NULL)
            ft_free_reorg(res);
    }
    return res;
}