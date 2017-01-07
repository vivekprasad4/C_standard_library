gcc -c  -DBUILDING_EXAMPLE_DLL example.c
gcc -shared -o example_dll.dll example.o -Wl,--out-implib,libexample_dll.a

gcc -c example_dll_test.c 
gcc -o example_dll_test.exe example_dll_test.o -L. -lexample_dll

./example_dll_test.exe 
