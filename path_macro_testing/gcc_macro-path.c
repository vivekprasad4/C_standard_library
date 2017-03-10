#include <stdio.h>

/* #define IDENT(x) x
#define XSTR(x) #x
#define STR(x) XSTR(x)

#define PCF_STRINGIFY(X)                      PCF_DIRECT_STRINGIFY(X)    
#define PCF_DIRECT_STRINGIFY(X)	#X                         

#define PCF_JOIN(X,Y)                         __PCF_USERS_DONT_USE_JOIN_2(X,Y)
#define __PCF_USERS_DONT_USE_JOIN_2(X,Y)      STR(IDENT(x)IDENT(y))   //#X  #Y
#define PCF_JOIN_X_Y                          PCF_JOIN
#define PCF_JOIN_X_Y_Z(X,Y,Z)                 PCF_JOIN(X,PCF_JOIN(Y,Z))
#define PCF_JOIN_W_X_Y_Z(W,X,Y,Z)             PCF_JOIN(W,PCF_JOIN_X_Y_Z(X,Y,Z))

#define PCF_CONDITIONAL_INCLUDE_FILE(PATH, PACKAGE, MODULE, INCLUDE_NAME) \
        PCF_STRINGIFY(PCF_JOIN_W_X_Y_Z(PATH, PACKAGE, MODULE, INCLUDE_NAME)) 


 */

/*
#define PCF_JOIN(x,y) STR(IDENT(x)IDENT(y))

//#define PCF_JOIN(x,y) "xy"

//__STDC_VERSION__
*/


#define PCF_IDENT(x) x
#define PCF_STRINGIFY(X)                      PCF_DIRECT_STRINGIFY(X)    
#define PCF_DIRECT_STRINGIFY(X)  #X                         

#define PCF_JOIN(X,Y)                         __PCF_USERS_DONT_USE_JOIN_2(X,Y)
//#define __PCF_USERS_DONT_USE_JOIN_2(X,Y)      X##Y
#define __PCF_USERS_DONT_USE_JOIN_2(X,Y)      PCF_STRINGIFY(PCF_IDENT(X)PCF_IDENT(Y))

#define PCF_JOIN_X_Y                          PCF_JOIN
#define PCF_JOIN_X_Y_Z(X,Y,Z)                 PCF_JOIN(X,PCF_JOIN(Y,Z))
#define PCF_JOIN_W_X_Y_Z(W,X,Y,Z)             PCF_JOIN(W,PCF_JOIN_X_Y_Z(X,Y,Z))
#define PCF_CONDITIONAL_INCLUDE_FILE(PATH, PACKAGE, MODULE, INCLUDE_NAME) \
        PCF_STRINGIFY(PCF_JOIN_W_X_Y_Z(PATH, PACKAGE, MODULE, INCLUDE_NAME))

#define MY_MAIN_H PCF_CONDITIONAL_INCLUDE_FILE(,,main/,main.h)
#include MY_MAIN_H 

int main(void)
{
	
	printme();
	printf("%s", PCF_STRINGIFY(MY_MAIN_H));
	//printf("%s",PCF_JOIN(gcc/,gcc.h));
	//printf("%s\n",__FILE__);
	//printf("%ld,%ld,%ld\n",__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__);
	
	//printf("%s\n",__func__);
	//printf("%s\n",__FUNCTION__);
	//printf("%s\n",__PRETTY_FUNCTION__);
	return 0;
}