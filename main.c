#include <stdio.h>
#include "list.h"

// #define LIST_MAX_NUM_HEADS 10
// #define LIST_MAX_NUM_NODES 100

// static int lists[LIST_MAX_NUM_HEADS];
// static int nodes[LIST_MAX_NUM_NODES];

int main(){
    // printf("arr[0] address = %p\n", &lists[0]);
    // printf("arr[9] address = %p\n", &lists[LIST_MAX_NUM_HEADS - 1]);
    // int i = &lists[LIST_MAX_NUM_HEADS-1] - &lists[0];
    // printf("%x\n", i);
    // bool r = undefined;


    List* list = List_create();
    List* list2 = List_create();
    List* list3 = List_create();
    // List* list4 = List_create();
    // List* list5 = List_create();
    printf("%p\n", list);
    printf("%p\n", list2);
    printf("%p\n", list3);
    // printf("%p\n", list4);
    // printf("%p\n", list5);

    printf("List head: %p\n", list->head);

    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int i4 = 4;
    List_append(list, &i1);
    List_append(list, &i2);
    List_append(list, &i3);
    List_append(list, &i4);
    printList(list);

    int a1 = 101;
    int a2 = 102;
    int a3 = 103;
    List_append(list2, &a1);
    List_append(list2, &a2);
    List_append(list2, &a3);
    printList(list2);

    int i5 = 5;
    int i6 = 6;
    List_append(list, &i5);
    List_append(list, &i6);
    printList(list);


    printf("Number of nodes: %d \n", List_count(list));
    printf("Number of nodes: %d \n", List_count(list2));

    //Test for List_first method
    {
        printf("\n------- TEST FOR LIST_FIRST ----------\n");
        printf("Current of the list: %p \n", list->current);
        printf("Head of the list: %p \n", List_first(list));
        printf("Beginning of the list: %p \n", list->head);
        printf("Current of the list: %p \n", list->current);
    }

    //Test for List_last method
    {
        printf("\n------- TEST FOR LIST_LAST ----------\n");
        printf("Current of the list: %p \n", list->current);
        printf("Tail of the list: %p \n", List_last(list));
        printf("Ending of the list: %p \n", list->tail);
        printf("Current of the list: %p \n", list->current);
    }

    //Test for List_next and List_curr method
    {
        printf("\n------- TEST FOR LIST_NEXT and LIST_CURR----------\n");
        printf("Head of the list: %p \n", List_first(list));
        printf("Current of the list: %p \n", list->current);
        printf("Current of the list: %p \n", List_curr(list));
        printf("Next current of the list: %p \n", List_next(list));
        printf("Next current of the list: %p \n", List_next(list));
        printf("Next current of the list: %p \n", List_next(list));
        printf("Next current of the list: %p \n", List_next(list));
    }

    //Test for List_prev and List_curr method
    {
        printf("\n------- TEST FOR LIST_NEXT and LIST_CURR----------\n");
        printf("Head of the list: %p \n", List_last(list));
        printf("Current of the list: %p \n", list->current);
        printf("Current of the list: %p \n", List_curr(list));
        printf("Prev current of the list: %p \n", List_prev(list));
        printf("Prev current of the list: %p \n", List_prev(list));
        printf("Prev current of the list: %p \n", List_prev(list));
        printf("Prev current of the list: %p \n", List_prev(list));
    }




    // List* list5 = List_create();
    // List* list6 = List_create();
    // List* list7 = List_create();
    // List* list8 = List_create();
    // List* list9 = List_create();
    // List* list10 = List_create();
    // List* list11 = List_create();
    // printf("%p\n", list5);
    // printf("%p\n", list6);
    // printf("%p\n", list7);
    // printf("%p\n", list8);
    // printf("%p\n", list9);
    // printf("%p\n", list10);
    // List_R(list2);
    // List* list8 = List_create();
    // printf("%p\n", list8);
    // printf("%p\n\n", list4);
    printf("\nAAAAAAAAAAAAAAAAAAAAAAAA\n");
    // printf("Number of items %d", List_count(list));

    

    

    return 0;
}