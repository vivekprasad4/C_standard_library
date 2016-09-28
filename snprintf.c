#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MSG_LOG      "Log File"
#define _MSG_GEN      "Generated on"
#define _MSG_B_VER    "EPCF Build Version"
#define _MSG_B_MOD    "EPCF Build Mode"
#define _MSG_B_PLAT   "EPCF Build Platform"
#define _MSG_EOL      "\r\n"
#define _MSG_COL      ": "
/* 
"Log File            : "
"Generated on        : "
"EPCF Build Version  : "
"EPCF Build Mode     : "
"EPCF Build Platform : "
 */

char string[100]={};
char str_buffer[500]={};

void msg_print(FILE* fp, const char * msg);

int main()
{
   FILE * fp;

   fp = fopen ("./file.log", "a");
   //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
   msg_print(fp,(const char *) _MSG_LOG);
   msg_print(fp,(const char *) _MSG_GEN);
   msg_print(fp,(const char *) _MSG_B_VER);
   msg_print(fp,(const char *) _MSG_B_MOD);
   msg_print(fp,(const char *) _MSG_B_PLAT);
   fclose(fp);
   return(0);
}


void msg_print(FILE* fp, const char * msg)
{
   strcpy(string, msg);
   sprintf(str_buffer, "%-20s", string);
   fprintf(fp,"%s", str_buffer);
   fprintf(fp,"%s", _MSG_COL);
   fprintf(fp,"%s", _MSG_EOL);
}