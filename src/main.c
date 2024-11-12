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
        printf("No flags passed. Displaying current directory:\n");
        my_ls_basic(dir_name, NULL);
    } else {
        get_flag_letters(argc, argv, flags);
        printf("Testing flags:\n");
        printf("Flags passed: %s\n", flags);
        my_ls_basic(dir_name, flags);
    }
    return 0;
}
