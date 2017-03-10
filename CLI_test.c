#include <stdio.h>
#include <windows.h>


int main(int argc, char *argv[])
{
    char ownPth[MAX_PATH]; 

    // Will contain exe path
    HMODULE hModule = GetModuleHandle(NULL);
    if (hModule != NULL)
    {
     // When passing NULL to GetModuleHandle, it returns handle of exe itself   
     GetModuleFileName(hModule,ownPth, MAX_PATH); 
    }
    
    printf("OwnPath: %s\n", ownPth);
    printf("Argv[0]: %s\n", argv[0]);
    
    return 0;
}
	



/*

#include <stdio.h>
#include <Windows.h>

int main (int argc, char* argv[])
{
    int i=0;
    char buffer[MAX_PATH]={};
    GetModuleFileName(NULL,buffer,MAX_PATH);
    for(i=0; i< argc; i++)
    {
        printf("\n%s", argv[i]);
    }
    
    printf("\nArgv[0]: %s", argv[0]);
    printf("\n Modulename: %s", buffer);
    return 0;
}


*/