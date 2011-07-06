/*
 * error.c
 *
 *  Created on: Oct 25, 2010
 *      Author: dasm80x86
 */

#include <stdlib.h>
#include <stdio.h>

#include "error.h"

/**
 * doError
 * Description: Writes an error message to standard out.
 * Parameters: aErrorMessage - literal string to write.
 */
inline void doError(const char* aErrorMessage)
{
	fprintf(stderr, "%s", aErrorMessage);
	exit(EXIT_FAILURE);
}

inline void doWarning(const char* aWarningMessage)
{
	fprintf(stderr, "%s", aWarningMessage);
}


