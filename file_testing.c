#include <stdio.h>


int main() 
{
   FILE *fp;

   fp = fopen("test.txt", "w+");
   if(fp == NULL)
   {
       printf("Unable to open the File\n");
       return (-1);
   }
   
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
   return (0);
}