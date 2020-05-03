#include <stdlib.h>
#include <stdio.h>

/*
Author: Lindsay Maggioncalda lnm22
Homework #1, due 30 January 2019
*/


/*
prints out the first N numbers that are divisible by either 7 or 11, each one on its
own line, where N is an integer that is input to the program on the command line. 
The first numbers your program should produce are 7, 11, 14, 21, etc.) If your binary
executable is called divby7or11, then you’d run it on an input of 21 with:
./divby7or11 21

Your program should return the value zero.
*/

int main (int argc, char *argv[])  {
	int n = atoi(argv[1]);
	if (n <= 0) return 0;
	int x = 7;
	int counter = 0;
	while (counter != n) {
		if (x%7 == 0 || x%11 == 0){
			printf("%d\n",x);
			counter += 1;
		}
		x += 1;
	}

	return 0;	
}