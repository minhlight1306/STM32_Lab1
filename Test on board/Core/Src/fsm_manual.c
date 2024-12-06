/*
 * fsm_manual.c
 *
 *  Created on: 28 thg 10, 2024
 *      Author: PC
 */

#include "fsm_manual.h"
#include "global.h"

void toAutomatic(){
		status = AUTO_RED_GREEN;
		clearAllLed();
		while(temp_count[0] != temp_count[1] + temp_count[2]){
			if(temp_count[1] > temp_count[0] || temp_count[2] > temp_count[0]){
				temp_count[1] = 3;
				temp_count[0] = temp_count[1] + temp_count[2];
			}
			else if(temp_count[1] > temp_count[2]){
				temp_count[1] = 3;
				temp_count[2] = temp_count[0] - temp_count[1];
			}
			else {
				temp_count[2] = temp_count[0] - temp_count[1];
			}
		}
		count[0] = temp_count[0];
		count[1] = temp_count[1];
		count[2] = temp_count[2];
		led_count[0] = count[0];
		led_count[1] = count[2];
//		setTimer(0, count[2] * 1000);
		SCH_Delete_Task(2); // turn off manual mode
		SCH_Delete_Task(3); // turn off toggle
		SCH_Add_Task(fsm_automatic_run, 2, 100, 1);
}

// gia su D3 high = red_on, D4 high = green_on, D3 va D4 high = yellow_on
int led_status = 1;
void toggleLed(){
	switch(status){
		case MODE_2:
				HAL_GPIO_WritePin(GPIOA, D7_Pin | D8_Pin, led_status);//pin A
				HAL_GPIO_WritePin(GPIOB, D3_Pin | D4_Pin | D5_Pin | D6_Pin | D10_Pin, led_status);//pin B
				HAL_GPIO_WritePin(GPIOC, D9_Pin, led_status);//pin C
				if(led_status == 1) led_status = 0;
				else led_status = 1;
			break;
		case MODE_3:
				HAL_GPIO_WritePin(GPIOB, D3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, D5_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, D7_Pin, 0);
				HAL_GPIO_WritePin(GPIOC, D9_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, D8_Pin, led_status);//pin A
				HAL_GPIO_WritePin(GPIOB, D4_Pin | D6_Pin | D10_Pin, led_status);//pin B
				if(led_status == 1) led_status = 0;
				else led_status = 1;
			break;
		case MODE_4:
				HAL_GPIO_WritePin(GPIOB, D4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, D6_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, D8_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, D10_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, D7_Pin, led_status);//pin A
				HAL_GPIO_WritePin(GPIOB, D3_Pin | D5_Pin, led_status);//pin B
				HAL_GPIO_WritePin(GPIOC, D9_Pin, led_status);//pin C
				if(led_status == 1) led_status = 0;
				else led_status = 1;
			break;
		default:
			break;
	}
}
void fsm_manual_run(){
	switch(status){
		case MODE_2:
			displayLCD(temp_count[0], -1, 2);

			if(isButtonPressed(0)){
				status = MODE_3;
				clearAllLed();
				lcd_clear_display();
				displayLCD(temp_count[1], -1, 3);
				count[0] = temp_count[0];
			}
			else if(isButtonPressed(1)){
				lcd_clear_display();
				temp_count[0]++;
				if(temp_count[0] > 99)
					temp_count[0] = 1;
				displayLCD(temp_count[0], -1, 2);
			}

			break;
		case MODE_3:
			displayLCD(temp_count[1], -1, 3);

			if(isButtonPressed(0)){
				status = MODE_4;
				clearAllLed();
				lcd_clear_display();
				displayLCD(temp_count[2], -1, 4);
				count[1] = temp_count[1];
			}
			else if(isButtonPressed(1)){
				lcd_clear_display();
				temp_count[1]++;
				if(temp_count[1] > 99)
					temp_count[1] = 1;
				displayLCD(temp_count[1], -1, 3);
			}

			break;
		case MODE_4:
			displayLCD(temp_count[2], -1, 4);

			if(isButtonPressed(0)){
				toAutomatic();//so sanh dieu kien va cap nhat gia tri
				lcd_clear_display();
			}
			else if(isButtonPressed(1)){
				lcd_clear_display();
				temp_count[2]++;
				if(temp_count[2] > 99)
					temp_count[2] = 1;
				displayLCD(temp_count[2], -1, 4);
			}

			break;
		default:
			break;
	}
}



