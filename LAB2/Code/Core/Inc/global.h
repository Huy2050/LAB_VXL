/*
 * global.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#define INIT_SYSTEM 0
#define INIT_AUTO 1
#define INIT_MANUAL 2
#define INIT_CONFIG 3
#define RED_GREEN_AUTO 4
#define RED_AMBER_AUTO 5
#define GREEN_RED_AUTO 6
#define AMBER_RED_AUTO 7
#define RED_GREEN_MAN 8
#define RED_AMBER_MAN 9
#define GREEN_RED_MAN 10
#define AMBER_RED_MAN 11
#define RED_CONFIG 12
#define GREEN_CONFIG 13
#define YELLOW_CONFIG 14
#define BLINK_MODE 15
#define MAX_BUTTON 4
#define MAX_TIMER 5
#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define MAX_LED 3
extern int idx_led;
extern int time[MAX_LED];
extern int counter[MAX_TIMER];
extern int status;
extern int temp[MAX_LED];
#endif /* INC_GLOBAL_H_ */
