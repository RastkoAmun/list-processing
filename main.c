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

    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    // int a4 = 4;
    List_append(list, &a1);
    List_append(list, &a2);
    List_append(list, &a3);
    // List_append(list, &a4);
    printList(list);

    int b1 = 101;
    int b2 = 102;
    // int b3 = 103;
    List_append(list2, &b1);
    List_append(list2, &b2);
    // List_append(list2, &b3);
    printList(list2);

    int a5 = 5;
    int a6 = 6;
    List_append(list, &a5);
    List_append(list, &a6);
    printList(list);

    int c1 = 1001;
    // int c2 = 1002;
    // int c3 = 1003;
    // int c4 = 1004;
    List_append(list3, &c1);
    // List_append(list3, &c2);
    // List_append(list3, &c3);
    // List_append(list3, &c4);
    printList(list3);

    printf("Number of nodes in list 1: %d \n", List_count(list));
    printf("Number of nodes in list 2: %d \n", List_count(list2));
    printf("Number of nodes in list 3: %d \n", List_count(list3));
    // void* removedItem1 = List_trim(list);
    // void* removedItem2 = List_trim(list);
    // printf("Removed item: %d and it's address is: %p\n", *(int*)removedItem1, removedItem1);
    // printf("Removed item: %d and it's address is: %p\n", *(int*)removedItem2, removedItem2);
    printf("Removed item:  and it's address is: %p\n", List_trim(list));
    printf("Removed item:  and it's address is: %p\n", List_trim(list));
    printf("Removed item:  and it's address is: %p\n", List_trim(list));
    // printf("Current of the list: %p \n", );

    int c2 = 1002;
    List_append(list3, &c2);
    printf("Tail of newly added is %p\n", List_last(list3));
    printList(list);
    printList(list2);
    printList(list3);


    //Test for List_first method
    // {
    //     printf("\n------- TEST FOR LIST_FIRST ----------\n");
    //     printf("Current of the list: %p \n", list->current);
    //     printf("Head of the list: %p \n", List_first(list));
    //     printf("Beginning of the list: %p \n", list->head);
    //     printf("Current of the list: %p \n", list->current);
    // }

    //Test for List_last method
    // {
    //     printf("\n------- TEST FOR LIST_LAST ----------\n");
    //     printf("Current of the list: %p \n", list->current);
    //     printf("Tail of the list: %p \n", List_last(list));
    //     printf("Ending of the list: %p \n", list->tail);
    //     printf("Current of the list: %p \n", list->current);
    // }

    //Test for List_next and List_curr method
    // {
    //     printf("\n------- TEST FOR LIST_NEXT and LIST_CURR----------\n");
    //     printf("Head of the list: %p \n", List_first(list));
    //     printf("Current of the list: %p \n", list->current);
    //     printf("Current of the list: %p \n", List_curr(list));
    //     printf("Next current of the list: %p \n", List_next(list));
    //     printf("Next current of the list: %p \n", List_next(list));
    //     printf("Next current of the list: %p \n", List_next(list));
    //     printf("Next current of the list: %p \n", List_next(list));
    // }

    //Test for List_prev and List_curr method
    // {
    //     printf("\n------- TEST FOR LIST_NEXT and LIST_CURR----------\n");
    //     printf("Head of the list: %p \n", List_last(list));
    //     printf("Current of the list: %p \n", list->current);
    //     printf("Current of the list: %p \n", List_curr(list));
    //     printf("Prev current of the list: %p \n", List_prev(list));
    //     printf("Prev current of the list: %p \n", List_prev(list));
    //     printf("Prev current of the list: %p \n", List_prev(list));
    //     printf("Prev current of the list: %p \n", List_prev(list));
    // }




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