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

