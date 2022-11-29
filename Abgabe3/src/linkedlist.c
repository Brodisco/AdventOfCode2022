/*
 * linkedlist.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

Element *elementCreate()
{
	Element *element = (Element*) malloc(sizeof(Element));
	element->pSuccessor = NULL;
	element->value = 0;
	return element;
}

List *listCreate()
{
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	return list;
}

void listPush(List *list, unsigned int value)
{
	Element *element = elementCreate();
	element->value = value;
	element->pSuccessor = list->head;
	list->head = element;

}

Element *listPop(List *list)
{
	Element *element = list->head;
	list->head = list->head->pSuccessor;
	return element;
}

void listPrint(const List *list)
{
	Element *element = list->head;

	if (element == NULL)
	{
		printf("Liste leer! \n");
	}

	while(element != NULL)
	{
		printf(" %d ", element->value);

		element = element->pSuccessor;

		if (element == NULL)
		{
			printf("\n");
		}
	}
}

void listFillRandom(List *list, int seed, int anzahlWerte, int min, int max)
{
	srand(seed);

	int randomNumber = 0;

	for (int i = 0; i < anzahlWerte; i++)
	{
		do
		{
			randomNumber = rand() % max;
		}while(randomNumber <= min);

		listPush(list, randomNumber);
	}
}

Element *listFindElement(List *list, unsigned int value)
{
	Element *element = list->head;

	while(element != NULL)
	{
		if (element->value == value)
		{
			break;
		}

		element = element->pSuccessor;
	}

	return element;
}


int listGetIndexOfElement(List *list, unsigned value)
{
	Element *element = list->head;

	int index = 0;

	int ret = -1;

	while(element != NULL)
	{
		if (element->value == value)
		{
			ret = index;
			break;
		}

		element = element->pSuccessor;

		index++;

	}

	return ret;
}


Element *listGetElementAtIndex(List *list, unsigned int index)
{
	Element *element = list->head;

	while(index > 0 && element != NULL)
	{
		element = element->pSuccessor;

		index--;
	}

	return element;

}

