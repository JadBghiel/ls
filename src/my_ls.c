/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** recreate the ls command
*/
#include "../include/my_ls.h"

void display_dir_entries_default(DIR *dir)
{
    struct dirent *entries[ENTRIES_COUNT];
    struct dirent *entry;
    int count = 0;

    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
        entries[count] = entry;
        count++;
        }
    entry = readdir(dir);
    }
    sort_entries_alphabetically(entries, count);
        for (int i = 0; i < count; i++) {
        my_putstr(entries[i]->d_name);
        my_putstr("  ");
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
