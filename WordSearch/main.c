/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: stefa
 */

#include "FileHandle.h"

void main()
{

	FILE* inFile;
	char* fileName = "puzzle1.txt";

	Puzzle puzzle;
	WordList wordList;

	WordListCreate(&wordList);
	puzzle.wordList = &wordList;


	//inFile = OpenFile(fileName);

	//ReadPuzzleFromFile(inFile, puzzle);


}
