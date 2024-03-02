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
    Node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//-------------------------------------------------------------------
void insertEnd(int data){
    Node* new_node = make(data);
    if(head == NULL){           //if list is empty
        head = new_node;
        return;         //close the function
    }
    //go find the last node (with next is NULL)
    Node* temp = head;
    while(temp->next != NULL){
        //move the temp forward
        temp = temp->next;
    }
    //make the next of last node point to the new node
    temp->next = new_node;
}
//-------------------------------------------------------------------
int main(){
    insertFront(100);
    insertFront(200);
    insertEnd(300);
    display();
	return 0;
}