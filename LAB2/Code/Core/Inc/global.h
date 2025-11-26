/*
 * global.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#define INIT 0
#define MAX_TIMER 5
#define SCH_MAX_TASKS 10
extern int idx_led;
extern int counter[MAX_TIMER];
extern int mode;
extern int status;
extern int temp[MAX_LED];
void blink_LED();
#endif /* INC_GLOBAL_H_ */
