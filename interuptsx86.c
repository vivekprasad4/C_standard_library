#include  <windows.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>

/* void my_handler(int sig){
           printf("Caught signal %d\n",sig);
           exit(1); 

}

int main(int argc,char** argv)
{
   signal (SIGINT,my_handler);

   while(1);
   return 0;

} */


void INThandler(int);
int FLAG = 0;

int  main(void)
{
	char c;
	
	//c = getchar();
	//printf("%c", c);
	signal(SIGINT, INThandler);
	while (1)
	{
		if(FLAG == 1)
		{
			
		}
		Sleep(20);
	}
	return 0;
}
	
void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("You Pressed Ctrl-C?\n");
	 printf("Terminating program\n");
     exit(-1);	
}