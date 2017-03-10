#include <stdio.h>

float a, b, c, d;
int t,s,r,w,x;

void main(void)
{
	a= -0.001;
	b= -1.0;
	s= -0;
	t= +0;
	r= 0;
	w= (int ) a;
	x= (int ) b*-1;
	
	printf ("a=%f, b=%f, s=%d, t=%d, r=%d, w=%d, x=%d \n",a,b,s,t,r,w,x);
	
}