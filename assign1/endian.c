#include <stdio.h>

int main(void)
{
    unsigned int num = 1;
    char* c = (char*) &num; // Takes the 'first' pointer as char
    if (*c == 1) // Does the 'first' mem location have LSB?
        printf("The underlying CPU architecture is Little Endian.\n");
    else
        printf("The underlying CPU architecture is Big Endian.\n");
}
