/*
** EPITECH PROJECT, 2024
** r_uppercase_flag
** File description:
** handles the -R flag
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

void list_directory_recursive(const char *dir_name)
{
    DIR *dir = opendir(dir_name);
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        return;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        my_putstr(entry->d_name);
        if (is_directory(entry->d_name)) {
            my_putstr(entry->d_name);
            list_directory_recursive(entry->d_name);
        }
    }
    closedir(dir);
}

void display_recursive(DIR *dir)
{
    struct dirent *entry;

    my_putstr(entry->d_name);
        if (is_directory(entry->d_name)) {
            my_putstr("./");
            my_putstr(entry->d_name);
            my_putchar(':');
            my_putchar('\n');
            list_directory_recursive(entry->d_name);
            my_putstr("  ");
        }
}

void r_uppercase_flag(DIR *dir)
{
    struct dirent *entry;
    char current_dir[ENTRIES_COUNT];

    getcwd(current_dir, sizeof(current_dir));
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] == '.') {
            entry++;
            continue;
        }
        display_recursive(dir);
    }
    my_putchar('\n');
}

