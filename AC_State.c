/*
 * AC_State.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed-PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "Bool_state.h"
#include "Datatypes.h"


void AC_State(u_int8 AC){
	switch (AC){				/* AC is ON or OFF. */
	case OFF:
		printf("AC: OFF\n");
		break;
	case ON:
		printf("AC: ON\n");
		break;
	default:
		printf("AC: ERROR!!!!!!!!\n");
		break;
	}
}
