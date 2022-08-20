/*
 * AC_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"



void AC_State(u_int8 AC){
	switch (AC){				/* AC is ON or OFF. */
	case 0:
		printf("AC: OFF\n");
		break;
	case 1:
		printf("AC: ON\n");
		break;
	default:
		printf("AC: ERROR!!!!!!!!\n");
		break;
	}
}
