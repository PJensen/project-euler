/*
 * graphics.c
 *
 *  Created on: Oct 24, 2010
 *      Author: dasm80x86
 */

#include "graphics.h"

volatile int cnt = 0;
volatile int mouse_clicked = 0;
volatile int keyboard_hit = 0;

// The graphics display function can be overridden
// using this pointer to function.
void (*graphics_display_func)() = NULL;

/**
 * Function: graphics_display
 * Description: Base display function; really meant as a place-holder.
 * Shows a line from bottom left, to top right and a box in the middle.
 */
void graphics_display()
{
	// Clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	// Color is while; (no alpha)
	glColor3f(1.0, 1.0, 1.0);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
	glEnd();

	// Start drawing some triangles
	glBegin(GL_POLYGON);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.25, 0.75);
	glEnd();

	// Flush
	glFlush();

	fprintf(stderr, "Finished graphics_display().\n");
}

/**
 * Function: graphics_reshape
 * Description: Occurs when the window is reshaped.
 * Parameters:
 * 	w - Width
 *  h - Height
 */
void graphics_reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);
}

/**
 * Fires when the 'f' key is pressed; posts a redisplay.
 */
void keyboard_func(unsigned char k, int x, int y)
{

	fprintf(stderr, "keyhit\n");
	switch (k) {
		case 'f':
			glutPostRedisplay();
			keyboard_hit++;
			break;
		case 'd':
			glutPostRedisplay();
			keyboard_hit--;
			break;
		default:
			break;
	}
}

/**
 * Mouse function
 */
void graphics_mouse(int b, int s, int x, int y)
{
	printf("%d", b);
}

/**
 * Function: graphics_init
 * Description: Initialize OpenGL
 */
void graphics_init(int* pargc, char** argv)
{
	// Wire up the base graphics display function
	graphics_display_func = &graphics_display;

	// glut initialization
	glutInit(pargc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(GRAPHICS_WINDOW_TITLE);

	// Initialize extents, color, matrix mode.
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);

	// Register reshape and draw functions.
	glutReshapeFunc(graphics_reshape);
	glutDisplayFunc(graphics_display_func);
	glutKeyboardFunc(keyboard_func);

	// Show that initialization went okay.
	fprintf(stderr, "OpenGL Init Success\n");
}
