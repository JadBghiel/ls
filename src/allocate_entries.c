/*
** EPITECH PROJECT, 2024
** allocate_entries
** File description:
** allocate entries for the -t flag (and skips hidden files)
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
