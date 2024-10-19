#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BOX_SIZE 5
#define TOTAL_ITEMS 10

typedef struct {
    int data[MAX_BOX_SIZE];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
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
        pthread_mutex_lock(&box.mutex);
    
        while (box.count == MAX_BOX_SIZE) {
            printf("Box is full! Teacher is waiting.\n");
            pthread_cond_wait(&box.not_full, &box.mutex);
        }
        
        box.data[box.in] = item;
        printf("Teacher puts %d in box at position %d\n", item, box.in);
        
        box.in = (box.in + 1) % MAX_BOX_SIZE;
        box.count++;
        
        pthread_cond_signal(&box.not_empty);
        pthread_mutex_unlock(&box.mutex);
        sleep(1);
    }
}

void* student_routine(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        pthread_mutex_lock(&box.mutex);
    
        while (box.count == 0) {
            printf("Box is empty! Student is waiting.\n");
            pthread_cond_wait(&box.not_empty, &box.mutex);
        }
        
        int item = box.data[box.out];
        printf("Student gets %d (%s) from box at position %d\n", item, number_to_name(item), box.out);
        
        box.out = (box.out + 1) % MAX_BOX_SIZE;
        box.count--;
        
        pthread_cond_signal(&box.not_full);
        pthread_mutex_unlock(&box.mutex);

        sleep(1);
    }
}

int main() {
    pthread_t teacher_thread, student_thread;
    
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