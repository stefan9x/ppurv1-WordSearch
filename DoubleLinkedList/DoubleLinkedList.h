/*
 * DoubleLinkedList.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <inttypes.h>

#define MAX_WORD_LENGTH 30
#define MAX_MATRIX_SIZE 20

typedef struct Word
{
	char letters[MAX_WORD_LENGTH];
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
	char charMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
	uint_least8_t markedWords[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
	int_least8_t sizeX;
	int_least8_t sizeY;
	WordList* wordList;
}Puzzle;

void WordListCreate(WordList* wordList);
void WordListDestroy(WordList* wordList);
void WordListInsert(WordList* wordList, Word* location, const char* newWord);
void WordListDelete(WordList* wordList, Word* location);
void PrintMatrix(Puzzle* puzzle);
void PrintWords(Puzzle* puzzle);

#endif /* DOUBLELINKEDLIST_H_ */
