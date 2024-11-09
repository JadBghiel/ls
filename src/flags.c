/*
** EPITECH PROJECT, 2024
** flags
** File description:
** handles the different flags for my_ls
*/
#include "../include/my.h"
#include "../include/my_ls.h"

void handle_a_flag(int *show_hidden)
{
    *show_hidden = 1;
}

void handle_d_flag(int *show_dir)
{
    *show_dir = 1;
}

int is_dir(const char *path)
{
    struct stat file_stat;

    if (stat(path, &file_stat) != 0) {
        return 0;
    }
    return S_ISDIR(file_stat.st_mode);
}

// is_dir() returns 0 if its NOT a dir and returns 1 if it is a dir
