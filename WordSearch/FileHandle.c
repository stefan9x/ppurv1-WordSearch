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

void ReadPuzzleFromFile(FILE* inFile, Puzzle* puzzle, WordList* wordList)
{
	char* line = NULL;
	char* charPtr;
	int_least8_t x = 0;
	int_least8_t y = 0;

	size_t lineLength;

	while(1)
	{
		getline(&line, &lineLength, inFile);
		if(strcmp(line, "#WORDS\n") == 0) break;
		charPtr = line;
		x = 0;

		while(*charPtr != '\n')
		{
			puzzle->charMatrix[y][x] = *charPtr;
			x++;
			charPtr++;
		}
		y++;
	}

	puzzle->sizeX = x;
	puzzle->sizeY = y;

	while(1)
	{
		getline(&line, &lineLength, inFile);
		if(strcmp(line, "#END") == 0) break;

		WordListInsert(wordList, NULL, line);
	}
}
