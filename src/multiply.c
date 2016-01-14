#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "multiply.h"
#include "utilities.h"
#include "../sdk/lab1_IO.h"
#include <math.h>

int **A; int **B; int **C; int n;
int number_threads;

int main (int argc, char * argv[]){
	number_threads = parse_number_threads(argc, argv);
	pthread_t threads[number_threads];

	Lab1_loadinput(&A, &B, &n);

	C = createResultMatrix(n);

	int i;
	for (i = 0; i < number_threads; i++){
		pthread_create(threads[i], NULL, multiplyBlock, (void *) i);
	}

	for (i = 0; i < number_threads; i++){
		pthread_join(threads[i], NULL);
	}

	Lab1_saveoutput(C, &n, 1000);


	return 0;
}

void* multiplyBlock(void* threadID){
	int k = (int) threadID;
	int p = number_threads;

	int x = k / sqrt(p);
	int y = (int) k % (int) sqrt(p);

	multiply_row_column((n/sqrt(p)) * x, (n/sqrt(p)) * y, 
	((n/sqrt(p))*(x+1)) -1, ((n/sqrt(p))*(y+1)) -1);
	
	return 0;
}

void multiply_row_column(int row_lower_bound, int column_lower_bound, 
	int row_upper_bound, int column_upper_bound){

	int i;
	int j;

	for (i = row_lower_bound; i <= row_upper_bound ; i++){
		for (j = column_lower_bound; j <= column_upper_bound; j++){
			C[i][j] = multiplyVector(i, j);
		}
	}
}

int multiplyVector(int i, int j){
	int x;

	int sum = 0;
	for (x = 0; x < n; x++){
		sum += A[i][x] * B[x][j];
	}

	return sum;
}

int ** createResultMatrix(int size){
	int **C = malloc(size * sizeof(int *));
	int i;
	for (i = 0; i < size; i++){
		C[i] = malloc (size * sizeof(int *));
	}

	return C;
}