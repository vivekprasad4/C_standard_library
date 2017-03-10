#include <stdio.h>

unsigned char a=0xfe ;
unsigned char p=0;

int test,parity=1,i,count=0;

	
int main( void) {
       
		printf( "a= %d, p= %d \n", a, p);
		count=0;
	   for (i=0; i<8; i++)
	   {
		  test= a & 0x01;
		  parity = (parity ^ test);
		  printf( "test= %d, parity= %d \n", test, parity);
		  a = a>>1;
	   }
	   printf( "parity= %d, p= %d \n", parity, p);
	   
	   if(parity == p)
		   printf("valid Data");
	   else
		   printf("invalid Data");	
       return 0;
}