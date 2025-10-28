/*
 * trafficLight.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Admin
 */
#include "trafficLight.h"
void display7SEGLine1A(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (num >> 3) & 0x01);
}

void display7SEGLine1B(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, (num >> 3) & 0x01);
}

void display7SEGLine2A(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (num >> 3) & 0x01);
}

void display7SEGLine2B(int num) {
    if (num < 0 || num > 9){
    	return;
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (num >> 0) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (num >> 1) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (num >> 2) & 0x01);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (num >> 3) & 0x01);
}
