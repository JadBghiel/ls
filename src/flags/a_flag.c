/*
** EPITECH PROJECT, 2024
** a_flag
** File description:
** handles the -a flag
*/
#include "../../include/my_ls.h"

void process_entries(DIR *dir, struct dirent *entries[], int *count)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
        if ((entry->d_name[0] == '.' &&
            (entry->d_name[1] == '\0' ||
            (entry->d_name[1] == '.' && entry->d_name[2] == '\0')))) {
            entries[*count] = entry;
            (*count)++;
        } else {
            entries[*count] = entry;
            (*count)++;
        }
        entry = readdir(dir);
    }
}

void a_flag(DIR *dir)
{
    struct dirent *entries[ENTRIES_COUNT];
    int count = 0;

    process_entries(dir, entries, &count);
    sort_entries_alphabetically(entries, count);
    for (int i = 0; i < count; i++) {
        my_putstr(entries[i]->d_name);
        my_putstr("  ");
    }
    my_putchar('\n');
}
