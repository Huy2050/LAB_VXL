/*
 * global.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */
#include "global.h"

int time[MAX_LED] = {10,7,3};
int counter[MAX_TIMER] = {[0 ... MAX_TIMER - 1] = 0};
int mode = INIT_SYSTEM;
int status;
int temp[MAX_LED] = {[0 ... MAX_LED - 1] = 0};
int idx_led = 0;
