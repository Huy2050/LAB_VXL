/*
 * trafficLight.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "trafficLight.h"
int led_buffer1[2];
int led_buffer2[2];
const uint8_t segmentMap[10] = {
    0x3F, // 0 -> abcdef
    0x06, // 1 -> bc
    0x5B, // 2 -> abdeg
    0x4F, // 3 -> abcdg
    0x66, // 4 -> bcfg
    0x6D, // 5 -> acdfg
    0x7D, // 6 -> acdefg
    0x07, // 7 -> abc
    0x7F, // 8 -> abcdefg
    0x6F  // 9 -> abcdfg
};
void display7SEGLine1(int num){
	if (num < 0 || num > 9){
		return;
	}
	uint8_t mask = segmentMap[num];
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (mask & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (mask & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (mask & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (mask & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (mask & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (mask & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (mask & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEGLine2(int num){
	if (num < 0 || num > 9){
		return;
	}
	uint8_t mask = segmentMap[num];
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, (mask & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (mask & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (mask & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (mask & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (mask & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (mask & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (mask & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
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
void resetLED(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
}
void updateBuffer(){
	int secLine1 = (counter[0] + 99) / 100;
	int secLine2 = (counter[1] + 99) / 100;
	led_buffer1[0] = secLine1 / 10;
	led_buffer1[1] = secLine1 % 10;
	led_buffer2[0] = secLine2 / 10;
	led_buffer2[1] = secLine2 % 10;
}
void updateBufferForConfig(){
	switch (status){
		case RED_CONFIG:
			led_buffer1[0] = 0;
			led_buffer1[1] = 1;
			led_buffer2[0] = temp[0] / 10;
			led_buffer2[1] = temp[0] % 10;
			break;
		case GREEN_CONFIG:
			led_buffer1[0] = 0;
			led_buffer1[1] = 2;
			led_buffer2[0] = temp[1] / 10;
			led_buffer2[1] = temp[1] % 10;
			break;
		case YELLOW_CONFIG:
			led_buffer1[0] = 0;
			led_buffer1[1] = 3;
			led_buffer2[0] = temp[2] / 10;
			led_buffer2[1] = temp[2] % 10;
			break;
		default:
			break;
	}
}
