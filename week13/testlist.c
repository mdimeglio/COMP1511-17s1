#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void testCopy1(void);
void testCopy2(void);
void testIdentical1(void);
void testIdentical2(void);
void testIdentical3(void);
void testIdentical4(void);
void testOrdered1(void);
void testOrdered2(void);
void testOrdered3(void);
void testSetIntersection1(void);
void testSetIntersection2(void);
void testSetIntersection3(void);
void testSetIntersection4(void);
void testSetIntersection5(void);
void testSetUnion1(void);
void testSetUnion2(void);
void testSetUnion3(void);
void testSetUnion4(void);
void testSetUnion5(void);

int main (void) {
	testCopy1();
	testCopy2();
	testIdentical1();
	testIdentical2();
	testIdentical3();
	testIdentical4();
	testOrdered1();
	testOrdered2();
	testOrdered3();
	testSetIntersection1();
	testSetIntersection2();
	testSetIntersection3();
	testSetIntersection4();
	testSetIntersection5();
	testSetUnion1();
	testSetUnion2();
	testSetUnion3();
	testSetUnion4();
	testSetUnion5();

	printf("All tests passed!\n");
	return EXIT_SUCCESS;
}

void printlist(struct node *list) {
	for (struct node *cur = list; cur != NULL; cur = cur->next) {
		printf("[%d]->", cur->data);
	}
	printf("X");
}
void testCopy1(void) {
	struct node n3 = {60, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	printf("Testing copy.\nList:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = copy(&n0);

	printf("Copied:");
	printlist(result);
	printf("\n");

	assert(result != &n0 &&
		result->data == n0.data &&
		n0.next == &n1);

	assert(result->next != &n1 &&
		result->next->data == n1.data &&
		n1.next == &n2);

	assert(result->next->next != &n2 &&
		result->next->next->data == n2.data &&
		n2.next == &n3);

	assert(result->next->next->next != &n3 &&
		result->next->next->next->data == n3.data &&
		n3.next == NULL);

	assert(result->next->next->next->next == NULL);

	free(result->next->next->next->next);
	free(result->next->next->next);
	free(result->next->next);
	free(result->next);
	free(result);

	printf("Passed!\n");
}

void testCopy2(void) {
	printf("Testing copy.\nList:\n");
	printlist(NULL);
	printf("\n");

	struct node *result = copy(NULL);

	printf("Copied:");
	printlist(result);
	printf("\n");

	assert(result == NULL);

	printf("Passed!\n");
}

void testIdentical1(void) {
	struct node n3 = {30, NULL};
	struct node n2 = {20, &n3};
	struct node n1 = {10, &n2};

	struct node n6 = {30, NULL};
	struct node n5 = {20, &n6};
	struct node n4 = {10, &n5};

	printf("Testing identical.\nList 1:\n");
	printlist(&n1);
	printf("\nList 2:\n");
	printlist(&n4);
	printf("\n");

	int result = identical(&n1, &n4);
	printf("Identical? %d", result);
	printf("\n");

	assert(result);

	printf("Passed!\n");
}

void testIdentical2(void) {
	struct node n3 = {30, NULL};
	struct node n2 = {20, &n3};
	struct node n1 = {10, &n2};

	struct node n5 = {20, NULL};
	struct node n4 = {10, &n5};

	printf("Testing identical.\nList 1:\n");
	printlist(&n1);
	printf("\nList 2:\n");
	printlist(&n4);
	printf("\n");

	int result = identical(&n1, &n4);
	printf("Identical? %d", result);
	printf("\n");

	assert(!result);

	printf("Passed!\n");
}


void testIdentical3(void) {
	struct node n3 = {30, NULL};
	struct node n2 = {20, &n3};
	struct node n1 = {10, &n2};

	printf("Testing identical.\nList 1:\n");
	printlist(&n1);
	printf("\nList 2:\n");
	printlist(NULL);
	printf("\n");

	int result = identical(&n1, NULL);
	printf("Identical? %d", result);
	printf("\n");

	assert(!result);

	printf("Passed!\n");
}

void testIdentical4(void) {
	printf("Testing identical.\nList 1:\n");
	printlist(NULL);
	printf("\nList 2:\n");
	printlist(NULL);
	printf("\n");

	int result = identical(NULL, NULL);
	printf("Identical? %d", result);
	printf("\n");

	assert(result);

	printf("Passed!\n");
}

void testOrdered1(void) {
	struct node n3 = {30, NULL};
	struct node n2 = {20, &n3};
	struct node n1 = {10, &n2};

	printf("Testing ordered.\nList:\n");
	printlist(&n1);
	printf("\n");

	int result = ordered(&n1);
	printf("Ordered? %d", result);
	printf("\n");

	assert(result);

	printf("Passed!\n");
}

void testOrdered2(void) {
	struct node n3 = {30, NULL};
	struct node n2 = {50, &n3};
	struct node n1 = {10, &n2};

	printf("Testing ordered.\nList:\n");
	printlist(&n1);
	printf("\n");

	int result = ordered(&n1);
	printf("Ordered? %d", result);
	printf("\n");

	assert(!result);

	printf("Passed!\n");
}

void testOrdered3(void) {
	printf("Testing ordered.\nList:\n");
	printlist(NULL);
	printf("\n");

	int result = ordered(NULL);
	printf("Ordered? %d", result);
	printf("\n");

	assert(result);

	printf("Passed!\n");
}

void testSetIntersection1(void) {
	struct node n3 = {60, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {30, &n6};

	printf("Testing set intersection.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_intersection(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result == NULL);

	printf("Passed!\n");
}

void testSetIntersection2(void) {
	struct node n3 = {60, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {10, &n6};

	printf("Testing set intersection.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_intersection(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10 && result->next == NULL);

	printf("Passed!\n");
}

void testSetIntersection3(void) {
	struct node n3 = {50, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {10, &n6};

	printf("Testing set intersection.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_intersection(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10);
	assert(result->next->data == 50);
	assert(result->next->next == NULL);

	printf("Passed!\n");
}

void testSetIntersection4(void) {
	struct node n3 = {50, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	printf("Testing set intersection.\nList 1:\n");
	printlist(NULL);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_intersection(&n0, NULL);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result == NULL);

	printf("Passed!\n");
}


void testSetIntersection5(void) {
	printf("Testing set intersection.\nList 1:\n");
	printlist(NULL);
	printf("\nList 2:\n");
	printlist(NULL);
	printf("\n");

	struct node *result = set_intersection(NULL, NULL);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result == NULL);

	printf("Passed!\n");
}




void testSetUnion1(void) {
	struct node n3 = {60, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {30, &n6};

	printf("Testing set union.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_union(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10);
	assert(result->next->data == 20);
	assert(result->next->next->data == 30);
	assert(result->next->next->next->data == 40);
	assert(result->next->next->next->next->data == 50);
	assert(result->next->next->next->next->next->data == 60);
	assert(result->next->next->next->next->next->next == NULL);
	printf("Passed!\n");
}

void testSetUnion2(void) {
	struct node n3 = {60, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {10, &n6};

	printf("Testing set union.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_union(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10);
	assert(result->next->data == 20);
	assert(result->next->next->data == 40);
	assert(result->next->next->next->data == 50);
	assert(result->next->next->next->next->data == 60);
	assert(result->next->next->next->next->next == NULL);

	printf("Passed!\n");
}

void testSetUnion3(void) {
	struct node n3 = {50, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	struct node n6 = {50, NULL};
	struct node n5 = {10, &n6};

	printf("Testing set union.\nList 1:\n");
	printlist(&n5);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_union(&n0, &n5);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10);
	assert(result->next->data == 20);
	assert(result->next->next->data == 40);
	assert(result->next->next->next->data == 50);
	assert(result->next->next->next->next == NULL);

	printf("Passed!\n");
}

void testSetUnion4(void) {
	struct node n3 = {50, NULL};
	struct node n2 = {40, &n3};
	struct node n1 = {20, &n2};
	struct node n0 = {10, &n1};

	printf("Testing set union.\nList 1:\n");
	printlist(NULL);
	printf("\nList 2:\n");
	printlist(&n0);
	printf("\n");

	struct node *result = set_union(&n0, NULL);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result->data == 10);
	assert(result->next->data == 20);
	assert(result->next->next->data == 40);
	assert(result->next->next->next->data == 50);
	assert(result->next->next->next->next == NULL);

	printf("Passed!\n");
}


void testSetUnion5(void) {
	printf("Testing set intersection.\nList 1:\n");
	printlist(NULL);
	printf("\nList 2:\n");
	printlist(NULL);
	printf("\n");

	struct node *result = set_union(NULL, NULL);

	printf("Result:");
	printlist(result);
	printf("\n");

	assert(result == NULL);

	printf("Passed!\n");
}

