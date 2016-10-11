/*
**prompt and validate user input
**draw the pyramid
*/

#include <stdio.h>
#include <cs50.h>

int main(void) {
    //prompt and validate user input
    int height;
    do {
        printf("enter height of pyramids: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    
    //draw the pyramid
    for (int i=0; i < height; i++) {
        //print spaces for left pyramid
        for (int s=1; s<height-i; s++) {
            printf(" ");
        }
        //print hashes for left pyramid
        for (int hleft=height-1; hleft<height+i; hleft++) {
            printf("#");
        }
        //print gap
        printf("  ");
        //print hashes for right pyramid
        for (int hright=height-1; hright<height+i; hright++) {
            printf("#");
        }
        //print new line
        printf("\n");
    }
}