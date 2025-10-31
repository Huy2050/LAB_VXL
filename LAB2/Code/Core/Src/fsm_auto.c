/*
 * fsm_auto.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "fsm_auto.h"
//status = INIT_AUTO;
void fsm_auto_run(){
	switch (status){
		case INIT_AUTO:
			setTimer(0,time[0] * 100);
			setTimer(1,time[1] * 100);
			setTimer(2,10);
			status = RED_GREEN_AUTO;
			break;
		case RED_GREEN_AUTO:
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBuffer();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			if (isTimerExpired(1) == 1){
				status = RED_AMBER_AUTO;
				setTimer(1,time[2] * 100);
			}
			break;
		case RED_AMBER_AUTO:
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBuffer();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0) == 1){
				status = GREEN_RED_AUTO;
				setTimer(1,time[0] * 100);
				setTimer(0,time[1] * 100);
			}
			break;
		case GREEN_RED_AUTO:
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBuffer();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0) == 1){
				status = AMBER_RED_AUTO;
				setTimer(0,time[2] * 100);
			}
			break;
		case AMBER_RED_AUTO:
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBuffer();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(1) == 1){
				status = RED_GREEN_AUTO;
				setTimer(0,time[0] * 100);
				setTimer(1,time[1] * 100);
			}
			break;
		default:
			break;
	}
}

