/*
 * WordSearch.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#include "DoubleLinkedList.h"
#include <inttypes.h>

void PrintSolution(const Puzzle* puzzle);
void MarkWord(Puzzle* puzzle, Word* word, int_fast8_t lastPosX, int_fast8_t lastPosY, int_least8_t dirX, int_least8_t dirY, uint_least8_t wordLength);
void PrintWordsPositions(Puzzle* puzzle);
void TryAllDirections(Puzzle* puzzle, int_fast8_t posX, int_fast8_t posY, Word* word);
void FindWord(Puzzle* puzzle, Word* word);
void SolvePuzzle(Puzzle* puzzle);

#endif /* WORDSEARCH_H_ */
