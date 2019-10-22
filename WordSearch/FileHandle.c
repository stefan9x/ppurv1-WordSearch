/*
 * FileHandle.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include "FileHandle.h"
#include <inttypes.h>
#include <string.h>

FILE* OpenFile(char* fileName)
{
	FILE* inFile;

	inFile = fopen(fileName, "r");

	if (inFile == NULL)
	{
		printf("Could not load file.");
		exit(EXIT_FAILURE);
	}

	return inFile;
}

// Popunjava matricu i listu reci, sa podacima iz datoteke
void ReadPuzzleFromFile(FILE* inFile, Puzzle* puzzle)
{
	char* line = NULL;
	char* charPtr;
	int_least8_t x = 0;
	int_least8_t y = 0;
	size_t lineLength;

	rewind(inFile);
	while (1)
	{
		getline(&line, &lineLength, inFile);
		if (strncmp(line, "#WORDS", 5) == 0) break;
		charPtr = line;
		x = 0;

		while (x < puzzle->sizeX)
		{
			puzzle->charMatrix[y][x] = *charPtr;
			x++;
			charPtr++;
		}
		y++;
	}

	while(1)
	{
		getline(&line, &lineLength, inFile);
		if (strncmp(line, "#END", 4) == 0) break;

		WordListInsert(puzzle->wordList, puzzle->wordList->tail, line);
	}
}
