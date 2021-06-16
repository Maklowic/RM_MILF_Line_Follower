/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define LED_USER_1_Pin GPIO_PIN_0
#define LED_USER_1_GPIO_Port GPIOC
#define LED_USER_2_Pin GPIO_PIN_1
#define LED_USER_2_GPIO_Port GPIOC
#define LED_USER_3_Pin GPIO_PIN_2
#define LED_USER_3_GPIO_Port GPIOC
#define LED_USER_4_Pin GPIO_PIN_3
#define LED_USER_4_GPIO_Port GPIOC
#define V_batt_Pin GPIO_PIN_0
#define V_batt_GPIO_Port GPIOA
#define KTIR_1_Pin GPIO_PIN_1
#define KTIR_1_GPIO_Port GPIOA
#define KTRI_2_Pin GPIO_PIN_2
#define KTRI_2_GPIO_Port GPIOA
#define KTIR_3_Pin GPIO_PIN_3
#define KTIR_3_GPIO_Port GPIOA
#define KTIR_4_Pin GPIO_PIN_4
#define KTIR_4_GPIO_Port GPIOA
#define KTIR_5_Pin GPIO_PIN_5
#define KTIR_5_GPIO_Port GPIOA
#define LED_USER_5_Pin GPIO_PIN_4
#define LED_USER_5_GPIO_Port GPIOC
#define LED_USER_6_Pin GPIO_PIN_5
#define LED_USER_6_GPIO_Port GPIOC
#define SW_USER_1_Pin GPIO_PIN_0
#define SW_USER_1_GPIO_Port GPIOB
#define SW_USER_2_Pin GPIO_PIN_1
#define SW_USER_2_GPIO_Port GPIOB
#define SW_USER_3_Pin GPIO_PIN_2
#define SW_USER_3_GPIO_Port GPIOB
#define START_P_Pin GPIO_PIN_10
#define START_P_GPIO_Port GPIOB
#define START_LED_Pin GPIO_PIN_12
#define START_LED_GPIO_Port GPIOB
#define L_IN_1_Pin GPIO_PIN_8
#define L_IN_1_GPIO_Port GPIOC
#define L_IN_2_Pin GPIO_PIN_9
#define L_IN_2_GPIO_Port GPIOC
#define PWM_L_Pin GPIO_PIN_8
#define PWM_L_GPIO_Port GPIOA
#define PWM_R_Pin GPIO_PIN_9
#define PWM_R_GPIO_Port GPIOA
#define R_IN_2_Pin GPIO_PIN_10
#define R_IN_2_GPIO_Port GPIOA
#define R_IN_1_Pin GPIO_PIN_11
#define R_IN_1_GPIO_Port GPIOA
#define SYS_SWDIO_Pin GPIO_PIN_13
#define SYS_SWDIO_GPIO_Port GPIOA
#define SYS_SWCLK_Pin GPIO_PIN_14
#define SYS_SWCLK_GPIO_Port GPIOA
#define LED_USER_7_Pin GPIO_PIN_10
#define LED_USER_7_GPIO_Port GPIOC
#define LED_USER_8_Pin GPIO_PIN_11
#define LED_USER_8_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
