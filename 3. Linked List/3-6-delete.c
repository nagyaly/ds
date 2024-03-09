#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
//---------------------------------------------------
Node* make(int data){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}
//---------------------------------------------------
void display(){
    Node* temp = head;
    while(temp){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//---------------------------------------------------
void insertFront(int data){
    Node* new_node = make(data);
    new_node->next = head;
    head = new_node;
}
//---------------------------------------------------
void deleteFirst(){
    if(!head){
        printf("List is empty\n");
        return;
    }
    Node* del = head;               //pointer to first node
    head = head->next;              //move the head forward
    free(del);                      //free first node
}
//---------------------------------------------------
void deleteLast(){
    if(!head || !head->next){     //list is empty or has 1 node
        free(head);
        head = NULL;
        return;
    }
    //find the last node
    Node* del = head;
    while(del->next->next){
        del = del->next;
    }
    free(del->next);            //delete data
    del->next = NULL;           //set pointer with null
}
//---------------------------------------------------
void deleteNode(int key){
    //to be implemented
}
//---------------------------------------------------
int main(){
    insertFront(100);
    insertFront(200);
    insertFront(300);
    insertFront(400);
    display();

    deleteFirst();
    display();

    deleteLast();
    display();
    return 0;
}
