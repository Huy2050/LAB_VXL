/*
 * command_parser.c
 *
 *  Created on: Nov 27, 2025
 *      Author: Admin
 */
#include "command_parser.h"
uint8_t status_parser = INIT; // Trạng thái hiện tại
uint8_t command_data[30];     // Lưu nội dung lệnh
uint8_t command_index = 0;


void command_parser_fsm() {
    switch (status_parser) {
        case INIT:
            if (temp == '!') {
                status_parser = READING;
                command_index = 0;
                memset(command_data, 0, 30);
            }
            break;

        case READING:
            if (temp == '#') {
                status_parser = INIT;

                //thêm kết thúc lệnh
                command_data[command_index] = '\0';

                if (strcmp((char*)command_data, "RST") == 0) {
                    command_flag = 1;
                }
                else if (strcmp((char*)command_data, "OK") == 0) {
                    command_flag = 2;
                }
            }
            else if (temp == '!') {
                command_index = 0;
                memset(command_data, 0, 30);
            }
            else {
                // Nếu còn trống thì thêm
                if (command_index < 29) {
                    command_data[command_index++] = temp;
                }
            }
            break;
        default:
            status_parser = INIT;
            break;
    }
}
void Check(){
	if(buffer_flag == 1){
	 command_parser_fsm();
	 buffer_flag = 0;
	 }
}

