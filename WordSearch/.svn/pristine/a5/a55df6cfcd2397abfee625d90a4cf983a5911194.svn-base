/*
 * FileHandle.c
 *
 *  Created on: Oct 18, 2019
 *      Author: stefa
 */

#include "FileHandle.h"
#include <inttypes.h>
#include <string.h>

FILE* OpenFile(char* fileName)
{
	FILE* inFile;

	inFile = fopen(fileName, "r");

	if(inFile == NULL)
	{
		printf("Could not load file.");
		exit(EXIT_FAILURE);
	}

	return inFile;
}

void ReadPuzzleFromFile(FILE* inFile, Puzzle* puzzle)
{
	char* line = NULL;
	char* charPtr;
	int_least8_t x = 0;
	int_least8_t y = 0;

	size_t lineLength;

	while(1)
	{
		getline(&line, &lineLength, inFile);
		charPtr = line;

		while(*charPtr != '\n' || (strcmp(line, "#WORDS") != 0))
		{
			puzzle->charMatrix[y][x] = *charPtr;
			x++;
			charPtr++;
		}
		y++;
		if(strcmp(line, "#END") == 0) break;

	}
}
