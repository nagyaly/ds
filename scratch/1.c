#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
//------------------------------------------
Node* make(int data){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}
//------------------------------------------
void insertFront(int data){
    Node* new_node = make(data);
    new_node->next = head;
    head = new_node;
}
//------------------------------------------
void insertEnd(int data){
    Node* new_node = make(data);
    if(!head){          //head == NULL
        head = new_node;
        return;
    }
    Node* last = head;              //start from the head
    while(last->next){              //as long as next is not null
        last = last->next;          //move the last forward
    }
    last->next = new_node;          //attach the new_node with last node
}
//------------------------------------------
void display(){
    if(!head){
        printf("List is empty...\n");
        return;
    }
    Node* temp = head;
    while(temp){                //while(temp != NULL)
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//------------------------------------------
void deleteFirst(){
    if(!head){      //safety condition
        printf("List is empty\n");
        return;
    }
    Node* del = head;           //save first node in *del
    head = head->next;          //move the head forward
    free(del);                  //delete first node
}
//------------------------------------------
void deleteLast(){
    if(!head || !head->next){     //empty  list or single node
        free(head);
        head = NULL;
        return;
    }
    Node* del = head;
    while(del->next->next){
        del = del->next;
    }
    free(del->next);
    del->next = NULL;
}
//------------------------------------------
void insertAfter(int data, int key){
    Node* temp = head;
    while(temp && temp->data != key){
        temp = temp->next;
    }
    if(!temp){
        printf("%d not found\n", key);
        return;
    }
    Node* new_node = make(data);
    new_node->next = temp->next;
    temp->next = new_node;
}
//------------------------------------------
void insertBetween(int data, int a, int b){
    Node* temp = head;
    while(temp && temp->data != a){
        temp = temp->next;
    }
    if(!temp){
        printf("%d not found\n", a);
        return;
    }
    if(!temp->next || temp->next->data != b){
        printf("%d not found\n", b);
        return;
    }
    Node* new_node = make(data);
    new_node->next = temp->next;
    temp->next = new_node;
}
//------------------------------------------
int main(){
    insertEnd(400);
    insertFront(100);
    insertFront(200);
    insertFront(300);
    display();
    insertEnd(500);
    display();
    //~~~~~~~~~~~~~~~~~~~~~~~
    deleteFirst();
    display();
    deleteLast();
    display();
    //~~~~~~~~~~~~~~~~~~~~~~~
    insertAfter(500, 100);
    display();
    insertBetween(600, 400, 200);
    display();
    return 0;
}
