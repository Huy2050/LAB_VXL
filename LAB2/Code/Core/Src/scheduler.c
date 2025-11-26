/*
 * app_scheduler.c
 *
 *  Created on: Nov 27, 2019
 *      Author: VAIO
 */
#include "scheduler.h"
typedef struct{
	void(* pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint32_t taskID;
	uint8_t runMe;
}Task;

static Task SCH_task[SCH_MAX_TASKS];
static uint32_t newTaskID = 0;
static uint32_t count_SCH_Update = 0;

static uint32_t Get_New_Task_ID(void);

void SCH_Update(void){
	count_SCH_Update++;
	if (SCH_task[0].pTask && SCH_task[0].runMe == 0){
		if (SCH_task[0].Delay > 0){
			SCH_task[0].Delay--;
		}
		if (SCH_task[0].Delay == 0){
			SCH_task[0].runMe = 1;
		}
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period) {
    uint8_t index = 0;

    // Tìm vị trí chèn dựa trên delay còn lại
    while ((index < SCH_MAX_TASKS) && (SCH_task[index].pTask != 0)) {
        if (delay < SCH_task[index].Delay) {
            // Vị trí chèn được tìm thấy
            break;
        } else {
            delay -= SCH_task[index].Delay;
            index++;
        }
    }

    // Nếu danh sách đầy, báo lỗi
    if (index >= SCH_MAX_TASKS) return SCH_MAX_TASKS;

    // Dịch các task sau để chèn task mới
    for (uint8_t i = SCH_MAX_TASKS - 1; i > index; i--) {
        SCH_task[i] = SCH_task[i - 1];
    }

    // Cập nhật delay của task sau (nếu có)
    if (SCH_task[index].pTask != 0) {
        SCH_task[index + 1].Delay -= delay;
    }

    // Gán thông tin task mới
    SCH_task[index].pTask = pFunction;
    SCH_task[index].Delay = delay;
    SCH_task[index].Period = period;
    SCH_task[index].runMe = (delay == 0) ? 1 : 0;
    SCH_task[index].taskID = Get_New_Task_ID();

    return SCH_task[index].taskID;
}

uint8_t SCH_Delete_Task(uint32_t taskID){
	uint8_t Return_code  = 0;
	uint8_t taskIndex = 0;
	uint8_t j;
	if (taskID == NO_TASK_ID){
		return Return_code;
	}
	while ((taskIndex < SCH_MAX_TASKS) && (SCH_task[taskIndex].taskID != taskID)){
		taskIndex++;
	}
	if (taskIndex >= SCH_MAX_TASKS || SCH_task[taskIndex].pTask == 0) {
		return Return_code; // Không tồn tại
	}
	Return_code = 1;
	if ((SCH_task[taskIndex + 1].pTask != 0x0000) && (taskIndex < SCH_MAX_TASKS - 1)){
		SCH_task[taskIndex + 1].Delay += SCH_task[taskIndex].Delay;
	}
	for(j = taskIndex; j < SCH_MAX_TASKS - 1; j ++){
		SCH_task[j] = SCH_task[j + 1];
	}
	SCH_task[j].pTask = 0;
	SCH_task[j].Period = 0;
	SCH_task[j].Delay = 0;
	SCH_task[j].runMe = 0;
	SCH_task[j].taskID = 0;
	return Return_code;
}


void SCH_Dispatch_Tasks(void){
	if(SCH_task[0].runMe > 0) {
		(*SCH_task[0].pTask)(); // Run the task
		SCH_task[0].runMe = 0; // Reset / reduce RunMe flag
		Task temtask = SCH_task[0];
		SCH_Delete_Task(temtask.taskID);
		if (temtask.Period != 0) {
			SCH_Add_Task(temtask.pTask, temtask.Period, temtask.Period);
		}
	}
}
static uint32_t Get_New_Task_ID(void){
	newTaskID++;
	if(newTaskID == NO_TASK_ID){
		newTaskID++;
	}
	return newTaskID;
}
