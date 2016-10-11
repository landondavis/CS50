//  /****************************************************
//  * CREDIT.C                                          *
//  * Landon Daivs                                      *
//  * Sept. 6, 2016                                     *
//  * CSCI E50 Harvard Extension School, Problem Set 1  *
//  *****************************************************/                                                  *
 
//  /*
//  **Takes a credit card number and uses a Luhn's Algorithm   
//  **to validate wheter the card is a valid           
//  **AMEX, MASTERCARD, VISA or an INVALID card number.  
//  */
 
#include <stdio.h>

int main(void) {

    //global variables
    long long ccNumber, loopLength;
    int multi, digit1, digit2, add, ccRemain;
    _Bool valid;
    int sum = 0;
    int sumRemain = 0;

    //prompt user for input
    printf("enter credit card number: ");
    scanf("%lld", &ccNumber);
    
    // --------------------------------------------------------
    // Multiply every other digit by 2, starting with the number’s second-to-last digit, 
    // and then add those products' digits together.
    // --------------------------------------------------------
    
    //determine length of card number
    //determine repeat of loop to grab every other number based on number length
    
    //13-digit: execute loop 6x
    if (ccNumber < 1e14 && ccNumber > 1e12) {
        loopLength = 1e11;
    }
    //15-digit: execute loop 7x
    else if (ccNumber < 1e15) {
        loopLength = 1e13;
    }
    //16-digit: execute loop 8x
    else {
        loopLength = 1e15;
    }
    
    for(long long i=10; i<=loopLength; i *= 100) {
        
        //take every other digit and multiply by 2 and store in multi
        multi = 2 * (ccNumber / i % 10);

        //take digits of multi
        if (multi < 10) {
            digit1 = multi % 10;
            digit2 = 0;
        }
        else if (multi > 10) {
            digit1 = 1;
            digit2 = multi % 10;
        }
        else {
            digit1 = 1;
            digit2 = 0;
        }
        
        //add together digits of multi
        add = digit1 + digit2;

        //sum the digits
        sum += add;
        
    // --------------------------------------------------------
    // Add that sum to the sum of the digits that weren’t multiplied by 2
    // --------------------------------------------------------
        //grab remaining credit card numbers if even
        if (loopLength == 1e15) {
            ccRemain = ccNumber / (i / 10) % 10;
            sumRemain += ccRemain;
        }
        
    }
    
    //grab remaining credit card numbers if odd
    if (loopLength == 1e11 || loopLength == 1e13) {
        for (long long a=1; a<loopLength*100; a *= 100) {
            ccRemain = ccNumber / a % 10;
            sumRemain += ccRemain;
        }
    }
    
    int totalSum = sum + sumRemain;
    
    // --------------------------------------------------------
    // If the total’s last digit is 0 the number is valid!
    // --------------------------------------------------------
    if(totalSum % 10 == 0) {
        valid = 1;
    }
    else {
        valid = 0;
    }
    
    // --------------------------------------------------------
    // Validate against card companies' starting digits
    // --------------------------------------------------------
    //if 16-digit, change loopLength to grab the correct digits
    if (loopLength == 1e15) {
        loopLength = 1e14;
    }
    
    //grab first digit
    int firstDigit = ccNumber / (loopLength*10);
    //grab first 2 digits
    int first2Digits = ccNumber / loopLength;
    
    //validate card company
    if (valid == 1) {
        if (firstDigit == 4) {
            printf("VISA\n");
        }
        else if (first2Digits == 34 || first2Digits == 37) {
            printf("AMEX\n");
        }
        else if (first2Digits >= 51 || first2Digits <= 55) {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }

    return 0;
}