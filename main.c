#include <stdio.h>
#include <assert.h>
#include "list.h"

void freeItem(void *currItem)
{
    currItem = NULL;
}

/*
    PLEASE READ BEFORE TESTING.
    All tests are divided into blocks by "{}" symbols.
    Make sure to test each block one at the time.
*/

int main()
{

    List *list = List_create();
    List *list2 = List_create();
    List *list3 = List_create();
    List *list4 = List_create();
    // List* list5 = List_create();
    printf("Addr: %p\n", list);
    printf("Addr: %p\n", list2);
    printf("Addr: %p\n", list3);
    printf("Addr: %p\n", list4);
    // printf("Addr: %p\n", list5);


    // MAIN TEST 1
    {
        int a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5, a6 = 6, a7 = 7, a8 = 8, a9 = 9;
        int b1 = 10, b2 = 20, b3 = 30, b4 = 40, b5 = 50;
        int c1 = 100, c2 = 200, c3 = 300, c4 = 400;
        List_insert_before(list, &a1);
        List_insert_before(list, &a2);
        List_append(list, &a3);
        List_prepend(list2, &b1);
        List_append(list2, &b2);
        List_first(list);
        List_next(list);
        List_remove(list);
        List_insert_after(list, &a4);
        List_insert_after(list3, &c1);
        List_insert_before(list3, &c2);
        List_last(list3);
        List_prev(list3);
        List_insert_after(list3, &c3);
        List_insert_before(list, &a5);
        List_insert_before(list2, &b3);
        List_remove(list);
        List_prev(list);
        List_remove(list);
        List_remove(list2);
        List_first(list3);
        List_remove(list3);
        List_append(list, &a6);
        List_append(list, &a7);
        List_insert_after(list3, &c4);
        List_prepend(list2, &b5);

        // List_insert_after(list3, c1);
        printf("Number of items in the list: %d\n", List_count(list));
        printf("Number of items in the list: %d\n", List_count(list2));
        printf("Number of items in the list: %d\n", List_count(list3));
        printList(list);
        printList(list2);
        printList(list3);

        printf("Head of list is: %d\n", *(int *)list->head->item);
        printf("Tail of list is: %d\n", *(int *)list->tail->item);
        printf("Head of list3 is: %d\n", *(int *)list3->head->item);
        printf("Tail of list3 is: %d\n", *(int *)list3->tail->item);
        List_concat(list, list3);
        printf("Tail of list is: %d\n", *(int *)list->tail->item);
        printList(list);

        List *list6 = List_create();
        printf("Addr: %p\n", list6);
        printf("Number of items in the list: %d\n", List_count(list));
        printf("Number of items in the list: %d\n", List_count(list2));
        printf("Number of items in the list: %d\n", List_count(list3));
        printf("Number of items in the list: %d\n", List_count(list4));
        printf("Tail 2: %p\n", list->tail);
        List_free(list, freeItem);
        List *list7 = List_create();
        printf("Addr: %p\n", list7);
        List_free(list2, freeItem);
        printf("Number of items in the list: %d\n", List_count(list));
        printf("Number of items in the list: %d\n", List_count(list2));
        printf("Addr: %p\n", list);
        printf("Addr: %p\n", list2);
        // List_free(list, freeItem);
        printList(list);
        printList(list2);
        printList(list3);

        
    }

    // Testing (prepend, append, remove)
    {
        // int x1=1, x2=2, x3=3, x4=4;
        // // printf("%d %d %d\n", x1, x2, x3);
        // List_append(list, &x1);
        // List_prepend(list, &x3);
        // List_append(list, &x2);
        // List_prepend(list, &x4);
        // printList(list);
    }

    // Testing List_insert_after and testing List_insert_before
    {
        int n1 = 10;
        int n2 = 20;
        int n3 = 30;
        int n4 = 40;
        int n5 = 50;
        int n6 = 60;
        int n7 = 70;
        int n8 = 80;
        int n9 = 90;

        // TESTING ONLY List_insert_after
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
            // printList(list4);
        }

        // TESTING ONLY List_insert_before
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
            // printList(list4);
        }

        // TESTING BOTH METHODS TOGETHER
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
            // printList(list4);
        }
    }

    // Testing List_remove method
    {
        // int r1 = 1;
        // int r2 = 2;
        // int r3 = 3;
        // int r4 = 4;
        // int r5 = 5;
        // int r6 = 6;
        // int r7 = 7;
        // int r8 = 8;
        // int r9 = 9;
        // int r10 = 10;
        // int r11 = 11;
        // int r12 = 12;
        // List_append(list, &r1);
        // List_append(list, &r2);
        // List_append(list, &r3);
        // List_next(list);
        // List_remove(list);
        // List_append(list, &r4);
        // List_first(list);
        // List_next(list);
        // List_insert_after(list, &r5);
        // List_remove(list);
        // List_append(list, &r6);
        // List_append(list, &r7);
        // List_append(list, &r8);
        // printList(list);
    }

    // Testing all methods for inserting and removing along with
    // testing if free node tracking system is implemented correctly
    {
        // int k1 = 1;
        // int k2 = 2;
        // int k3 = 3;
        // int k4 = 4;
        // int k5 = 5;
        // int k6 = 6;
        // int k7 = 7;
        // int k8 = 8;
        // int k9 = 9;
        // int k10 = 10;
        // int k11 = 11;
        // int k12 = 12;
        // int k13 = 13;
        // int k14 = 14;
        // List_append(list2, &k1);
        // List_append(list2, &k2);
        // List_append(list2, &k3);
        // List_append(list2, &k4);
        // List_append(list2, &k5);
        // List_append(list2, &k6);
        // List_append(list2, &k7);
        // List_append(list2, &k8);
        // List_append(list2, &k9);
        // List_append(list2, &k10);
        // List_remove(list2);
        // List_append(list2, &k11);
        // List_first(list2);
        // List_remove(list2);
        // List_prepend(list2, &k12);
        // List_first(list2);
        // List_next(list2);
        // List_next(list2);
        // List_next(list2);
        // List_next(list2);
        // List_remove(list2);
        // List_next(list2);
        // List_remove(list2);
        // List_insert_after(list2, &k13);
        // List_append(list2, &k14);
        // List_append(list2, &k13);
        // List_append(list2, &k13);
        // printf("%d \n", List_append(list2, &k12));
        // List_append(list2, &k14);
        // printf("Number of items in the list: %d\n\n", List_count(list2));
        // printList(list2);
    }

    // Testing functions for moving pointers
    /*
        IMPORTANT: Please ignore THE REST OF THE TESTS they works specifically in combination
        with some other tests from above. These were only for me to test certain fetures.
    */
    {
        // Test for List_first method
        {
            // printf("\n------- TEST FOR LIST_FIRST ----------\n");
            // printf("Current of the list: %p \n", list->current);
            // printf("Head of the list: %p \n", List_first(list));
            // printf("Beginning of the list: %p \n", list->head);
            // printf("Current of the list: %p \n", list->current);
            // printf("First item is: %d\n", *(int*)list->current->item);
        }

        // Test for List_last method
        {
            // printf("\n------- TEST FOR LIST_LAST ----------\n");
            // printf("Current of the list: %p \n", list->current);
            // printf("Tail of the list: %p \n", List_last(list));
            // printf("Ending of the list: %p \n", list->tail);
            // printf("Current of the list: %p \n", list->current);
        }

        // Test for List_next and List_curr method
        {
            // printf("\n------- TEST FOR LIST_NEXT and LIST_CURR----------\n");
            // printf("Head of the list: %p \n", List_first(list));
            // printf("Current of the list: %p \n", list->current);
            // printf("Current of the list: %p \n", List_curr(list));
            // printf("Next current of the list: %p \n", List_next(list));
            // printf("Next current of the list: %p \n", List_next(list));
            // printf("Next current of the list: %p \n", List_next(list));
            // printf("Next current of the list: %p \n", List_next(list));
        }

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