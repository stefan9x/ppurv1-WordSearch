/*
 * DoubleLinkedList.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "DoubleLinkedList.h"

void WordListCreate(WordList* wordList)
{
	wordList->head = NULL;
	wordList->tail = NULL;
}

void WordListDestroy(WordList* wordList)
{
	if (wordList->head == NULL) return;

	Word* current = wordList->head;

	while(current != wordList->tail)
	{
		current = current->next;
		free(current->previous);
	}

	free(current);

	wordList->head = NULL;
	wordList->tail = NULL;

	free(wordList);
}

void WordListInsert(WordList* wordList, Word* location, const char* newWord)
{
	Word* word = malloc(sizeof(Word));
	int_least8_t newWordLength = strlen(newWord);

	strncpy(word->letters, newWord, newWordLength);
	word->letters[newWordLength] = '\0';

	if(location == NULL)
	{
		word->next = wordList->head;
		word->previous = location;
		wordList->head = word;
		wordList->tail = word;
	}
	else
	{
		word->next = location->next;
		word->previous = location;
		location->next = word;
		wordList->tail = word;
	}
}

void WordListDelete(WordList* wordList, Word* location)
{
	location->previous->next = location->next;
	location->next->previous = location->previous;

	if(wordList->head == location)
	{
		wordList->head = location->next;
	}

	if(wordList->tail == location)
	{
		wordList->tail = location->previous;
	}

	free(location);
}

void PrintMatrix(Puzzle* puzzle)
{
	int_fast8_t x;
	int_fast8_t y;

	printf(" ");

	for(x = 0; x < puzzle->sizeX; x++)
	{
		printf(" %d", x);
	}

	for(y = 0; y < puzzle->sizeY; y++)
	{
		printf("\n%d ", y);
		for(x = 0; x < puzzle->sizeX; x++)
		{
			printf("%c ", puzzle->charMatrix[y][x]);
		}
	}
}

void PrintWords(Puzzle* puzzle)
{
	Word* word = puzzle->wordList->head;

	while(word != NULL)
	{
		printf("%s", word->letters);
		word = word->next;
	}
}
