/*
**CAESAR.C
**Sept. 11, 2016
**CSCI E50 Harvard Extension School, Problem Set 2
*/

/*
**Takes command-line argument integer and uses it as a key
**to encrypt an user-input string by pushing characters by
**the key amount to return the ciphered text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // only take 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    // local variables
    // convert second argument to integer
    int p;
    int k = atoi(argv[1]);

    // prompt user for plaintext
    printf("plaintext: ");
    string pText = get_string();
    
    // prepare for output
    printf("ciphertext: ");
    
    // variables for encryption loop
    int pLength = strlen(pText);
    char cText[pLength];
    
    // iterate over characters in the string
    for (int i=0; i < pLength; i++)
    {
        // create alphabetic index
        if (isupper(pText[i]))
        {
            p = pText[i] - 65;
        }
        else if (islower(pText[i]))
        {
            p = pText[i] - 97;
        }
        
        // shift plaintext by key if alphabetic letter
        if (isalpha(pText[i]))
        {
            cText[i] = (p + k) % 26;
        }
        else
        {
            cText[i] = pText[i];
        }
        
        // convert ciphertext back to ASCII
        if (isupper(pText[i]))
        {
            cText[i] += 65;
        }
            
        else if (islower(pText[i]))
        {
            cText[i] += 97;
        }
        
        // print ciphertext
        printf("%c", cText[i]);
    }
    
    printf("\n");
    return 0;
}