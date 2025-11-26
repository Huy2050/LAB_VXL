/*
 * fsm_uart.c
 *
 *  Created on: Nov 26, 2025
 *      Author: Admin
 */
// Định nghĩa trạng thái
#include "fsm_uart.h"
#define ADC_IDLE    0
#define ADC_WAIT_OK 1

uint8_t status_uart = ADC_IDLE;
uint32_t ADC_value = 0;
char str_buffer[50];

// Extern các handle từ main.c để sử dụng được
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void uart_communication_fsm() {
    switch (status_uart) {
        case ADC_IDLE:
            if (command_flag == 1) { // RST
                command_flag = 0;
                // Đọc ADC
                ADC_value = HAL_ADC_GetValue(&hadc1);
                // Gửi dữ liệu
                sprintf(str_buffer, "!ADC=%lu#\r\n", ADC_value);
                HAL_UART_Transmit(&huart2, (uint8_t*)str_buffer, strlen(str_buffer), 1000);

                status_uart = ADC_WAIT_OK;
                setTimer(0, 3000); // Set timer 0, 3000ms (Hàm setTimer của bạn chia cho 10 bên trong)
            }
            else if (command_flag == 2) { // OK
            	command_flag = 0; // Xóa cờ thừa nếu có
            }
            break;

        case ADC_WAIT_OK:
            if (command_flag == 2) { // Nhận được OK
                command_flag = 0;
                status_uart = ADC_IDLE;
            }
            else if (isTimerExpired(0) == 1) { // Kiểm tra Timer 0
                // Timeout -> Gửi lại
                HAL_UART_Transmit(&huart2, (uint8_t*)str_buffer, strlen(str_buffer), 1000);
                setTimer(0, 3000); // Reset timer
            }
            break;

        default:
            status_uart = ADC_IDLE;
            break;
    }
}
void Check(){
	if(buffer_flag == 1){
	 command_parser_fsm();
	 buffer_flag = 0;
	 }
}
