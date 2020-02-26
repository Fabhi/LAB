#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
int bufferBound;
int *queue;
int queueLength;
int max;
sem_t semaphore,bound;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer( void * param){
    for ( int i=0; i<max; i++ ){
        // Add item to queue
        sem_wait(&bound);
        pthread_mutex_lock( &mutex );
        queue[ queueLength++ ] = i;
        printf("Produced %d\n", i);
        pthread_mutex_unlock( &mutex );
        // Signal semaphore
        sem_post( &semaphore );
    }
}
void *consumer(void * param){
    for ( int i=0; i<max; i++ ){
        int item;
        // Wait if nothing in queue
        sem_wait(&semaphore);
        pthread_mutex_lock( &mutex );
        item = queue[ -- queueLength ];
        printf("Consumed %i\n", item);
        pthread_mutex_unlock( &mutex );
        sem_post(&bound);
    }
}
int main(){
    printf("Enter the size of the buffer: ");
    scanf("%d", &bufferBound);
    printf("Enter the maximum items allowed to be produced: ");
    scanf("%d", &max);
    queue = malloc((bufferBound) *sizeof(int));
    pthread_t threads[2];
    sem_init( &semaphore, 0, 0 );
    sem_init( &bound,0,bufferBound);
    pthread_create( &threads[0], 0, producer, 0 );
    pthread_create( &threads[1], 0, consumer, 0 );
    pthread_join( threads[0], 0 );
    pthread_join( threads[1], 0 );
    sem_destroy( &semaphore );
}

// Compile using -lpthread -lrt flag
// For example: gcc 1.c -lpthread -lrt