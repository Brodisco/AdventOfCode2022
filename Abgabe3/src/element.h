/*
 * element.h
 *
 *  Created on: 22.11.2022
 *      Author: student
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

struct Element
{
	unsigned int value;
	void *pSuccessor;
};
typedef struct Element Element;


#endif /* ELEMENT_H_ */
