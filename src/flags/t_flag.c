/*
** EPITECH PROJECT, 2024
** t_flag
** File description:
** handles the -t flag
*/
#include "../../include/my_ls.h"

int compare_time(time_t time1, time_t time2)
{
    if (time1 < time2) {
        return -1;
    }
    if (time1 > time2) {
        return 1;
    }
    return 0;
}

void swap_entries(struct dirent **entries, int i, int j)
{
    struct dirent *temp = entries[i];

    entries[i] = entries[j];
    entries[j] = temp;
}

int compare_and_swap(struct dirent **entries, int j)
{
    struct stat stat1;
    struct stat stat2;

    stat(entries[j]->d_name, &stat1);
    stat(entries[j + 1]->d_name, &stat2);
    if (compare_time(stat1.st_mtime, stat2.st_mtime) < 0) {
        swap_entries(entries, j, j + 1);
        return 1;
    }
    return 0;
}

void sort_entries_by_time(struct dirent **entries, int entry_count)
{
    int swapped;

    for (int i = 0; i < entry_count - 1; i++) {
        swapped = 0;
        for (int j = 0; j < entry_count - i - 1; j++) {
            swapped |= compare_and_swap(entries, j);
        }
        if (!swapped) {
            break;
        }
    }
}

void t_flag(DIR *dir)
{
    int entry_count = 0;
    struct dirent **entries = allocate_entries_array_basic(dir, &entry_count);

    if (entries == NULL) {
        return;
    }
    sort_entries_by_time(entries, entry_count);
    display_sorted_entries(entries, entry_count);
    free(entries);
}
