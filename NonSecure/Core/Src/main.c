/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "cmox_crypto.h"
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

/* USER CODE BEGIN PV */
 const uint8_t Public_Key[96] = {
	  0x8F,0x21,0x3C,0xA7,0x0D,0x65,0x49,0xB3,
	  0x1E,0xFC,0x72,0x9A,0x4D,0x28,0xBE,0x11,
	  0x53,0x6F,0xC2,0x8D,0x90,0x34,0x7A,0xE5,
	  0x19,0xB1,0xC8,0x6F,0x42,0x0A,0xD5,0x8C,
	  0x2E,0xF3,0x61,0x7B,0x94,0x0D,0xAF,0x33,
	  0xC6,0x12,0x85,0xBE,0x9A,0x41,0x0F,0x72,
	  0x5D,0xE4,0x9A,0x3F,0x12,0xC8,0x6B,0x90,
	  0xAB,0x4F,0x73,0x1D,0xE9,0x20,0x5C,0x86,
	  0xB7,0x39,0xF1,0x62,0x8C,0x0E,0xD4,0x5A,
	  0x91,0x6B,0x3E,0xC5,0x0F,0x78,0xA2,0x14,
	  0x3D,0x87,0xE1,0x5B,0xA6,0x22,0xCF,0x09,
	  0x74,0xBD,0x18,0x63,0x8E,0xF2,0x4A,0x57
};
 uint8_t signature[96];
 size_t sig_len;
 uint8_t msg[] = "Hello ECC!";
 uint32_t fault_check = 0;
 cmox_ecc_handle_t Ecc_Ctx_NS;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void MX_GTZC_NS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// Public key (Non-Secure World)

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

  /* GTZC initialisation */
  MX_GTZC_NS_Init();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  // Call Secure world to sign
  	if (SECURE_ECC_Sign_NSC(msg, sizeof(msg)-1, signature, &sig_len) != 0) {
  	 HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET); // red LED means signing failed
  	} else {
  	 // Verify signature
  	 cmox_initialize(NULL);
     cmox_ecc_retval_t ret = cmox_ecdsa_verify(&Ecc_Ctx_NS,
                                               CMOX_ECC_SECP384R1_LOWMEM,
											   Public_Key, sizeof(Public_Key),
                                               msg, sizeof(msg)-1,
                                               signature, sig_len,
                                               &fault_check);
  	 cmox_finalize(NULL);

  	 if (ret == CMOX_ECC_AUTH_SUCCESS)
  		 HAL_GPIO_WritePin(GPIOH, GPIO_PIN_7, GPIO_PIN_SET); // green LED
  	 else
  		 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); // red LED
  	}
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief GTZC_NS Initialization Function
  * @param None
  * @retval None
  */
static void MX_GTZC_NS_Init(void)
{

  /* USER CODE BEGIN GTZC_NS_Init 0 */

  /* USER CODE END GTZC_NS_Init 0 */

  /* USER CODE BEGIN GTZC_NS_Init 1 */

  /* USER CODE END GTZC_NS_Init 1 */
  /* USER CODE BEGIN GTZC_NS_Init 2 */

  /* USER CODE END GTZC_NS_Init 2 */

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
#ifdef USE_FULL_ASSERT
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
