#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-------------------------------------------
typedef struct Student Student;
struct Student{
    int id;
    char name[32];
    float gpa;
};
//-------------------------------------------
typedef struct Node Node;
struct Node{
    Student data;
    Node* next;
};
//-------------------------------------------
Node* head = NULL;
//-------------------------------------------
Node* makeNode(int id, char* name, float gpa){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data.id = id;
    strcpy(p->data.name, name);
    p->data.gpa = gpa;
    p->next = NULL;
    return p;
}
//-------------------------------------------
void displayList(){
    if(head == NULL){
        printf("List is empty !\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("[%d, %s, %.2f] -> ", temp->data.id, temp->data.name, temp->data.gpa);
        temp = temp->next;      //move temp forward
    }
    printf("\n");
}
//-------------------------------------------
void insertEnd(int id, char* name, float gpa){
    Node* new_node = makeNode(id, name, gpa);    //pass data to makeNode
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* last = head;
    //as long as last does not point on the last node....
    while(last->next != NULL){
        last = last->next;      //move last forward
    }
    //at the end, last will point on the last node... 
    last->next = new_node;
}
//-------------------------------------------
void insertAtIndex(int index, int id, char* name, float gpa){
    Node* new_node = makeNode(id, name, gpa);    //pass data to makeNode
    if(head == NULL){
        head = new_node;
        return;
    }
    if(index == 0){         //insert front...
        new_node->next = head;
        head = new_node;
        return;
    }
    Node* temp = head;
    //move temp number of steps equal to index...
    //but stop anyway at last node !!
    while(index > 1 && temp->next != NULL){
        temp = temp->next;
        index--;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
//-------------------------------------------
void insertAfter(int targetId, int id, char* name, float gpa){
    Node* find = head;
    while(find != NULL && find->data.id != targetId){
        find = find->next;
    }
    if(find == NULL){
        printf("id %d not found\n", targetId);
        return;
    }
    Node* new_node = makeNode(id, name, gpa);    //pass data to makeNode
    new_node->next = find->next;
    find->next = new_node;
}
//-------------------------------------------
int main(){
    insertEnd(10, "Ahmed", 3.0);
    insertEnd(20, "Saeed", 3.9);
    insertEnd(30, "Karim", 2.5);
    insertAtIndex(2, 40, "Hassan", 3.2);
    insertAfter(21, 50, "Begad", 1.2);
    displayList();
    return 0;
}
//-------------------------------------------