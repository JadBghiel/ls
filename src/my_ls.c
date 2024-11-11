/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** recreate the ls command
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

void display_dir_entries_default(DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] == '.') {
            entry = readdir(dir);
            continue;
        }
        my_putstr(entry->d_name);
        my_putstr("  ");
        entry = readdir(dir);
    }
    my_putchar('\n');
}

void call_correct_flag(const char *flags, DIR *dir)
{
    void (*handler)(DIR *);

    for (int i = 0; flags[i] != '\0'; i++) {
        handler = resolve_handler(flags[i]);
        if (handler != NULL) {
            handler(dir);
        } else {
            my_putstr("Error: Unknown flag\n");
        }
    }
}

int my_ls_basic(const char *dir_name, const char *flags)
{
    DIR *dir;

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return 84;
    }
    if (flags == NULL || flags[0] == '\0') {
        display_dir_entries_default(dir);
    } else {
        call_correct_flag(flags, dir);
        }
    if (closedir(dir) == -1) {
        perror("closedir");
        return 84;
    }
    return 0;
}
