#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"


struct node *copy(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *new_head = malloc(sizeof (struct node));
    assert(new_head);
    new_head->data = head->data;
    new_head->next = copy(head->next);
    return new_head;
}

int identical(struct node *head1, struct node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return 1;
    }
    if (head1 == NULL || head2 == NULL || head1->data != head2->data) {
        return 0;
    }
    return identical(head1->next, head2->next);
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

struct node *set_intersection(struct node *set1, struct node *set2) {
    if (set1 == NULL || set2 == NULL) {
        return NULL;
    }
    if (set1->data == set2->data) {
        struct node *new_head = malloc(sizeof (struct node));
        assert(new_head);
        new_head->data = set1->data;
        new_head->next = set_intersection(set1->next, set2->next);
        return new_head;
    } else if (set1->data < set2->data) {
        return set_intersection(set1->next, set2);
    } else {
        return set_intersection(set1, set2->next);
    }
}

struct node *set_union(struct node *set1, struct node *set2) {
    if (set1 == NULL && set2 == NULL) {
        return NULL;
    }
    struct node *new_head = malloc(sizeof (struct node));
    assert(new_head);
    if (set1 != NULL && set2 != NULL && set1->data == set2->data) {
        new_head->data = set1->data;
        new_head->next = set_union(set1->next, set2->next);
    } else if (set2 == NULL || (set1 != NULL && set1->data < set2->data)) {
        new_head->data = set1->data;
        new_head->next = set_union(set1->next, set2);
    } else {
        new_head->data = set2->data;
        new_head->next = set_union(set1, set2->next);
    }
    return new_head;
}