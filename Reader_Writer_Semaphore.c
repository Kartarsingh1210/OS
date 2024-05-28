
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h> 

#define N 10

int rc = 0;
typedef int semaphore;
int buffer[N];
semaphore mutex = 1;
semaphore db = 1;

void wait(semaphore *s) {
    while (*s <= 0)
        ;
    (*s)--;
}

void signal(semaphore *s) {
    (*s)++;
}

void read_buffer() {
    printf("Reading Buffer\n");
}

void *reader(void *arg) {
    while (true) {
        wait(&mutex);
        rc = rc + 1;
        if (rc == 1) {
            wait(&db);
        }
        signal(&mutex);
        read_buffer();
        wait(&mutex);
        rc = rc - 1;
        if (rc == 0) {
            signal(&db);
        }
        signal(&mutex);
        sleep(1); 
    }
}

void write_buffer() {
    printf("Writing to Buffer\n");
}

void *writer(void *arg) {
    while (true) {
        wait(&db);
        write_buffer();
        signal(&db);
        sleep(2); 
    }
}

int main() {
    pthread_t reader_thread, writer_thread;
    pthread_create(&reader_thread, NULL, reader, NULL);
    pthread_create(&writer_thread, NULL, writer, NULL);

    pthread_join(reader_thread, NULL);
    pthread_join(writer_thread, NULL);
    return 0;
}