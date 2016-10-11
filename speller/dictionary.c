/**
 * DICTIONARY.C
 * Landon Davis
 * CSCI E50 Harvard Extension School, Problem Set 5
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

/**
 * Global variables
 */
char word[LENGTH + 1];
unsigned int words;

// define node structure for linked lists
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// define hashtable, with tested size for optimal speed
#define HASHMAX 50000
node *hashTable[HASHMAX] = {NULL};


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    
    // pointer that points to appropriate bucket in dictionary hashtable
    const unsigned int index = hash(word);
    node *cursor = hashTable[index];
    
    // iterate through linked list
    while (cursor != NULL)
    {
        // if words match, return true
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // if no match, move on to next node
        cursor = cursor->next;
    }
    
    // no match
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open dictionary for reading
    FILE *dFile = fopen(dictionary, "r");
    if (dFile == NULL)
    {
        return false;
    }
    
    // scan and store words in dictionary
    while (fscanf(dFile, "%s", word) != EOF)
    {
        // allocate memory for nodes
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            unload();
            return false;
        }
        
        // copy word into node
        strcpy(newNode->word, word);
        
        // track word count
        words++;
        
        // hash for index
        unsigned int index = hash(word);
        
        // put node into linked list
        // insert node at hashtable index if empty
        if (hashTable[index] == NULL)
        {
            hashTable[index] = newNode;
            newNode->next = NULL;
        }
        // insert node to beginning of linked list if not empty
        else
        {
            newNode->next = hashTable[index];
            hashTable[index] = newNode;
        }
    }
    
    fclose(dFile);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return word count from load function
    return words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < HASHMAX; i++)
    {
        // pointer to linked lists
        node *head = hashTable[i];
        
        // iterate through linked list
        while (head != NULL)
        {
            // pointers to current and next node
            node *temp = head;
            head = head->next;
            
            // free current node
            free(temp);
        }
        
        // clear hashtable buckets
        hashTable[i] = NULL;
    }
    
    return true;
}

/**
 * Hash function
 */
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    
    // first letter influences distribution spread
    const unsigned int firstLetter = (toupper(word[0]) * 100);
    
    // sums ASCII values and adds first letter modifier
    for(int i = 0; word[i] != '\0'; i++)
    {
        hash += toupper(word[i]) + firstLetter;
    }
    return hash % HASHMAX;
}