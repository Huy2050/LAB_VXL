/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 26, 2025
 *      Author: Admin
 */
#include "command_parser_fsm.h"
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t idx_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t status_parser = INIT; // Trạng thái hiện tại
uint8_t command_data[30];     // Lưu nội dung lệnh (ví dụ: RST, OK)
uint8_t command_index = 0;

uint8_t command_flag = 0;     // 1: RST, 2: OK (Ví dụ)

void command_parser_fsm() {
    // Duyệt qua dữ liệu mới nhận (được lưu trong buffer hoặc temp từ ngắt)
    // Giả sử biến 'temp' là dữ liệu mới nhất đọc được từ bộ đệm

    switch (status_parser) {
        case INIT:
            if (temp == '!') {
                status_parser = READING;
                command_index = 0;
                // Xóa bộ đệm lệnh cũ nếu cần
                memset(command_data, 0, 30);
            }
            break;

        case READING:
            if (temp == '#') {
                // Kết thúc lệnh, bắt đầu kiểm tra nội dung
                status_parser = INIT;

                // Kiểm tra xem lệnh là gì
                if (strcmp((char*)command_data, "RST") == 0) {
                    command_flag = 1; // Báo hiệu đã nhận lệnh RST
                }
                else if (strcmp((char*)command_data, "OK") == 0) {
                    command_flag = 2; // Báo hiệu đã nhận lệnh OK
                }
            }
            else if (temp == '!') {
                // Trường hợp lỗi: gặp dấu ! mới khi chưa kết thúc lệnh cũ
                // Reset lại để bắt đầu lệnh mới này
                command_index = 0;
                memset(command_data, 0, 30);
            }
            else {
                // Đang đọc nội dung lệnh, lưu vào mảng
                command_data[command_index++] = temp;
                if (command_index >= 30) command_index = 0; // Chống tràn
            }
            break;

        default:
            status_parser = INIT;
            break;
    }
}



