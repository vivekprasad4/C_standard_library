/* #include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include  <unistd.h>

void     INThandler(int);

int  main(void)
{
    char  m_char;
     signal(SIGINT, INThandler);
     printf("\nTesting interrupt\n");
     while (1)
     {
          //pause();
        m_char = getchar();
        printf("%c",m_char);
        sleep(1);
     }
     return 0;
}

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("\nOUCH, did you hit Ctrl-C?\n"
            "\nDo you really want to quit? [y/n] ");
     c = getchar();
     if (c == 'y' || c == 'Y')
          exit(0);
     else
          signal(SIGINT, INThandler);
     getchar(); // Get new line character
} */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
void sigproc(int);
 
//void quitproc(int); 
 
int main(void)
{		 signal(SIGINT, sigproc);
		 //signal(SIGBREAK, quitproc);
		 printf("ctrl-c disabled use ctrl-\\ to quit\n");
		 for(;;); /* infinite loop */
}
 
void sigproc(int sig)
{
    char c;
    signal(SIGINT, sigproc); /*  */
    /* NOTE some versions of UNIX will reset signal to default
    after each call. So for portability reset signal each time */
    printf("you have pressed ctrl-c \n");
    printf("\nDo you really want to quit? [Y/N] ");
    while(1)
    {
        c= getchar();
        if( c == 'Y' || c == 'y')
            exit(0);
        else
        {
            printf("\nexiting int\n");
            break;
        }
    }
}
 
// void quitproc(int sig)
// { 		 printf("ctrl-\\ pressed to quit\n");
         // while(1)
         // {
             // if(getchar() == 'A')
                 // break;
         // }
		 // exit(0); /* normal exit status */
// }
