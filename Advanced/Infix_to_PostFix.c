#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int len;
    char *arr;
} Stack;

char peek(Stack *s) {
    return *(s->arr + s->len - 1);
}

void push(Stack *s, char ch) {
    s->arr = (char *)realloc(s->arr, ++s->len);
    *(s->arr + s->len - 1) = ch;
}

char pop(Stack *s) {
    char ch = peek(s);
    s->arr = (char *)realloc(s->arr, --s->len);
    return ch;    
}

int isEmpty(Stack *s) {
    return s->len <= 0;
}

int precedence(char op) {
    switch(op) {
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

int isOp(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main() {
    char str[100];
    scanf("%[^\n]", &str[0]);

    int len = 0;

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->len = 0;
    s->arr = (char *)malloc(0);

    char result[100];
    int resLen = 0;

    while(*(str + len) != '\0') {
        char ch = *(str + len);
        if(isalnum(ch)) {
            result[resLen++] = ch;
        }

        else if(ch == '(') {
            push(s, ch);
        }

        else if(ch == ')') {
            while(peek(s) != '(') {
                result[resLen++] = pop(s);
            }
            pop(s);
        }

        else if(isOp(ch)) {
            while(!isEmpty(s) && (precedence(peek(s)) >= precedence(ch))) {
                result[resLen++] = pop(s);
            }
            push(s, ch);
        }

        len++;
    }

    while(!isEmpty(s)) {
        result[resLen++] = pop(s);
    }

    result[resLen] = '\0';

    printf("\n%s\n", result);

    return 0;

}