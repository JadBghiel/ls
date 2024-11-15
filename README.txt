ASK IF THE MAKEFILE IS SUPPOSE TO BE IN /BONUS OR IN THE ROOT unclear
not sure if all throughout the code i have implemented this: Error messages
have to be written on the error output, and the program should then exit
with the 84 error code (0 if there is no error).


KNOWN ISSUES:
- with multiple flags sometimes an extra line is skipped
- regular my_ls doesnt show in the right order
- ./my_ls -a -r include/ have the dots at the begining instead of at the end (alphabetical issue with -a)
- ./my_ls -r -a include/ doesnt show hidden files 




//- multiple flags doesnt work sometimes?: not sure tho
//- the -a flag doesnt sort the thing alphabetically (this issue affect -r)
//- the -d flag doesnt work alone without any file specification
//- the flag_handler array is not suppose to be in a src file, but when i put it in
//the header it compile properly 




TODO:
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
- implement the -R recursive display subdirectories


_______________________________________________________________________________



TO TEST further:

with -t flag and a directory:
./my_ls -t include/
./my_ls include/ -t

with -t and -r flags:
./my_ls -t -r include/
./my_ls -r -t include/
./my_ls include/ -r -t

with -t and -a flags:
./my_ls -t -a include/
./my_ls -a -t include/
./my_ls include/ -a -t

multiple flags with files/folders:
./my_ls -r -t include/
./my_ls -r -a -t include/
./my_ls -a -r -t include/
./my_ls -a -r include/ -t

multiple directories and flags:
./my_ls -a include/ src/
./my_ls src/ include/ -a
./my_ls -r src/ include/
./my_ls -r -a src/ include/

flags before files/folders and multiple dir:
./my_ls -r -a include/ src/
./my_ls -t src/ include/
./my_ls -r -a -t include/ src/

testing with no files/folders, only flags:
./my_ls -a
./my_ls -r
./my_ls -t
./my_ls -r -a
./my_ls -a -r


using multiple files/folders in any order:
./my_ls src/ include/ main.c
./my_ls include/ src/ main.c

testing the default directory (.) with flags:
./my_ls -r -a .
./my_ls -a . -r