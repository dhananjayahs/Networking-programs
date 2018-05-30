
/*
* Program to determine the host byte order 
* hex 0x0102 = decimal 258
* In Binary representation of 16 bits
*     00000001 00000010
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main( int argc, char *argv[] )
{
	union {
		short s;
		char c[sizeof(short)];
	} un;

	un.s = 0x0102;
	if ( 2 == sizeof(short) ) {
		if( un.c[0] == 1 && un.c[1] == 2 ) 
			printf("big-endian \n");
		else if ( un.c[0] == 2 && un.c[1] == 1 )
			printf("little-endian \n");
		else
			printf("unknown\n");
	}
	else 
		printf("sizeof(short) = %d \n", sizeof(short) );
	
	exit(0);
}
		
