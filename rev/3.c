#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node Node;
struct Node{
    char data;
    Node* next;
};
//---------------------------
Node* makeNode(char data){
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
void push(Stack* s, char data){
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
char pop(Stack* s){
    if(s->size == 0){
        printf("Stack Underflow\n");
        return ' ';
    }
    Node* del = s->top;
    char data = del->data;
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
        printf("Stack is empty noting to show\n");
        return;
    }
    Stack* temp = makeStack(s->max);
    while(!empty(s)){
        char x = pop(s);         //pop from stack
        printf("| %c |\n", x); //print
        push(temp, x);

    }
    printf("------\n");
    //return data from temp to original stack
    while(!empty(temp)){
        char x = pop(temp);
        push(s, x);
    }
    freeStack(temp);
}
//---------------------------
int validateExpression(char* exp){
    //make stack with same length as array
    Stack* s1 = makeStack(strlen(exp));
    int i;
    int valid = 1;
    for(i=0;i<strlen(exp);i++){
        char curr = exp[i];
        if(curr == ' '){        //skip space
            continue;
        }
        if(curr == '('){
            push(s1, curr);
        }
        else if(curr == ')'){
            char res = pop(s1);
            if(res == ' '){ //no closing found ...
                valid = 0;
                break;
            }
        }
        //uncomment these lines for tracing only...
        // printf("%c\n", curr);        //for tracing
        // displayStack(s1);                //for tracing
    }
    if(valid && empty(s1)){
        return 1;
    }
    else{
        return 0;
    }
    freeStack(s1);
}
//---------------------------
int main(){
    // char exp[50] = "((E+H)+((C-D)-(A+B)))";       
    char exp[50];
    printf("Expression: ");
    // scanf("%s", exp);        //dont enter spaces
    fgets(exp, 50, stdin);      // array, maxSize, stding
    printf("Your Expression: %s\n", exp);
    int valid = validateExpression(exp);
    if(valid){
        printf("Valid Expression\n");
    }
    else{
        printf("Invalid Expression\n");
    }
    return 0;
}