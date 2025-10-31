/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2025
 *      Author: Admin
 */


#include "fsm_manual.h"
void fsm_manual_run(){
	switch (status){
		case INIT_MANUAL:
			status = RED_GREEN_MAN;
		case RED_GREEN_MAN:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			if (isButtonPressed(1)){
				status = RED_AMBER_MAN;
				setTimer(0, 200);
			}
//			if (isButtonPressed(2)){
//				status = ERROR;
//				setTimer(0,50);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
//			}
			break;
		case RED_AMBER_MAN:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0)){
				status = GREEN_RED_MAN;
			}
			break;
		case GREEN_RED_MAN:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isButtonPressed(1)){
				status = AMBER_RED_MAN;
				setTimer(0, 200);
			}
//			if (isButtonPressed(2)){
//				state = ERROR;
//				setTimer(0, 50);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
//			}
			break;
		case AMBER_RED_MAN:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0)){
				status = RED_GREEN_MAN;
				setTimer(0,200);
			}
			break;
//		case ERROR:
//			if (isTimerExpired(0)){
//				setTimer(0,50);
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
//			}
//			if (isButtonPressed(2)){
//				state = INIT;
//			}
		default:
			break;
	}
}
