/*
 * p305.c
 *
 *  Created on: Oct 25, 2010
 *      Author: dasm80x86
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>

#include "p305.h"
#include "error.h"

char* s;

int run_p305()
{
	s = NULL;
	int index;				// Looping through entire problem space
	int max_length = 0;		// Maximum length possible
	char intBuffer[7];		// Quick integer buffer; stores 1594323 as max.

	// Figure out what we'll need to store
	for (index = P305_MIN_PROBLEM_SPACE;
			index < P305_MAX_PROBLEM_SPACE; ++index)
	{
		snprintf(intBuffer, sizeof(int), "%d", index);
		max_length += strlen(intBuffer);
	}

	// Show it
	fprintf(stderr, "string buffer size: %d\n", max_length);

	s = malloc(sizeof(char));	// init one

	for (index = P305_MIN_PROBLEM_SPACE;
			index < P305_MAX_PROBLEM_SPACE; ++index)
	{
		snprintf(intBuffer, sizeof(int), "%d", index);
		strcat(s, intBuffer);
	}
	printf("[done]");

	// int numChars = ceil(log(index));

	// Clean up
	free(s);

	return EXIT_SUCCESS;
}

