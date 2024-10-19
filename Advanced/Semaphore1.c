#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_BOX_SIZE 5
#define TOTAL_ITEMS 10

typedef struct {
    int data[MAX_BOX_SIZE];
    int count;
    int in;
    int out;
    sem_t mutex;
    sem_t empty;
    sem_t full;
} Box;

Box box;

const char* number_to_name(int number) {
    static const char* names[] = {
        "Zero", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Unknown"
    };
    return (number >= 0 && number <= 9) ? names[number] : names[10];
}

void* teacher_routine(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        int item = rand() % 10;
        
        sem_wait(&box.empty);
        sem_wait(&box.mutex);
        
        box.data[box.in] = item;
        printf("Teacher puts %d in box at position %d\n", item, box.in);
        
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
        
        int item = box.data[box.out];
        printf("Student gets %d (%s) from box at position %d\n", item, number_to_name(item), box.out);
        
        box.out = (box.out + 1) % MAX_BOX_SIZE;
        box.count--;
        
        sem_post(&box.mutex);
        sem_post(&box.empty);

        sleep(1);
    }
}

int main() {
    pthread_t teacher_thread, student_thread;
    
    box.count = 0;
    box.in = 0;
    box.out = 0;
    
    sem_init(&box.mutex, 0, 1);
    sem_init(&box.empty, 0, MAX_BOX_SIZE);
    sem_init(&box.full, 0, 0);
    
    pthread_create(&teacher_thread, NULL, teacher_routine, NULL);
    pthread_create(&student_thread, NULL, student_routine, NULL);
    
    pthread_join(teacher_thread, NULL);
    pthread_join(student_thread, NULL);
    
    sem_destroy(&box.mutex);
    sem_destroy(&box.empty);
    sem_destroy(&box.full);
    
    return 0;
}