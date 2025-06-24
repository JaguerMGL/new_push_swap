#include "../includes/push_swap.h"

void print_error(const char *str, int flag, int time_to_leave)
{
    int i;

    i = -1;
    if (!str || str[0] == '\0')
        return;
    while (str[++i] != '\0')
        write(2, &str[i], 1);
    if (flag == 1)
        write(2, "\n", 1);
    if (time_to_leave == 1)
        exit(1);
}