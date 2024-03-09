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
void insertEnd(int data){
    Node* new_node = make(data);
    if(!head){
        head = new_node;
        return;
    }
    Node* last = head;
    while(last->next){
        last= last->next;
    }
    last->next = new_node;
}
//---------------------------------------------------
void insertAfter(int data, int key){
    //find the desired node (key)
    Node* temp = head;
    while(temp && temp->data != key){
        temp = temp->next;
    }
    if(!temp){              //if node (key) not found
        printf("%d Not found\n", key);
        return;
    }
    Node* new_node = make(data);
    new_node->next = temp->next;
    temp->next = new_node;
}
//---------------------------------------------------
void insertBetween(int data, int a, int b){
    //find the first node (a)
    Node* temp = head;
    while(temp && temp->data != a){
        temp = temp->next;
    }
    if(!temp){              //if first node (a) not found
        printf("%d Not found\n", a);
        return;
    }
    if(!temp->next || temp->next->data != b){      //if second node (b) not found
        printf("%d Not found\n", b);
        return;
    }
    Node* new_node = make(data);
    new_node->next = temp->next;
    temp->next = new_node;
}
//---------------------------------------------------
int main(){
    insertFront(100);
    insertEnd(200);
    display();

    insertAfter(500, 100);
    display();
    
    insertBetween(900, 100, 500);
    display();
    return 0;
}
