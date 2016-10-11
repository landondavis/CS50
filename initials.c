/*
**INITIALS.C
**Sept. 10, 2016
**CSCI E50 Harvard Extension School, Problem Set 2
*/

/*
**Takes a name input and prints the
**initials of the words.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(void)
{

    // get user input
    string name = get_string();
    
    // print first character if not a space
    if (name[0] != 32)
    {
        printf("%c", toupper(name[0]));
    }
    
    // iterate through string
    for(int i=0, n = strlen(name); i < n; i++)
    {
        // print first character after space
        if (name[i] == 32 && name[i + 1] >= 'A' && name[i + 1] <= 'z')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
        
    // new line
    printf("\n");
    return 0;
}