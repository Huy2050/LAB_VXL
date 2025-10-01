/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Admin
 */
#include "software_timer.h"
int timer4_flag = 0;
int timer3_flag = 0;
int timer2_flag = 0;
int timer1_flag = 0;
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration;
	timer3_flag = 0;
}
void setTimer4(int duration){
	timer4_counter = duration;
	timer4_flag = 0;
}
int isTimer1Expired(int timer1_flag){
	if (timer1_flag == 1){
		return 1;
	}
	return 0;
}
int isTimer2Expired(int timer2_flag){
	if (timer2_flag == 1){
		return 1;
	}
	return 0;
}
int isTimer3Expired(int timer3_flag){
	if (timer3_flag == 1){
		return 1;
	}
	return 0;
}
int isTimer4Expired(int timer4_flag){
	if (timer4_flag == 1){
		return 1;
	}
	return 0;
}
void timerRun(){
	if (timer1_counter > 0){
	    timer1_counter--;
	    if(timer1_counter == 0){
	    	timer1_flag = 1;
	    }
	}
	if (timer2_counter > 0){
	    timer2_counter--;
	    if(timer2_counter == 0){
	    	timer2_flag = 1;
	    }
	}
	if (timer3_counter > 0){
	    timer3_counter--;
	    if(timer3_counter == 0){
	    	timer3_flag = 1;
	    }
	}
	if (timer4_counter > 0){
	    timer4_counter--;
	    if(timer4_counter == 0){
	    	timer4_flag = 1;
	    }
	}
}
