/*
**prompt and validate user input
**calculate equivalent bottles
**print equivalent bottles
*/

#include <stdio.h>
#include <cs50.h>

int main(void) {
    int n;
    do {
        printf("enter shower length in minutes: ");
        n = get_int();
    }
    while (n < 0);
    
    printf("minutes: %i\n", n);
    printf("bottles: %i\n", n * 12);
}


