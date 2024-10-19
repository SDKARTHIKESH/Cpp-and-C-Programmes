// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    int len;
    char *arr;
}Stack;

void push(Stack *s, char ch);
char peek(Stack *s);
char pop(Stack *s);
int isEmpty(Stack *s);

int main() {
    char str[100];
    scanf("%[^\n]%c", &str[0]);
    
    char result[100];
    int resLen = 0;
    
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->len = 0;
    s->arr = (char *)malloc(0);
    
    int len = 0;
    while(*(str + len) != '\0') len++;
    len--;
    
    while(len >= 0) {
        char ch = *(str + len);
        printf("%c\n", ch);
        if(ch >= '0' && ch <= '9') {
            result[resLen++] = ch;
        }
        
        else if(isEmpty(s)) {
            push(s, ch);
        }

        else {
            if(ch == '+' || ch == '-') {
                if(peek(s) >= '0' && peek(s) <= '9' || peek(s) == ')') {
                    push(s, ch);
                }
                else if(peek(s) == '+' || peek(s) == '-') {
                    result[resLen++] = pop(s);
                    push(s, ch);
                }
                else {
                    result[resLen++] = pop(s);
                    while(1) {
                        if(peek(s) >= '0' && peek(s) <= '9') {
                            push(s, ch);
                            break;
                        }
                        else if(peek(s) == '+' || peek(s) == '-') {
                            result[resLen++] = pop(s);
                            push(s, ch);
                            break;
                        } else {
                            result[resLen++] = pop(s);
                        }
                    }
                }
            }
            
            else if(ch == '*' || ch == '/') {
                if(peek(s) == '*' || peek(s) == '/') {
                    result[resLen++] = pop(s);
                }
                push(s, ch);
            }
            
            else if(ch == ')') {
                push(s, ch);
            }
            
            else if(ch == '(') {
                while(peek(s) !=')') {
                    result[resLen++] = pop(s);
                }
                pop(s);
            }
        }
        
        len--;
    }

    while(!isEmpty(s)) {
        result[resLen++] = pop(s);
    }

    while(resLen > 0) {
        printf("%c", result[--resLen]);
    }
    printf("\n");
    
    return 0;
}

void push(Stack *s, char ch) {
    s->arr = (char *)realloc(s->arr, ++s->len);
    *(s->arr + s->len - 1) = ch;
}

char peek(Stack *s) {
    return *(s->arr + s->len - 1);
}

char pop(Stack *s) {
    char ch = peek(s);
    s->arr = (char *)realloc(s->arr, --s->len);
    return ch;
}

int isEmpty(Stack *s) {
    return s->len == 0;
}