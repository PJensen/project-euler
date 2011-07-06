/*
 * p45.h
 *
 *  Created on: Oct 27, 2010
 *      Author: dasm80x86
 */

#ifndef P45_H_
#define P45_H_

#define TRIANGLE_NUMBER_START = 285;

int run_p45();
void display_p45();
void plot_function(int (*f_func)(), int x);

int triangle_number(int n);
int pentagonal_number(int n);
int hexagonal_number(int n);

#endif /* P45_H_ */
