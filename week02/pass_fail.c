#include <stdio.h>

int main(void) {
    int mark;
    
    printf("Please enter your mark:");
    scanf("%d", &mark);
    
    if (mark >= 50 && mark <= 100) {
        printf("PASS");
    } else if (mark >= 0 && mark < 50) {
        printf("FAIL");
    } else {
        printf("ERROR");
    }
    
    printf("\n");
    

    return 0;
}