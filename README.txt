KNOWN ISSUES:
- the -r flag shows all file in reverse order (as opposed to just the not hidden files)
- multiple flags doesnt work sometimes?:
    the -d and -a skip an extra line
    more generally, when 2 flags are specified its skips one extra line
    the -da dont work the same as -and
    maybe the issue is in the main
    the -r flag print as if the -a was specified
- the void display_directory() function in the d_flag file is maybe useless
- the main have coding style issue
- the _a flag doesnt sort the thing alphabetically
- used qsort() instead of custom made lexicographical sorting function


TODO:
- implement the -t sort by modif dates
- implement the -R recursive display subdirectories
- implement the -l use a long display format
- in the a_flag.c eventually have the 50 be remplaced by somethign else like the actual number en entries
- some other place needs the thing above i dont remember where

DONE:
- implement the my_ls_basic (without any flags)
- implement the -a display all even hidden files (currently its not alphabetically correct)
- implement the -d display only directories
- implement the -r display with reverse order
