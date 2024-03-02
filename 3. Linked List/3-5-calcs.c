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
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
//-------------------------------------------------------------------
int sum(){
    //as usual make a temp pointer
    Node* temp = head;
    int sum = 0;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}
//-------------------------------------------------------------------
int main(){
    insertFront(100);
    insertFront(200);
    insertEnd(300);
    display();
    printf("SUM: %d\n", sum());
	return 0;
}