#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j;
    int len = strlen(infix);
    char stack[MAX_EXPR_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        // If the scanned character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the scanned character is '(', push it to the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // If the scanned character is ')', pop and add to the postfix expression from the stack 
        // until an '(' is encountered
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return; // Invalid expression
            else
                top--;
        }
        // If an operator is scanned
        else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    // Pop all the remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(')
            return; // Invalid expression
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0;  // Remove trailing newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}