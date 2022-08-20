/*
 * 	Name      :	main_project.c
 *	Project	  : Vehicle Control system
 *  Created on: Aug 19, 2022
 *  Author	  :	Ahmed Kaead
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "engine_state_question.h"
#include "Sensors_set_menu.h"
#include "traffic_light_reading.h"
#include "Traffic_Decision.h"
#include "room_temp_reading.h"
#include "Engine_Temp_Reading.h"
#include "Delay.h"
#include "Bool_state.h"
#include "Room_temp_controller.h"
#include "Engine_Control_Unit.h"
#include "Specific_Conditions.h"
#include "Vehicle_State.h"
#include "Vehicle_State_Turn_OFF.h"

int main(void){

	u_int8 state[3][30] = {"the vehicle engine is now ON","the vehicle engine is now OFF","the program is closing"};
	u_int8 choices[5] = {'a','b','c','d','\0'};
	u_int8 input = 0;			/* Input from user to use the vehicle control system. */
	u_int8 set;					/* Used for sensors menu. */
	u_int8 AC = 0;				/* Air Conditioner state. */
	u_int8 Engine_Temperature_Controller = 0;			/* ETC. */
	u_int8 traffic_light;		/* Used to determine traffic light data. */
	u_int8 Engine_state = 0;	/* Engine state. */
	u_int16 speed = 20;				/* Vehicle Speed. */
	f_32 engine_temp = 55.00;	/* Engine Temperature .. let default be (40) */
	f_32 room_temp = 27.00;		/* Room Temperature .. let default be (27). */


	fflush( stdout );		 	/* Fix for not printing. */
	setbuf(stdout, NULL);		/* Fix for not printing. */


	Beginning:					/* Destination jump point.*/

	/* Asking the User to make an action and to choose whether turning on or off the engine. */
	input = engine_state_question(input);


	if(input == choices[0] )				 /* Here the user choose to turn ON the engine. */
	{
		Engine_ON:						 /* Destination jump point.*/
		Engine_state = ON;			 /* Engine is now ON. */
		printf("%s\n", state[0]);		 /* Prints that the engine is now ON. */

		Sensors_Menu:					 /* Destination jump point. */
		set = Sensors_set_menu(set);	 /* Sensors menu function. */

		if(set == choices[0])			 /*First choice is to turn off the engine.*/
		{
			goto OFF_Question;			 /*Jump to...*/
		}
		else if(set == choices[1])		 /*Second choice is to set the traffic light color. */
		{

			/* Assign the color using the reading function to the traffic_light variable. */
			traffic_light = traffic_light_reading(traffic_light);

			/* Assign the speed according to the traffic light color. */
			speed = Traffic_Light_Decision(traffic_light);

			/* Check speed to jump to The specific conditions function*/
			if(speed == 30)
			{
				goto Speed_30Km_Condition;
			}

			/* After the program gets the readings it will show the current state of the vehicle. */
			Vehicle_Current_State(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

			goto Sensors_Menu;		/* Rolls back to the sensors menu to choose another function. */
		}

		else if(set == choices[2])	/* Third choice is to check the room temperature sensor. */
		{

			/* Assign room temperature using the sensor function to the room_temp variable. */
			room_temp = Room_Temp_Reading(room_temp);

			/* Function used to turn on AC upon need to change the temperature of the room. */
			Room_temp_controller(&room_temp, &AC);

			/* Check speed to jump to The specific conditions function*/
			if(speed == 30)
			{
				goto Speed_30Km_Condition;
			}

			/* After the program gets the readings it will show the current state of the vehicle. */
			Vehicle_Current_State(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

			goto Sensors_Menu;	/* Rolls back to the sensors menu to choose another function. */
		}
		else if(set == choices[3])	/* Fourth choice is to check the engine temperature sensor. */
		{
			/* Assign engine temperature using the sensor function to the engine_temp variable. */
			engine_temp = Engine_Temp_Reading(engine_temp);

			/* Function used to turn on ETC upon need to change the temperature of the engine. */
			Engine_Control_Unit(&engine_temp, &Engine_Temperature_Controller);

			/* Check speed to jump to The specific conditions function*/
			if(speed == 30)
			{
				goto Speed_30Km_Condition;
			}

			/* After the program gets the readings, It will show the current state of the vehicle. */
			Vehicle_Current_State(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

		}

		/* If the input to the sensors menu is incorrect, It will roll  back to the beginning of the menu. */
		else if ((set != choices[0]) || (set != choices[1]) || (set != choices[2]) ||(set != choices[3]))

		{
			printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n");
			goto Sensors_Menu;	/* Rolls back to the sensors menu to choose another function. */
		}

		Speed_30Km_Condition:

		/* The function below is only used when speed is 3o and no AC or ETC. */
		Specific_Conditions(&speed, &AC, &room_temp, &engine_temp, &Engine_Temperature_Controller, &Engine_state);
		/* After the program gets override the old readings due to the 30 Km condition, It will show the current state of the vehicle. */
		Vehicle_Current_State(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);


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
			Engine_state = OFF;
			speed = STOP;
			AC = OFF;
			Engine_Temperature_Controller = OFF;
			printf("\n%s\n", state[1]);		/* Prints that the engine is now OFF. */

			/* Displaying the current state of the vehicle after turning OFF the engine. */
			Vehicle_Current_State_Turn_OFF(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

			goto Beginning;
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
		goto Exit;
	}

	else if((input != 'a') || (input != 'b') || (input != 'c'))
	{
		/* If the input to the main menu of the program is incorrect, It will roll  back to the beginning of the menu. */
		printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n");
		goto Beginning;
	}

	Exit:
	printf("\nExiting the program.......");

	return 0;
}



