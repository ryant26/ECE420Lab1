# ifndef TEST_H
# define TEST_H

#include <pthread.h>

pthread_t* createThreads(int);
void* threadFunc(void*);

# endif