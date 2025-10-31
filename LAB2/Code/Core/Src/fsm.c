/*
 * fsm.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#include "fsm.h"
void fsm_run(){
	switch (status){
		case INIT_SYSTEM:
			status = INIT_AUTO;
			break;
		case INIT_AUTO:
			fsm_auto_run();
			if (isButtonPressed(0)){
				status = INIT_MANUAL;
			}
			if (isButtonPressed(3)){
				status = BLINK_MODE;
				setTimer(0,50);
			}
			break;
		case INIT_MANUAL:
			fsm_manual_run();
			if (isButtonPressed(0)){
				status = INIT_CONFIG;
			}
			if (isButtonPressed(3)){
				status = BLINK_MODE;
				setTimer(0,50);
			}
			break;
		case INIT_CONFIG:
			fsm_config_run();
			if (isButtonPressed(3)){
				status = BLINK_MODE;
				setTimer(0,50);
			}
			break;
		case BLINK_MODE:
			if (isTimerExpired(0)){
				setTimer(0,50);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
			}
			if (isButtonPressed(2)){
				status = INIT_SYSTEM;
			}
			break;
		default:
			break;
	}
}
