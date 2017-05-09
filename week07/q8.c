#include <stdio.h>

#define MAX_LINE 4096

int
main(void) {
    char line[MAX_LINE];
    int  i;

    FILE *file = fopen("q11.c", 'r');
    //use fgets to get lines into the buffer
    //calculate and print the line length
    while(fgets(line, MAX_LINE, file) != NULL) {
        i = 0;
        while(line[i] != '\0') {
            i = i + 1;
        }
        printf("Line length is %d", i);
    }

    fclose(file);

    return 0;
}