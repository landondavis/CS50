/**
 * HELPERS.C
 * Landon Davis
 * Helper functions for Problem Set 3 (find.more).
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // local variables
    int min = 0;
    int max = n - 1;
    
    // while (length of list > 0)
    while (min <= max)
    {
        // look at middle of list
        int median = (min + max) / 2;
    
        // if number found, return true
        if (values[median] == value)
            return true;
            
        // else if number higher, search left
        else if (value < values[median])
            max = median - 1;
            
        // else if number lower, search right
        else if (value > values[median])
            min = median + 1;
    }

    // if number isn't found, return false
    return false;
}

/**
 * Sorts array of n values using a counting sort.
 */
void sort(int values[], int n)
{
    // local variables
    const int range = 65536;
    int count[65536] = {0};
    int final[n];
    
    // create counting array to count number frequencies
    for (int i = 0; i < n; i++)
    {
        count[values[i]]++;
    }
    
    // turn the counting array into a running sum
    // this informs us of each number's relative position
    for (int j = 1; j < range; j++)
    {
        count[j] = count[j - 1] + count[j];
    }
    
    // iterate from end of intial array
    // place initial value in running sum's index position of the final array
    for (int k = n - 1; k >= 0; k--)
    {
        count[values[k]] -= 1;
        final[count[values[k]]] = values[k];
    }
    
    // transfer final, sorted array values back to initial array
    for (int l = 0; l < n; l++)
    {
        values[l] = final[l];
    }
    
    return;
}
