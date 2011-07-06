/*
 * params.h
 *
 *  Created on: Oct 24, 2010
 *      Author: dasm80x86
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#define STR_EMPTY = (const char*)"";

// Structure for storing input parameters
struct parameters
{
	unsigned short int single_problem;
	unsigned char all_problems;
	char fileName[25];
} params;

/**
 * Function: showHelp
 * Description: Displays help information to standard-error
 */
inline void showHelp() {
	// TODO: Ensure this is cooked
	printf("Usage:\n./ProjectEuler_Dasm80x86 [--all | -p (n)] \n");
}

/**
 * Function: parseArgs
 * Description: Parse arguments and populate the parameters struct with
 * settings pulled from argv.
 * Remarks: argv and argc are not modified.
 */
inline void parseArgs(const int argc, char** argv)
{
	// Define various parameters for command line usage.
	const char* FILENAME_PARAM = "-f";
	const char* PROBLEM_PARAM = "-p";
	const char* PROBLEM_ALL = "--ALL";
	const char* HELP_PARAM = "-help";

	int index;

	// Initialize parameters
	params.all_problems = 0;
	params.single_problem = 0;

	// Index through all arguments
	for (index = 0; index < argc; ++index)
		if (strcmp(FILENAME_PARAM, argv[index]) == 0) {
			if (argv[index + 1] != '\0')
				strcat(params.fileName, argv[index + 1]);
		} else if (strcmp(HELP_PARAM, argv[index]) == 0) {
			showHelp();
			exit(EXIT_SUCCESS);
		} else if (strcmp(PROBLEM_PARAM, argv[index]) == 0) {
			params.single_problem = atoi(argv[index + 1]);
		} else if (strcmp(PROBLEM_ALL, argv[index]) == 0) {
			params.all_problems = 1;
		}

	if (params.all_problems)
		printf("Running all problems\n");
	else if (params.single_problem > 0)
		printf("Running problem #%d\n", params.single_problem);
	printf("\n");
}

#endif /* PARAMS_H_ */
