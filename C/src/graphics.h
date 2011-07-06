/*
 * graphics.h
 *
 *  Created on: Oct 24, 2010
 *      Author: dasm80x86
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>

// Open GL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define GRAPHICS_WINDOW_TITLE		"ProjectEuler_Dasm80x86"

// Prototypes for init and callbacks.
void graphics_init(int* pargc, char** argv);
void graphics_display(void);
void graphics_reshape(int w, int h);
void graphics_mouse(int b, int s, int x, int y);
void keyboard_func(unsigned char k, int x, int y);

#endif /* GRAPHICS_H_ */
