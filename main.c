#include <stdio.h>
#include <assert.h>
#include "list.h"

int main(){
    // printf("arr[0] address = %p\n", &lists[0]);
    // printf("arr[9] address = %p\n", &lists[LIST_MAX_NUM_HEADS - 1]);
    // int i = &lists[LIST_MAX_NUM_HEADS-1] - &lists[0];
    // printf("%x\n", i);
    // bool r = undefined;
    List* list = List_create();
    List* list2 = List_create();
    List* list3 = List_create();

    //MAIN TEST 1
    {
        // // List* list4 = List_create();
        // // List* list5 = List_create();
        // printf("%p\n", list);
        // printf("%p\n", list2);
        // printf("%p\n", list3);
        // // printf("%p\n", list4);
        // // printf("%p\n", list5);

        // printf("List head: %p\n", list->head);

        // int a1 = 1;
        // int a2 = 2;
        // int a3 = 3;
        // // int a4 = 4;
        // List_append(list, &a1);
        // List_append(list, &a2);
        // List_prepend(list, &a3);
        // // List_append(list, &a4);
        // printList(list);

        // int b1 = 101;
        // int b2 = 102;
        // // int b3 = 103;
        // List_append(list2, &b1);
        // List_append(list2, &b2);
        // // List_append(list2, &b3);
        // printList(list2);

        // int a5 = 5;
        // int a6 = 6;
        // List_prepend(list, &a5);
        // List_append(list, &a6);
        // printList(list);

        // int c1 = 1001;
        // // int c2 = 1002;
        // // int c3 = 1003;
        // // int c4 = 1004;
        // List_append(list3, &c1);
        // // List_append(list3, &c2);
        // // List_append(list3, &c3);
        // // List_append(list3, &c4);
        // printList(list3);

        // printf("Number of nodes in list 1: %d \n", List_count(list));
        // printf("Number of nodes in list 2: %d \n", List_count(list2));
        // printf("Number of nodes in list 3: %d \n", List_count(list3));
        // // void* removedItem1 = List_trim(list);
        // // void* removedItem2 = List_trim(list);
        // // printf("Removed item: %d and it's address is: %p\n", *(int*)removedItem1, removedItem1);
        // // printf("Removed item: %d and it's address is: %p\n", *(int*)removedItem2, removedItem2);
        // printf("Removed item:  and it's address is: %p\n", List_trim(list));
        // printf("Removed item:  and it's address is: %p\n", List_trim(list));
        // printf("Removed item:  and it's address is: %p\n", List_trim(list));
        // printf("Removed item:  and it's address is: %p\n", List_trim(list));
        // // printf("Current of the list: %p \n", );

        // int c2 = 1002;
        // List_append(list3, &c2);
        // printf("Tail of newly added is %p\n", List_last(list3));

        // int b3 = 103;
        // int b4 = 104;
        // List_append(list, &b3);
        // List_append(list, &b4);

        // int a7 = 7;
        // List_append(list, &a7);

        // int b5 = 105;
        // printf("IS it added?: %d\n", List_prepend(list2, &b5));
        // printf("IS it added?: %d\n", List_prepend(list2, &b5));
        // printf("IS it added?: %d\n", List_prepend(list2, &b5));

        // printList(list);
        // printList(list2);
        // printList(list3);
    }

    //MAIN TEST 2 (prepend, append, remove)
    {
        // int x1=1, x2=2, x3=3, x4=4;
        // // printf("%d %d %d\n", x1, x2, x3);
        // List_append(list, &x1);
        // List_prepend(list, &x3);
        // List_append(list, &x2);
        // List_prepend(list, &x4);
        // printList(list);
    }

    //Testing List_insert_after and testing List_insert_before
    {
        List* list4 = List_create();
        int n1 = 10;
        int n2 = 20;
        int n3 = 30;
        int n4 = 40;
        int n5 = 50;
        int n6 = 60;
        int n7 = 70;
        int n8 = 80;
        int n9 = 90;

        //TESTING ONLY List_insert_after
        {
            // List_insert_after(list4, &n1);
            // List_insert_after(list4, &n2);
            // List_insert_after(list4, &n3);
            // List_first(list4);
            // List_insert_after(list4, &n4);
            // List_next(list4);
            // List_insert_after(list4, &n5);
            // List_last(list4);
            // List_next(list4);
            // List_insert_after(list4, &n6);
            // List_next(list4);
            // List_next(list4);
            // List_next(list4);
            // List_insert_after(list4, &n7);
            // List_first(list4);
            // List_insert_after(list4, &n8);
            // List_first(list4);
            // List_prev(list4);
            // List_prev(list4);
            // List_prev(list4);
            // List_insert_after(list4, &n9);
        }
        
        //TESTING ONLY List_insert_before 
        {
            // List_insert_before(list4, &n1);
            // List_insert_before(list4, &n2);
            // List_insert_before(list4, &n3);
            // List_last(list4);
            // List_insert_before(list4, &n4);
            // List_next(list4);
            // List_prev(list4);
            // List_insert_before(list4, &n5);
            // List_last(list4);
            // List_insert_before(list4, &n6);
            // List_last(list4);
            // List_next(list4);
            // List_next(list4);
            // List_insert_before(list4, &n7);
            // List_first(list4);
            // List_insert_before(list4, &n8);
            // List_first(list4);
            // List_prev(list4);
            // List_prev(list4);
            // List_prev(list4);
            // List_insert_after(list4, &n9);
        }
        
        //TESTING BOTH METHODS TOGETHER
        {
            // List_insert_before(list4, &n1);
            // List_insert_after(list4, &n2);
            // List_insert_before(list4, &n3);
            // List_insert_before(list4, &n4);
            // List_next(list4);
            // List_next(list4);
            // List_prev(list4);
            // List_insert_after(list4, &n5);
            // List_last(list4);
            // List_insert_before(list4, &n6);
            // List_last(list4);
            // List_insert_after(list4, &n7);
            // List_last(list4);
            // List_next(list4);
            // List_next(list4);
            // List_insert_after(list4, &n8);
            // List_first(list4);
            // List_prev(list4);
            // List_insert_before(list4, &n9);
        }

        printList(list4);
    }

    //Testing functions for moving pointers
    {
        // //Test for List_first method
        // {
        //     printf("\n------- TEST FOR LIST_FIRST ----------\n");
        //     printf("Current of the list: %p \n", list->current);
        //     printf("Head of the list: %p \n", List_first(list));
        //     printf("Beginning of the list: %p \n", list->head);
        //     printf("Current of the list: %p \n", list->current);
        //     printf("First item is: %d\n", *(int*)list->current->item);
        // }

        // //Test for List_last method
        // {
        //     printf("\n------- TEST FOR LIST_LAST ----------\n");
        //     printf("Current of the list: %p \n", list->current);
        //     printf("Tail of the list: %p \n", List_last(list));
        //     printf("Ending of the list: %p \n", list->tail);
        //     printf("Current of the list: %p \n", list->current);
        // }

        // //Test for List_next and List_curr method
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

        // //Test for List_prev and List_curr method
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
    }
    
    //Testing List_remove method
    {
        int r1 = 1;
        int r2 = 2;
        int r3 = 3;
        int r4 = 4;
        int r5 = 5;
        int r6 = 6;
        int r7 = 7;
        int r8 = 8;
        int r9 = 9;
        int r10 = 10;
        int r11 = 11;
        int r12 = 12;
        List_append(list, &r1);
        List_append(list, &r2);
        List_append(list, &r3);
        List_next(list);
        List_remove(list);
        List_append(list, &r4);
        List_first(list);
        List_next(list);
        List_insert_after(list, &r5);
        List_remove(list);
        List_append(list, &r6);
        List_append(list, &r7);
        List_append(list, &r8);
        printList(list);
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