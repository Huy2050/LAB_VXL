/*
 * uart.c
 *
 *  Created on: Nov 27, 2025
 *      Author: Admin
 */
#include "uart.h"
#define ADC_IDLE    0
#define ADC_WAIT_OK 1

uint8_t status_uart = ADC_IDLE;
uint32_t ADC_value = 0;
char str_buffer[50]; // Bộ đệm lưu trữ gói tin để gửi lại

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void uart_communication_fsm() {
    switch (status_uart) {
        case ADC_IDLE:
            // Chờ người dùng gõ !RST#
            if (command_flag == 1) {
                command_flag = 0; // Xóa cờ lệnh đã xử lý

                // Đọc giá trị ADC
                ADC_value = HAL_ADC_GetValue(&hadc1);


                sprintf(tx_buffer, "!ADC=%lu#\r\n", ADC_value);

                // Gửi lần đầu
                HAL_UART_Transmit(&huart2, (uint8_t*)tx_buffer, strlen(tx_buffer), 1000);

                // Chờ 3s lệnh OK, nếu không gửi lại
                status_uart = ADC_WAIT_OK;
                setTimer(0, 3000);
            }
            break;

        case ADC_WAIT_OK:
            // Kiểm tra nếu nhận được lệnh !OK#
            if (command_flag == 2) {
                command_flag = 0;
                status_uart = ADC_IDLE; // Kết thúc giao tiếp, quay về chờ
            }
            // Kiểm tra Timeout 3 giây
            else if (isTimerExpired(0) == 1) {
            	// Gửi lại nội dung cũ
                HAL_UART_Transmit(&huart2, (uint8_t*)tx_buffer, strlen(tx_buffer), 1000);
                // Đặt lại Timer
                setTimer(0, 3000);
            }
            break;

        default:
            status_uart = ADC_IDLE;
            break;
    }
}
