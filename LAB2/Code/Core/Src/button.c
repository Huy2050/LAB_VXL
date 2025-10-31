/*
 * button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "button.h"
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
	for (int i = 0; i < MAX_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}
    // Đọc giá trị nút thực tế
    KeyReg0[0] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
    KeyReg0[1] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
    KeyReg0[2] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
    KeyReg0[3] = HAL_GPIO_ReadPin(button4_GPIO_Port, button4_Pin);
    // Lọc chống dội và phát hiện sự kiện
    for(int i = 0; i < MAX_BUTTON; i++){
        if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
            // Khi trạng thái ổn định
            if(KeyReg3[i] != KeyReg2[i]){
                // Có thay đổi trạng thái
                KeyReg3[i] = KeyReg2[i];

                if(KeyReg3[i] == PRESSED_STATE){
                    // Vừa được nhấn
                    flagButton[i] = 1;             // set cờ nhấn
                    TimeOutForKeyPress[i] = 500;   // reset bộ đếm giữ
                } else {
                    // Vừa được thả
                    TimeOutForKeyPress[i] = 500;
                    buttonHold[i] = 0;             // clear cờ giữ
                }
            } else {
                // Không đổi trạng thái → kiểm tra xem có giữ lâu không
                if(KeyReg3[i] == PRESSED_STATE){
                    if(TimeOutForKeyPress[i] > 0){
                        TimeOutForKeyPress[i]--;
                    } else {
                        // Giữ đủ lâu
                        buttonHold[i] = 1;         // set cờ giữ
                        TimeOutForKeyPress[i] = 500;
                    }
                }
            }
        }
    }
}


