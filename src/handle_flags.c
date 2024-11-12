/*
** EPITECH PROJECT, 2024
** flags
** File description:
** handles the different flags for my_ls
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

const void (*flag_handlers[])(DIR *) = {
    a_flag, // -a
    d_flag, // -d
    r_flag, // -r
    t_flag, // -t
//    r_uppercase_flag, // -R
//    l_flag  // -l
};

int is_flag_argument(const char *arg)
{
    int len = my_strlen(arg);

    return (arg[0] == '-' && len > 1);
}

void process_flags(const char *arg, char *flags, int *flag_index)
{
    int len = my_strlen(arg);

    for (int j = 1; j < len; j++) {
        flags[*flag_index] = arg[j];
        (*flag_index)++;
    }
}

void get_flag_letters(int argc, char **argv, char *flags)
{
    int flag_index = 0;
    int is_flag;

    for (int i = 1; i < argc; i++) {
        is_flag = is_flag_argument(argv[i]);
        if (is_flag) {
            process_flags(argv[i], flags, &flag_index);
        }
    }
    flags[flag_index] = '\0';
}

void (*resolve_handler(char flag))(DIR *)
{
    const char *flags = "adrtRl";

    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == flag) {
            return flag_handlers[i];
        }
    }
    return NULL;
}
