struct node {
    int       data;
    struct node *next;
};


struct node *copy(struct node *head);

int identical(struct node *head1, struct node *head2);

int ordered(struct node *head);

struct node *set_intersection(struct node *set1, struct node *set2);

struct node *set_union(struct node *set1, struct node *set2);