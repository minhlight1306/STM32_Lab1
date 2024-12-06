/*
 * led_traffic.c
 *
 *  Created on: 28 thg 10, 2024
 *      Author: PC
 */

#include "led_traffic.h"


void clearAllLed(){
	HAL_GPIO_WritePin(GPIOA, D7_Pin | D8_Pin, 1);//pin A
	HAL_GPIO_WritePin(GPIOB, D3_Pin | D4_Pin | D5_Pin | D6_Pin | D10_Pin, 0);//pin B
	HAL_GPIO_WritePin(GPIOC, D9_Pin, 0);//pin C
	HAL_Delay(10);
}

//automatic
//red on top and bottom is 1
//red on left and right is 2
// gia su D3 high = green_on, D4 high = yellow_on, D3 va D4 high = red_on
void red_on(int index){
	switch (index){
	case 1:
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 1);

		break;
	case 2:
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 1);// pin A
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, 1);//pin A
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, 1);//pin C
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, 1);

		break;
	default:
		break;
	}
}
//
void green_on(int index){
	switch (index){
	case 1:
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
		break;
	case 2:
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 1);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, 0);
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, 1);
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, 0);
		break;
	default:
		break;
	}
}
//
void yellow_on(int index){
	switch (index){
	case 1:
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 0);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 0);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, 1);
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, 0);
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, 1);
		break;
	default:
		break;
	}
}
void traffic_automatic(){
	switch(status){
	case AUTO_RED_GREEN://led_red is horizontal, led_green is vertical
		red_on(1);
		green_on(2);
		break;
	case AUTO_RED_YELLOW:
		red_on(1);
		yellow_on(2);

		break;
	case AUTO_GREEN_RED:
		green_on(1);
		red_on(2);

		break;
	case AUTO_YELLOW_RED:
		yellow_on(1);
		red_on(2);

		break;
	default:
		break;
	}
}

