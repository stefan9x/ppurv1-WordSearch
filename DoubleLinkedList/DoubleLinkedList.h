#pragma once
/*
 * DoubleLinkedList.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <stdio.h>
#include <inttypes.h>

typedef struct Word
{
	char* letters;
	uint_least8_t* xPos;
	uint_least8_t* yPos;
	struct Word* next;
	struct Word* previous;
} Word;

typedef struct WordList
{
	Word* head;
	Word* tail;
} WordList;

typedef struct Puzzle
{
	char** charMatrix;
	uint_least8_t** markedWords;
	int_least8_t sizeX;
	int_least8_t sizeY;
	WordList* wordList;
}Puzzle;

void WordListCreate(WordList* wordList);
void WordListDestroy(WordList* wordList);
void WordListInsert(WordList* wordList, Word* location, const char* newWord);
void AlocateMatrixMemory(FILE* inFile, Puzzle* puzzle);
void PrintMatrix(Puzzle* puzzle);
void PrintWords(Puzzle* puzzle);

#endif /* DOUBLELINKEDLIST_H_ */
