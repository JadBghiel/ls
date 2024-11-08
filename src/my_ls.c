/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** recreate the ls command
*/
#include "../include/my.h"
#include "../include/my_ls.h"

void display_directory_entries(DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
    if (entry->d_name[0] != '.') {
        my_putstr(entry->d_name);
        my_putchar('\n');
    }
    entry = readdir(dir);
    }
}

int my_ls_basic(const char *dir_name)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return 84;
    }
    display_directory_entries(dir);
    if (closedir(dir) == -1) {
        perror("closedir");
        return EXIT_FAILURE;
    }
    return 0;
}
