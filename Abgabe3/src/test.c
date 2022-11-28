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
	printf("Index: %x \n", element);

	if (element == NULL)
	{
		printf("Korrekt \n");
	} else {
		printf("Falsch \n");
	}

	listPrint(list);

	printf("\n");
}

