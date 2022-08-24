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
#include "Yes_Else_Question.h"


int main(void){

	u_int8 state[3][26] = {"The vehicle engine is ON","The vehicle engine is OFF","The program is closing"};
	u_int8 choices[11] = {'a','b','c','d','A','B','C','D','Y','y','\0'};
	u_int8 input = 0;			/* Input from user to use the vehicle control system. */
	u_int8 set;					/* Used for sensors menu. */
	u_int8 AC = 0;				/* Air Conditioner state. */
	u_int8 Engine_Temperature_Controller = 0;			/* ETC. */
	u_int8 traffic_light;		/* Used to determine traffic light data. */
	u_int8 Engine_state = 0;	/* Engine state. */
	u_int8 Y_N_Ans;				/* Yes or No Answer. */
	u_int16 speed = 20;				/* Vehicle Speed. */
	f_32 engine_temp = 85.00;	/* Engine Temperature .. let default be (40) */
	f_32 room_temp = 27.00;		/* Room Temperature .. let default be (27). */


	fflush( stdout );		 	/* Fix for not printing. */
	setbuf(stdout, NULL);		/* Fix for not printing. */


	while(1){

		/* Asking the User to make an action and to choose whether turning on or off the engine. */
		input = engine_state_question(input);

		if(choices[0] == input || choices[4] == input)				 /* Here the user choose to turn ON the engine. */
		{
			while(1)
			{
				Engine_state = ON;			 /* Engine is now ON. */
				printf("%s\n", state[0]);		 /* Prints that the engine is now ON. */

				set = Sensors_set_menu(set);	 /* Sensors menu function. */

				if(choices[0] == set || choices[4] == set)			 /*First choice is to turn off the engine.*/
				{
					break;		/* Breaks out from the On Engine loop. */
				}
				else if(choices[1] == set || choices[5] == set)		 /*Second choice is to set the traffic light color. */
				{

					/* Assign the color using the reading function to the traffic_light variable. */
					traffic_light = traffic_light_reading(traffic_light);

					/* Assign the speed according to the traffic light color. */
					speed = Traffic_Light_Decision(traffic_light);

				}

				else if(choices[2] == set || choices[6] == set)		/* Third choice is to check the room temperature sensor. */
				{

					/* Assign room temperature using the sensor function to the room_temp variable. */
					room_temp = Room_Temp_Reading(room_temp);

					/* Function used to turn on AC upon need to change the temperature of the room. */
					Room_temp_controller(&room_temp, &AC);

				}

				else if(choices[3] == set || choices[7] == set)		/* Fourth choice is to check the engine temperature sensor. */
				{
					/* Assign engine temperature using the sensor function to the engine_temp variable. */
					engine_temp = Engine_Temp_Reading(engine_temp);

					/* Function used to turn on ETC upon need to change the temperature of the engine. */
					Engine_Control_Unit(&engine_temp, &Engine_Temperature_Controller);
				}

				/* The function below is only used when speed is 3o and no AC or ETC. */
				Specific_Conditions(&speed, &AC, &room_temp, &engine_temp, &Engine_Temperature_Controller, &Engine_state);

				/* After the program gets override the old readings due to the 30 Km condition, It will show the current state of the vehicle. */
				Vehicle_Current_State(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

				/* If the input to the sensors menu is incorrect, It will roll  back to the beginning of the menu. */
				while (choices[0] != set && choices[1] != set && choices[2] != set && choices[3] != set && choices[4] != set && choices[5] != set && choices[6] != set && choices[7] != set)

				{
					printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n\n");

					break;	/* Exits current loop. (incorrect choices) */
				}
			}
		}
		else if(choices[1] == input || choices[5] == input)			/* Here the user choose to turn OFF the engine. */
		{

			Engine_state = OFF;
			speed = STOP;
			AC = OFF;
			Engine_Temperature_Controller = OFF;

			printf("%s\n\n", state[1]);		/* Prints that the engine is now OFF. */

			/* Displaying the current state of the vehicle after turning OFF the engine. */
			Vehicle_Current_State_Turn_OFF(&Engine_state, &AC, &speed, &room_temp, &engine_temp, &Engine_Temperature_Controller);

			continue;			/* Returns to beginning of the main loop to engine menu question. */

		}

		else if(choices[2] == input || choices[6] == input)			/* Here the user choose to quit the program. */
		{

			Y_N_Ans = Yes_Else_Question(Y_N_Ans);		/* A function that is meant to take Y for yes or any character to return back to Engine menu question. */
			if(choices[8] == Y_N_Ans || choices[9] == Y_N_Ans)
			{
				printf("%s\n\n", state[2]);		/* Prints that the program is closing. */
				break;							/* Exits main loop. */
			}
			else
			{
				continue;						/* Returns to beginning of the main loop to engine menu question. */
			}
		}

		/* If the input to the main menu of the program is incorrect, It will roll  back to the beginning of the menu. */
		while(choices[0] != input && choices[1] != input && choices[2] != input && choices[3] != input && choices[4] != input && choices[5] != input && choices[6] != input)
		{

			printf("INVALID INPUT!!! Please enter the letters beside the choice you want.\n\n");
			input = engine_state_question(input);
		}
		continue;		/* Returns to beginning of the main loop to engine menu question. */
	}

	printf("\nExiting the program.......");
	return 0;
}



