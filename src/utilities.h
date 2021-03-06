#ifndef UTILITIES_H
#define UTILITIES_H

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