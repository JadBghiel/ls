/*
** EPITECH PROJECT, 2024
** r_uppercase_flag
** File description:
** handles the -R flag
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

void build_path(const char *parent, const char *name, char *result)
{
    int i = 0;
    int j = 0;

    while (parent[i] != '\0') {
        result[i] = parent[i];
        i = i + 1;
    }
    result[i] = '/';
    i = i + 1;
    while (name[j] != '\0') {
        result[i] = name[j];
        i = i + 1;
        j = j + 1;
    }
    result[i] = '\0';
}

void format_directory_name(const char *dir_name, char *result)
{
    int i = 0;
    int j = 0;

    result[0] = '.';
    result[1] = '/';
    i = my_strlen(dir_name) - 1;
    while (i >= 0 && dir_name[i] != '/') {
        i--;
    }
    i++;
    j = 2;
    while (dir_name[i] != '\0') {
        result[j] = dir_name[i];
        i++;
        j++;
    }
    result[j] = '\0';
}

void list_subdirectories(const char *dir_name)
{
    DIR *dir;
    struct dirent *entry;
    char new_path[ENTRIES_COUNT];

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.' && is_directory(entry->d_name)) {
            my_putchar('\n');
            build_path(dir_name, entry->d_name, new_path);
            list_directory_recursive(new_path);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}

void list_directory_recursive(const char *dir_name)
{
    DIR *dir;
    char formatted_dir[ENTRIES_COUNT];

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    if (my_strcmp(dir_name, ".") == 0) {
        my_putstr(".:\n");
    } else {
        format_directory_name(dir_name, formatted_dir);
        my_putstr(formatted_dir);
        my_putstr(":\n");
    }
    display_dir_entries_default(dir);
    list_subdirectories(dir_name);
    closedir(dir);
}

void r_uppercase_flag(DIR *dir)
{
    list_directory_recursive(".");
}
