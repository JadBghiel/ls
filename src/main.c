/*
** EPITECH PROJECT, 2024
** main
** File description:
** main file for my_ls project
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

int main(int argc, char **argv)
{
    const char *dir_name = ".";
    char flags[7] = {0};

    if (argc == 1) {
        my_putstr("no flags passed so displaying current dir:\n");
        my_ls_basic(dir_name, NULL);
    } else {
        get_flag_letters(argc, argv, flags);
        my_putstr("flags passed:");
        my_putstr(flags);
        my_putchar('\n');
        my_ls_basic(dir_name, flags);
    }
    return 0;
}
