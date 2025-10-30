/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define led_test_Pin GPIO_PIN_1
#define led_test_GPIO_Port GPIOA
#define button1_Pin GPIO_PIN_2
#define button1_GPIO_Port GPIOA
#define button2_Pin GPIO_PIN_3
#define button2_GPIO_Port GPIOA
#define button3_Pin GPIO_PIN_4
#define button3_GPIO_Port GPIOA
#define SIGN_LED_Pin GPIO_PIN_5
#define SIGN_LED_GPIO_Port GPIOA
#define LED_RED_1_Pin GPIO_PIN_6
#define LED_RED_1_GPIO_Port GPIOA
#define LED_YELLOW_1_Pin GPIO_PIN_7
#define LED_YELLOW_1_GPIO_Port GPIOA
#define SEG1B_Pin GPIO_PIN_1
#define SEG1B_GPIO_Port GPIOB
#define SEG1C_Pin GPIO_PIN_2
#define SEG1C_GPIO_Port GPIOB
#define LED_GREEN_1_Pin GPIO_PIN_8
#define LED_GREEN_1_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_9
#define LED_RED_2_GPIO_Port GPIOA
#define LED_YELLOW_2_Pin GPIO_PIN_10
#define LED_YELLOW_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_11
#define LED_GREEN_2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_12
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_13
#define EN1_GPIO_Port GPIOA
#define SEG1D_Pin GPIO_PIN_3
#define SEG1D_GPIO_Port GPIOB
#define SEG2A_Pin GPIO_PIN_4
#define SEG2A_GPIO_Port GPIOB
#define SEG2B_Pin GPIO_PIN_5
#define SEG2B_GPIO_Port GPIOB
#define SEG2C_Pin GPIO_PIN_6
#define SEG2C_GPIO_Port GPIOB
#define SEG2D_Pin GPIO_PIN_7
#define SEG2D_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
