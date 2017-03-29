#include <stdio.h>

double max_value(double array[], int length);

int main(void) {
	double array[] = {1.5, 2.5, 3.5};
	double max = max_value(array, 3);
	printf("The max value in [1.5, 2.5, 3.5] is %d", max);
    return 0;
}

double max_value(double array[], int length) {

}