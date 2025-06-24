#include "../includes/push_swap.h"

void check_arg2(char *str)
{
    int i;
    int digit_count;

    i = -1;
    digit_count = 0;
    if (ft_strlen(str) < 1)
        print_error("Error: Empty argument", 1, 1);
    while (str[++i])
    {
        if (is_digit(str[i]))
        digit_count++;
        else if (str[i] != ' ' && str[i] != '-')
        {
            print_error("Error: Invalid character in argument", 1, 1);
        }
        if (str[i] == '-' && (str[i + 1] == '\0' || !is_digit(str[i + 1])))
        print_error("Error: Invalid character in argument", 1, 1);
    }
    if (digit_count == 0)
        print_error("Error: No digits found in argument", 1, 1);
}

void check_all_args(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[++i])
    {
        j = -1;
        while (str[i][++j])
        {
            if (!is_digit(str[i][j]))
            {
                if (str[i][j] == '-')
                {
                    if (str[i][j + 1] == '\0' || !is_digit(str[i][j + 1]))
                        print_error("Error: Invalid character in argument", 1, 1);
                }
                else
                    print_error("Error: Invalid character in argument", 1, 1);
            }
        }
    }
}

int check_space(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (i == 0 && str[i] == ' ')
            return 1;
        if (str[i] == ' ' && str[i + 1] == ' ')
            return 1;
    }
    return 0;    
}

char **check_arg(int ac, char **av)
{
    char *str;
    char **res;

    res = NULL;
    str = NULL;
    if (ac == 2)
    {
        check_arg2(av[1]);
        str = ft_strdup(av[1]);
    }
    else
    {
        check_all_args(av);
        str = ft_join_all(ac, av);
    }
    if(check_space(str))
    {
        free(str);
        return NULL;
    }
    res = ft_split(str, ' ');
    return res;
}