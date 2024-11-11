/*
** EPITECH PROJECT, 2024
** a_flag
** File description:
** handles the -a flag
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

struct dirent **allocate_entries_array(DIR *dir, int *entry_count)
{
    struct dirent *entry;
    struct dirent **entries;

    entries = malloc(50 * sizeof(struct dirent *));
    if (entries == NULL) {
        perror("malloc");
        exit(84);
    }
    *entry_count = 0;
    entry = readdir(dir);
    while (entry != NULL) {
        entries[*entry_count] = entry;
        (*entry_count)++;
        entry = readdir(dir);
    }
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

int compare_entries(const void *a, const void *b)
{
    struct dirent *entry_a = *(struct dirent **)a;
    struct dirent *entry_b = *(struct dirent **)b;

    return my_strcmp(entry_a->d_name, entry_b->d_name);
}

void a_flag(DIR *dir)
{
    int entry_count;
    struct dirent **entries = allocate_entries_array(dir, &entry_count);

    qsort(entries, entry_count, sizeof(struct dirent *), compare_entries);
    display_sorted_entries(entries, entry_count);
    free(entries);
}
