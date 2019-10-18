/*
 * DoubleLinkedList.h
 *
 *  Created on: Oct 18, 2019
 *      Author: stefa
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#define MAX_WORD_LENGTH 30

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

void WordListCreate(WordList* wordList);
void WordListDestroy(WordList* wordList);
void WordListInsert(WordList* wordList, Word* location, const char* newWord);
void WordListDelete(WordList* wordList, Word* location);

#endif /* DOUBLELINKEDLIST_H_ */
