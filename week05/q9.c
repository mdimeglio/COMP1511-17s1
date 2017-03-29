#include <stdio.h>

#define ARRAY_SIZE 15

int main(void) {
	int squares[ARRAY_SIZE];

	int i = 0;
	while(i < ARRAY_SIZE) {
		squares[i] = i * i;
		i = i + 1;
	}
    return 0;
}