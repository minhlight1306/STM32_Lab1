/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ex4.c"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
const uint8_t segDigits[10] = {
    0b01000000, // 0: Seg0, Seg1, Seg2, Seg3, Seg4, Seg5
    0b01111001, // 1: Seg1, Seg2
    0b00100100, // 2: Seg0, Seg1, Seg3, Seg4, Seg6
    0b00110000, // 3: Seg0, Seg1, Seg2, Seg3, Seg6
    0b00011001, // 4: Seg1, Seg2, Seg5, Seg6
    0b00010010, // 5: Seg0, Seg2, Seg3, Seg5, Seg6
    0b00000010, // 6: Seg0, Seg2, Seg3, Seg4, Seg5, Seg6
    0b01111000, // 7: Seg0, Seg1, Seg2
    0b00000000, // 8: Seg0, Seg1, Seg2, Seg3, Seg4, Seg5, Seg6
    0b00010000  // 9: Seg0, Seg1, Seg2, Seg3, Seg5, Seg6
};

// ham thuc hien led 7 doan
void displayDigit(uint8_t digit) {
    HAL_GPIO_WritePin(Seg0_GPIO_Port, Seg0_Pin, (segDigits[digit] & 0x01) ? 1 : 0);
    HAL_GPIO_WritePin(Seg1_GPIO_Port, Seg1_Pin, (segDigits[digit] & 0x02) ? 1 : 0);
    HAL_GPIO_WritePin(Seg2_GPIO_Port, Seg2_Pin, (segDigits[digit] & 0x04) ? 1 : 0);
    HAL_GPIO_WritePin(Seg3_GPIO_Port, Seg3_Pin, (segDigits[digit] & 0x08) ? 1 : 0);
    HAL_GPIO_WritePin(Seg4_GPIO_Port, Seg4_Pin, (segDigits[digit] & 0x10) ? 1 : 0);
    HAL_GPIO_WritePin(Seg5_GPIO_Port, Seg5_Pin, (segDigits[digit] & 0x20) ? 1 : 0);
    HAL_GPIO_WritePin(Seg6_GPIO_Port, Seg6_Pin, (segDigits[digit] & 0x40) ? 1 : 0);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  uint8_t count = 1;
  uint8_t count5s = 1;
  uint8_t counter = 0;
  while (1)
  {
	  //led red trai va phai on
	  if(count <= 5){
		  HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, 1);//red
		  HAL_GPIO_WritePin(Led3_GPIO_Port, Led3_Pin, 0);//green
		  HAL_GPIO_WritePin(Led4_GPIO_Port, Led4_Pin, 0);//yellow

		  HAL_GPIO_WritePin(Led8_GPIO_Port, Led8_Pin, 1);
		  HAL_GPIO_WritePin(Led9_GPIO_Port, Led9_Pin, 0);
		  HAL_GPIO_WritePin(Led10_GPIO_Port, Led10_Pin, 0);
		  //led green tren va duoi on
		  if(count5s <= 3){
		  HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 0);
		  HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 1);
		  HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 0);
		  HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 0);
		  HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 1);
		  HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 0);
		  count5s++;
		  }
		  //led yellow tren va duoi on
		  else{
		  HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 0);
		  HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 0);
		  HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 1);
		  HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 0);
		  HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 0);
		  HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 1);
		  count5s++;
		  }
		  count++;
	  }
	  //led green tren va duoi on
	  else if(count <= 8){
		  HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, 0);
		  HAL_GPIO_WritePin(Led3_GPIO_Port, Led3_Pin, 1);
		  HAL_GPIO_WritePin(Led4_GPIO_Port, Led4_Pin, 0);

		  HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 1);
		  HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 0);
		  HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 0);

		  HAL_GPIO_WritePin(Led8_GPIO_Port, Led8_Pin, 0);
		  HAL_GPIO_WritePin(Led9_GPIO_Port, Led9_Pin, 1);
		  HAL_GPIO_WritePin(Led10_GPIO_Port, Led10_Pin, 0);

		  HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 1);
		  HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 0);
		  HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 0);
		  count++;
	  }
	  //led yellow tren va duoi on
	  else if(count <= 9){
		  HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, 0);
		  HAL_GPIO_WritePin(Led3_GPIO_Port, Led3_Pin, 0);
		  HAL_GPIO_WritePin(Led4_GPIO_Port, Led4_Pin, 1);

		  HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 1);
		  HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 0);
		  HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 0);

		  HAL_GPIO_WritePin(Led8_GPIO_Port, Led8_Pin, 0);
		  HAL_GPIO_WritePin(Led9_GPIO_Port, Led9_Pin, 0);
		  HAL_GPIO_WritePin(Led10_GPIO_Port, Led10_Pin, 1);

		  HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 1);
		  HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 0);
		  HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 0);
		  count++;
	  }
	  else{
		  count = 1;
		  count5s = 1;
	  }
	  if(counter >= 10) counter = 0;
	  displayDigit(counter++);

	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Led0_Pin|Seg0_Pin|Seg1_Pin|Seg2_Pin
                          |Seg3_Pin|Seg4_Pin|Seg5_Pin|Seg6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Led1_Pin|Led2_Pin|Led3_Pin|Led11_Pin
                          |Led12_Pin|Led4_Pin|Led5_Pin|Led6_Pin
                          |Led7_Pin|Led8_Pin|Led9_Pin|Led10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Led0_Pin Seg0_Pin Seg1_Pin Seg2_Pin
                           Seg3_Pin Seg4_Pin Seg5_Pin Seg6_Pin */
  GPIO_InitStruct.Pin = Led0_Pin|Seg0_Pin|Seg1_Pin|Seg2_Pin
                          |Seg3_Pin|Seg4_Pin|Seg5_Pin|Seg6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Led1_Pin Led2_Pin Led3_Pin Led11_Pin
                           Led12_Pin Led4_Pin Led5_Pin Led6_Pin
                           Led7_Pin Led8_Pin Led9_Pin Led10_Pin */
  GPIO_InitStruct.Pin = Led1_Pin|Led2_Pin|Led3_Pin|Led11_Pin
                          |Led12_Pin|Led4_Pin|Led5_Pin|Led6_Pin
                          |Led7_Pin|Led8_Pin|Led9_Pin|Led10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
