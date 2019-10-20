/*
 * WordSearch.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include "WordSearch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printSolution(const Puzzle* puzzle)
{
	uint_fast8_t x;
	uint_fast8_t y;

	printf("Resenje: ");
	for(y = 0; y < puzzle->sizeY; y++)
	{
		for(x = 0; x < puzzle->sizeX; x++)
		{
			if(puzzle->markedWords[y][x] != 1)
			{
				printf("%c", puzzle->charMatrix[y][x]);
			}
		}
	}
	printf("\n");
}

void printWord(Puzzle* puzzle, int_fast8_t lastPosX, int_fast8_t lastPosY, int_least8_t dirX, int_least8_t dirY, uint_least8_t wordLength)
{
	int_fast8_t i;
	int_least8_t xPosArray[wordLength];
	int_least8_t yPosArray[wordLength];
	int_least8_t invDirX;
	int_least8_t invDirY;
	int_fast8_t posX;
	int_fast8_t posY;

	char* word = (char*)malloc(wordLength + 1);

	invDirX = dirX * (-1);
	invDirY = dirY * (-1);

	posX = lastPosX;
	posY = lastPosY;

	word[wordLength] = '\0';

	for (i = wordLength - 1; i >= 0; i--)
	{
		xPosArray[i] = posX;
		yPosArray[i] = posY;
		word[i] = puzzle->charMatrix[posY][posX];
		puzzle->markedWords[posY][posX] = 1;
		posX += invDirX;
		posY += invDirY;
	}

	printf("%s:{", word);

	for (i = 0; i < wordLength; i++)
	{
		printf("[%d,%d]", xPosArray[i], yPosArray[i]);
	}

	printf("}\n");
}

void tryAllDirections(Puzzle* puzzle, int_fast8_t posX, int_fast8_t posY, Word* word)
{
	int_least8_t directions[] = {1, 0, -1};
	int_least8_t directionX;
	int_least8_t directionY;
	int_fast8_t newPosX;
	int_fast8_t newPosY;
	uint_fast8_t i;
	uint_fast8_t j;
	uint_least8_t wordLength = strlen(word->letters) - 1;
	uint_least8_t matchCounter;


	for(j = 0; j < 3; j++)
	{
		for(i = 0; i < 3; i++)
		{
			directionX = directions[i];
			directionY = directions[j];

			newPosX = posX + directionX;
			if(newPosX > puzzle->sizeX || newPosX < 0) continue;

			newPosY = posY + directionY;
			if(newPosY > puzzle->sizeY || newPosY < 0) continue;

			char* charPtr = word->letters + 1;

			matchCounter = 1;

			while(*charPtr != '\0' && *charPtr == puzzle->charMatrix[newPosY][newPosX])
			{

				charPtr++;
				matchCounter++;

				if(matchCounter == wordLength)
				{
					printWord(puzzle, newPosX, newPosY, directionX, directionY, wordLength);
					break;
				}

				newPosX += directionX;
				newPosY += directionY;
			}
		}
	}
}

void findWord(Puzzle* puzzle, Word* word)
{

	char* charPtr = word->letters;

	int_fast8_t mX = 0;
	int_fast8_t mY = 0;

	for (mY = 0; mY < puzzle->sizeY; mY++)
	{
		for(mX = 0; mX < puzzle->sizeX; mX++)
		{
			if(*charPtr == puzzle->charMatrix[mY][mX])
			{
				tryAllDirections(puzzle, mX, mY, word);
			}
		}
	}
}

void solvePuzzle(Puzzle* puzzle)
{
	Word* word;
	word = puzzle->wordList->head;

	while(word != NULL)
	{
		findWord(puzzle, word);
		word = word->next;
	}

	printSolution(puzzle);

}
