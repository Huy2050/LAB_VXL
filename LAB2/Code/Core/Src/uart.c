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

                // 1. Đọc giá trị ADC (Chỉ đọc 1 lần tại đây)
                ADC_value = HAL_ADC_GetValue(&hadc1);

                // 2. Đóng gói dữ liệu vào buffer (Lưu lại để dùng cho việc gửi lại sau này)
                sprintf(tx_buffer, "!ADC=%lu#\r\n", ADC_value);

                // 3. Gửi lần đầu tiên
                HAL_UART_Transmit(&huart2, (uint8_t*)tx_buffer, strlen(tx_buffer), 1000);

                // 4. Chuyển trạng thái và đặt Timer chờ 3 giây
                status_uart = ADC_WAIT_OK;

                // setTimer(0, 300) -> 300 * 10ms = 3000ms = 3s
                // (Giả sử timer interrupt của bạn là 10ms)
                setTimer(0, 300);
            }
            // Nếu nhận !OK# khi đang rảnh thì không làm gì (hoặc xóa cờ)
            else if (command_flag == 2) {
                command_flag = 0;
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
                // Yêu cầu: "The value is kept as the previous packet"
                // -> KHÔNG đọc lại ADC ở đây.
                // -> Chỉ gửi lại nội dung cũ trong str_buffer.

                HAL_UART_Transmit(&huart2, (uint8_t*)tx_buffer, strlen(tx_buffer), 1000);

                // Đặt lại Timer để tiếp tục chờ thêm 3s nữa
                setTimer(0, 300);
            }
            break;

        default:
            status_uart = ADC_IDLE;
            break;
    }
}
