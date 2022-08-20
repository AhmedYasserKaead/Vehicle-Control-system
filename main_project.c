/*
 * main_project.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Ahmed-PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "engine_state_question.h"
#include "Sensors_set_menu.h"
#include "traffic_light_reading.h"
#include "room_temp_reading.h"
#include "Engine_Temp_Reading.h"
#include "Delay.h"

#include "Vehicle_State.h"

#include "Engine_State.h"
#include "AC_State.h"
//#include "Room_Temp_State.h"
#include "Engine_Temperature_Controller_State.h"
//#include "Engine_Temp_State.h"





int main(void){

	u_int8 state[3][30] = {"the vehicle engine is now ON","the vehicle engine is now OFF","the program is closing"};
	u_int8 choices[5] = {'a','b','c','d','\0'};
	u_int8 input = 0;			/* Input from user to use the vehicle control system. */
	u_int8 set;					/* Used for sensors menu. */
	u_int8 AC = 0;				/* Air Conditioner state. */
	u_int8 Engine_Temperature_Controller = 0;
	u_int8 traffic_light;		/* Used to determine traffic light data. */
	u_int8 Engine_state = 0;	/* Engine state. */
	u_int16 speed;				/* Vehicle Speed. */
	f_32 engine_temp = 55.00;	/* Engine Temperature .. let default be (40) */
	f_32 room_temp = 27.00;		/* Room Temperature .. let default be (27). */


	fflush( stdout );		 	/* Fix for not printing. */
	setbuf(stdout, NULL);		/* Fix for not printing. */


	Beginning:					/* Destination jump point.*/

	/* Asking the User to make an action and to choose whether turning on or off the engine. */
	input = engine_state_question(input);


	if(input == choices[0])				 /* Here the user choose to turn ON the engine. */
	{
		Engine_ON:						 /* Destination jump point.*/
		Engine_state = 1;				 /* Engine is now ON. */
		printf("%s\n", state[0]);		 /* Prints that the engine is now ON. */

		Sensors_Menu:					 /* Destination jump point. */
		set = Sensors_set_menu(set);	 /* Sensors menu function. */

		if(set == choices[0])			 /*First choice is to turn off the engine.*/
		{
			goto OFF_Question;			 /*Jump to...*/
		}
		else if(set == choices[1])		 /*Second choice is to set the traffic light color. */
		{
			TRAFFIC :					 /* Destination jump point. */

			/* Assign the color using the reading function to the traffic_light variable. */
			traffic_light = traffic_light_reading(traffic_light);

			switch (traffic_light)
			{
			case 'G':					/* Reads Green light. */
				speed = 100;
				break;
			case 'O':					/* Reads Orange light. */
				speed = 30;
				break;
			case 'R':					/* Reads Red light. */
				speed = 0;
				break;
			default:
				printf("\n!!!! Revise your readings !!!!\n\n");
				goto TRAFFIC;		/* Rolls back to the traffic menu to read it correctly. */
			}
			goto Sensors_Menu;		/* Rolls back to the sensors menu to choose another function. */
		}

		else if(set == choices[2])	/* Third choice is to check the room temperature sensor. */
		{
			/* Assign room temperature using the sensor function to the room_temp variable. */
			room_temp = Room_Temp_Reading(room_temp);
			if (room_temp < 10)
			{
				AC = 1;			/* Turn on AC to achieve 20 degrees for the room temperature. */
				room_temp = 20;
			}
			else if (room_temp > 30)
			{
				AC = 1;			/* Turn on AC to achieve 20 degrees for the room temperature. */
				room_temp = 20;
			}
			else
			{
				AC = 0;			/* Turn off if the temperature is in the suitable range. */
			}
			goto Sensors_Menu;	/* Rolls back to the sensors menu to choose another function. */
		}
		else if(set == choices[3])	/* Fourth choice is to check the engine temperature sensor. */
		{
			/* Assign engine temperature using the sensor function to the engine_temp variable. */
			engine_temp = Engine_Temp_Reading(engine_temp);
			if(engine_temp < 100)
			{
				/* Turn on Temperature controller to achieve 125 degrees for the engine temperature. */
				Engine_Temperature_Controller = 1;
				engine_temp = 125;
			}
			else if(engine_temp > 150)
			{
				/* Turn on Temperature controller to achieve 125 degrees for the engine temperature. */
				Engine_Temperature_Controller = 1;
				engine_temp = 125;
			}
			else
			{
				Engine_Temperature_Controller = 0; /* Turn off if the temperature is in the suitable range. */
			}
		}

		/* If the input to the sensors menu is incorrect, It will roll  back to the beginning of the menu. */
		else if ((set != choices[0]) || (set != choices[1]) || (set != choices[2]) ||(set != choices[3]))
		{
			printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n");
			goto Sensors_Menu;	/* Rolls back to the sensors menu to choose another function. */
		}
		if (speed == 30)
		{
			if(AC == 0)
			{
				AC = 1;		/* If the speed is 30 km/h, then AC is turned ON */
				room_temp = (room_temp * 1.25) + 1;
			}
			if(Engine_Temperature_Controller == 0)
			{
				Engine_Temperature_Controller = 1;	 /* If the speed is 30 km/h, then the engine Temperature controller. */
				engine_temp = (engine_temp * 1.25) + 1;
			}
		}

		/* After the program gets all the readings it will show the current state of the vehicle. */

	//	Vehicle_Current_State(Engine_state, AC, speed, room_temp, engine_temp, Engine_Temperature_Controller);

		/*
		printf("\n		***** Current Vehicle State *****\n");
		switch (Engine_state){		 Engine is ON or OFF.
		case 0:
			printf("Engine state: OFF\n");
			break;
		case 1:
			printf("Engine state: ON\n");
			break;
		default:
			printf("Engine state: ERROR!!!!!!!!\n");
			break;
		}
		switch (AC){				 AC is ON or OFF.
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
		printf("Vehicle Speed is %hu Km/hr\n", speed);	 Show the current speed of the vehicle
		printf("Room Temperature is %0.2f degree\n", room_temp);	 Show the room temperature.
		switch (Engine_Temperature_Controller){		Engine temperature controller is ON or OFF.
		case 0:
			printf("Engine Temperature Controller State: OFF\n");
			break;
		case 1:
			printf("Engine Temperature Controller State: ON\n");
			break;
		default:
			printf("Engine Temperature Controller State: ERROR!!!!!!!!\n");
			break;
		}
		printf("Engine Temperature %0.2f degree\n", engine_temp);		 Show the engine temperature.

		 */

		Engine_State(Engine_state);
		AC_State(AC);
		printf("Room Temperature is %0.2f degree\n", room_temp);	/* Show the room temperature. */
		Engine_Temperature_Controller_State(Engine_Temperature_Controller);
		printf("Engine Temperature %0.2f degree\n", engine_temp);		/* Show the engine temperature. */




		Delay();	/* A small delay function that aims to wait a bit so the user can read the current state. */

		goto Sensors_Menu;	/* Rolls back to the sensors menu to choose another function. */
	}
	else if(input == choices[1]){	/* Here the user choose to turn OFF the engine. */

		OFF_Question:				/* Destination jump point. */
		/* Asking the User to confirm turning off the engine or to change the action */
		input = engine_state_question(input);

		if(input == choices[0])
		{
			/* In case the user change his mind and want to turn the engine on, the program will roll back as if he chose to turn on from the beginning. */
			goto Engine_ON;
		}
		else if(input == choices[1])
		{
			/* In case the user confirms to turn off the engine. */
			Engine_state = 0;
			speed = 0;
			AC = 0;
			Engine_Temperature_Controller = 0;
			printf("\n%s\n", state[1]);		/* Prints that the engine is now OFF. */
		}

		else if(input == choices[2])
		{
			/* In case the user change his mind and Quit, It will jump to Quit at the nearly end of the program. */
			goto Quit;
		}

	}

	else if(input == choices[2])
	{
		Quit:
		printf("%s\n\n", state[2]);		/* Prints that the program is closing. */
	}

	else if((input != 'a') || (input != 'b') || (input != 'c'))
	{
		/* If the input to the main menu of the program is incorrect, It will roll  back to the beginning of the menu. */
		printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n");
		goto Beginning;
	}


	/* Displaying the current state of the vehicle after turning on the engine and upon closing the program. */


	/*

	printf("		***** Current Vehicle State *****\n");
	switch (Engine_state){
	case 0:
		printf("Engine state: OFF\n");
		break;
	case 1:
		printf("Engine state: ON\n");
		break;
	default:
		printf("Engine state: ERROR!!!!!!!!\n");
		break;
	}
	switch (AC){
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
	printf("Vehicle Speed is %hu Km/hr\n", speed);
	printf("Room Temperature is %0.2f degree\n", room_temp);
	switch (Engine_Temperature_Controller){
	case 0:
		printf("Engine Temperature Controller State: OFF\n");
		break;
	case 1:
		printf("Engine Temperature Controller State: ON\n");
		break;
	default:
		printf("Engine Temperature Controller State: ERROR!!!!!!!!\n");
		break;
	}
	printf("Engine Temperature %0.2f degree\n\n", engine_temp);

	 */

//	Vehicle_Current_State(Engine_state, AC, speed, room_temp, engine_temp, Engine_Temperature_Controller);


	Engine_State(Engine_state);
	AC_State(AC);
	printf("Room Temperature is %0.2f degree\n", room_temp);	/* Show the room temperature. */
	Engine_Temperature_Controller_State(Engine_Temperature_Controller);
	printf("Engine Temperature %0.2f degree\n", engine_temp);		/* Show the engine temperature. */




	Delay();

	printf("Exiting the program.......");

	return 0;
}



