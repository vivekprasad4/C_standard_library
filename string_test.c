#include <stdio.h>

char ch_s[8] = {'H','E','L','l','o','1','2','3'};
char * ch = "Test my string";
char ch_l[5] = {'H','E','L','L','O'};

unsigned int test_int= 65535;
char test = 'A';
int i;
int main ()
{
    printf("\nCh_s : ");
    while (ch_s[i] != '\0') 
    {
            printf("%c",ch_s[i]);
            i++;
    }
    i=0;
    printf("\nCh_l : ");
    while (ch_l[i] != '\0') 
    {
            printf("%c",ch_l[i]);
            i++;
    }
    i=0;
    printf("\nch_l : %s",ch_l);
    printf("\nComplete");
    printf("\nAddress of ch_s 0 : %x, contain : %c",&ch_s[0],ch_s[0]);
    printf("\nAddress of ch_s 1 : %x, contain : %c",&ch_s[1],ch_s[1]);
    printf("\nAddress of ch_s 2 : %x, contain : %c",&ch_s[2],ch_s[2]);
    printf("\nAddress of ch_s 3 : %x, contain : %c",&ch_s[3],ch_s[3]);
    printf("\nAddress of ch_s 4 : %x, contain : %c",&ch_s[4],ch_s[4]);
    printf("\nAddress of ch_s 5 : %x, contain : %c",&ch_s[5],ch_s[5]);
    printf("\nAddress of ch_s 6 : %x, contain : %c",&ch_s[6],ch_s[6]);
    printf("\nAddress of ch_s 7 : %x, contain : %c",&ch_s[7],ch_s[7]);
    printf("\nAddress of ch_s 8 : %x, contain : %c",&ch_s[8],ch_s[8]);
    printf("\nAddress of ch_s 9 : %x, contain : %c",&ch_s[9],ch_s[9]); 
    printf("\nAddress of ch_s 10 : %x, contain : %c",&ch_s[10],ch_s[10]);
    printf("\nAddress of ch_s 11 : %x, contain : %c",&ch_s[11],ch_s[11]); 
    printf("\nAddress of ch_s 12 : %x, contain : %c",&ch_s[12],ch_s[12]); 
    printf("\nAddress of ch_s 13 : %x, contain : %c",&ch_s[13],ch_s[13]); 
    printf("\n");
    printf("\nAddress of ch : %x, contain : %s",&ch,ch);
    printf("\n");
    printf("\nAddress of ch_l 0 : %x, contain : %c",&ch_l[0],ch_l[0]);
    printf("\nAddress of ch_l 1 : %x, contain : %c",&ch_l[1],ch_l[1]);
    printf("\nAddress of ch_l 2 : %x, contain : %c",&ch_l[2],ch_l[2]);
    printf("\nAddress of ch_l 3 : %x, contain : %c",&ch_l[3],ch_l[3]);
    printf("\nAddress of ch_l 4 : %x, contain : %c",&ch_l[4],ch_l[4]);
    printf("\nAddress of ch_l 5 : %x, contain : %c",&ch_l[5],ch_l[5]);
    printf("\nAddress of ch_l 6 : %x, contain : %c",&ch_l[6],ch_l[6]);
    printf("\n");
    printf("\nAddress of ch_s     : %x",&ch_s);
    printf("\nAddress of ch_l     : %x",&ch_l);
    printf("\nAddress of test_int : %x",&test_int);
    printf("\nAddress of test     : %x",&test);
    printf("\nAddress of i        : %x",&i);
}