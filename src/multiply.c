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
	}
	return 0;
}

void print_usage(){
	printf("USAGE: mulitply <number of threads> \n");
}