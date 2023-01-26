#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main(){
    Node root, element2;
    root.data = 15;
    root.next = &element2;
    element2.data = -2;
    element2.next = NULL;

    printf("First: %d\n", root.data);
    printf("Second: %d\n", element2.data);

    return 0;
}