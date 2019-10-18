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
	wordList->head = NULL;
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
	}
	else
	{
		word->next = location->next;
		word->previous = location;
		location->next = word;
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
