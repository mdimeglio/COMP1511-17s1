#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int c;
    int digitCount, digitSum;

    digitCount = 0;
    digitSum = 0;

    c = getchar();
    while(c != EOF) {
    	if ('0' <= c && c <= '9') {
    		digitCount = digitCount + 1;
    		digitSum = digitSum + c - '0';
    	}
    	c = getchar();
    }
    // CODE HERE
    printf("Input contained %d digits which summed to %d\n", digitCount, digitSum);
    return 0;
}