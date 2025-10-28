/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "software_timer.h"
#define MAX_TIMER 5
int counter[MAX_TIMER] = {0};
int flagTimer[MAX_TIMER] = {0};
void setTimer(int index, int duration){
	counter[index] = duration;
	flagTimer[index] = 0;
}
int isTimerExpired(int index){
	if (flagTimer[index] == 1) return 1;
	return 0;
}
void timerRun(){
	for (int i = 0; i  < MAX_TIMER; i++){
		if (counter[i] > 0){
			counter[i]--;
			if (counter[i] == 0){
				flagTimer[i] = 1;
			}
		}
	}
}

