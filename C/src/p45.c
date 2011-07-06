/*
 * p45.c
 *
 *  Created on: Oct 27, 2010
 *      Author: dasm80x86
 */
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"
#include "p45.h"

// Point out to the graphics display function.
extern void (*graphics_display_func)();
extern int keyboard_hit;
extern int cnt;

int run_p45()
{
	// TODO: Function assignment is okay, but calling
	// glutDisplayFunc right after negates the whole point.
	// This needs to be refactored to a new function that
	// takes a func as arg and *then* calls glutDisplayFunc
	graphics_display_func = &display_p45;
	glutDisplayFunc(graphics_display_func);

	glutMainLoop();

	return EXIT_SUCCESS;
}


void plot_function(int (*f_func)(), int x)
{
	glVertex2i(x, f_func(x) / 100);
}

void display_p45()
{
	const int MAX_X = 1000000;
	// x-coordinate, time
	register int x = 0;

	// Clear all pixels
	// Color is while; (no alpha)
	glClear(GL_COLOR_BUFFER_BIT);

	// Show triangle numbers
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	for (x = 1; x < MAX_X; ++x)
		plot_function(triangle_number, x);
	glEnd();

	// Show triangle numbers
	glBegin(GL_POINTS);
	glColor3f(0.0, 1.0, 0.0);
	for (x = 1; x < MAX_X; ++x)
		plot_function(pentagonal_number, x);
	glEnd();

	// Show triangle numbers
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	for (x = 1; x < MAX_X; ++x)
		plot_function(hexagonal_number, x);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	plot_function(triangle_number, 285);
	plot_function(hexagonal_number, 143);
	plot_function(hexagonal_number, 143);
	plot_function(pentagonal_number, 165);
	glEnd();


	// Flush
	glFlush();
	glFinish();
}

inline int triangle_number(int n) { return n * ( n + 1) / 2; }
inline int pentagonal_number(int n) { return n * (3 * n - 1) / 2; }
inline int hexagonal_number(int n) { return n * (2 * n - 1); }

