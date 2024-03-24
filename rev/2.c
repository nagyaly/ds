#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
//---------------------------
Node* makeNode(int data){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}
//---------------------------
typedef struct Stack Stack;
struct Stack{
    Node* top;
    int size;           //count
    int max;            //capacity
};
//---------------------------
Stack* makeStack(int max){
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = NULL; 
    new_stack->size = 0; 
    new_stack->max = max;
    return new_stack; 
}
//---------------------------
void push(Stack* s, int data){
    if(s->size == s->max){
        printf("Stack Overflow\n");
        return;
    }
    Node* new_node = makeNode(data);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}
//---------------------------
int pop(Stack* s){
    if(s->size == 0){
        printf("Stack Underflow\n");
        return 0;
    }
    Node* del = s->top;
    int data = del->data;
    s->top = s->top->next;
    free(del);
    s->size--;
    return data;
}
//---------------------------
int empty(Stack* s){
    if(s->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}
//---------------------------
void freeStack(Stack* s){
    //free node one by one
    while(!empty(s)){
        pop(s);
    }
    //free the stack structure itself
    free(s);
}
//---------------------------
void displayStack(Stack* s){
    if(empty(s)){
        printf("Stack is empty\n");
        return;
    }
    Stack* temp = makeStack(s->max);
    while(!empty(s)){
        int x = pop(s);         //pop from stack
        printf("| %2d |\n", x); //print
        push(temp, x);

    }
    printf("------\n");
    //return data from temp to original stack
    while(!empty(temp)){
        int x = pop(temp);
        push(s, x);
    }
    freeStack(temp);
}
//---------------------------
int main(){
    Stack* s1 = makeStack(4);
    printf("Stack empty: %d\n", empty(s1));
    push(s1, 10);
    push(s1, 20);
    push(s1, 15);
    push(s1, 9);
    printf("Stack empty: %d\n", empty(s1));
    displayStack(s1);

    freeStack(s1);
    return 0;
}