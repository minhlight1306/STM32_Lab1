/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#define Seg7_Pin GPIO_PIN_1
#define Seg7_GPIO_Port GPIOA
#define Seg8_Pin GPIO_PIN_2
#define Seg8_GPIO_Port GPIOA
#define Seg9_Pin GPIO_PIN_3
#define Seg9_GPIO_Port GPIOA
#define Seg10_Pin GPIO_PIN_4
#define Seg10_GPIO_Port GPIOA
#define Seg11_Pin GPIO_PIN_5
#define Seg11_GPIO_Port GPIOA
#define Seg12_Pin GPIO_PIN_6
#define Seg12_GPIO_Port GPIOA
#define Seg0_Pin GPIO_PIN_7
#define Seg0_GPIO_Port GPIOA
#define Led1_Pin GPIO_PIN_0
#define Led1_GPIO_Port GPIOB
#define Led2_Pin GPIO_PIN_1
#define Led2_GPIO_Port GPIOB
#define Led3_Pin GPIO_PIN_2
#define Led3_GPIO_Port GPIOB
#define Led11_Pin GPIO_PIN_10
#define Led11_GPIO_Port GPIOB
#define Led12_Pin GPIO_PIN_11
#define Led12_GPIO_Port GPIOB
#define Seg1_Pin GPIO_PIN_8
#define Seg1_GPIO_Port GPIOA
#define Seg2_Pin GPIO_PIN_9
#define Seg2_GPIO_Port GPIOA
#define Seg3_Pin GPIO_PIN_10
#define Seg3_GPIO_Port GPIOA
#define Seg4_Pin GPIO_PIN_11
#define Seg4_GPIO_Port GPIOA
#define Seg5_Pin GPIO_PIN_12
#define Seg5_GPIO_Port GPIOA
#define Seg6_Pin GPIO_PIN_13
#define Seg6_GPIO_Port GPIOA
#define Seg13_Pin GPIO_PIN_14
#define Seg13_GPIO_Port GPIOA
#define Led4_Pin GPIO_PIN_3
#define Led4_GPIO_Port GPIOB
#define Led5_Pin GPIO_PIN_4
#define Led5_GPIO_Port GPIOB
#define Led6_Pin GPIO_PIN_5
#define Led6_GPIO_Port GPIOB
#define Led7_Pin GPIO_PIN_6
#define Led7_GPIO_Port GPIOB
#define Led8_Pin GPIO_PIN_7
#define Led8_GPIO_Port GPIOB
#define Led9_Pin GPIO_PIN_8
#define Led9_GPIO_Port GPIOB
#define Led10_Pin GPIO_PIN_9
#define Led10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
