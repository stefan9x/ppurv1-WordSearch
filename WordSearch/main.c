/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 *
 *  Zadatak se sastoji iz:
 *  	-Dinamicke biblioteke koja sadrzi dvostruko spregnutu listu
 *  	-Programa koji resava osmosmerku
 *
 *  Rešenje:
 *  	Program ucitava matricu i reci iz datoteke ciji se naziv prosledjuje
 *  	preko argumenta, prilikom poziva programa. Zatim uzima rec po rec iz liste,
 *  	trazi ih u matrici, i kada pronadje, pamti i oznacava lokaciju svakog karaktera.
 *  	Na kraju prolazi redom kroz matricu, i ispisuje sve neoznacene karaktere,
 *  	tako da taj ispis predstavlja resenje osmosmerke.
 */

#include "DoubleLinkedList.h"
#include "FileHandle.h"
#include "WordSearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <getopt.h>

int main(int argc, char *argv[])
{

	// getopt() zahteva tip int
	int options;

	FILE* inFile;
	uint_fast8_t i;

	Puzzle puzzle;
	WordList wordList;

	WordListCreate(&wordList);
	puzzle.wordList = &wordList;

	//Obrada unetih argumenata

	while ((options = getopt(argc, argv, "f:smw")) != -1)
	{
		switch(options)
		{
			case 'f':
				printf("----WordSeach Game----\n");
				// Ucitavanje datoteke
				if(optarg && strlen(optarg) > 1) inFile = OpenFile(optarg);

				//Dimicki zauzima mmeoriju za matricu
				AlocateMatrixMemory(inFile, &puzzle);

				//Ucitavanje podataka iz datoteke
				ReadPuzzleFromFile(inFile, &puzzle);

				// Resavanje osmosmerke
				SolvePuzzle(&puzzle);

				// Ispisivanje resenja
				PrintSolution(&puzzle);

				break;
			case 's':
				// Ispisuje reci i lokacije svakog karaktera, ako postoji "-s" switch
				PrintWordsPositions(&puzzle);
				break;
			case 'm':
				PrintMatrix(&puzzle);
				break;
			case 'w':
				PrintWords(&puzzle);
				break;
		}
	}

	// Ako nije unet nijedan argument, ispisuje uputstvo za koristenje
	// else, oslobadja zauzetu memoriju
	if (argc < 3)
	{
		printf("Usage: WordSearch [options]\n");
		printf("Options:\n");
		printf("\t-f filename\tInput file name. (This switch must be first)\n");
		printf("\t-s\t\tPrint words with characters locations.\n");
		printf("\t-m\t\tPrint matrix.\n");
		printf("\t-w\t\tPrint list of words.\n");
	}
	else
	{
		for (i = 0; i < puzzle.sizeY; i++)
		{
			free(puzzle.charMatrix[i]);
			free(puzzle.markedWords[i]);
		}

		free(puzzle.charMatrix);
		free(puzzle.markedWords);
		WordListDestroy(&wordList);
		if (inFile) fclose(inFile);
	}

	return 1;
}
