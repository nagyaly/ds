#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int* arr;
    int top;
    int capacity;
} Stack;
//-----------------------------------------
Stack makeStack(int capacity){
    Stack s;
    s.arr = (int*) malloc(sizeof(int) * capacity);      //DMA, require free()
    s.top = 0;
    s.capacity = capacity;
    return s;
}
//-----------------------------------------
void push(Stack* s, int data){
    if(s->top == s->capacity){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[s->top] = data;
    s->top++;
}
//-----------------------------------------
int pop(Stack* s){
    if(s->top == 0){
        printf("Stack Underflow\n");
        return 0;
    }
    s->top--;
    return s->arr[s->top];
}
//-----------------------------------------
int empty(Stack* s){
    if(s->top == 0){
        return 1;
    }
    return 0;
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
void destroyStack(Stack* s){
    free(s->arr);
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



/*
    a + b       infix
    ab+         postfix

    a b c       operands
    + *         operators
    (a + b) * c     infix notation
    a b + c *       postfix             no ( )
*/