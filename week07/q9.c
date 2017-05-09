#include <stdio.h>

#define MAX_LINE 4096

int
main(void) {
    char line[MAX_LINE];
    int  i;

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        //Remove comments here!

        // write possibly-modified line
        printf("%s", line);
    }
    return 0;
}