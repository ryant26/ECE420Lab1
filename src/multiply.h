#ifndef MULTIPLY_H
#define MULTIPLY_H

// The function passed to pthread_create
// Params: threadID
void* multiplyBlock(void*);

// The function to parse the number of threads from the 
// command line
// Params: int argc, char** argv
int parse_number_threads(int, char**);

//Prints the usage of the binary from the terminal
void print_usage();

// Tests if the input ineger is a square number
// Params: int number to check
int check_square(int);

#endif