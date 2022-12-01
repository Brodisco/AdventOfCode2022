/*
 * test.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void test_pushPrint(void)
{
	List *list = listCreate();

	printf("Aufgabe 4a: \n");

	listPrint(list);

	for (int i = 1; i <= 10; i++)
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

	for (int i = 10; i > 0; i--)
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

	for (int i = 10; i > 0; i--)
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

	for (int i = 10; i > 0; i--)
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

void deleteElementTest(void)
{
	printf("Delete Element: \n");

	List *list = listCreate();

		for (int i = 1; i < 10; i++)
		{
			listPush(list, i);
		}

		listPrint(list);

		for (int i = 0; i < 10; i++)
		{
			printf("Index(%d): %p \n",i,  listGetElementAtIndex(list, i));
		}

		listSwapElements(list, 3, 4);

		for (int i = 0; i < 10; i++)
		{
			listDeleteElement(list, i);
			listPrint(list);
		}
}

void swapElementTest(void)
{
	printf("Swap Element: \n");

	List *list = listCreate();

	for (int i = 1; i < 10; i++)
	{
		listPush(list, i);
	}

	listSwapElements(list, 7, 8);

	listPrint(list);

	listSwapElements(list, 7, 8);

	listPrint(list);

	unsigned int i = 0, k = 8;
	char check = 1;

	do
	{

		check = listSwapElements(list, i, k);
		printf("%d <-> %d = (%d)", i, k, check);
		listPrint(list);

	}while(++i < 8 && --k >= 0 && check == 1);

	printf("\n");

}

