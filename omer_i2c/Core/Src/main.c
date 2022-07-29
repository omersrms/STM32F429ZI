/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
 I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */




HAL_StatusTypeDef ret;
uint8_t udata[6]="123abc";


/*
ret = HAL_I2C_Mem_Write(&hi2c1,(0x50<<1),0x03,8,udata,6,HAL_MAX_DELAY);
if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\rhata1",6,100);
	  }

HAL_UART_Transmit(&huart2, "\rWritten data:",14,100);
HAL_UART_Transmit(&huart2,udata,6,100);

HAL_Delay(500);

ret = HAL_I2C_Mem_Read(&hi2c1,(0x50<<1),0x03,8,rdata,10,HAL_MAX_DELAY);
if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\rhata2",6,100);
	  }

HAL_UART_Transmit(&huart2, "\rReceived data:",15,100);
HAL_UART_Transmit(&huart2,rdata,10,100);


*/


/*
ret = HAL_I2C_Master_Transmit(&hi2c1,(0x50<<1),"edcba",5,100);

if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\nhata1",6,100);
	  }



HAL_Delay(500);

ret = HAL_I2C_Master_Receive(&hi2c1, (0x50<<1) | 0x01, test,5,10000);

if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\nhata2",6,100);
	  }


HAL_UART_Transmit(&huart2," \rreceived2 data:",17,100);
HAL_UART_Transmit(&huart2,(char *)test,5,100);
/*


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */



  while (1)
  {


	   HAL_UART_Receive(&huart2,&rdata,sizeof(rdata),HAL_MAX_DELAY);

	   HAL_UART_Transmit(&huart2, "\rfull data:",11,100);
	   HAL_UART_Transmit(&huart2,&rdata,sizeof(rdata),100);


	    memcpy(state,&rdata[0],1);

	    HAL_UART_Transmit(&huart2, " state:",7,100);
	    HAL_UART_Transmit(&huart2,&state,sizeof(state),100);


	    uint8_t address[4]="0000";
	    memcpy(address,&rdata[1],4);


	    realaddress[0]=0;
	    realaddress[1]=atoi('x');
	    realaddress[2]=rdata[1];
	    realaddress[3]=rdata[2];
	    realaddress[4]=rdata[3];
	    realaddress[5]=rdata[4];
	//    realaddress=((rdata[1]-48)*1000)+((rdata[2]-48)*100)+((rdata[3]-48)*10)+((rdata[4]-48)*1);



	    HAL_UART_Transmit(&huart2, " address:",9,100);
	    HAL_UART_Transmit(&huart2,&realaddress,sizeof(realaddress),100);

	    memcpy(data,&rdata[5],15);


	    HAL_UART_Transmit(&huart2, " data:",6,100);
	    HAL_UART_Transmit(&huart2,&data,sizeof(data),100);

	 HAL_Delay(500);



if(rdata[0]=='W'){
HAL_UART_Transmit(&huart2, "\r--WRITING EEPROM--",19,100);

//ret = HAL_I2C_Mem_Write(&hi2c1,(0x50<<1),realaddress,8,data,sizeof(data),HAL_MAX_DELAY);


HAL_I2C_Master_Transmit(&hi2c1,(0x50<<1),0x0205,6,HAL_MAX_DELAY);

HAL_Delay(5);

ret = HAL_I2C_Master_Transmit(&hi2c1,(0x50<<1),data,sizeof(data),HAL_MAX_DELAY);

if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\rhata1",6,100);
	  }

HAL_UART_Transmit(&huart2, "\rWritten data:",14,100);
HAL_UART_Transmit(&huart2,data,sizeof(data),100);


}else if(rdata[0]=='R'){
HAL_UART_Transmit(&huart2, "\r--READING EEPROM--",19,100);

//ret = HAL_I2C_Mem_Read(&hi2c1,(0x50<<1),realaddress,8,data,sizeof(data),HAL_MAX_DELAY); // adrese SAYI gir. string girme
//                address               HEX --> DEC


 HAL_I2C_Master_Transmit(&hi2c1,(0x50<<1),0x0205,6,HAL_MAX_DELAY);

 HAL_Delay(5);

ret= HAL_I2C_Master_Receive(&hi2c1,(0x50<<1), data,sizeof(data),HAL_MAX_DELAY);
if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\rhata2",6,100);
	  }



HAL_UART_Transmit(&huart2, "\rReceived data:",15,100);
HAL_UART_Transmit(&huart2,data,sizeof(data),100);

}


else{
	HAL_UART_Transmit(&huart2, "HATA", 4,100);
}

HAL_Delay(500);

































    /* USER CODE END WHILE */
/*
	  ret = HAL_I2C_Master_Transmit(&hi2c1, (0x50<<1) ,test,2,100);

	  if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\nhata",5,100);
	  }else{
		HAL_UART_Transmit(&huart2," \rtransmit1 data:",17,100);
	  	HAL_UART_Transmit(&huart2,test,5,100);
	  }

	  HAL_Delay(500);
	  ret = HAL_I2C_Master_Receive(&hi2c1, (0x50<<1) | 0x01 ,test,2,100);

	  if(ret !=HAL_OK){
	  	HAL_UART_Transmit(&huart2, "\nhata",5,100);
	  }else{
		HAL_UART_Transmit(&huart2," \rreceived2 data:",17,100);
	  	HAL_UART_Transmit(&huart2,test,5,100);
	  }

	  HAL_Delay(500);

*/
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  __HAL_RCC_I2C1_CLK_ENABLE();
  /* I2C1 interrupt Init */
  HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
  HAL_NVIC_SetPriority(I2C1_ER_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */
  HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

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
