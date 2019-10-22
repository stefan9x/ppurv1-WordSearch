/*
 * WordSearch.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#include "WordSearch.h"
#include "DoubleLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ispisuje resenje osmosmerke
void PrintSolution(const Puzzle* puzzle)
{
	uint_fast8_t x;
	uint_fast8_t y;

	printf("Resenje: ");
	for (y = 0; y < puzzle->sizeY; y++)
	{
		for (x = 0; x < puzzle->sizeX; x++)
		{
			if (puzzle->markedWords[y][x] != 1)
			{
				printf("%c", puzzle->charMatrix[y][x]);
			}
		}
	}
	printf("\n");
}

// Oznacava pronadjenu rec u matrici
void MarkWord(Puzzle* puzzle, Word* word, int_fast8_t lastPosX, int_fast8_t lastPosY, int_least8_t dirX, int_least8_t dirY, uint_least8_t wordLength)
{
	int_fast8_t i;
	int_least8_t invDirX;
	int_least8_t invDirY;
	int_least8_t posX;
	int_least8_t posY;

	invDirX = dirX * (-1);
	invDirY = dirY * (-1);

	posX = lastPosX;
	posY = lastPosY;

	word->xPos = (uint_least8_t*)malloc(wordLength * sizeof(uint_least8_t));
	word->yPos = (uint_least8_t*)malloc(wordLength * sizeof(uint_least8_t));

	for (i = wordLength - 1; i >= 0; i--)
	{
		word->xPos[i] = posX;
		word->yPos[i] = posY;
		puzzle->markedWords[posY][posX] = 1;
		posX += invDirX;
		posY += invDirY;
	}

}

// Ispisuje poziciju svakog karaktera reci u matrici
void PrintWordsPositions(Puzzle* puzzle)
{
	uint_least8_t wordLength;
	uint_least8_t i;
	Word* word = puzzle->wordList->head;

	while (word != NULL)
	{
		wordLength = strlen(word->letters);
		printf("%s:{", word->letters);

		for (i = 0; i < wordLength; i++)
		{
			printf("[%"PRIuLEAST8",%"PRIuLEAST8"]", word->xPos[i], word->yPos[i]);
		}

		printf("}\n");

		word = word->next;
	}
}

// Trazi rec i svakom smeru
void TryAllDirections(Puzzle* puzzle, int_fast8_t posX, int_fast8_t posY, Word* word)
{
	int_least8_t directions[] = {1, 0, -1};
	int_least8_t directionX;
	int_least8_t directionY;
	int_least8_t newPosX;
	int_least8_t newPosY;
	uint_fast8_t i;
	uint_fast8_t j;
	uint_least8_t matchCounter;

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			directionX = directions[i];
			directionY = directions[j];

			newPosX = posX + directionX;
			if (newPosX >= puzzle->sizeX || newPosX < 0) continue;

			newPosY = posY + directionY;
			if (newPosY >= puzzle->sizeY || newPosY < 0) continue;

			char* charPtr = word->letters + 1;

			matchCounter = 1;

			while (*charPtr == puzzle->charMatrix[newPosY][newPosX])
			{

				charPtr++;
				matchCounter++;

				if (*charPtr == '\0')
				{
					MarkWord(puzzle, word, newPosX, newPosY, directionX, directionY, matchCounter);
					break;
				}

				newPosX += directionX;
				if (newPosX >= puzzle->sizeX || newPosX < 0) break;
				newPosY += directionY;
				if (newPosY >= puzzle->sizeY || newPosY < 0) break;
			}
		}
	}
}

// Trazi pocetno slovo reci u matrici i kada nadje
// poziva funckiju koja trazi ostatak rec u svakom smeru
// oko tog slova
void FindWord(Puzzle* puzzle, Word* word)
{
	char* charPtr = word->letters;

	int_fast8_t mX = 0;
	int_fast8_t mY = 0;

	for (mY = 0; mY < puzzle->sizeY; mY++)
	{
		for (mX = 0; mX < puzzle->sizeX; mX++)
		{
			if (*charPtr == puzzle->charMatrix[mY][mX])
			{
				TryAllDirections(puzzle, mX, mY, word);
			}
		}
	}
}

// Uzima rec po rec iz liste, i poziva funckiju
// koja trazi rec u matrici
void SolvePuzzle(Puzzle* puzzle)
{
	Word* word;
	word = puzzle->wordList->head;

	while (word != NULL)
	{
		FindWord(puzzle, word);
		word = word->next;
	}
}
