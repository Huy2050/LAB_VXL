/*
 * global.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */
#include "global.h"

void blink_LED(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
}
int counter[MAX_TIMER] = {[0 ... MAX_TIMER - 1] = 0};
uint8_t temp = 0;
uint8_t buffer_flag;
uint8_t command_flag; // Để fsm_uart dùng được
