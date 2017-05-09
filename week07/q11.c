#include <stdio.h>

#define MAX_LINE 4096

int
main(void) {
    char line[MAX_LINE];
    int  i;

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        //print reversed line here!
        printf("\n");

    }
    return 0;
}