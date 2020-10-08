// Randstring.c
// Last edit 02.12.2019
// final edit and release 08.10.2020

/*
 *  Randstring.c:  Fully automated string generator (linux based)
 *
 *  Copyright Magnus Danielsen (18 February 2019-2020)
 *
 *  This program is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free Software
 *  Foundation, version 2.
 *
 */

// INCLUDES
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rand_str(char *, size_t);
int main(void) {
    char str[] = { [] = '\1' }; // make the last character non-zero so we can test based on it later
    rand_str(str, sizeof str - 1);
    assert(str[26] == '\0');  // test the correct insertion of string terminator
    puts(str);
}

void rand_str(char *dest, size_t length) {   //generates a random string using the charset
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "+=&%¤#@£$€*<>-.,_";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}
// END
