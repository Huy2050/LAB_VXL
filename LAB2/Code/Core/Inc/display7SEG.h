/*
 * display7SEG.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Admin
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_
extern int hour, minute, second;
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
#endif /* INC_DISPLAY7SEG_H_ */
