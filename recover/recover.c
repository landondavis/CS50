/**
 * RECOVER.C
 * Landon Davis
 * CSCI E50 Harvard Extension School, Problem Set 4
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }
    
    // open memory card file
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    // local variables
    const int block = 512;
    FILE *img = NULL;
    unsigned char buffer[512] = {0};
    char fileName[8];
    int fileCount = 0;
    
    // repeat until end of file (able to read one full block)
    while (fread(&buffer, block, 1, inptr) == 1)
    {
        // start of new JPEG
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff && 
            (buffer[3] & 0xf0) == 0xe0)
        {
            // close file if open
            if (img != NULL)
            {
                fclose(img);
            }
            
            // create filename for JPEG
            sprintf(fileName, "%03i.jpg", fileCount);
            
            // open JPEG file
            img = fopen(fileName, "w");
            
            // increment file number
            fileCount++;
        }
        
        // write block into jpeg file if part of JPEG
        if (img != NULL)
        {
            fwrite(&buffer, block, 1, img);
        }
    }
    
    // close files
    fclose(inptr);
    fclose(img);
    
    return 0;
}