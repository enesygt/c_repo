// C program to illustrate 
// size of struct 
#include <stdio.h> struct A { // sizeof(int) = 4 // Padding of 4 bytes // sizeof(double) = 8 double z; // sizeof(short int) = 2 
		short int y; 
		// Padding of 6 bytes 
				int x; 
	}; 
                             int main() 
{ 

int y = 6;

int bit= 0b1110;
//(0<<2);

	printf("%x", bit); 

	return 0; 
} 

