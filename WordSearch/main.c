/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include "FileHandle.h"

int main()
{

	FILE* inFile;
	char* fileName = "puzzle1.txt";

	Puzzle puzzle;
	WordList wordList;

	WordListCreate(&wordList);
	puzzle.wordList = &wordList;

	inFile = OpenFile(fileName);

	ReadPuzzleFromFile(inFile, &puzzle, &wordList);

	PrintMatrix(&puzzle);
	printf("\n");
	PrintWords(&puzzle);

	WordListDestroy(&wordList);

	printf("finished.");

	return 1;
}
