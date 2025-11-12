/*
 * app_scheduler.h
 *
 *  Created on: Nov 27, 2019
 *      Author: VAIO
 */

#ifndef APP_SCHEDULER_H_
#define APP_SCHEDULER_H_

#include "main.h"
#include "global.h"
#include "software_timer.h"
#include "button.h"
#define NO_TASK_ID 0
void SCH_Update();
void SCH_Dispatch_Tasks();
uint32_t SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);
#endif /* APP_SCHEDULER_H_ */
