# README #

This prject contains 2 files written in C to convert decimal or binairy numbers to hexadecimal.


### instalation ###

copy the tohex.c and tohex.h to your program's directory and then put

        #include "tohex.h"

into your main file or in the file where you want access the two public functions.

### Usage ###

There are two public functions, one for converting a decimal number to hexadecimal and one to convert a binairy string into hexadecimal.

        char * decimalToHex(int);
        char * binairToHex(char *);

Example call:

        printf("\ndecimal: %d\t\t\tHex: %s\n",255,decimalToHex(255));
        printf("binair: %s\t\tHex: %s\t\t%d\n","11111111",binairToHex("11111111"),255);

That's it.
