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

struct List
{
	struct Element *head;
};
typedef struct List List;

List *listCreate();

#endif /* LIST_H_ */
