/*
 * software_timer.h
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int flagTimer[5];
extern int counter[5];
void setTimer(int index, int duration);
int isTimerExpired(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
