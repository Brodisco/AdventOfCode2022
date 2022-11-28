/*
 * main.c
 *
 *  Created on: 22.11.2022
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

	int foundIndex = 0;

	if (element == NULL)
	{
		return -1;
	}

	while(element != NULL)
	{
		if (element->value == value)
		{
			foundIndex = 1;
			break;
		}

		element = element->pSuccessor;

		index++;
	}

	if (foundIndex == 1)
	{
		return index;
	} else {
		return -1;
	}


}

Element *listGetElementAtIndex(List *list, unsigned int index)
{
	Element *element = list->head;

	for (int i = 0; i < index; i++)
	{
		if (element == NULL)
		{
			break;
		} else {
			element = element->pSuccessor;
		}
	}

	return element;
}

boolean listSwapElements(List *list, unsigned int aIndex, unsigned int bIndex)
{

	Element *specificElement[2] = {listGetElementAtIndex(list, aIndex),
								   listGetElementAtIndex(list, bIndex)};

	Element *backupElement;

	if (aIndex == bIndex)
	{
		return FALSE;
	}

	if (specificElement[0] == NULL || specificElement[1] == NULL)
	{
		return FALSE;
	}

	backupElement = specificElement[0]->pSuccessor;
	specificElement[0]->pSuccessor = specificElement[1]->pSuccessor;
	specificElement[1]->pSuccessor = backupElement;

	if(aIndex == 0)
	{
		list->head = specificElement[1];
		listGetElementAtIndex(list, bIndex - 1)->pSuccessor = specificElement[0];
	}
	else if(bIndex == 0)
	{
		list->head = specificElement[0];
		listGetElementAtIndex(list, aIndex - 1)->pSuccessor = specificElement[1];
	}
	else
	{
		listGetElementAtIndex(list, aIndex - 1)->pSuccessor = specificElement[1];
		listGetElementAtIndex(list, bIndex - 1)->pSuccessor = specificElement[0];
	}


	return TRUE;

}

boolean listDeleteElement(List *list, unsigned int value)
{
	Element *specificElement = listFindElement(list, value);
	Element *prevElement = NULL;
	int index = 0;

	if (specificElement == NULL)
	{
		return FALSE;
	}

	index = listGetIndexOfElement(list, value);
	prevElement = listGetElementAtIndex(list, index - 1);

	if (index == 0)
	{
		list->head = specificElement->pSuccessor;
		free(specificElement);
		return TRUE;
	}

	if (specificElement->pSuccessor == NULL)
	{
		prevElement->pSuccessor = NULL;
		free(specificElement);
		return TRUE;
	}

	prevElement->pSuccessor = specificElement->pSuccessor;
	free(specificElement);

	return TRUE;
}

void test_pushPrint(void)
{
	List *list = listCreate();

	printf("Aufgabe 4a: \n");

	listPrint(list);

	for (int i = 1; i < 10; i++)
	{
		printf(" %d ", i);
		listPush(list, i);
	}
	printf("\n");

	listPrint(list);

	printf("\n");
}

void testListFindElement(void)
{
	List *list = listCreate();

	printf("Aufgabe 4b: \n");

	listPrint(list);

	Element *element = listFindElement(list, 0);


	if (element == NULL)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	for (int i = 1; i < 10; i++)
	{
		listPush(list, i);
	}

	element = listFindElement(list, 5);

	if (element->value == 5)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	element = listFindElement(list, 20);

	if (element == NULL)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	listPrint(list);

	printf("\n");
}

void testListGetIndexOfElement(void)
{
	List *list = listCreate();

	printf("Aufgabe 5a: \n");

	listPrint(list);

	int index = listGetIndexOfElement(list, 0);

	if (index == -1)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	for (int i = 10 - 1; i > 0; i--)
	{
		listPush(list, i);
	}

	index = listGetIndexOfElement(list, 1);

	if (index == 0)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	index = listGetIndexOfElement(list, 4);

	if (index == 3)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	index = listGetIndexOfElement(list, 25);

	if (index == -1)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	listPrint(list);

	printf("\n");
}

void testListGetElementAtIndex(void)
{
	List *list = listCreate();

	printf("Aufgabe 5b: \n");

	listPrint(list);

	Element *element = listGetElementAtIndex(list, 5);

	if (element == NULL)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	for (int i = 9; i > 0; i--)
	{
		listPush(list, i);
	}

	element = listGetElementAtIndex(list, 5);

	if (element->value == 6)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	element = listGetElementAtIndex(list, 15);

	if (element == NULL)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	listPrint(list);

	printf("\n");
}

int main(void)
{
	printf("Abgabe3 \n \n");

	/*
	List *list = listCreate();

	//listFillRandom(list, time(NULL), 20, 2, 10);
	for (int i = 0; i < 20; i++)
	{
		listPush(list, i);
	}


	listPrint(list);

	//listSwapElements(list, 0, 19);

	//listPrint(list);

	//listSwapElements(list, 0, 19);

	listDeleteElement(list, 0);

	listPrint(list);
	*/

	test_pushPrint();
	testListFindElement();
	testListGetIndexOfElement();
	testListGetElementAtIndex();

	int wait;
	scanf("%d", &wait);
	return EXIT_SUCCESS;
}
