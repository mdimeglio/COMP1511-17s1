#include <stdio.h>


int main(void) {
	int start, finish;
	printf("Enter start:");
	scanf("%d", &start);
	printf("Enter finish:");
	scanf("%d", &finish);

	while(start <= finish) {
		if (start % 10 == 0) {
			printf("%d\n", start);
		}
		start = start + 1;
	}

	return 0;
}