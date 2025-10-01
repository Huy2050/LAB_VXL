/*
 * display7SEG.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Admin
 */
#include "display7SEG.h"
#include "main.h"
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
void display7SEG(int num){
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
int led_buffer[4];
void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			display7SEG(led_buffer[index]);
			break;
		default:
			break;
	}
}
int hour, minute, second;
void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}
uint8_t matrix_buffer[8] = {
    0x00,  // Column 0: 00000000
    0x7E,  // Column 1: 01111110
    0x09,  // Column 2: 00001001
    0x09,  // Column 3: 00001001
    0x09,  // Column 4: 00001001
    0x7E,  // Column 5: 01111110
    0x00,  // Column 6: 00000000
    0x00   // Column 7: 00000000 (
};
void initColLEDMatrix(int index){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	uint8_t display = matrix_buffer[index];
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (display & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (display & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (display & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (display & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (display & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (display & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (display & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (display & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void updateLEDMatrix(int index){
	initColLEDMatrix(index);
	switch (index){
 	 	 case 0:
 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
 			break;
 	 	 case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
			break;
 	 	 case 2:

			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			break;
 	 	 case 3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			break;
 	 	 case 4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			break;
 	 	 case 5:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
			break;
 	 	 case 6:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
			break;
 	 	 case 7:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			break;
 	 	 default:
 	 		break;
	 }
  }
