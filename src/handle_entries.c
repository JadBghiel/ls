/*
** EPITECH PROJECT, 2024
** allocate_entries
** File description:
** allocate entries and skip hidden files (used in -t flag)
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

struct dirent **allocate_entries_array_basic(DIR *dir, int *entry_count)
{
    struct dirent *entry;
    struct dirent **entries = malloc(ENTRIES_COUNT * sizeof(struct dirent *));
    int count = 0;

    if (entries == NULL) {
        return NULL;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
            entries[count] = entry;
            count++;
        }
        entry = readdir(dir);
    }
    *entry_count = count;
    return entries;
}

void display_sorted_entries(struct dirent **entries, int entry_count)
{
    for (int i = 0; i < entry_count; i++) {
        my_putstr(entries[i]->d_name);
        my_putstr("  ");
    }
    my_putchar('\n');
}

int strcmp_nodot(char const *s1, char const *s2)
{
    if (s1[0] == '.') {
        s1++;
    }
    if (s2[0] == '.') {
        s2++;
    }
    return my_strcmp(s1, s2);
}

int sort_pass(struct dirent **entries, int count)
{
    int swapped = 0;
    struct dirent *temp;

    for (int i = 0; i < count - 1; i++) {
        if (strcmp_nodot(entries[i]->d_name, entries[i + 1]->d_name) > 0) {
            temp = entries[i];
            entries[i] = entries[i + 1];
            entries[i + 1] = temp;
            swapped = 1;
        }
    }
    return swapped;
}

void sort_entries_alphabetically(struct dirent **entries, int count)
{
    int swapped;

    do {
        swapped = sort_pass(entries, count);
    } while (swapped);
}
