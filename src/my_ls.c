/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** recreate the ls command
*/
#include "../include/my.h"
#include "../include/my_ls.h"

int display_entry(const struct dirent *entry, int show_hidden, int show_dir)
{
    if (show_hidden || entry->d_name[0] != '.') {
        if (!show_dir || is_dir(entry->d_name)) {
            return 1;
        }
    }
    return 0;
}

void display_dir_entries(DIR *dir, int show_hidden, int show_dir)
{
    struct dirent *entry = readdir(dir);

    while (entry != NULL) {
        if (display_entry(entry, show_hidden, show_dir)) {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
        entry = readdir(dir);
    }
}

int my_ls_basic(const char *dir_name, int show_hidden, int show_dir)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return 84;
    }
    display_dir_entries(dir, show_hidden, show_dir);
    if (closedir(dir) == -1) {
        perror("closedir");
        return 84;
    }
    return 0;
}
