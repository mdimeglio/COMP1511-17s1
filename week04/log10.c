#include <stdio.h>

int main(void) {
	int n, log10;
	
	printf("Enter an integer:");

	if (scanf("%d", &n) != 1) {
		printf("Must enter an integer.");
		return 1;
	}

	//calculate log10 here

	printf("floor(log10(%d)) is %d", n, log10);
	return 0;
}