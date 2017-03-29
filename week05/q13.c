#include <stdio.h>

#define VECTOR_LENGTH 3;

int dot_product(
	int vector1[VECTOR_LENGTH],
	int vector2[VECTOR_LENGTH]);

int main(void) {
	int vectorA[VECTOR_LENGTH] = {1, 2, 3};
	int vectorB[VECTOR_LENGTH] = {1, 1, 2};
	int aDotB = dot_product(vectorA, vectorB);

	printf("Dot product of [1, 2, 3] and [1, 1, 2] is %d.",
		aDotB);

    return 0;
}

int dot_product(
	int vector1[VECTOR_LENGTH],
	int vector2[VECTOR_LENGTH]) {

}