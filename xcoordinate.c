#include <stdio.h>
#define num  1
unsigned int temp=0 ;
signed char data = -num;
unsigned char data_u = num;
unsigned char  of=0, sign_bit=1, d=0;
	
int main( void) {
       
//	printf( "temp= %x, data= %x \n", temp, data);
	printf( "temp= %x \n", temp);
	printf( "temp= %x \n", temp-1);
	
/*	if( sign_bit == 1)
	{
		temp = 0xFF00;
		temp = temp | data;
		temp = ~temp;
		temp += 1;
		d=~data;
		
	}
	else
	{
		temp = 0x0000;
		temp = temp | data_u;
	}
	
	printf( "temp= %x,data=%x \n", temp, d);
*/
    return 0;
}