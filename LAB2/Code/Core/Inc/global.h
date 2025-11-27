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
#define MAX_BUFFER_SIZE 30
#define READING 1
#define INIT 0
#define MAX_TIMER 5
#define SCH_MAX_TASKS 10
extern int idx_led;
extern int counter[MAX_TIMER];
extern int mode;
extern int status;
extern uint8_t temp;
extern uint8_t buffer_flag;
extern uint8_t command_flag; // Để fsm_uart dùng được
extern char tx_buffer[50];
void blink_LED();
#endif /* INC_GLOBAL_H_ */
