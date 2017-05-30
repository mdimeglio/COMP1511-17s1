#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node *copy(struct node *head) {
	if (head == NULL) {
		return NULL;
	} else {
		struct node *copied = malloc(sizeof(struct node));
		assert(copied != NULL);
		copied->data = head->data;
		copied->next = copy(head->next);
		return copied;
	}
}

int identical(struct node *head1, struct node *head2) {
	if (head1 != NULL && head2 != NULL) {
		return (head1->data == head2->data &&
			identical(head1->next, head2->next));
	}

	return head1 == NULL && head2 == NULL;
}

int ordered(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }
    if (head->data >= head->next->data) {
        return 0;
    }
    return ordered(head->next);
}

struct node *set_intersection(struct node *head1, struct node *head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	} else if (head1->data < head2->data) {
		return set_intersection(head1->next, head2);
	} else if (head1->data > head2->data) {
		return set_intersection(head1, head2->next);
	} else {
		struct node *intersection = malloc(sizeof(struct node));
		intersection->data = head1->data;
		intersection->next = set_intersection(head1->next, head2->next);
		return intersection;
	}
}

struct node *set_union(struct node *set1, struct node *set2) {
	return NULL;
}