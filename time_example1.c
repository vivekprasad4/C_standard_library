
#define  T_EX_TRUE  1
#define  T_EX_FALSE 0

#define  Example_1 	T_EX_FALSE
#define  Example_2 	T_EX_FALSE
#define  Example_3 	T_EX_FALSE
#define  Example_4 	T_EX_TRUE



#if Example_1 == T_EX_TRUE

#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
   struct tm t;

   t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday   = 6;

   puts(asctime(&t));
   
   return(0);
}

#endif


#if Example_2 == T_EX_TRUE
#include <stdio.h>
#include <time.h>

int main ()
{
   time_t curtime;

   time(&curtime);

   printf("Current time = %s", ctime(&curtime));

   return(0);
}

#endif

#if Example_3 == T_EX_TRUE
#include <stdio.h>
#include <time.h>

int main ()
{
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );
   printf("Current local time and date: %s", asctime(info));

   return(0);
}
#endif

#if Example_4 == T_EX_TRUE
#include <stdio.h>
#include <time.h>

int main ()
{
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer,80,"%x - %I:%M%p", info);
   printf("Formatted date & time : |%s|\n", buffer );
  
   return(0);
}
#endif