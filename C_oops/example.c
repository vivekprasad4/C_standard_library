/*
 ============================================================================
 Name        : C_oops.c
 Author      : Vivek
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "shape.h"
int main(void) {
	Shape s1, s2; /* multiple instances of Shape */

	puts("!!!Hello World 2!!!"); /* prints !!!Hello World!!! */

    Shape_ctor(&s1, 0, 1);
    Shape_ctor(&s2, -1, 2);
    Shape_moveBy(&s1, 2, -4);

	return EXIT_SUCCESS;
}
