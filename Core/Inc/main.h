/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
#pragma once
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
#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_7
#define LD2_GPIO_Port GPIOB

#define LeftShift_Pin GPIO_PIN_2
#define LeftShift_GPIO_Port GPIOC
#define RightShift_Pin GPIO_PIN_3
#define RightShift_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

// #define JOYSTICK_UP_Pin GPIO_PIN_14  //yellow wire
// #define JOYSTICK_UP_Port GPIOD

// #define JOYSTICK_DOWN_Pin GPIO_PIN_8  //green wire
// #define JOYSTICK_DOWN_Port GPIOE

// #define JOYSTICK_LEFT_Pin GPIO_PIN_14  //orange wire
// #define JOYSTICK_LEFT_Port GPIOF

// #define JOYSTICK_RIGHT_Pin GPIO_PIN_5 //red wire
// #define JOYSTICK_RIGHT_Port GPIOF

// #define JOYSTICK_1_P1_Pin  GPIO_PIN_12
// #define JOYSTICK_1_P1_Port GPIOB

// #define JOYSTICK_1_P2_Pin  GPIO_PIN_1
// #define JOYSTICK_1_P2_Port GPIOB

//#define array of pins and ports



#define KEYBOARD_UP      0x52
#define KEYBOARD_DOWN    0x51
#define KEYBOARD_LEFT    0x50
#define KEYBOARD_RIGHT   0x4F
#define KEYBOARD_ENTER   0x58
#define KEYBOARD_A       0x04
#define KEYBOARD_B       0x05
#define KEYBOARD_C       0x06
#define KEYBOARD_D       0x07
#define KEYBOARD_E       0x08
#define KEYBOARD_F       0x09
#define KEYBOARD_G       0x0a
#define KEYBOARD_H       0x0b
#define KEYBOARD_I       0x0c
#define KEYBOARD_J       0x0d
#define KEYBOARD_K       0x0e
#define KEYBOARD_L       0x0f
#define KEYBOARD_M       0x10
#define KEYBOARD_N       0x11
#define KEYBOARD_O       0x12
#define KEYBOARD_P       0x13
#define KEYBOARD_Q       0x14

#define P1_UP       0 //yellow wire
#define P1_DOWN     1  //green wire
#define P1_LEFT     2  //orange wire
#define P1_RIGHT    3 //red wire
#define P1_B1       4 
#define P1_B2       5 
#define P1_B3       6 
#define P1_B4       7 
#define P1_B5       8 
#define P1_B6       9 
#define COIN1       10
#define P1_Start    11
#define Shift       12
#define Extra1      13
#define Extra2      14


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
