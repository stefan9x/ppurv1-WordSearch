/*
 * DoubleLinkedList.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>  //Zbog free()
#include <string.h>

// Inicijalizacija pokazivaca za pocetak i kraj liste
void WordListCreate(WordList* wordList)
{
	wordList->head = NULL;
	wordList->tail = NULL;
}

// Oslobadja memoriju koju je lista zauzela
void WordListDestroy(WordList* wordList)
{
	if (wordList->head == NULL) exit(EXIT_FAILURE);

	Word* current = wordList->head;

	while(current != wordList->tail)
	{
		free(current->letters);
		free(current->xPos);
		free(current->yPos);
		current = current->next;
		free(current->previous);
	}

	free(current->letters);
	free(current->xPos);
	free(current->yPos);
	free(current);

	wordList->head = NULL;
	wordList->tail = NULL;
}

// Ubacuje rec na kraj liste i trimuje string
void WordListInsert(WordList* wordList, Word* location, const char* newWord)
{
	Word* word = malloc(sizeof(Word));
	const char* charPtr = newWord;
	int_least8_t newWordLength = 0;

	while(*charPtr != '\r' && *charPtr != '\n')
	{
		newWordLength++;
		charPtr++;
	}

	word->letters = (char*)malloc(newWordLength);
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

// Pronalazi velicinu matrice i zauzima memoriju za istu
void AlocateMatrixMemory(FILE* inFile, Puzzle* puzzle)
{
	char* line = NULL;
	char* charPtr;
	int_least8_t x = 0;
	int_least8_t y = 1;
	size_t lineLength;

	getline(&line, &lineLength, inFile);

	charPtr = line;

	while(*charPtr != '\n' && *charPtr != '\r')
	{
		x++;
		charPtr++;
	}

	puzzle->sizeX = x;

	while(1)
	{
		getline(&line, &lineLength, inFile);
		if(strncmp(line, "#WORDS", 5) == 0) break;
		y++;
	}

	puzzle->sizeY = y;

	puzzle->charMatrix = (char**)malloc(puzzle->sizeY * sizeof(char*));
	puzzle->markedWords = (uint_least8_t**)malloc(puzzle->sizeY * sizeof(uint_least8_t*));

	for(y = 0; y < puzzle->sizeY; y++)
	{
		puzzle->charMatrix[y] = (char*)malloc(puzzle->sizeX * sizeof(char));
		puzzle->markedWords[y] = (uint_least8_t*)malloc(puzzle->sizeX * sizeof(uint_least8_t*));
	}
}

// Ispisuje matricu(osmosmerku) na ekran
void PrintMatrix(Puzzle* puzzle)
{
	int_fast8_t x;
	int_fast8_t y;

	printf("\nOsmosmerka:\n");
	printf(" ");

	for(x = 0; x < puzzle->sizeX; x++)
	{
		printf(" %"PRIiFAST8, x);
	}

	for(y = 0; y < puzzle->sizeY; y++)
	{
		printf("\n%"PRIiFAST8" ", y);
		for(x = 0; x < puzzle->sizeX; x++)
		{
			printf("%c ", puzzle->charMatrix[y][x]);
		}
	}
}

// Ispisuje reci iz liste
void PrintWords(Puzzle* puzzle)
{
	Word* word = puzzle->wordList->head;

	printf("Words list:\n");
	while(word != NULL)
	{
		printf("%s\n", word->letters);
		word = word->next;
	}
}
