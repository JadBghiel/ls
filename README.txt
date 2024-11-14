ASK IF THE MAKEFILE IS SUPPOSE TO BE IN /BONUS OR IN THE ROOT unclear
not sure if all throughout the code i have implemented this: Error messages
have to be written on the error output, and the program should then exit
with the 84 error code (0 if there is no error).


KNOWN ISSUES:
- multiple flags doesnt work sometimes?: not sure tho

- the -a flag doesnt sort the thing alphabetically
- the -d flag doesnt work alone without any file specification
- the -r flag works as -r and -a are called (fix: need to skip the hidden files)
- same for the -t flag
- the -t flag and the -r flag show hidden files which is not suppose to happen


- used qsort() instead of custom made lexicographical sorting function (the
qsort still doesnt work as intentded)


TODO:
- implement the -R recursive display subdirectories
- implement the -l use a long display format
- in the a_flag.c eventually have the 50 be remplaced by somethign else like the actual number en entries
- some other place needs the thing above i dont remember where, ENTRIES_COUNT
- stop when there is an unkonw flags
- everthing else that is not after the - is a fodler specifed, 
- basic test are ./my_ls /include SO MAKE sure it works 
-  


TO TEST:
- test if the this syntax works: ls [-alRdrt] [FILE]
- test if its possible to pass a list of files/folders as parameters:


DONE:
- implement the my_ls_basic (without any flags)
- implement the -a display all even hidden files (currently its not alphabetically correct)
- implement the -d display only directories
- implement the -r display with reverse order
- implement the -t sort by modif dates