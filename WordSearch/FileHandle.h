/*
 * FileHandle.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Stefan Jovanovic
 *       Index: RA234/2013
 */

#ifndef FILEHANDLE_H_
#define FILEHANDLE_H_

#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

FILE* OpenFile(char* fileName);
void ReadPuzzleFromFile(FILE* inFile, Puzzle* puzzle);

#endif /* FILEHANDLE_H_ */
