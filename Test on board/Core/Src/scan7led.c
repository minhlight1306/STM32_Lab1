/*
 * scan7led.c
 *
 *  Created on: Oct 28, 2024
 *      Author: PC
 */
#include "scan7led.h"
#include "global.h"

char str1[20], str2[20], str3[20];

// thuc hien in ra lcd thoi gian dem nguoc
void displayLCD(int time1, int time2, int mode){
		lcd_goto_XY(1, 0);
		sprintf(str1, "Time1: %d", time1);
		lcd_send_string(str1);
	if(time2 != -1){
		lcd_goto_XY(2, 0);
		sprintf(str2, "Time2: %d", time2);
		lcd_send_string(str2);
	}
//	else if(time2 == -1){
//		lcd_goto_XY(2, 0);
//		lcd_send_string("-SETTING-");
//	}
		lcd_goto_XY(1, 10);
		sprintf(str3, "Mode:%d", mode);
		lcd_send_string(str3);
}
