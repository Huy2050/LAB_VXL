/*
 * button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "button.h"
#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define MAX_BUTTON 3
int KeyReg0[MAX_BUTTON] = { [0 ... MAX_BUTTON-1] = NORMAL_STATE };
int KeyReg1[MAX_BUTTON] = { [0 ... MAX_BUTTON-1] = NORMAL_STATE };
int KeyReg2[MAX_BUTTON] = { [0 ... MAX_BUTTON-1] = NORMAL_STATE };
int KeyReg3[MAX_BUTTON] = { [0 ... MAX_BUTTON-1] = NORMAL_STATE };

int TimeOutForKeyPress[MAX_BUTTON] = {[0 ... MAX_BUTTON -1] = 500};
int button_pressed[MAX_BUTTON] = {[0 ... MAX_BUTTON -1] = 0};
int flagButton[MAX_BUTTON] = {[0 ... MAX_BUTTON -1] = 0};
int buttonHold[MAX_BUTTON] = {[0 ... MAX_BUTTON -1] = 0};
int isButtonPressed(int index){
	if(flagButton[index] == 1){
		flagButton[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonHold(int index){
	if(buttonHold[index] == 1){
		buttonHold[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	KeyReg0[0] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	KeyReg0[1] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
	KeyReg0[2] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
	// Add your key
	for (int i = 0; i < MAX_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = 500;
					//subKeyProcess();
					flagButton[i] = 1;
				}
			}else{
				TimeOutForKeyPress[i]--;
				if (KeyReg3[i] == PRESSED_STATE){
					if (TimeOutForKeyPress[i] > 0){
						TimeOutForKeyPress[i]--;
					}else{
						buttonHold[i] = 1;
						TimeOutForKeyPress[i] = 500;
					}
				}
			}
		}
	}
}

