/*
 * list.h
 *
 *  Created on: 22.11.2022
 *      Author: student
 */

#ifndef LIST_H_
#define LIST_H_

#include "myboolean.h"
#include "element.h"
#include "test.h"

struct List
{
	struct Element *head;
};
typedef struct List List;

Element *elementCreate();
List *listCreate();
void listPush(List *list, unsigned int value);
Element *listPop(List *list);
void listPrint(const List *list);
void listFillRandom(List *list, int seed, int anzahlWerte, int min, int max);
Element *listFindElement(List *list, unsigned int value);
int listGetIndexOfElement(List *list, unsigned value);
Element *listGetElementAtIndex(List *list, unsigned int index);

boolean listSwapElements(List *list, unsigned int aIndex, unsigned int bIndex);
boolean listDeleteElement(List *list, unsigned int value);

#endif /* LIST_H_ */
