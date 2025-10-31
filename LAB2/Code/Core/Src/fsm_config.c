/*
 * fsm_config.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */
#include "fsm_config.h"
void fsm_config_run(){
	switch (status){
		case INIT_CONFIG:
			status = RED_CONFIG;
			setTimer(2,10);
			break;
		case RED_CONFIG:
			if (isButtonPressed(1)){
				temp[0]++;
			}
			if (isButtonHold(1)){
				temp[0] += 5;
			}
			if (temp[0] > 99){
				temp[0] = 0;
			}
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBufferForConfig();
			if (isButtonHold(0)){
				status = GREEN_CONFIG;
			}
			break;
		case GREEN_CONFIG:
			if (isButtonPressed(1)){
				temp[1]++;
			}
			if (isButtonHold(1)){
				temp[1] += 5;
			}
			if (temp[1] > 99){
				temp[1] = 0;
			}
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBufferForConfig();
			if (isButtonHold(0)){
				status = YELLOW_CONFIG;
			}
			break;
		case YELLOW_CONFIG:
			if (isButtonPressed(1)){
				temp[2]++;
			}
			if (isButtonHold(1)){
				temp[2] += 5;
			}
			if (temp[2] > 99){
				temp[2] = 0;
			}
			if (isTimerExpired(2)){
				update7SEG(idx_led++);
				setTimer(2,10);
				if (idx_led > 1){
					idx_led = 0;
				}
			}
			updateBufferForConfig();
			if (isButtonPressed(2)){
				if (temp[0] != temp[1] + temp[2] && temp[0] > temp[1]){
					temp[2] = temp[0] - temp[1];
				}
				for (int i = 0; i < MAX_LED; i++){
					time[i] = temp[i];
				}
				status = INIT_AUTO;
			}
	}
}

