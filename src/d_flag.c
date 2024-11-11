/*
** EPITECH PROJECT, 2024
** d_flag
** File description:
** handles the -d flag
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

int is_directory(const char *path)
{
    struct stat statbuf;

    if (stat(path, &statbuf) == 0) {
        return S_ISDIR(statbuf.st_mode);
    }
    return 0;
}

void display_directory(const char *path)
{
    my_putstr(path);
    my_putchar('\n');
}

void d_flag(DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] == '.') {
            entry = readdir(dir);
            continue;
        }
        if (is_directory(entry->d_name)) {
            my_putstr(entry->d_name);
            my_putstr("  ");
        }
        entry = readdir(dir);
    }
    my_putchar('\n');
}
