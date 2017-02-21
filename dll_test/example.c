#include <stdio.h>
#include "example.h"

__stdcall void hello(const char *s)
{
        printf("Hello %s\n", s);
}
int Double(int x)
{
        return 2 * x;
}
void CFunc(void)
{
        printf("CppFunc");
}

// void CppFunc(void)
// {
        // puts("CppFunc");
// }
// void MyClass::func(void)
// {
        // puts("MyClass.func()");
// }