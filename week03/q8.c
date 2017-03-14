#include <stdio.h>

int main(void) {
    int number = 1023;
    
    while(number > 0) {
        int lastDigit = number %10;
        printf("%d \n", lastDigit);
        number = number / 10;
    }
    return 0;
}
