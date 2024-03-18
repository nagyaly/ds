#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
typedef struct{
    Node* top;      //pointer to the top Node
    int size;       //elements count
    int capacity;   //max number of elements
} Stack;
//-----------------------------------------
Stack makeStack(int capacity){
    Stack new_stack;
    new_stack.top = NULL;
    new_stack.size = 0;         //zero elements
    new_stack.capacity = capacity;
    return new_stack;
}
//-----------------------------------------
Node* makeNode(int data){
    Node* p = (Node*) malloc(sizeof(Node));     //DMA, require free
    p->data = data;
    p->next = NULL;
    return p;
}
//-----------------------------------------
void push(Stack* s, int data){
    if(s->size == s->capacity){
        printf("Stack Overflow\n");
        return;
    }
    Node* new_node = makeNode(data);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;                  //increase the size
}
//-----------------------------------------
int pop(Stack* s){
    if(s->size == 0){
        printf("Stack Underflow\n");
        return 0;
    }
    Node* del = s->top;
    s->top = s->top->next;          //move the top 1 stop down
    int data = del->data;
    free(del);
    s->size--;                      //derecement the size
    return data;
}
//-----------------------------------------
int empty(Stack* s){
    if(s->size == 0){
        return 1;
    }
    return 0;
}
//-----------------------------------------
void destroyStack(Stack* s){
    while(!empty(s)){
        pop(s);
    }
}
//-----------------------------------------
void display(Stack* s){
    //temp local stack
    Stack temp = makeStack(s->capacity);
    while(!empty(s)){
        int x = pop(s);             //pop from the original stack
        printf("%d\n", x);          //** do any operation
        push(&temp, x);             //push data to temp stack
    }
    //move data back from the temp stack to the original stack
    while(!empty(&temp)){
        int x = pop(&temp);         //pop from the temp stack
        push(s, x);                 //push data back to the original stack
    }
}
//-----------------------------------------
int sumStack(Stack* s){
    int sum = 0;
    Stack temp = makeStack(s->capacity);
    while(!empty(s)){
        int x = pop(s);
        sum += x;                   //** do any operation
        push(&temp, x);
    }
    while(!empty(&temp)){
        int x = pop(&temp); 
        push(s, x);
    }
    return sum;
}
//-----------------------------------------
void removeData(Stack* s, int data){
    Stack temp = makeStack(s->capacity);
    while(!empty(s)){
        int x = pop(s);
        if(x != data){
            push(&temp, x);         //save
        }
        //else... just discard x
    }
    while(!empty(&temp)){
        int x = pop(&temp); 
        push(s, x);
    }
}
//-----------------------------------------
void removeOdd(Stack* s){
    //to be implemented
}
//-----------------------------------------
void reverseStack(Stack* s){
    //to be implemented
}
//-----------------------------------------
int main(){
    Stack s1 = makeStack(4);
    push(&s1, 100);
    push(&s1, 150);
    push(&s1, 170);
    push(&s1, 120);

    Stack s2 = makeStack(2);
    push(&s2, 200);
    push(&s2, 300);

    printf("---------------\n");
    display(&s1);
    printf("---------------\n");
    printf("Stack 1 sum: %d\n", sumStack(&s1));
    printf("---------------\n");
    display(&s2);
    printf("Stack 2 sum: %d\n", sumStack(&s2));

    removeData(&s1, 150);
    printf("---------------\n");
    display(&s1);
    printf("---------------\n");
    printf("Stack 1 sum: %d\n", sumStack(&s1));

    /*
    Stack s1 = makeStack(4);
    push(&s1, 100);
    push(&s1, 150);
    push(&s1, 170);
    push(&s1, 120);
    push(&s1, 90);
    push(&s1, 90);
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));

    printf("---------------\n");

    Stack s2 = makeStack(2);
    push(&s2, 200);
    push(&s2, 555);
    push(&s2, 666);
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));

    */
    destroyStack(&s1);
    destroyStack(&s2);
    return 0;
}