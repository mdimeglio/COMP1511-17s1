#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void printlist(struct node *list) {
	for (struct node *cur = list; cur != NULL; cur = cur->next) {
		printf("[%d]->", cur->data);
	}
	printf("X");
}


void insert_front(struct node **list, struct node *to_insert) {
	to_insert->next = *list;
	*list = to_insert;
}

/*
struct node *insert_front(struct node *list, struct node *to_insert) {
	to_insert->next = list;
	return to_insert;
}*/


struct node *remove_front(struct node **list) {
	struct node *first = *list;
	assert(first != NULL);
	*list = (*list)->next;
	return first;
}

/*void insert_after(struct node *before, struct node *to_insert) {

}*/
int is_empty(struct node *list) {
	return list == NULL;
}


void reverse_list(struct node **list) {
	struct node *from = *list;
	struct node *reversed = NULL;

	while(!is_empty(from)) {
		struct node *temp =  remove_front(&from);
		insert_front(&reversed, temp);
	}

	*list = reversed;
}


int member(int value, struct node *list) {
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		if (curr->data == value) {
			return 1;
		}
	}
	return 0;

}
struct node *list_append(struct node *base, struct node *toAppend) {
	if (is_empty(base)) {
		return toAppend;
	} else {
		struct node *curr;
		for (curr = base; curr->next != NULL; curr = curr->next);
		curr->next = toAppend;
		return base;
	}
}

struct node *insert_ordered(int item, struct node *list) {
	struct node *reversed = NULL;
	while(!is_empty(list) && list->data < item) {
		struct node *front = remove_front(&list);
		insert_front(&reversed, front);

	}

	struct node *to_insert = malloc(sizeof(struct node));
	to_insert->data = item;

	insert_front(&list, to_insert);

	while(!is_empty(reversed)) {
		insert_front(&list, remove_front(&reversed));
	}

	return list;
}


/* OPTION 1*/
struct node *merge_sorted(struct node *list1, struct node *list2) {
	struct node *reversed = NULL;
	while(!is_empty(list1) && !is_empty(list2)) {
		if (list1->data < list2->data) {
			insert_front(&reversed, remove_front(&list1));
		} else {
			insert_front(&reversed, remove_front(&list2));
		}
	}

	if (!is_empty(list1)) {
		while(!is_empty(reversed)) {
			insert_front(&list1, remove_front(&reversed));
		}
		return list1;
	} else {
		while(!is_empty(reversed)) {
			insert_front(&list2, remove_front(&reversed));
		}
		return list2;
	}
}

/* OPTION 2*/
struct node *merge_sorted(struct node *list1, struct node *list2) {
	struct node *reversed = NULL;
	while(!is_empty(list1) && !is_empty(list2)) {
		if (list1->data < list2->data) {
			insert_front(&reversed, remove_front(&list1));
		} else {
			insert_front(&reversed, remove_front(&list2));
		}
	}

	while(!is_empty(list1)) {
		insert_front(&reversed, remove_front(&list1));
	}

	while(!is_empty(list2)) {
		insert_front(&reversed, remove_front(&list2));
	}

	struct node *to_return = NULL;
	while(!is_empty(reversed)) {
		insert_front(&to_return, remove_front(&reversed));
	}
	return to_return;
	
	/* OR DO:
	reverse_list(&reversed);
	return reversed;
	*/
}
