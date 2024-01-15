#include "main.h"
#include <stdio.h>
#include <stdlib.h> // Include the standard library header for EXIT_SUCCESS

int _strlen(const char *str); // Declaration of _strlen

int main(void) {
    printf("%d\n", _strlen("My Dyn Lib"));
    return EXIT_SUCCESS; // Use EXIT_SUCCESS instead of just 'EXIT_SUCCESS'
}
