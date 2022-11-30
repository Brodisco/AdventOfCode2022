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

	deleteElementTest();
	swapElementTest();


	test_pushPrint();
	testListFindElement();
	testListGetIndexOfElement();
	testListGetElementAtIndex();

	int wait;
	scanf("%d", &wait);
	return EXIT_SUCCESS;
}
