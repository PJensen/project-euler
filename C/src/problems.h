/*
 * problems.h
 *
 *  Created on: Oct 24, 2010
 *      Author: dasm80x86
 */

#ifndef PROBLEMS_H_
#define PROBLEMS_H_

#define PROBLEM_OK		= 0x0000
#define PROBLEM_FAIL	= 0x0001

// Define a pointer to the problem to execute
int (*problem_execute)() = NULL;

// A function that doesn't do anything
inline int run_nothing() { return EXIT_SUCCESS; }

#endif /* PROBLEMS_H_ */
