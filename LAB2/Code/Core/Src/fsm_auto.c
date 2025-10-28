/*
 * fsm_auto.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "fsm_auto.h"
#define INIT 0
#define RED_GREEN 1
#define RED_AMBER 2
#define GREEN_RED 3
#define AMBER_RED 4
int status = 0;
int secPerLine[2] = {0,0};
int oldSec[2] = {0,0};
void fsm_auto_run(){
	switch (status){
		case INIT:
			setTimer(0,500);
			setTimer(1,300);
			status = RED_GREEN;
			break;
		case RED_GREEN:
			secPerLine[0] = (counter[0] - 1) / 100 + 1;
			secPerLine[1] = (counter[1] - 1) / 100 + 1;
			if (secPerLine[0] != oldSec[0] || secPerLine[1] != oldSec[1]) {
				display7SEGLine1A(secPerLine[0] % 10);
				display7SEGLine1B(secPerLine[0] / 10);
				display7SEGLine2A(secPerLine[1] % 10);
				display7SEGLine2B(secPerLine[1] / 10);
			}
			oldSec[0] = secPerLine[0];
			oldSec[1] = secPerLine[1];
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			if (isTimerExpired(1) == 1){
				status = RED_AMBER;
				setTimer(1,200);
				setTimer(0,200);
			}
			break;
		case RED_AMBER:
			secPerLine[0] = (counter[0] - 1) / 100 + 1;
			secPerLine[1] = (counter[1] - 1) / 100 + 1;
			if (secPerLine[0] != oldSec[0] || secPerLine[1] != oldSec[1]) {
				display7SEGLine1A(secPerLine[0] % 10);
				display7SEGLine1B(secPerLine[0] / 10);
				display7SEGLine2A(secPerLine[1] % 10);
				display7SEGLine2B(secPerLine[1] / 10);
			}
			oldSec[0] = secPerLine[0];
			oldSec[1] = secPerLine[1];
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0) == 1){
				status = GREEN_RED;
				setTimer(1,500);
				setTimer(0,300);
			}
			break;
		case GREEN_RED:
			secPerLine[0] = (counter[0] - 1) / 100 + 1;
			secPerLine[1] = (counter[1] - 1) / 100 + 1;
			if (secPerLine[0] != oldSec[0] || secPerLine[1] != oldSec[1]) {
				display7SEGLine1A(secPerLine[0] % 10);
				display7SEGLine1B(secPerLine[0] / 10);
				display7SEGLine2A(secPerLine[1] % 10);
				display7SEGLine2B(secPerLine[1] / 10);
			}
			oldSec[0] = secPerLine[0];
			oldSec[1] = secPerLine[1];
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(0) == 1){
				status = AMBER_RED;
				setTimer(0,200);
				setTimer(1,200);
			}
			break;
		case AMBER_RED:
			secPerLine[0] = (counter[0] - 1) / 100 + 1;
			secPerLine[1] = (counter[1] - 1) / 100 + 1;
			if (secPerLine[0] != oldSec[0] || secPerLine[1] != oldSec[1]) {
				display7SEGLine1A(secPerLine[0] % 10);
				display7SEGLine1B(secPerLine[0] / 10);
				display7SEGLine2A(secPerLine[1] % 10);
				display7SEGLine2B(secPerLine[1] / 10);
			}
			oldSec[0] = secPerLine[0];
			oldSec[1] = secPerLine[1];
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			if (isTimerExpired(1) == 1){
				status = RED_GREEN;
				setTimer(0,500);
				setTimer(1,300);
			}
			break;
		default:
			break;
	}
}

