#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
	int data;
    Node* next;
};
//-------------------------------------------------------------------
//head pointer is the start of the linked list
//we initialize it to NULL assuming the list is empty
Node* head = NULL;
//-------------------------------------------------------------------
Node* make(int data){
    //allocate sizeof(Node) bytes from the heap
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = data;     //put the received data in the node
    p->next = NULL;     //assume node point to nothing
    return p;           //return value of pointer (address of node)
}
//-------------------------------------------------------------------
int main(){
    Node* n1 = make(100);       //*n1 -> [100, *] -> NULL
    Node* n2 = make(200);       //*n2 -> [200, *] -> NULL
    //now we want to put n1 and n2 together in the linked list
	return 0;
}