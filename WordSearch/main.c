/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include "DoubleLinkedList.h"
#include "FileHandle.h"
#include "WordSearch.h"

int main()
{

	FILE* inFile;
	char* fileName = "puzzle2.txt";

	inFile = OpenFile(fileName);

	Puzzle puzzle;
	WordList wordList;

	WordListCreate(&wordList);
	puzzle.wordList = &wordList;

	ReadPuzzleFromFile(inFile, &puzzle, &wordList);

	//PrintMatrix(&puzzle);
	//printf("\n");
	//PrintWords(&puzzle);

	solvePuzzle(&puzzle);

	WordListDestroy(&wordList);

	printf("\nFinished");

	return 1;
}
