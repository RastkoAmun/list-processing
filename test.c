#include <stdio.h>
#include <stdbool.h>

#define LIST_MAX_NUM_HEADS 10
#define LIST_MAX_NUM_NODES 100

static int lists[LIST_MAX_NUM_HEADS];
static int nodes[LIST_MAX_NUM_NODES];

int main(){
    int arr[10];
    int* p1 = &arr[7];
    int* p2 = &arr[7];
    printf("%d \n", p1 == &arr[7]);
    printf("%d \n", p1 == &arr[8]);

    return 0;
}