//extern void foo1(int x, int y, int z, int a) __attribute__((fastcall));
extern void foo2(int x, int y, int z, int a, int c, int as);

/* void bar1()
{
    foo1(99, 100, 101, 102);
} */

void bar2()
{
    foo2(89, 90, 91, 92,12,13);
}