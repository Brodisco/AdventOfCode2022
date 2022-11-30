/*
 * extendedlinkedlist.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

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
	int index = listGetIndexOfElement(list, value);

	if (specificElement == NULL || index == -1)
	{
		return FALSE;
	}

	prevElement = listGetElementAtIndex(list, index - 1);

	if (index == 0)
	{
		free(listPop(list));
		return TRUE;
	}

	prevElement->pSuccessor = specificElement->pSuccessor;
	free(specificElement);

	return TRUE;
}
