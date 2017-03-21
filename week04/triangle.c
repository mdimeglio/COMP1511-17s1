#include <stdio.h>

int main(void) {
    int number;
    int x, y;

    // Obtain input
    printf("Enter size: ");
    scanf("%d", &number);

    y = number -1;
    while(y >= 0) {
        //print row
        x = 0;
        while (x <= number - 1) {
            if (x >= y) {
                printf("*");
            } else {
                printf("-");
            }

            x = x + 1;

        }

        printf("\n");
        y = y -1;
    }


    return 0;
}