#include <stdio.h>

int main(void) {
    double area, length, width;
    
    printf("Please enter rectangle length: ");
    scanf("%lf", &length);
    
    printf("Please enter rectangle width: ");
    scanf("%lf", &width);
    
    area = length*width;
    
    printf("Area =  %20.2lf\n", area);

    return 0;
}