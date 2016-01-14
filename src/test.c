#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "test.h"

int main(int argc, char * argv[]){
	int num_threads = 4;
	pthread_t* threads = createThreads(num_threads);
	int i;
	for (i=0; i < num_threads; i++){
		pthread_join(threads[i], NULL);
	}
	printf("Hello from the main thread!\n");
	free(threads);
	return 0;
}

pthread_t* createThreads(int number){
	pthread_t* threads = malloc(number * sizeof(pthread_t));

	int rc;

	int t;
	for (t=0; t < number; t++){
		rc = pthread_create(&threads[t], NULL, threadFunc, (void*) t);
		if (rc){
			printf("Error creating thread: %d\n", t);
		}
	}

	return threads;
}

void* threadFunc(void* thread_id){
	int tid;
	tid = (int) thread_id;
	printf("Hello from thread %d\n", tid);
	pthread_exit(NULL);
}

