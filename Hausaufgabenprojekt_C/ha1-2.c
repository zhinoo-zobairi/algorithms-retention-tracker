#include <stdio.h>
#include <stdlib.h>

#define N 5

struct le {
    int array[N];
    struct le *next;
};
typedef struct le listelement;
typedef listelement *list;

void insert(int ar[], list *l) {
    listelement *newNode = (listelement *)malloc(sizeof(listelement));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++) {
        newNode->array[i] = ar[i];
    }
    newNode->next = *l;
    *l = newNode;
}

void delete_all(list *l) {
    listelement *current = *l;
    while (current != NULL) {
        listelement *next = current->next;
        free(current);
        current = next;
    }
    *l = NULL;
}

void print_list(list l) {
    listelement *current = l;
    while (current != NULL) {
        printf("[");
        for (int i = 0; i < N; i++) {
            printf("%d", current->array[i]);
            if (i < N - 1) printf(",");
        }
        printf("]");
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
    printf("\n");
}

int compare(int ar[], list l, int pos) {
    if (l == NULL || pos < 0) {
        return -2;
    }
    listelement *current = l;
    for (int i = 0; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return -2;
    }
    for (int i = 0; i < N; i++) {
        if (ar[i] != current->array[i]) {
            return i;
        }
    }
    return -1;
}

int insertBehind(int newArr[], list *l, int ar[]) {
    listelement *current = *l;

    while (current != NULL) {
        if (compare(ar, (list)current, 0) == -1) {
            listelement *newNode = (listelement *)malloc(sizeof(listelement));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < N; i++) {
                newNode->array[i] = newArr[i];
            }
            newNode->next = current->next;
            current->next = newNode;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

list reverse(list l) {
    list reversed = NULL;
    listelement *current = l;

    while (current != NULL) {
        listelement *newNode = (listelement *)malloc(sizeof(listelement));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < N; i++) {
            newNode->array[i] = current->array[N - 1 - i];
        }
        newNode->next = reversed;
        reversed = newNode;
        current = current->next;
    }
    return reversed;
}

int main() {
    list myList = NULL;

    int a[N] = {1, 2, 3, 4, 5};
    int b[N] = {6, 7, 8, 9, 10};
    int c[N] = {11, 12, 13, 14, 15};
    int d[N] = {42, 42, 42, 42, 42};
    int target[N] = {6, 7, 8, 9, 10};

    insert(a, &myList);
    insert(b, &myList);
    insert(c, &myList);

    printf("Initial list:\n");
    print_list(myList);

    printf("\nTesting insertBehind (after [6,7,8,9,10]):\n");
    insertBehind(d, &myList, target);
    print_list(myList);

    printf("\nTesting reverse:\n");
    list reversed = reverse(myList);
    print_list(reversed);

    printf("\nTesting compare (position 1):\n");
    int cmpResult = compare(target, myList, 1);
    printf("Compare result: %d\n", cmpResult);

    printf("\nTesting delete_all:\n");
    delete_all(&myList);
    delete_all(&reversed);
    printf("List after delete_all:\n");
    print_list(myList);

    printf("\nTesting on empty list:\n");
    int insertResult = insertBehind(d, &myList, target);
    printf("insertBehind on empty list returned: %d\n", insertResult);
    int compareResult = compare(target, myList, 0);
    printf("compare on empty list returned: %d\n", compareResult);

    printf("\nSomit waren alle Tests erfolgreich!!!\n");

    return 0;
}