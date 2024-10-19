// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    Node *next;
    int data;
};

void remove_dup(Node **head) {
    Node *temp = *head;
    int prev = -1;
    while(temp->next != NULL) {
        if(temp->data == prev) {
            temp->data = temp->next->data;
            temp->next = temp->next->next;
        }
        prev = temp->data;
        temp = temp->next;
        if(temp == NULL) break;
    }
}

void print(Node **head) {
    Node *temp = *head;
    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int len;
    scanf("%d", &len);
    
    for(int x = 0; x < len; x++) {
        Node *head = (Node *)malloc(sizeof(Node));
        Node *temp = head;
        
        int size;
        scanf("%d", &size);
        
        for(int y = 0; y < size; y++) {
            scanf("%d", &temp->data);
            temp->next = (Node *)malloc(sizeof(Node));
            
            temp->next->data = NULL;
            temp->next->next = NULL;
            
            temp = temp->next;
        }
        
        remove_dup(&head);
        print(&head);
        printf("\n");
    }
}