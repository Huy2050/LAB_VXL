/*
 * fsm_uart.h
 *
 *  Created on: Nov 26, 2025
 *      Author: Admin
 */

#ifndef INC_FSM_UART_H_
#define INC_FSM_UART_H_
#include "global.h"
#include "main.h"
#include "software_timer.h"
#include "command_parser_fsm.h" // Để lấy biến command_flag
#include <stdio.h>
#include <string.h> // Để dùng strlen
void uart_communication_fsm();
void Check();
#endif /* INC_FSM_UART_H_ */
