#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "multiply.h"

int main (int argc, char * argv[]){
	parse_number_threads(argc, argv);
	return 0;
}

int parse_number_threads(int argc, char** argv){
	if (argc != 2){
		printf("You didn't enter the correct number of arguments\n");
		print_usage();

		exit(EXIT_FAILURE);
	}

	int threads = atoi(argv[1]);
	if (threads < 1 || !check_square(threads)){
		printf("You entered an invalid number of threads\n");
		printf("Please select a square integer greater than 1\n");
		print_usage();		
	}

	return 0;
}

void print_usage(){
	printf("USAGE: mulitply <square number of threads> \n");
}

int check_square(int number){
	int i;
	for(i = 0; i <= number; i++){
		if (number == i * i){
			return 1;
		}
	}
	return 0;
}