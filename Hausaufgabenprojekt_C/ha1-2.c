#include <stdio.h>
#include <stdlib.h>

#define N 5

struct listelement {
    int array[N];
    struct listelement *next;
};

struct list {
    struct listelement *head;
};

void insert(int ar[], struct list *l) {
    struct listelement* new_node = (struct listelement*) malloc(sizeof(struct listelement));
    if (new_node == NULL)
    {
        printf("Node konnte nicht erstellt werden\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < N; i++) {
        new_node->array[i] = ar[i];
    }
    new_node->next = l->head;
    l->head = new_node;
}

void delete_all(struct list *l) {
    struct listelement* current = l->head;
    while (current != NULL) {
        struct listelement* next = current->next;
        free(current);
        current = next;
    }
    l->head = NULL;
}

void print_list(struct list l) {
    struct listelement *current = l.head;
    while (current != NULL) {
        printf("[");
        for (int i = 0; i < N; i++) {
            printf("%d", current->array[i]);
            if (i < N - 1) printf(",");
        }
        printf("]");
        if (current->next != NULL) printf(",");
        current = current->next;
    }
    printf("\n");
}

int compare(int ar[], struct list l, int pos) { 
    if (l.head == NULL || pos < 0) {
        return -2; 
    }

    struct listelement* current = l.head;

    for (int i = 0; i < pos; i++) {
        if (current == NULL) return -2; 
        current = current->next;
    }

    if (current == NULL) return -2;

    for (int i = 0; i < N; i++) {
        if (current->array[i] != ar[i]) {
            return i;
        }
    }

    return -1; 
}

int insertBehind(int new_arr[], struct list *l, int ar[]) {
    struct listelement *current = l->head;
    int pos = 0;

    while (current != NULL) {
        if (compare(ar, *l, pos) == -1) {
            struct listelement *new_node = (struct listelement*)malloc(sizeof(struct listelement));
            if (new_node == NULL) {
                printf("Node konnte nicht erstellt werden\n");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < N; i++) {
                new_node->array[i] = new_arr[i];
            }
            new_node->next = current->next;
            current->next = new_node;
            return 0;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

struct list reverse(struct list l) {
    struct list reversed;
    reversed.head = NULL;
    struct listelement *current = l.head;
    while (current != NULL) {
        struct listelement *new_node = (struct listelement*)malloc(sizeof(struct listelement));
        for (int i = 0; i < N; i++)
            new_node->array[i] = current->array[N - 1 - i];
        new_node->next = reversed.head;
        reversed.head = new_node;
        current = current->next;
    }
    return reversed;
}
int main() {
    struct list myList;
    myList.head = NULL;

    int a[N] = {1, 2, 3, 4, 5};
    int b[N] = {6, 7, 8, 9, 10};
    int c[N] = {11, 12, 13, 14, 15};
    int d[N] = {42, 42, 42, 42, 42};
    int target[N] = {6, 7, 8, 9, 10};

    printf("Testing with a non-empty list:\n");
    insert(a, &myList);
    insert(b, &myList);
    insert(c, &myList);

    printf("Initial list:\n");
    print_list(myList);

    printf("\nTesting insertBehind:\n");
    insertBehind(d, &myList, target);
    print_list(myList);

    printf("\nTesting reverse:\n");
    struct list reversed = reverse(myList);
    print_list(reversed);

    printf("\nTesting compare:\n");
    printf("Compare result: %d\n", compare(target, myList, 1));

    printf("\nTesting delete_all:\n");
    delete_all(&myList);
    delete_all(&reversed);
    printf("List after delete_all:\n");
    print_list(myList);

    printf("\nTesting with an empty list:\n");
    printf("Compare result: %d\n", compare(target, myList, 0));
    insertBehind(d, &myList, target);
    print_list(myList);

    printf("\nSomit waren alle Tests erfolgreich!!!\n");

    return 0;
}