#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void printlist(struct node *list) {
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		printf("[%d]->", curr->data);
	}
	printf("X");
}

int member(int value, struct node *list) {
    return list != NULL && (list->data == value || member(value, list->next));
}


/*
int member(int value, struct node *list) {
    struct node *n;
    for (n = list; n != NULL; n = n->next) {
        if (n->data == value) {
            return 1;
        }
    }
    return 0;
}*/

struct node *list_append(struct node *list1, struct node *list2) {
    struct node *n;
    if (list1 == NULL) {
        return list2;
    }
    n = list1;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = list2;
    return list1;
}

struct node *insert_ordered(int item, struct node *list) {
    struct node *n;
    struct node *new = malloc(sizeof *new);
    if (new == NULL) {
        fprintf(stderr, "Out of memory");
        exit(1);
    }
    new->data = item;
    if (list == NULL || item < list->data) {
        new->next = list;
        return new;
    }
    n = list;
    while (n->next != NULL && n->next->data < item) {
        n = n->next;
    }
    new->next = n->next;
    n->next = new;
    return list;
}


struct node *merge_sorted(struct node *list1, struct node *list2) {
    struct node *start;
    struct node *n;
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    } else if (list1->data < list2->data) {
        start = list1;
        n = list1;
        list1 = list1->next;
    } else {
        start = list2;
        n = list2;
        list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            n->next = list1;
            n = list1;
            list1 = list1->next;
        } else {
            n->next = list2;
            n = list2;
            list2 = list2->next;
        }
    }
    if (list1 == NULL) {
        n->next = list2;
    } else {
        n->next = list1;
    };
    return start;
}
/*
struct node *merge_sorted(struct node *list1, struct node *list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    } else if (list1->data < list2->data) {
        list1->next = merge_sorted(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_sorted(list1, list2->next);
        return list2;
    }
}*/