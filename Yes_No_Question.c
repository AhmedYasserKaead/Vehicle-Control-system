/*
 * Yes_No_Question.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>

#include "Datatypes.h"


u_int8 Yes_No_Question(u_int8 Answer)
{

	printf("Are you sure you want to End the program? Yes--->(Y/y) or No--->(N/n)\n");
	scanf(" %c", &Answer);
	printf("\n");
	return Answer;
}
