# 42_cursus_get_next_line

The get next line function returns line by line from a descriptor. 

It uses a Buffer [BUFFER_SIZE] variable which determiner the amount of characters which the script will read on each 'read' call.

The BUFFER_SIZE must be set at compiling ex: `gcc -D BUFFER_SIZE=4 *.c *.h` or set in the variable SIZE of the Makefile.


### Dependencies 
- unistd.h
- stdlib.h
- stdio.h
