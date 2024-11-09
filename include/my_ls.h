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
int my_ls_basic(const char *dir_name, int show_hidden, int show_dir);
int display_entry(const struct dirent *entry, int show_hidden, int show_dir);
void display_dir_entries(DIR *dir, int show_hidden, int show_dir);
void handle_a_flag(int *show_hidden);
void handle_d_flag(int *show_dir);
int is_dir(const char *path);
#endif /* MY_LS_H */
