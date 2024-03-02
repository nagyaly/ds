#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
	int data;
    Node* next;
};
Node* head = NULL;
//-------------------------------------------------------------------
Node* make(int data){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}
//-------------------------------------------------------------------
/*
    the visualization assume the linked list contain the 100,
    *head -> [100, *] -> NULL
*/
void insertFront(int data){
    //make new node using our function
    Node* new_node = make(data);                //*new_node -> [data, *] -> NULL

    //now both head and next of new node point to the first node (100)
    // *head ------------------> [100, *] -> NULL
    // *new_node -> [200, *] ______⤴
    new_node->next = head;

    //move the head to point on the new node
    // *head -> [200, *] -> [100, *] -> NULL
    head = new_node;
}
//-------------------------------------------------------------------
int main(){
    insertFront(100);
    insertFront(200);
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
	return 0;
}