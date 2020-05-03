#include <stdlib.h>
#include <stdio.h>

/*
Author: Lindsay Maggioncalda lnm22
Homework #1, due 30 January 2019
*/


/*
Computes and prints out f(N), where N is an integer greater than zero 
that is input to the program on the command line. f(N) = 4*N + [2*f(N-1)] + 3.
The base case is f(0)=5. 
Your code must be recursive.

Your program should return the value zero.
*/

int doRecursion (int n);

int main (int argc, char *argv[])  {
	int n = atoi(argv[1]);
	printf("%d\n",doRecursion(n));
	return 0;		
}

int doRecursion (int n){
	if (n == 0) {
		return 5;
		}
	return ((4*n) + (2* doRecursion(n-1)) + 3);
}