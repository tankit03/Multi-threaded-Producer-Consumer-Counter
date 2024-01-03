#include <stdio.h>
#include <pthread.h>
#define SIZE 1

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myCond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t myCond2 = PTHREAD_COND_INITIALIZER;
int myCount = 0;
int count = 0; 

// Function prototype for the consumer thread
void* consumer(void* arg);

int main() {

    printf("PROGRAM START\n");

    // create the consumer thread
    pthread_t consumerThread;
    pthread_create(&consumerThread, NULL, consumer, NULL);

    printf("CONSUMER THREAD CREATED\n");

    while (1) {

        // Producer thread locks the mutex
        printf("PRODUCER: myMutex locked\n");
        fflush(stdout);
        pthread_mutex_lock(&myMutex);

        // wait while buffer is Full
        while (count == SIZE ) {
            printf("PRODUCER: waiting on myCond1\n");
            fflush(stdout);
            pthread_cond_wait(&myCond1, &myMutex);
        }

        // Increment Counter        
        count++;
        myCount++;

        // Display the count
        printf("myCount: %d -> %d\n", myCount - 1, myCount);

        //Unlock the Mutex
        printf("PRODUCER: myMutex unlocked\n");
        fflush(stdout);
        pthread_mutex_unlock(&myMutex);


        //Signal consumer that data is ready
        printf("PRODUCER: signaling myCond2\n");
        fflush(stdout);
        pthread_cond_signal(&myCond2);

        // Check if the required count is reached
        if(myCount >= 10){
            break;
        }

    }
    
    //wait for the consumer thread to finish
    pthread_join(consumerThread, NULL);
    printf("END OF PROGRAM\n");

    return 0;
}


void* consumer(void* arg) {

    while (1) {
        
        //Consumer thread locks the mutex
        printf("CONSUMER: myMutex locked\n");
        fflush(stdout);
        pthread_mutex_lock(&myMutex);

        // Wait while the buffer is empty
        while (count == 0) {

            printf("CONSUMER: waiting on myCond2\n");
            fflush(stdout);
            pthread_cond_wait(&myCond2, &myMutex);
        }

        //Decrement the count
        count--;

        // Unlock the mutex
        printf("CONSUMER: MyMutex unlocked\n");
        pthread_mutex_unlock(&myMutex);
        
        // Signal producer that space is available
        printf("CONSUMER: Signaling myCond1\n");
        fflush(stdout);
        pthread_cond_signal(&myCond1);

        // Check if the required count is reached
        if (myCount >= 10) {
            break; 
        }
    }
}
