
#include <stdio.h>

//#define DEBUG_MSG(__VA_ARGS__)      printf("")
//#define DEBUG_MSG(format, ...)      printf("%s:%d",__FILE__,__LINE__,format,##__VA_ARGS__); printf(format,##__VA_ARGS__)
#define DEBUG_MSG(format, ...)      printf("%s:%d:",__FILE__,__LINE__);printf(format,##__VA_ARGS__);

int main (void)
{
	DEBUG_MSG("TESTING DEBUG MACRO\n");
	DEBUG_MSG("test %d\n",1);
	return 0;
}