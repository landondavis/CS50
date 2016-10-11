/*
**VIGENERE.C
**Sept. 14, 2016
**CSCI E50 Harvard Extension School, Problem Set 2
*/

/*
**Takes command-line argument string and uses it as a key
**to encrypt the user-input string by pushing characters by
**the key amount (alphabetic index) to return the ciphered text.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    /* *********************************
    INPUT, VALIDATION, & LOCAL VARIABLES
    ************************************/
    // only take 1 word argument/key
    if (argc != 2) 
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    // local variables
    int p, k;
    string key = argv[1];
    int keyLength = strlen(key);
    int keyChar = 0;
    
    // validate arugment/key input as alphabetic
    for (int i=0; i < keyLength; i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    
    // prompt user for plaintext
    printf("plaintext: ");
    string pText = get_string();
    
    /* *********************************
    ENCRYPTION
    ************************************/
    // prepare for output
    printf("ciphertext: ");
    
    // variables for encryption loop
    int pLength = strlen(pText);
    char cText[pLength];
    
    // iterate over characters in plaintext string
    for (int i=0; i < pLength; i++)
    {
        // create alphabetic index for key
        if (isupper(key[keyChar]))
        {
            k = key[keyChar] - 65;
        }
        else if (islower(key[keyChar]))
        {
            k = key[keyChar] - 97;
        }
        
        // create alphabetic index for plaintext
        if (isupper(pText[i]))
        {
            p = pText[i] - 65;
        }
        else if (islower(pText[i]))
        {
            p = pText[i] - 97;
        }
        
        // shift alphabetic plaintext by key and iterate to next key character
        if (isalpha(pText[i]))
        {
            cText[i] = (p + k) % 26;
            keyChar++;
        }
        else
        {
            cText[i] = pText[i];
        }
        
        // reset key string iteration at end of key string
        if (keyChar == keyLength)
        {
            keyChar = 0;
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