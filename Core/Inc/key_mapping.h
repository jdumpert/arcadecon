#pragma once


#define XKEYS \
X(EN_SPECIAL_SHIFT ,  "SpecialShift" ,  GPIOF ,  GPIO_PIN_6  ,  0               ,  0          ,  KEYBOARD_A) \
X(EN_P1_UP         ,  "P1 Up"        ,  GPIOF ,  GPIO_PIN_14 ,  KEYBOARD_UP     ,  KEYBOARD_W ,  KEYBOARD_B) \ 
X(EN_P1_DOWN       ,  "P1 Down"      ,  GPIOF ,  GPIO_PIN_5  ,  KEYBOARD_DOWN   ,  KEYBOARD_V ,  KEYBOARD_C) \
X(EN_P1_LEFT       ,  "P1 Left"      ,  GPIOE ,  GPIO_PIN_8  ,  KEYBOARD_LEFT   ,  KEYBOARD_U ,  KEYBOARD_D) \
X(EN_P1_RIGHT      ,  "P1 Right"     ,  GPIOD ,  GPIO_PIN_14 ,  KEYBOARD_RIGHT  ,  KEYBOARD_T ,  KEYBOARD_E) \
X(EN_P1_B1         ,  "P1 B1"        ,  GPIOC ,  GPIO_PIN_13 ,  KEYBOARD_LCTRL  ,  KEYBOARD_S ,  KEYBOARD_F) \
X(EN_P1_B2         ,  "P1 B2"        ,  GPIOB ,  GPIO_PIN_12 ,  KEYBOARD_LALT   ,  KEYBOARD_R ,  KEYBOARD_G) \
X(EN_P1_B3         ,  "P1 B3"        ,  GPIOG ,  GPIO_PIN_7  ,  KEYBOARD_SPACE  ,  KEYBOARD_Q ,  KEYBOARD_H) \
X(EN_P1_B4         ,  "P1 B4"        ,  GPIOC ,  GPIO_PIN_3  ,  KEYBOARD_LSHIFT ,  KEYBOARD_P ,  KEYBOARD_I) \
X(EN_P1_B5         ,  "P1 B5"        ,  GPIOB ,  GPIO_PIN_1  ,  KEYBOARD_Z      ,  KEYBOARD_9 ,  KEYBOARD_J) \
X(EN_P1_B6         ,  "P1 B6"        ,  GPIOF ,  GPIO_PIN_12 ,  KEYBOARD_X      ,  KEYBOARD_8 ,  KEYBOARD_K) \
X(EN_COIN1         ,  "Coin1"        ,  GPIOF ,  GPIO_PIN_7  ,  KEYBOARD_5      ,  KEYBOARD_7 ,  KEYBOARD_L) \
X(EN_START1        ,  "Start1"       ,  GPIOA ,  GPIO_PIN_4  ,  KEYBOARD_1      ,  KEYBOARD_6 ,  KEYBOARD_M) \
X(EN_CONTROL_COUNT ,  "ControlCount" ,  NULL  ,  0           ,  0               ,  0          ,  0)  //this must be last line
//   enum              name             port     pin            key                shiftKey      debugKey