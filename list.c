#include <stdio.h>
#include <stdbool.h>
#include "list.h"

static List lists[LIST_MAX_NUM_HEADS];
static Node nodes[LIST_MAX_NUM_NODES];

//FOR LIST HEADS
static List* currentFreeHead = &lists[0];
static int numberOfListHeads = 0;
//FOR NODES
//This is the main pointer for keeping the track
static Node* currentFreeNode = &nodes[0];
//This is helper pointer that will help me keep address of the highest index in array of nodes
static Node* highestNode = &nodes[0];
//Integer to keep track how many nodes are busy
static int numberOfListNodes = 0;


// Makes a new, empty list, and returns its reference on success. 
// Returns a NULL pointer on failure.
List* List_create(){
    if(numberOfListHeads == LIST_MAX_NUM_HEADS){
        return NULL;
    }else{
        currentFreeHead->head = NULL;
        currentFreeHead->tail = NULL;
        currentFreeHead->current = NULL;
        currentFreeHead->indexInArray = numberOfListHeads;
        currentFreeHead->numberOfItems = 0;
        numberOfListHeads++;
        // printf("Current address: %p\n", currentFreeHead);
        currentFreeHead = &lists[numberOfListHeads];
        // printf("Current address: %p\n", currentFreeHead);
        return &lists[numberOfListHeads-1];
    }
}

// List* List_R(List* list){
//     list->currentItem = NULL;
//     list->isFree = false;
//     list->numberOfItems = 0;
// }

// Returns the number of items in pList.
int List_count(List* pList){
    return pList->numberOfItems;
}

// Returns a pointer to the first item in pList and makes the first item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_first(List* pList){
    if(pList->head == NULL){
        pList->current = NULL;
        return NULL;
    }else{
        pList->current = pList->head;
        return pList->head;
    }
}

// Returns a pointer to the last item in pList and makes the last item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_last(List* pList){
    if(pList->head == NULL){
        pList->current = NULL;
        return NULL;
    }else{
        pList->current = pList->tail;
        return pList->tail;
    }
} 

// Advances pList's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the pList, a NULL pointer 
// is returned and the current item is set to be beyond end of pList.
void* List_next(List* pList){
    if(pList->current->next == NULL){
        pList->current = (void*)LIST_OOB_END;
        return NULL;
    }else{
        pList->current = pList->current->next;
        return pList->current;
    }
}

// Backs up pList's current item by one, and returns a pointer to the new current item. 
// If this operation backs up the current item beyond the start of the pList, a NULL pointer 
// is returned and the current item is set to be before the start of pList.
void* List_prev(List* pList){
    if(pList->current->prev == NULL){
        pList->current = (void*)LIST_OOB_START;
        return NULL;
    }else{
        pList->current = pList->current->prev;
        return pList->current;
    }
}

// Returns a pointer to the current item in pList.
void* List_curr(List* pList){
    return pList->current;
}

// Adds the new item to pList directly after the current item, and makes item the current item. 
// If the current pointer is before the start of the pList, the item is added at the start. If 
// the current pointer is beyond the end of the pList, the item is added at the end. 
// Returns 0 on success, -1 on failure.
int List_insert_after(List* pList, void* pItem);

//DUMMY
void printList(List* pList){
    Node* temp = pList->head;
    while(temp != NULL){
        printf("%d ", *(int*)(temp)->item);
        temp = temp->next;
    }
    printf("\n");
    // printf("%d ", *(int*)(temp)->item);
    // temp = temp->next;
    // printf("%d ", *(int*)(temp)->item);
    // temp = temp->next;
    // printf("%d ", *(int*)(temp)->item);
}

// Adds item to pList directly before the current item, and makes the new item the current one. 
// If the current pointer is before the start of the pList, the item is added at the start. 
// If the current pointer is beyond the end of the pList, the item is added at the end. 
// Returns 0 on success, -1 on failure.
int List_insert_before(List* pList, void* pItem);

// Adds item to the end of pList, and makes the new item the current one. 
// Returns 0 on success, -1 on failure.
int List_append(List* pList, void* pItem){
    if(numberOfListNodes == LIST_MAX_NUM_NODES){
        return -1;
    }else{
        if(pList->head == NULL){
            pList->head = currentFreeNode;
            pList->current = currentFreeNode;
            pList->tail = currentFreeNode;

            pList->tail->item = pItem;

            // printf("%d \n", *(int*)pList->head->item);
            // printf("HERE\n");
            pList->tail->next = NULL;
            pList->tail->prev = NULL;

            if(currentFreeNode == highestNode){
                // printf("Current address: %p\n", currentFreeNode);
                currentFreeNode = currentFreeNode + 1;
                // printf("Current address: %p\n", currentFreeNode);
                highestNode = currentFreeNode;
                // printf("HigestNode address: %p\n", currentFreeNode);
            }else{
                currentFreeNode = currentFreeNode->prev;
            }
        }else{
            pList->tail->next = currentFreeNode;
            // printf("Address: %p \n", pList->tail);
            // printf("Current address: %p\n", currentFreeNode);
            // printf("Next Address: %p \n", pList->tail->next);
            pList->tail->next->prev = pList->tail;
            pList->tail = currentFreeNode;
            pList->current = currentFreeNode;
            pList->current->item = pItem;
            // printf("Item: %d \n", *(int*)pList->tail->item);
            // printf("Address: %p \n", pList->tail);
            // printf("HERE 22\n");
            if(currentFreeNode == highestNode){
                // printf("Current address: %p\n", currentFreeNode);
                currentFreeNode = currentFreeNode + 1;
                // printf("Current address: %p\n", currentFreeNode);
                highestNode = currentFreeNode;
                // printf("HigestNode address: %p\n", currentFreeNode);
            }else{
                currentFreeNode = currentFreeNode->prev;
            }
        }
        pList->numberOfItems++;
        numberOfListNodes++;
        return 0;
    }
}

// Adds item to the front of pList, and makes the new item the current one. 
// Returns 0 on success, -1 on failure.
int List_prepend(List* pList, void* pItem);

// Return current item and take it out of pList. Make the next item the current one.
// If the current pointer is before the start of the pList, or beyond the end of the pList,
// then do not change the pList and return NULL.
void* List_remove(List* pList);

// Return last item and take it out of pList. Make the new last item the current one.
// Return NULL if pList is initially empty.
void* List_trim(List* pList);

// Adds pList2 to the end of pList1. The current pointer is set to the current pointer of pList1. 
// pList2 no longer exists after the operation; its head is available
// for future operations.
void List_concat(List* pList1, List* pList2);

// Delete pList. pItemFreeFn is a pointer to a routine that frees an item. 
// It should be invoked (within List_free) as: (*pItemFreeFn)(itemToBeFreedFromNode);
// pList and all its nodes no longer exists after the operation; its head and nodes are 
// available for future operations.
typedef void (*FREE_FN)(void* pItem);
void List_free(List* pList, FREE_FN pItemFreeFn);

// Search pList, starting at the current item, until the end is reached or a match is found. 
// In this context, a match is determined by the comparator parameter. This parameter is a
// pointer to a routine that takes as its first argument an item pointer, and as its second 
// argument pComparisonArg. Comparator returns 0 if the item and comparisonArg don't match, 
// or 1 if they do. Exactly what constitutes a match is up to the implementor of comparator. 
// 
// If a match is found, the current pointer is left at the matched item and the pointer to 
// that item is returned. If no match is found, the current pointer is left beyond the end of 
// the list and a NULL pointer is returned.
// 
// If the current pointer is before the start of the pList, then start searching from
// the first node in the list (if any).
typedef bool (*COMPARATOR_FN)(void* pItem, void* pComparisonArg);
void* List_search(List* pList, COMPARATOR_FN pComparator, void* pComparisonArg);