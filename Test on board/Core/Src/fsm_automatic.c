/*
 * fsm_automatic.c
 *
 *  Created on: 28 thg 10, 2024
 *      Author: PC
 */

#include "fsm_automatic.h"
#include "global.h"

void counter(){
		led_count[0]--;
		led_count[1]--;
		lcd_clear_display();
}

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = AUTO_RED_GREEN;
			//time automatic
		case AUTO_RED_GREEN:
			traffic_automatic();
			displayLCD(led_count[0], led_count[1], 1);
			counter();
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				lcd_clear_display();
				//displayLCD(led_count[0], led_count[1], 2);
				SCH_Add_Task(fsm_manual_run, 0, 500, 2);
				SCH_Add_Task(toggleLed, 0, 500, 3);
				SCH_Delete_Task(1);
			}
			if(isButtonPressed(1)){}
			if(led_count[1] == 0){
				status = AUTO_RED_YELLOW;
				led_count[1] = count[1];
			}
			break;
		case AUTO_RED_YELLOW:
			traffic_automatic();
			displayLCD(led_count[0], led_count[1], 1);
			counter();
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				lcd_clear_display();
				//displayLCD(led_count[0], led_count[1], 2);
				SCH_Add_Task(fsm_manual_run, 0, 500, 2);
				SCH_Add_Task(toggleLed, 0, 500, 3);
				SCH_Delete_Task(1);
			}
			if(isButtonPressed(1)){}
			if(led_count[0] == 0 || led_count[1] == 0){
				status = AUTO_GREEN_RED;
				led_count[0] = count[2];
				led_count[1] = count[0];
			}
			break;
		case AUTO_GREEN_RED:
			traffic_automatic();
			displayLCD(led_count[0], led_count[1], 1);
			counter();
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				lcd_clear_display();
				//displayLCD(led_count[0], led_count[1], 2);
				SCH_Add_Task(fsm_manual_run, 0, 500, 2);
				SCH_Add_Task(toggleLed, 0, 500, 3);
				SCH_Delete_Task(1);
			}
			if(isButtonPressed(1)){}
			if(led_count[0] == 0){
				status = AUTO_YELLOW_RED;
				led_count[0] = count[1];
			}
			break;
		case AUTO_YELLOW_RED:
			traffic_automatic();
			displayLCD(led_count[0], led_count[1], 1);
			counter();
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				lcd_clear_display();
				//displayLCD(led_count[0], led_count[1], 2);
				SCH_Add_Task(fsm_manual_run, 0, 500, 2);
				SCH_Add_Task(toggleLed, 0, 500, 3);
				SCH_Delete_Task(1);
			}
			if(isButtonPressed(1)){}
			if(led_count[0] == 0 || led_count[1] == 0){
				status = AUTO_RED_GREEN;
				led_count[0] = count[0];
				led_count[1] = count[2];
			}
			break;
		default:
			break;
		  }
}



