/*
 ============================================================================
 Name        : ProjectEuler_Dasm80x86.c
 Author      : Peter Jensen
 Version     :
 Copyright   : Copyright (c) 2010 Peter Jensen All Rights Reserved
 Description : Project-Euler Problems; some problems include a basic
 graphical representation using OpenGL.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

// Open GL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Include supporting utility functions
#include "error.h"
#include "problems.h"
#include "params.h"
#include "graphics.h"

// Include all problems for potential use
#include "p102.h"
#include "p305.h"
#include "p45.h"

int main(int argc, char** argv)
{
	int result;	// Intermediate result.

	// Parse arguments to the argument parser, populates parameters structure.
	parseArgs(argc, argv);

	// graphics initialize pass through to glutInit
	graphics_init(&argc, argv);

	// set problem_execute to point to address of the given problem
	// entry point function.
	switch (params.single_problem)
	{
	case 102:
		problem_execute = &run_p102;
		break;
	case 305:
		problem_execute = &run_p305;
		break;
	case 45:
		problem_execute = &run_p45;
		break;
	default:
		problem_execute = &run_nothing;
	}

	// Execute the problem; *may* render graphics depending on
	// the problem.
	result = (*problem_execute) ();

	printf("%d", result);

	return EXIT_SUCCESS & result;
}


