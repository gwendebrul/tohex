#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define HEX_MAX_SIZE 32

static char backwards_hex[HEX_MAX_SIZE];
static char hex[HEX_MAX_SIZE];
static char backwards_binair_string[HEX_MAX_SIZE];

static void ToUpper(char *s) {
    for (int i = 0; *s; ++s )
        s[i] = toupper(s[i]);
}

static void ConvertToBackwardsHex(int decimal) {
    int dividend;
    int divisor = 16;
    int remainder;
    int counter = 0;
    char hexes[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    dividend = decimal;
    
    while (dividend >= 1) {
        remainder = dividend % divisor;
        backwards_hex[counter] = hexes[remainder];
        dividend = dividend / divisor;
        counter++;
    }

   backwards_hex[counter] = '\0';
}

static void SwapBackwardsHex(void) {
   int i= 0;
   int length = (int)strlen(backwards_hex);
   for(int index = length-1; index >= 0; index--) {
        hex[i] = backwards_hex[index];
        i++;
    }
    hex[i] = '\0';
}
static int ConvertBinairToDecimal(void) {
    int decimal = 0;
    int length = (int)strlen(backwards_binair_string);
    
    for (int index = 0; index < length;index++) {
       if (backwards_binair_string[index] == '1')
           decimal += pow(2,index);
    }
    
    return decimal;
}

static void SwapBinairStringToBackwards(char * binair_string) {
    int length = (int)strlen(binair_string);
    int i = 0;
    for (int index = length-1; index >= 0; index-- ) {
        backwards_binair_string[i] = binair_string[index];
        i++;
    }
    backwards_binair_string[i] = '\0';
}

static int GetIndexOfHexes(char *hex_character) {
    char hexes[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int i = 0;
    
    for (i = 0; i <= 16; i++) {
        if (hexes[i] == *hex_character)
            return i;
    }
    
    return 0;
}

static int ConvertHexToDecimalString(char *hex_string) {
    int length = (int)strlen(hex_string);
    ToUpper(hex_string);
    int i = 0;
    int decimal = 0;
    int hex_value = 0;
    
    for (int index = length-1; index >= 0; index--) {
        hex_value = GetIndexOfHexes(&hex_string[index]);
        decimal += hex_value * pow(16, i);
        i++;
    }
    
    return decimal;
}

char * gdb_DecimalToHex(int decimal) {
    ConvertToBackwardsHex(decimal);
    SwapBackwardsHex();

    return hex;
}

char * gdb_BinairToHex(char *binair_string) {
    SwapBinairStringToBackwards(binair_string);
    int decimal = ConvertBinairToDecimal();
    gdb_DecimalToHex(decimal);
    
    return hex;
}

int gdb_HexToDecimal(char *hex_string) {
     // In windows Visual Studio strlen must be replaced with sizeof
     char hex[strlen(hex_string)];
     // In windows Visual Studio strncpy must be replaced with strncpy_s
     //strncpy_s(hex, sizeof(char*), hex_string, strlen(hex_string));
     strncpy(hex, hex_string, strlen(hex));
     int decimal = ConvertHexToDecimalString(hex);
    
    return decimal;
}
