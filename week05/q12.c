#include <stdio.h>

#define ARRAY_SIZE 10

int not_in_int_array(int nums[], int n, int x);

int main(void) {
	int toSearchFor, found;
	int array[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("Enter number to search for:");
	scanf("%d", &toSearchFor);


	found = not_in_int_array(array, ARRAY_SIZE, toSearchFor);
	if (found) {
		printf("%d was in the array.\n");
	} else {
		printf("%d was not in the array.\n");
	}

    return 0;
}

int not_in_int_array(int nums[], int n, int x) {
	
}