#include <stdio.h>

int main(void) {
	double fahrenheit;
	printf("Enter temp in fahrenheit:");
	scanf("%lf", &fahrenheit);

	double celsius = 5/9.0*(fahrenheit - 32);

	printf("%lf\n", celsius);

	return 0;
}