#include <stdio.h>
#include <stdbool.h>
#include "list.h"

static List lists[LIST_MAX_NUM_HEADS];
static Node nodes[LIST_MAX_NUM_NODES];

//FOR LIST HEADS
//This is the main pointer for keeping the track of free list heads
static List* currentFreeHead = &lists[0];
//This is helper pointer that will help me keep address of the highest index in array of list heads
static List* highestHead = &lists[0];
//Integer to keep track how many list heads are busy
static int numberOfListHeads = 0;


//FOR NODES
//This is the main pointer for keeping the track of free nodes
static Node* currentFreeNode = &nodes[0];
//This is helper pointer that will help me keep address of the highest index in array of nodes
static Node* highestNode = &nodes[0];
//Integer to keep track how many nodes are busy
static int numberOfListNodes = 0;

//HELPER FUNCTIONS
//Helper functions for my implementation are keeping track of nodes in reverse
//When we remove a node, the Next_free_node will connect currentFreeNode with the one we just deleted
//This way we will have connected free nodes
//When we add a node, the Prev_free_node will set the currentFreeNode to null (so
//it won't be connected among free nodes anymore)
//and the prev node will become currentFreeNode
void Prev_free_node(){
    //if currentFreeNode is not connected to any nodes, that will mean the next free
    //node will be the one at the next index in the array
    //if currentFreeNode is connected to other nodes, then we will use the last connected nodes
    //make it busy and reverse back to prev node to set it as a currentFreeNode
    if(currentFreeNode == highestNode){
        currentFreeNode = currentFreeNode + 1;
        highestNode = currentFreeNode;
    }
    else{
        Node* temp = currentFreeNode;
        currentFreeNode = currentFreeNode->prevFree;
        currentFreeNode->nextFree = NULL;
        temp->prevFree = NULL;
        
    }
}

void Next_free_node(Node* removedNode){
    currentFreeNode->nextFree = removedNode;
    removedNode->prevFree = currentFreeNode;
    currentFreeNode = removedNode;
}

//SAME FUNCTIONALITY AS DESCRIBED BELOW ARE IMPLEMENTED FOR KEEPING TRACK OF FREE HEADS
void Prev_free_list_head(){
    if(currentFreeHead == highestHead){
        currentFreeHead = currentFreeHead + 1;
        highestHead = currentFreeHead;
    }
    else{
        List* temp = currentFreeHead;
        currentFreeHead = currentFreeHead->prevFree;
        currentFreeHead->nextFree = NULL;
        temp->prevFree = NULL;
    }
}

void Next_free_list_head(List* removedHead){
    currentFreeHead->nextFree = removedHead;
    removedHead->prevFree = currentFreeHead;
    currentFreeHead = removedHead;
    // removedHead = NULL;
}

//DUMMY (for testing purposes only)
void printList(List* pList){
    if(pList == NULL){
        printf("No items in the list.\n");
    }else{
        Node* temp = pList->head;
        while(temp != NULL){
            printf("%d ", *(int*)(temp)->item);
            temp = temp->next;
        }
    }
    printf("\n");
}



// Makes a new, empty list, and returns its reference on success. 
// Returns a NULL pointer on failure.
List* List_create(){
    if(numberOfListHeads == LIST_MAX_NUM_HEADS){
        return NULL;
    }else{
        currentFreeHead->head = NULL;
        currentFreeHead->tail = NULL;
        currentFreeHead->current = NULL;
        currentFreeHead->numberOfItems = 0;
        numberOfListHeads++;
        List* temp = currentFreeHead;
        Prev_free_list_head();
        return temp;
    }
}

// Returns the number of items in pList.
int List_count(List* pList){
    return pList->numberOfItems;
}

// Returns a pointer to the first item in pList and makes the first item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_first(List* pList){
    if(pList == NULL){
        return NULL;
    }else if(pList->head == NULL){
        pList->current = NULL;
        return NULL;
    }else{
        pList->current = pList->head;
        return pList->current->item;
    }
}

// Returns a pointer to the last item in pList and makes the last item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_last(List* pList){
    if(pList == NULL){
        return NULL;
    }else if(pList->head == NULL){
        pList->current = NULL;
        return NULL;
    }else{
        pList->current = pList->tail;
        return pList->tail->item;
    }
} 

// Advances pList's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the pList, a NULL pointer 
// is returned and the current item is set to be beyond end of pList.
void* List_next(List* pList){
    if(pList->current == NULL){
        return NULL;
    }else if(pList->current == (void*)LIST_OOB_END){
        pList->current = (void*)LIST_OOB_END;
        return NULL;
    }else if(pList->current->next == NULL){
        pList->current = (void*)LIST_OOB_END;
        return NULL;
    }else{
        pList->current = pList->current->next;
        return pList->current->item;
    }
}

// Backs up pList's current item by one, and returns a pointer to the new current item. 
// If this operation backs up the current item beyond the start of the pList, a NULL pointer 
// is returned and the current item is set to be before the start of pList.
void* List_prev(List* pList){
    if(pList->current == NULL){
        return NULL;
    }else if(pList->current == (void*)LIST_OOB_START){
        pList->current = (void*)LIST_OOB_START;
        return NULL;
    }else if(pList->current->prev == NULL){
        pList->current = (void*)LIST_OOB_START;
        return NULL;
    }else{
        pList->current = pList->current->prev;
        return pList->current->item;
    }
}

// Returns a pointer to the current item in pList.
void* List_curr(List* pList){
    if(pList->current == NULL){
        return NULL;
    }else{
        return pList->current->item;
    }
}

// Adds the new item to pList directly after the current item, and makes item the current item. 
// If the current pointer is before the start of the pList, the item is added at the start. If 
// the current pointer is beyond the end of the pList, the item is added at the end. 
// Returns 0 on success, -1 on failure.
int List_insert_after(List* pList, void* pItem){
    if(numberOfListNodes == LIST_MAX_NUM_NODES){
        return -1;
    }else if(pList == NULL){
        return -1;
    }else{
        if(pList->current == pList->tail){
            return List_append(pList, pItem);
        }else if(pList->current == (void*)LIST_OOB_END){
            return List_append(pList, pItem);
        }else if(pList->current == (void*)LIST_OOB_START){
            return List_prepend(pList, pItem);
        }else{
            Node* temp = pList->current->next;
            pList->current->next = currentFreeNode;
            currentFreeNode->prev = pList->current;
            currentFreeNode->next = temp;
            temp->prev = currentFreeNode;
            pList->current = currentFreeNode;
            pList->current->item = pItem;

            Prev_free_node();
            pList->numberOfItems++;
            numberOfListNodes++;
        }
        return 0;
    }
}

// Adds item to pList directly before the current item, and makes the new item the current one. 
// If the current pointer is before the start of the pList, the item is added at the start. 
// If the current pointer is beyond the end of the pList, the item is added at the end. 
// Returns 0 on success, -1 on failure.
int List_insert_before(List* pList, void* pItem){
    if(numberOfListNodes == LIST_MAX_NUM_NODES){
        return -1;
    }else if(pList == NULL){
        return -1;
    }else{
        if(pList->current == pList->head){
            return List_prepend(pList, pItem);
        }else if(pList->current == (void*)LIST_OOB_END){
            return List_append(pList, pItem);
        }else if(pList->current == (void*)LIST_OOB_START){
            return List_prepend(pList, pItem);
        }else{
            Node* temp = pList->current->prev;
            pList->current->prev = currentFreeNode;
            currentFreeNode->next = pList->current;
            currentFreeNode->prev = temp;
            temp->next = currentFreeNode;
            pList->current = currentFreeNode;
            pList->current->item = pItem;

            Prev_free_node();
            pList->numberOfItems++;
            numberOfListNodes++;
        } 
        return 0;    
    }
}

// Adds item to the end of pList, and makes the new item the current one. 
// Returns 0 on success, -1 on failure.
int List_append(List* pList, void* pItem){
    if(numberOfListNodes == LIST_MAX_NUM_NODES){
        return -1;
    }else if(pList == NULL){
        return -1;
    }else{
        if(pList->head == NULL){
            pList->head = currentFreeNode;
            pList->current = currentFreeNode;
            pList->tail = currentFreeNode;

            pList->tail->item = pItem;

            pList->tail->next = NULL;
            pList->tail->prev = NULL;
            Prev_free_node();
        }else{
            pList->tail->next = currentFreeNode;
            currentFreeNode->prev = pList->tail;
            pList->tail = currentFreeNode;
            pList->current = currentFreeNode;
            pList->tail->item = pItem;
            pList->tail->next = NULL;

            Prev_free_node();
        }
        pList->numberOfItems++;
        numberOfListNodes++;
        return 0;
    }
}

// Adds item to the front of pList, and makes the new item the current one. 
// Returns 0 on success, -1 on failure.
int List_prepend(List* pList, void* pItem){
    if(numberOfListNodes == LIST_MAX_NUM_NODES){
        return -1;
    }else if(pList == NULL){
        return -1;
    }else{
        if(pList->head == NULL){
            pList->head = currentFreeNode;
            pList->current = currentFreeNode;
            pList->tail = currentFreeNode;

            pList->head->item = pItem;
            pList->head->next = NULL;
            pList->head->prev = NULL;

            Prev_free_node();
        }else{
            pList->head->prev = currentFreeNode;
            currentFreeNode->next = pList->head;
            pList->head = currentFreeNode;
            pList->current = currentFreeNode;
            pList->head->item = pItem;
            pList->head->prev = NULL;
            Prev_free_node();
        }
        pList->numberOfItems++;
        numberOfListNodes++;
        return 0;
    }
}

// Return current item and take it out of pList. Make the next item the current one.
// If the current pointer is before the start of the pList, or beyond the end of the pList,
// then do not change the pList and return NULL.
void* List_remove(List* pList){
    if(pList->current == (void*)LIST_OOB_START || pList->current == (void*)LIST_OOB_END){
        return NULL;
    }else{
        if(pList->current == pList->tail){
            return List_trim(pList);
        }else if(pList->numberOfItems == 1){
            return List_trim(pList);
        }else if(pList->current == pList->head){
            Node* temp = pList->head;
            pList->head = pList->head->next;
            pList->current = pList->head;
            // pList->head->prev = NULL;
            void* currentItem = temp->item;
            // temp->next = NULL;
            temp->item = NULL;
            
            Next_free_node(temp);
            pList->numberOfItems--;
            numberOfListNodes--;
            return currentItem;
        }else{
            Node* temp = pList->current;
            pList->current = temp->next;
            pList->current->prev = temp->prev;
            temp->prev->next = pList->current;
            // temp->prev = NULL;
            // temp->next = NULL;
            Next_free_node(temp);
            pList->numberOfItems--;
            numberOfListNodes--;
            return temp->item;
        }
    }
}

// Return last item and take it out of pList. Make the new last item the current one.
// Return NULL if pList is initially empty.
void* List_trim(List* pList){
    if(pList->tail == NULL){
        return NULL;
    }else if(pList->numberOfItems == 1){
        Node* temp = pList->tail;
        pList->tail = NULL;
        pList->current = NULL;
        pList->head = NULL;
        Next_free_node(temp);
        pList->numberOfItems--;
        numberOfListNodes--;
        return temp->item;
    }else{
        Node* temp = pList->tail;
        pList->current = temp->prev;
        void* tempItem = temp->item;
        // printf("Number of items in the list: %d\n", List_count(pList));
        // printf("ADDRgf: %p\n", temp->prev);
        // printf("ADDRgf: %p\n", temp->prev->next);
        pList->tail = temp->prev;
        // temp->prev->next = NULL;
        
        temp->prev = NULL;

        Next_free_node(temp);
        pList->numberOfItems--;
        numberOfListNodes--;
        return tempItem;
    }
}


// Adds pList2 to the end of pList1. The current pointer is set to the current pointer of pList1. 
// pList2 no longer exists after the operation; its head is available
// for future operations.
void List_concat(List* pList1, List* pList2){
    if(pList1->head == NULL || pList2->head == NULL){
        return;
    }else{
        pList1->tail->next = pList2->head;
        pList2->head->prev = pList1->tail;
        pList1->tail = pList2->tail;
        pList1->current = pList1->tail;
        pList1->numberOfItems = pList1->numberOfItems + pList2->numberOfItems;
        List* temp = pList2;
        pList2->current = NULL;
        pList2->head = NULL;
        pList2->tail = NULL;
        pList1->tail->next = NULL;
        pList2->numberOfItems = 0;
        numberOfListHeads--;
        Next_free_list_head(temp);
    }
}

// Delete pList. pItemFreeFn is a pointer to a routine that frees an item. 
// It should be invoked (within List_free) as: (*pItemFreeFn)(itemToBeFreedFromNode);
// pList and all its nodes no longer exists after the operation; its head and nodes are 
// available for future operations.
typedef void (*FREE_FN)(void* pItem);
void List_free(List* pList, FREE_FN pItemFreeFn){
    // List* removedHead = pList->head;
    for(int i = pList->numberOfItems; i > 0; i--){
        void* itemToDelete = List_trim(pList);
        (*pItemFreeFn)(itemToDelete);
    }
    Next_free_list_head(pList);
    numberOfListHeads--;
}

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
void* List_search(List* pList, COMPARATOR_FN pComparator, void* pComparisonArg){
    return 0;
}