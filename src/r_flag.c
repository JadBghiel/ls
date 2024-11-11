/*
** EPITECH PROJECT, 2024
** r_flag
** File description:
** handles the -r flag
*/
#include "../include/my.h"
#include "../include/my_ls.h"
#include "../include/my_flags.h"

void r_flag(DIR *dir)
{
    struct dirent *entry;
    struct dirent *entries[100];
    int count = 0;

    count = store_entries(dir, entries);
    reverse_entries(entries, count);
}

int store_entries(DIR *dir, struct dirent *entries[])
{
    struct dirent *entry;
    int count = 0;

    entry = readdir(dir);
    while (entry != NULL) {
        entries[count] = entry;
        count++;
        entry = readdir(dir);
    }
    return count;
}

void reverse_entries(struct dirent *entries[], int count)
{
    int i;
    struct dirent *temp;

    for (i = 0; i < count / 2; i++) {
        temp = entries[i];
        entries[i] = entries[count - 1 - i];
        entries[count - 1 - i] = temp;
    }
    for (i = 0; i < count; i++) {
        my_putstr(entries[i]->d_name);
        my_putstr("  ");
    }
    my_putchar('\n');
}
