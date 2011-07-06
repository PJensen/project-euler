/*
 * p102.h
 *
 *  Created on: Oct 23, 2010
 *      Author: dasm80x86
 */

#ifndef P102_H_
#define P102_H_

#define TRIANGLES_TXT 		"triangles.txt"

// As required by all problems; we *must* implement
// a run function that returns 0 | 1
int run_p102();

// Structure representing one triangle
typedef struct _triangle {
	int x1, y1, x2, y2, x3, y3;
} Triangle;

typedef struct _point { int x, y; } Point;
typedef struct _line { Point p1, p2; } Line;

int ccw(Point p0, Point p1, Point p2);
int intersect(Line l1, Line l2);
Point midpoint2P(Point a, Point b);
Point midpoint1L(Line ab);
Line cline(Point p1, Point p2);


// Prototypes
void readTriangles(void);
void freeTriangles(Triangle* aPtr);
void show_p102(void);
void display_p102(void);

#endif /* P102_H_ */
