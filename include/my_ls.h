/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** header file for my_ls
*/
#ifndef MY_LS_H
    #define MY_LS_H
    #include "my.h"

typedef struct {
    int show_all;       // -a
// add the others flags here

} ls_options_t;

// custom functions prototype
int my_ls_basic(const char *dir_name);
void display_directory_entries(DIR *dir);



#endif /* MY_LS_H */
