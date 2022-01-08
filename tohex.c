#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <math.h>
#define HEX_MAX_SIZE 32

static char backwardsHex[HEX_MAX_SIZE];
static char hex[HEX_MAX_SIZE];
static char backwardsBinairString[HEX_MAX_SIZE];


static void convertToBackwardsHex(int decimal) {
    int dividend;
    int divisor = 16;
    int remainder;
    int counter = 0;
    char hexes[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    dividend = decimal;
    
    while (dividend >= 1) {
        remainder = dividend % divisor;
        backwardsHex[counter] = hexes[remainder];
        dividend = dividend / divisor;
        counter++;
    }

   backwardsHex[counter] = '\0';
}

static void swapBackwardsHex() {
   int i= 0;
   int length = (int)strlen(backwardsHex);
   for(int index = length-1; index >= 0; index--) {
        hex[i] = backwardsHex[index];
        i++;
    }
    hex[i] = '\0';
}
static int convertBinairToDecimal() {
    int decimal = 0;
    int length = (int)strlen(backwardsBinairString);
    
    for (int index = 0; index < length;index++) {
       if (backwardsBinairString[index] == '1')
           decimal += pow(2,index);
    }
    
    return decimal;
}

static void swapBinairStringToBackwards(char * binairString) {
    int length = (int)strlen(binairString);
    int i = 0;
    for (int index = length-1; index >= 0; index-- ) {
        backwardsBinairString[i] = binairString[index];
        i++;
    }
    backwardsBinairString[i] = '\0';
}
char * decimalToHex(int decimal) {
    convertToBackwardsHex(decimal);
    swapBackwardsHex();

    return hex;
}

char * binairToHex(char *binairString) {
    swapBinairStringToBackwards(binairString);
    int decimal = convertBinairToDecimal(backwardsBinairString);
    decimalToHex(decimal);
    
    return hex;
}
