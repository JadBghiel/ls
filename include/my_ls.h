/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** header file for my_ls
*/
#ifndef MY_LS_H
    #define MY_LS_H
    #include "my.h"

// custom functions prototype for my_ls
int my_ls_basic(const char *dir_name, const char *flags);
void call_correct_flag(const char *flags, DIR *dir);
void display_dir_entries_default(DIR *dir);

int is_flag_argument(const char *arg);
void process_flags(const char *arg, char *flags, int *flag_index);
void get_flag_letters(int argc, char **argv, char *flags);

void (*resolve_handler(char flag))(DIR *);



struct dirent **allocate_entries_array(DIR *dir, int *entry_count);
void display_sorted_entries(struct dirent **entries, int entry_count);
int compare_entries(const void *a, const void *b);
void a_flag(DIR *dir);


int is_directory(const char *path);
void display_directory(const char *path);
void d_flag(DIR *dir);

void r_flag(DIR *dir);
int store_entries(DIR *dir, struct dirent *entries[]);
void reverse_entries(struct dirent *entries[], int count);




#endif /* MY_LS_H */
