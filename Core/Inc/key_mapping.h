#pragma once


#define XKEYS \
X(EN_P1_UP        ,  "P1 Up"       ,  GPIOF,  GPIO_PIN_14,  KEYBOARD_UP) \ 
X(EN_P1_DOWN      ,  "P1 Down"     ,  GPIOF,  GPIO_PIN_5 ,  KEYBOARD_DOWN) \
X(EN_P1_LEFT      ,  "P1 Left"     ,  GPIOF,  GPIO_PIN_4 ,  KEYBOARD_LEFT) \
X(EN_P1_RIGHT     ,  "P1 Right"    ,  GPIOF,  GPIO_PIN_3 ,  KEYBOARD_RIGHT) \
X(EN_P1_B1        ,  "P1 B1"       ,  GPIOF,  GPIO_PIN_2 ,  KEYBOARD_A) \
X(EN_P1_B2        ,  "P1 B2"       ,  GPIOF,  GPIO_PIN_1 ,  KEYBOARD_B) \
X(EN_P1_B3        ,  "P1 B3"       ,  GPIOF,  GPIO_PIN_0 ,  KEYBOARD_C) \
X(EN_P1_B4        ,  "P1 B4"       ,  GPIOE,  GPIO_PIN_15,  KEYBOARD_D) \
X(EN_P1_B5        ,  "P1 B5"       ,  GPIOE,  GPIO_PIN_14,  KEYBOARD_E) \
X(EN_P1_B6        ,  "P1 B6"       ,  GPIOE,  GPIO_PIN_13,  KEYBOARD_F) \
X(EN_COIN1        ,  "Coin1"       ,  GPIOE,  GPIO_PIN_12,  KEYBOARD_5) \
X(EN_START1       ,  "Start1"      ,  GPIOE,  GPIO_PIN_11,  KEYBOARD_1) \
X(EN_SPECIAL_SHIFT,  "SpecialShift",  GPIOE,  GPIO_PIN_10,  KEYBOARD_2) \
X(EN_CONTROL_COUNT,  "ControlCount",   NULL,           0 ,           0)  //this must be last line