#include <stdio.h>
#include <string.h>
#include <assert.h>

struct node;

struct node {
	int data;
	struct node *next;
};

// tests if a specified value is a found in a specified list
int member(int value, struct node *list) {
	for(struct node *cur = list; cur != NULL; cur = cur->next) {
		if (cur->data == value) {
			return 1;
		}
	}
	return 0;
}
/*
int member(int value, struct node *list) {
    if (list == NULL) {
    	return 0;
    } else if (list->data == value) {
    	return 1;
    } else {
    	return member(value, list->next);
    }
}*/

int main (void) {
	struct node n3 = {3, NULL};
	n3.data = 4;
	struct node n2 = {2, &n3};
	struct node n1 = {1, &n2};

	assert(member(2, &n1));
	assert(!member(5, &n1));

	assert(!member(2, NULL));
	assert(!member(1, &n2));

	printf("All tests passed!\n");
	return 0;
}

/*
int
member(int value, struct node *list) {
    struct node *n;
    for (n = list; n != NULL; n = n->next)
        if (n->data == value)
            return 1;
    return 0;
}

int member(int value, struct node *list) {
    return list != NULL && (list->data == value || member(value, list->next));
}*/