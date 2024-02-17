#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    linked lists can be used to create arrays that are not adjacent in memory,
    in other words, traditional array (int arr[100]) requires a complete
    (100 * 4 = 400 bytes) block of memory, and this is not memory efficient.

    but we can group the data with a pointer for the next element (node)
    [10|*]-> [25|*]-> [40|*]-> [50|*]-> NULL
    now data can be scattered in the memory, 
    its not required that all data must adjacent.
*/
typedef struct Node Node;
struct Node{
	int data;
    Node* next;
};
int main(){
    printf("Nothing here yet...");
	return 0;
}