#include <stdio.h>
#include <pthread.h>

void *myThread(void *arg) {
    printf("Hello from the new thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    printf("Creating a new thread...\n");
    pthread_create(&thread_id, NULL, myThread, NULL);

    printf("Waiting for the new thread to finish...\n");
    pthread_join(thread_id, NULL);

    printf("The new thread has finished.\n");

    return 0;
}