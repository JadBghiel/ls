/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** header for the struct and the flags
*/
#ifndef MY_FLAGS_H
    #define MY_FLAGS_H
    #include "my.h"
    #include "my_ls.h"

const void (*flag_handlers[])(DIR *) = {
    a_flag, // -a
    d_flag, // -d
    r_flag, // -r
    t_flag, // -t
    r_uppercase_flag, // -R
//    l_flag  // -l
};

#endif /* MY_FLAGS_H */
