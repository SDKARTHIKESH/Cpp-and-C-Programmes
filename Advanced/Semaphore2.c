#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <semaphore.h>

#define MAX_BOX_SIZE 5
#define TOTAL_ITEMS 10
#define WORD_LENGTH 3

typedef struct {
    char data[MAX_BOX_SIZE][WORD_LENGTH + 1];
    int in;
    int out;
    int count;
    sem_t empty;
    sem_t full;
    sem_t mutex;
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
        char word[WORD_LENGTH + 1];
        generate_random_word(word);
        
        sem_wait(&box.empty);
        sem_wait(&box.mutex);
        
        strcpy(box.data[box.in], word);
        printf("Teacher puts '%s' in box at position %d\n", word, box.in);
        box.in = (box.in + 1) % MAX_BOX_SIZE;
        box.count++;
        
        sem_post(&box.mutex);
        sem_post(&box.full);
        
        sleep(1);
    }
}

void* student_routine(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        sem_wait(&box.full);
        sem_wait(&box.mutex);
        
        char word[WORD_LENGTH + 1];
        strcpy(word, box.data[box.out]);
        printf("Student gets '%s' from box at position %d\n", word, box.out);
        box.out = (box.out + 1) % MAX_BOX_SIZE;
        box.count--;
        
        sem_post(&box.mutex);
        sem_post(&box.empty);
        
        encrypt_word(word);
        printf("Student encrypts it to: '%s'\n", word);
        
        sleep(1);
    }
}

int main() {
    pthread_t teacher_thread, student_thread;
    
    srand(time(NULL));
    
    box.in = 0;
    box.out = 0;
    box.count = 0;

    sem_init(&box.empty, 0, MAX_BOX_SIZE);
    sem_init(&box.full, 0, 0);
    sem_init(&box.mutex, 0, 1);
    
    pthread_create(&teacher_thread, NULL, teacher_routine, NULL);
    pthread_create(&student_thread, NULL, student_routine, NULL);
    
    pthread_join(teacher_thread, NULL);
    pthread_join(student_thread, NULL);

    sem_destroy(&box.empty);
    sem_destroy(&box.full);
    sem_destroy(&box.mutex);
    
    return 0;
}