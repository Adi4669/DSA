#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char c){
    if(top == max - 1){
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek(){
    if(top == -1) return '\0';
    return stack[top];
}

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[]){
    char postfix[max];
    int i, k = 0;
    char c;
    for(i = 0; infix[i] != '\0'; i++){
        c = infix[i];
        if(isalnum(c)){
            postfix[k++] = c;
            postfix[k++] = ' ';
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while((top != -1) && peek() != '('){
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop(); // remove '('
        }
        else{
            while((top != -1) && precedence(peek()) >= precedence(c)){
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        }
    }

    while(top != -1){
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main(){
    char infix[max];
    printf("Enter an Infix Expression: ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix);
    return 0;
}