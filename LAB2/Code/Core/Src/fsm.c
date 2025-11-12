/*
 * fsm.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#include "fsm.h"
void fsm_run(){
	switch (mode){
		case INIT_SYSTEM:
			mode = AUTO;
			status = INIT_AUTO;
			break;
		case AUTO:
			fsm_auto_run();
			if (isButtonPressed(0)){
				mode = MANUAL;
				status = INIT_MANUAL;
			}
			if (isButtonPressed(3)){
				mode = BLINK_MODE;
				setTimer(0,50);
				resetLED();
			}
			break;
		case MANUAL:
			fsm_manual_run();
			if (isButtonPressed(0)){
				mode = CONFIG;
				status = INIT_CONFIG;
			}
			if (isButtonPressed(3)){
				mode = BLINK_MODE;
				setTimer(0,50);
				resetLED();
			}
			break;
		case CONFIG:
			fsm_config_run();
			if (isButtonPressed(3)){
				mode = BLINK_MODE;
				setTimer(0,50);
				resetLED();
			}
			break;
		case BLINK_MODE:
			if (isTimerExpired(0)){
				setTimer(0,50);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
			}
			if (isButtonPressed(2)){
				mode = INIT_SYSTEM;
			}
			break;
		default:
			break;
	}
}
