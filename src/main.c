/*
** EPITECH PROJECT, 2024
** main
** File description:
** main file for my_ls project
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

void parse_flags(int argc, char **argv, char *flags)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            get_flag_letters(argc, argv, flags);
        }
    }
}

void parse_dir(int argc, char **argv, char *directories[], int *dir_count)
{
    const char *default_dir = ".";

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            directories[*dir_count] = argv[i];
            (*dir_count)++;
        }
    }
    if (*dir_count == 0) {
        directories[0] = (char *)default_dir;
        *dir_count = 1;
    }
}

void process_directories(int dir_count, char *directories[], char *flags)
{
    for (int i = 0; i < dir_count; i++) {
        my_ls_basic(directories[i], flags);
    }
}

int main(int argc, char **argv)
{
    char flags[7] = {0};
    int dir_count = 0;
    char *directories[argc];

    parse_flags(argc, argv, flags);
    parse_dir(argc, argv, directories, &dir_count);
    process_directories(dir_count, directories, flags);
    return 0;
}
