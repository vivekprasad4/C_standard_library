#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

int main ()
{
    FILE * pfile;
    int errnum;

    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );

    pfile = fopen ("test.txt", "rb");
    if (pfile == NULL)
    {
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
    }
    else
    {
       fprintf(stdout, "Testing fprintf\n");
       fclose (pfile);
    }

    return 0;
}