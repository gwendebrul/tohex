# README #

This prject contains 2 files written in C to convert decimal or binairy numbers to hexadecimal.


### instalation ###

copy the tohex.c and tohex.h to your program's directory and then put

        #include "tohex.h"

into your main file or in the file where you want access the two public functions.

### Usage ###

There are 3 public functions, one for converting a decimal number to hexadecimal, one to convert a binairy string into hexadecimal and one to convert a hexadecimal string into a decimal value.

        char * gdb_decimalToHex(int);
        char * gdb_binairToHex(char *);
        int gdb_HexToDecimal(char *);

Example call:

        gdb_DecimalToHex(255)       ; This returns FF as a string
        gdb_BinairToHex("11111111") ; This also returns FF as a string
		gdb_HexToDecimal("ac")	   ; This returns 172
		  

This code is tested on XCode on macos, for windows Visual Studio you should fix two errors. The fix is documented in the tohex.c file.

That's it.
