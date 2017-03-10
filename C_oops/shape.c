/*
 * shape.c
 *
 *  Created on: 27 Jun 2016
 *      Author: Vivek
 */

#include <stdint.h>
#include "shape.h"
/* constructor */
void Shape_ctor(Shape * const me, int16_t x, int16_t y)
{
    me->x = x;
    me->y = y;
}
/* move-by operation */
void Shape_moveBy (Shape * const me, int16_t dx, int16_t dy)
{
    me->x += dx;
    me->y += dy;
}


