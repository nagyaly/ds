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
void insertFront(int data){
    Node* new_node = make(data);
    new_node->next = head;
    head = new_node;
}
//-------------------------------------------------------------------
void display(){
    //!!! DO NOT MOVE HEAD UNLESS YOU WANT TO INSERT/DELETE FIRST NODE !!!
    //make a temp pointer to preserve the head.
    Node* temp = head;
    while(temp != NULL){
        //print the data using the temp
        printf("%d->", temp->data);
        //move the temp forward
        temp = temp->next;
    }
    printf("\n");               //just a new line :)
}
//-------------------------------------------------------------------
int main(){
    insertFront(100);
    insertFront(200);
    display();
	return 0;
}