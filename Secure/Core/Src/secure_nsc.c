/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Secure/Src/secure_nsc.c
  * @author  MCD Application Team
  * @brief   This file contains the non-secure callable APIs (secure world)
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

/* USER CODE BEGIN Non_Secure_CallLib */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "secure_nsc.h"
#include "cmox_crypto.h"
/** @addtogroup STM32U5xx_HAL_Examples

  * @{
  */

/** @addtogroup Templates
  * @{
  */
extern const uint8_t Private_Key[48];
extern cmox_ecc_handle_t Ecc_Ctx;
/* Global variables ----------------------------------------------------------*/
void *pSecureFaultCallback = NULL;   /* Pointer to secure fault callback in Non-secure */
void *pSecureErrorCallback = NULL;   /* Pointer to secure error callback in Non-secure */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Secure registration of non-secure callback.
  * @param  CallbackId  callback identifier
  * @param  func        pointer to non-secure function
  * @retval None
  */
CMSE_NS_ENTRY void SECURE_RegisterCallback(SECURE_CallbackIDTypeDef CallbackId, void *func)
{
  if(func != NULL)
  {
    switch(CallbackId)
    {
      case SECURE_FAULT_CB_ID:           /* SecureFault Interrupt occurred */
        pSecureFaultCallback = func;
        break;
      case GTZC_ERROR_CB_ID:             /* GTZC Interrupt occurred */
        pSecureErrorCallback = func;
        break;
      default:
        /* unknown */
        break;
    }
  }
}

CMSE_NS_ENTRY
int32_t SECURE_ECC_Sign_NSC(uint8_t *msg, size_t msg_len,
                             uint8_t *sig, size_t *sig_len)
{
    // Here you can call the low-level cmox_ecdsa_sign() safely
    // Private key stays inside Secure World

    uint8_t random[48]; // ECDSA random (for demo, pseudo-random)
    for(int i=0;i<48;i++) random[i] = i+1;

    cmox_initialize(NULL);
    cmox_ecc_retval_t ret = cmox_ecdsa_sign(&Ecc_Ctx,
                                            CMOX_ECC_SECP384R1_LOWMEM,
											random, sizeof(random),
											Private_Key, sizeof(Private_Key),
                                            msg, msg_len,
                                            sig, sig_len);
    cmox_finalize(NULL);

    return (ret == CMOX_ECC_SUCCESS) ? 0 : -1;
}
/**
  * @}
  */

/**
  * @}
  */
/* USER CODE END Non_Secure_CallLib */

