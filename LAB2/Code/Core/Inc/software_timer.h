/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
int isTimer1Expired(int timer1_flag);
int isTimer2Expired(int timer2_flag);
int isTimer3Expired(int timer3_flag);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
