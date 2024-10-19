#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_BOX_SIZE 5
#define TOTAL_ITEMS 10
#define WORD_LENGTH 3

typedef struct {
    char data[MAX_BOX_SIZE][WORD_LENGTH + 1];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} Box;

Box box;

void encrypt_word(char* word) {
    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) {
            char base = isupper(word[i]) ? 'A' : 'a';
            word[i] = base + (25 - (word[i] - base));
        }
    }
}

void generate_random_word(char* word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[WORD_LENGTH] = '\0';
}

void* teacher_routine(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        pthread_mutex_lock(&box.mutex);
    
        while (box.count == MAX_BOX_SIZE) {
            printf("Box is full! Teacher is waiting.\n");
            pthread_cond_wait(&box.not_full, &box.mutex);
        }
        
        generate_random_word(box.data[box.in]);
        printf("Teacher puts '%s' in box at position %d\n", box.data[box.in], box.in);
        
        box.in = (box.in + 1) % MAX_BOX_SIZE;
        box.count++;
        
        pthread_cond_signal(&box.not_empty);
        pthread_mutex_unlock(&box.mutex);
        sleep(1);
    }
    return NULL;
}

void* student_routine(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        pthread_mutex_lock(&box.mutex);
    
        while (box.count == 0) {
            printf("Box is empty! Student is waiting.\n");
            pthread_cond_wait(&box.not_empty, &box.mutex);
        }
        
        char word[WORD_LENGTH + 1];
        strcpy(word, box.data[box.out]);
        printf("Student gets '%s' from box at position %d\n", word, box.out);
        
        encrypt_word(word);
        printf("Student encrypts it to: '%s'\n", word);
        
        box.out = (box.out + 1) % MAX_BOX_SIZE;
        box.count--;
        
        pthread_cond_signal(&box.not_full);
        pthread_mutex_unlock(&box.mutex);

        sleep(1);
    }
}

int main() {
    pthread_t teacher_thread, student_thread;
    
    srand(time(NULL));
    
    box.count = 0;
    box.in = 0;
    box.out = 0;
    
    pthread_mutex_init(&box.mutex, NULL);
    pthread_cond_init(&box.not_full, NULL);
    pthread_cond_init(&box.not_empty, NULL);
    
    pthread_create(&teacher_thread, NULL, teacher_routine, NULL);
    pthread_create(&student_thread, NULL, student_routine, NULL);
    
    pthread_join(teacher_thread, NULL);
    pthread_join(student_thread, NULL);
    
    pthread_mutex_destroy(&box.mutex);
    pthread_cond_destroy(&box.not_full);
    pthread_cond_destroy(&box.not_empty);
    
    return 0;
}