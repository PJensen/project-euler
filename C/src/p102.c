/*
 * p102.c
 *
 *  Created on: Oct 23, 2010
 *      Author: dasm80x86
 *
 *  http://projecteuler.net/index.php?section=problems&id=102
 */

#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"
#include "p102.h"

// global pointer to all triangles
static Triangle *triangles;

static int num_triangles = 0;

// Point out to the graphics display function.
extern void (*graphics_display_func)();
extern int keyboard_hit;
extern int cnt;

/**
 * Executes problem 102
 */
int run_p102()
{
	// Show the description for problem 102 in the console.
	show_p102();

	// Read in all triangle data; into static triangles memory block.
	readTriangles();

	// TODO: Function assignment is okay, but calling
	// glutDisplayFunc right after negates the whole point.
	// This needs to be refactored to a new function that
	// takes a func as arg and *then* calls glutDisplayFunc
	graphics_display_func = &display_p102;
	glutDisplayFunc(graphics_display_func);

	int index = 0;
	int total = 0;

	// Define the origin for readability
	Point origin;
	origin.x = 0; origin.y = 0;

	// TODO: Solve
	for (index = 0; index < num_triangles; ++index)
	{
		// Declare the three lines in the triangle
		Point p1, p2, p3;

		// Point 1
		p1.x = triangles[index].x1;
		p1.y = triangles[index].y1;

		// Point 2
		p2.x = triangles[index].x2;
		p2.y = triangles[index].y2;

		// Point 3
		p3.x = triangles[index].x3;
		p3.y = triangles[index].y3;

		Point mPoint1 = midpoint2P(p1, p2);
		Point mPoint2 = midpoint2P(p1, p3);
		Point mPointD = midpoint2P(mPoint1, mPoint2);

		Line s1 = cline(p1, p2);			// Segment A
		Line s2 = cline(p2, p3);			// Segment B
		Line s3 = cline(p3, p1);			// Segment C

		Line oO = cline(mPointD, origin);	// Mid -> Origin
		Line o0 = cline(mPointD, origin);	// Mid -> Origin

		if (intersect(oO, s1) == 0 && intersect(oO, s2) == 0 && intersect(oO, s3) == 0)
			total = total + 1;

		printf(" %d\t%d\n", index, total);
		//printf(" %d ", intersect(s1, oO) & intersect(oO, s1));
		//printf(" %d ", intersect(s2, oO) & intersect(oO, s2));
		//printf(" %d", intersect(s3, oO) & intersect(oO, s3));
	}

	// otal = 0;

	// TODO: Show triangle data
	glutMainLoop();

	// Free data
	freeTriangles(triangles);

	return EXIT_SUCCESS;
}

// Adopted from "Algorithms in C", Sedgewick
int ccw(Point p0, Point p1, Point p2)
{
	int dx1, dx2, dy1, dy2;
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	if (dx1 * dy2 > dy1 * dx2) return (+1);
	if (dx1 * dy2 < dy1 * dx2) return (-1);
	if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return (-1);
	if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2))
		return (+1);
	return (0);
}

// Adopted from "Algorithms in C", Sedgewick
int intersect(Line l1, Line l2)
{
	return ((ccw(l1.p1, l1.p2, l2.p1)
		   * ccw(l1.p1, l1.p2, l2.p2)) <= 0)
		   &&
		   ((ccw(l2.p1, l2.p2, l1.p1)
		   * ccw(l2.p1, l2.p2, l1.p2)) <= 0);
}

/**
 * Create a line from two points.
 */
Line cline(Point p1, Point p2)
{
	Line retLine;
	retLine.p1 = p1;	// Set point #1
	retLine.p2 = p2;	// Set point #2
	return retLine;
}

void draw_line(Line aLine)
{
	glVertex2i(aLine.p1.x, aLine.p1.y);
	glVertex2i(aLine.p2.x, aLine.p2.y);
}

void display_p102()
{

	Point p1, p2, p3;
	int index = 0;		// Index for looping through all triangles.

	// Clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	// Color is while; (no alpha)
	glColor3f(1.0, 1.0, 1.0);

	//

	// for (index = keyboard_hit; index < keyboard_hit + 1; ++index) {
	for (index = 0; index < num_triangles; ++index) {

		// Point 1
		p1.x = triangles[index].x1;
		p1.y = triangles[index].y1;

		// Point 2
		p2.x = triangles[index].x2;
		p2.y = triangles[index].y2;

		// Point 3
		p3.x = triangles[index].x3;
		p3.y = triangles[index].y3;

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(p1.x, p1.y);
		glVertex2i(p2.x, p2.y);

		glVertex2i(p2.x, p2.y);
		glVertex2i(p3.x, p3.y);

		glVertex2i(p3.x, p3.y);
		glVertex2i(p1.x, p1.y);

		Point mPoint1 = midpoint2P(p1, p2);
		Point mPoint2 = midpoint2P(p1, p3);
		Point mPointD = midpoint2P(mPoint1, mPoint2);
		Point origin;
		origin.x = 0; origin.y = 0;
		Line s1 = cline(p1, p2);			// Segment A
		Line s2 = cline(p2, p3);			// Segment B
		Line s3 = cline(p3, p1);			// Segment C
		Line oO = cline(mPointD, origin);	// Mid -> Origin

		if (intersect(oO, s1) == 1 ||
				intersect(oO, s2) == 1 ||
				intersect(oO, s3) == 1){
			glColor3f(1.0, 0.0, 0.0);

		}
		else {
			glColor3f(1.0, 1.0, 1.0);
			cnt++;
		}

		draw_line(cline(mPointD, origin));
		glEnd();

		/*
		getchar();
		glFlush();
		glutPostRedisplay();
		glClear(GL_COLOR_BUFFER_BIT);
		*/


		/*
		 glBegin(GL_POLYGON);
		 glColor3f(1.0, 0.0, 0.0);
		 glVertex2i(triangles[index].x1, triangles[index].y1);
		 glColor3f(0.0, 1.0, 0.0);
		 glVertex2i(triangles[index].x2, triangles[index].y2);
		 glColor3f(0.0, 0.0, 1.0);
		 glVertex2i(triangles[index].x3, triangles[index].y3);
		 glEnd();
		 */
	}


	// Flush
	glFlush();

	printf("%d\n", cnt);

	// Show that we finished the display of p102
	fprintf(stderr, "Finished display_p102().\n");
}

/**
 * show information for p102
 * Straight from: http://projecteuler.net/index.php?section=problems&id=102
 */
void show_p102()
{
	printf("Three distinct points are plotted at random on a Cartesian plane, \n");
	printf("for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.\n");
	printf("Consider the following two triangles:\n\n");
	printf("\tA(-340,495), B(-153,-910), C(835,-947)\n");
	printf("\tX(-175,41), Y(-421,-714), Z(574,-645)\n\n");
	printf("It can be verified that triangle ABC contains the origin, whereas\n");
	printf("triangle XYZ does not.\n\n");
	printf("Using triangles.txt  (right click and 'Save Link/Target As...'), a \n");
	printf("27K text file containing the co-ordinates of one thousand 'random' \n");
	printf("triangles, find the number of triangles for which the interior\n");
	printf("contains the origin.\n\n");
}

/**
 * Free all allocated triangles
 */
void freeTriangles(Triangle* aPtr)
{
	fprintf(stderr, "Freeing triangles.");
	free(aPtr);
}

/**
 * Return the midpoint between two points.
 */
Point midpoint2P(Point a, Point b)
{
	Point retPoint;
	retPoint.x = (a.x + b.x) / 2;
	retPoint.y = (a.y + b.y) / 2;
	return retPoint;
}

/**
 * Return the midpoint between two points.
 */
Point midpoint1L(Line ab)
{
	return midpoint2P(ab.p1, ab.p2);
}

/**
 * Read triangles from 'triangles.txt'
 */
void readTriangles()
{
	FILE* fp;				// Input file pointer

	// Show that were about to read in genetic data.
	fprintf(stdout, "Reading triangle data ... ");

	// Try to open params.fileName, exit on failure.
	if ((fp = fopen(TRIANGLES_TXT, "r")) == NULL)
		doError("Triangles input file does not exist.");

	// Hack to figure out how many triangles there are; I'll have to rewind
	// after this.
	int index = 0;

	// Need space for the first triangle
	triangles = calloc(1, sizeof(*triangles));

	// TODO: It's possible to refactor and count number of newline chars
	// but that doesn't resolve what could be a formatting issue.
	do {
		// Keep overwriting the same triangle; ensuring it's properly formatted
		// and keeping track of how many we found.
		index = fscanf(fp, "%d,%d,%d,%d,%d,%d", &triangles[0].x1, &triangles[0].y1,
				&triangles[0].x2, &triangles[0].y2, &triangles[0].x3, &triangles[0].y3);
		if (index == 6)
			num_triangles++;
		else if (index != 6 && index > 0)
			doError("Formatting error");
	} while (index == 6);

	// Calloc a fresh block for all triangles instead of just the one.
	triangles = calloc(num_triangles, sizeof(*triangles));

	// Rewind the back to beginning
	rewind(fp);

	// Read everything into the newly allocated (and zero-ed) memory.
	for (index = 0; index < num_triangles; ++index)
		fscanf(fp, "%d,%d,%d,%d,%d,%d", &triangles[index].x1, &triangles[index].y1,
			&triangles[index].x2, &triangles[index].y2, &triangles[index].x3, &triangles[index].y3);

	// Close file
	if (fclose(fp) != 0)
		doError("Couldn't close file");

	// Write done to standard-out
	printf("[done]\n");
}



