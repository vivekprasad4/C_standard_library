#include <stdio.h>
#include <string.h>

/*
#define PCF_IDENT(X) X
#define PCF_STRINGIFY(X)                      PCF_DIRECT_STRINGIFY(X)    
#define PCF_DIRECT_STRINGIFY(X)  #X                         

#define PCF_JOIN_X_Y(X,Y)                     __PCF_USERS_DONT_USE_JOIN_2(X,Y)
#define __PCF_USERS_DONT_USE_JOIN_2(X,Y)      PCF_STRINGIFY(PCF_IDENT(X)PCF_IDENT(Y))

#define PCF_JOIN_X_Y_Z(X,Y,Z)                 __PCF_USERS_DONT_USE_JOIN_3(X,Y,Z)
#define __PCF_USERS_DONT_USE_JOIN_3(X,Y,Z)    PCF_STRINGIFY(PCF_IDENT(X)PCF_IDENT(Y)PCF_IDENT(Z))

#define PCF_JOIN_W_X_Y_Z(W,X,Y,Z)                 __PCF_USERS_DONT_USE_JOIN_4(W,X,Y,Z)
#define __PCF_USERS_DONT_USE_JOIN_4(W,X,Y,Z)    PCF_STRINGIFY(PCF_IDENT(W)PCF_IDENT(X)PCF_IDENT(Y)PCF_IDENT(Z))


#define PCF_CONDITIONAL_INCLUDE_FILE(PATH, PACKAGE, MODULE, INCLUDE_NAME) \
        PCF_JOIN_W_X_Y_Z(PATH, PACKAGE, MODULE, INCLUDE_NAME)

//#define MY_MAIN_H PCF_CONDITIONAL_INCLUDE_FILE(,,main/,main.h)

#define	PATH1_MAIN_H  PCF_JOIN_W_X_Y_Z(,test/,,main.h)
#define PCF_CONFIG_INCLUDE PCF_CONDITIONAL_INCLUDE_FILE(,,PCF/,config.h) */
//#define	PATH1_MAIN_H  PCF_JOIN_W_X_Y_Z(try/,test/,main/,main.h)
//#define	PATH1_MAIN_H  PCF_JOIN_X_Y_Z(test/,main/,main.h)
//#define	PATH2_MAIN_H  PCF_JOIN_X_Y(main/,main.h)
//#include MY_MAIN_H 

int main ()
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
/* 
int main(void)
{
	//float i =0;
  //double j=0;
  //printf("Size of float: %ld bytes\n",sizeof(i));
  //printf("Size of double: %ld bytes\n",sizeof(j));
	//printme();
	//printf("%s\n", PCF_STRINGIFY(PCF_CONFIG_INCLUDE));
	//printf("%s\n", "PC_config.h");
	//printf("%s\n", PCF_STRINGIFY(PATH2_MAIN_H));
	return 0;
}

Size of float: 4 bytes
Size of double: 8  bytes*/