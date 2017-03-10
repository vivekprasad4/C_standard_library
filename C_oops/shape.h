/*
 * shape.h
 *
 *  Created on: 27 Jun 2016
 *      Author: Vivek
 */

#ifndef SHAPE_H_
#define SHAPE_H_

/* Shape's attributes... */
typedef struct {
    int16_t x; /* x-coordinate of Shape's position */
    int16_t y; /* y-coordinate of Shape's position */
}
Shape
;
/* Shape's operations (Shape's interface)... */
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);

#endif /* SHAPE_H_ */
