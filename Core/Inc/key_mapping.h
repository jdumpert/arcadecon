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
X(EN_P2_UP         ,  "P2 Up"        ,  GPIOD ,  GPIO_PIN_6  ,  KEYBOARD_N      ,  KEYBOARD_N ,  KEYBOARD_N) \
X(EN_P2_DOWN       ,  "P2 Down"      ,  GPIOD ,  GPIO_PIN_5  ,  KEYBOARD_O      ,  KEYBOARD_O ,  KEYBOARD_O) \
X(EN_P2_LEFT       ,  "P2 Left"      ,  GPIOD ,  GPIO_PIN_4  ,  KEYBOARD_P      ,  KEYBOARD_P ,  KEYBOARD_P) \
X(EN_P2_RIGHT      ,  "P2 Right"     ,  GPIOD ,  GPIO_PIN_3  ,  KEYBOARD_Q      ,  KEYBOARD_Q ,  KEYBOARD_Q) \
X(EN_P2_B1         ,  "P2 B1"        ,  GPIOC ,  GPIO_PIN_15 ,  KEYBOARD_R      ,  KEYBOARD_R ,  KEYBOARD_R) \
X(EN_P2_B2         ,  "P2 B2"        ,  GPIOC ,  GPIO_PIN_14 ,  KEYBOARD_S      ,  KEYBOARD_S ,  KEYBOARD_S) \
X(EN_P2_B3         ,  "P2 B3"        ,  GPIOC ,  GPIO_PIN_12 ,  KEYBOARD_T      ,  KEYBOARD_T ,  KEYBOARD_T) \
X(EN_P2_B4         ,  "P2 B4"        ,  GPIOC ,  GPIO_PIN_11 ,  KEYBOARD_U      ,  KEYBOARD_U ,  KEYBOARD_U) \
X(EN_P2_B5         ,  "P2 B5"        ,  GPIOC ,  GPIO_PIN_10 ,  KEYBOARD_V      ,  KEYBOARD_V ,  KEYBOARD_V) \
X(EN_P2_B6         ,  "P2 B6"        ,  GPIOC ,  GPIO_PIN_9  ,  KEYBOARD_W      ,  KEYBOARD_W ,  KEYBOARD_W) \
X(EN_COIN2         ,  "Coin2"        ,  GPIOC ,  GPIO_PIN_8  ,  KEYBOARD_X      ,  KEYBOARD_X ,  KEYBOARD_X) \
X(EN_START2        ,  "Start2"       ,  GPIOC ,  GPIO_PIN_7  ,  KEYBOARD_Y      ,  KEYBOARD_Y ,  KEYBOARD_Y) \
X(EN_CONTROL_COUNT ,  "ControlCount" ,  NULL  ,  0           ,  0               ,  0          ,  0)  //this must be last line
//   enum              name             port     pin            key                shiftKey      debugKey


/*

A   8
A   9
A  10
A  11
A  12
A  13
A  14

B  0
B   7
B  14

C 13

D   8
D   9

G   6
G   7

H  0

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
*/