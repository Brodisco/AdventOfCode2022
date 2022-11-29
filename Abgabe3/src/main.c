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





int main(void)
{
	printf("Abgabe3 \n \n");

	List *list = listCreate();

	for (int i = 1; i < 10; i++)
	{
		listPush(list, i);
	}

	listPrint(list);

	for (int i = 0; i < 11; i++)
	{
		printf("Index(%d): %d \n",i,  listGetElementAtIndex(list, i));
	}

	listSwapElements(list, 3, 4);

	listPrint(list);

/*
	test_pushPrint();
	testListFindElement();
	testListGetIndexOfElement();
	testListGetElementAtIndex();
*/
	int wait;
	scanf("%d", &wait);
	return EXIT_SUCCESS;
}
