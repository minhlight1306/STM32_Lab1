/*
 * fsm_automatic.c
 *
 *  Created on: 28 thg 10, 2024
 *      Author: PC
 */

#include "fsm_automatic.h"
#include "global.h"

void counter(){
	if(isTimerExpired(2)){
		led_count[0]--;
		led_count[1]--;
		setTimer(2, 1000);
		lcd_clear_display();
	}
}
void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = AUTO_RED_GREEN;
			setTimer(0, 3000);//time automatic
			break;
		case AUTO_RED_GREEN:
			traffic_automatic();
			displayLCD(led_count[0], led_count[1], 1);
			counter();
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				lcd_clear_display();
				//displayLCD(led_count[0], led_count[1], 2);
				setTimer(1, 500);
				setTimer(2, 500);
			}
			if(isButtonPressed(1)){}
			if(isTimerExpired(0)){
				status = AUTO_RED_YELLOW;
				led_count[1] = count[1];
				setTimer(0, count[1] * 1000);
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
				setTimer(1, 500);
				setTimer(2, 500);
			}
			if(isButtonPressed(1)){}
			if(isTimerExpired(0)){
				status = AUTO_GREEN_RED;
				led_count[0] = count[2];
				led_count[1] = count[0];
				setTimer(0, count[2] * 1000);
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
				setTimer(1, 500);
				setTimer(2, 500);
			}
			if(isButtonPressed(1)){}
			if(isTimerExpired(0)){
				status = AUTO_YELLOW_RED;
				led_count[0] = count[1];
				setTimer(0, count[1] * 1000);
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
				setTimer(1, 500);
				setTimer(2, 500);
			}
			if(isButtonPressed(1)){}
			if(isTimerExpired(0)){
				status = AUTO_RED_GREEN;
				led_count[0] = count[0];
				led_count[1] = count[2];
				setTimer(0, count[2] * 1000);
			}
			break;
		default:
			break;
		  }
}



