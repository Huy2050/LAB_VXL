/*
 * trafficLight.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "trafficLight.h"
int led_buffer1[2];
int led_buffer2[2];
void display7SEGLine1(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (num >> 3) & 0x01);
}

void display7SEGLine2(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, (num >> 3) & 0x01);
}
void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
			display7SEGLine1(led_buffer1[index]);
			display7SEGLine2(led_buffer2[index]);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
			display7SEGLine1(led_buffer1[index]);
			display7SEGLine2(led_buffer2[index]);
			break;
		default:
			break;
	}
}
void updateBuffer(){
	int secLine1 = (counter[0] + 99) / 100;
	int secLine2 = (counter[1] + 99) / 100;
	led_buffer1[0] = secLine1 / 10;
	led_buffer1[1] = secLine1 % 10;
	led_buffer2[0] = secLine2 / 10;
	led_buffer2[1] = secLine2 % 10;
}
