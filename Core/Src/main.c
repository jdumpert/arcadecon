
#include "main.h"
#include "usb_device.h"
#include <stdbool.h>
#include "key_mapping.h"


/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define CLICK_REPORT_SIZE 5
uint8_t click_report[CLICK_REPORT_SIZE] = {0};


// defined in Device Class Definition for Human Interface Devices (HID)
// Appendix B, B.1 Protocol 1 (Keyboard)
#define PRESS_REPORT_SIZE 8
uint8_t press_report[PRESS_REPORT_SIZE] = {0};

  struct keyboardHID_t {
      uint8_t id;
      uint8_t modifiers;
      uint8_t key1;
      uint8_t key2;
      uint8_t key3;
  };

extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE END 0 */

#define X(en,str,port,pin,key) pin,
const uint16_t xIoPins[] = {XKEYS};
#undef X

#define X(en,str,port,pin,key) port,
const GPIO_TypeDef * xIoPorts[] = {XKEYS};
#undef X

#define X(en,str,port,pin,key) key,
const uint16_t xUserControlsIndex[] = {XKEYS};
#undef X

#define X(en,str,port,pin,key) str,
const char * xUserControls[] = {XKEYS};
#undef X

#define X(en,str,port,pin,key) en,
enum xUserControlsEnum {XKEYS};
#undef X


static const uint16_t ioPins[]         = { (GPIO_PIN_14), (GPIO_PIN_8), (GPIO_PIN_14), (GPIO_PIN_5), (GPIO_PIN_12),  
                                           (GPIO_PIN_1), (GPIO_PIN_12), (GPIO_PIN_7), (GPIO_PIN_5), (GPIO_PIN_3), 
                                           (GPIO_PIN_13), (GPIO_PIN_4), (GPIO_PIN_7), (GPIO_PIN_6)};
const GPIO_TypeDef * ioPorts[]  = {        (GPIOD),      (GPIOE),       (GPIOF),      (GPIOF),       (GPIOB),      
                                           (GPIOB),       (GPIOF),      (GPIOG),      (GPIOD),      (GPIOC),             
                                           (GPIOC),       (GPIOA),      (GPIOF),      (GPIOF)};

const uint16_t userControlsIndex[] =      {P1_RIGHT, P1_LEFT,P1_UP, P1_DOWN,  P1_B1, 
                                          P1_B2,   P1_B3,   P1_B4,   P1_B5,   P1_B6, 
                                           COIN1, P1_Start,  Shift,  Extra2};

const uint16_t keycodes[] =                {KEYBOARD_A, KEYBOARD_B, KEYBOARD_C, KEYBOARD_D, KEYBOARD_E, 
                                            KEYBOARD_F, KEYBOARD_G, KEYBOARD_H, KEYBOARD_I, KEYBOARD_J, 
                                            KEYBOARD_K, KEYBOARD_L, KEYBOARD_M, SPECIAL_SHIFT,
                                             KEYBOARD_O, KEYBOARD_P, KEYBOARD_Q};

const uint16_t mameKeycodes[] =             {KEYBOARD_RIGHT, KEYBOARD_LEFT, KEYBOARD_UP, KEYBOARD_DOWN,  KEYBOARD_E, 
                                            KEYBOARD_F, KEYBOARD_G, KEYBOARD_H, KEYBOARD_I, KEYBOARD_J, 
                                            KEYBOARD_K, KEYBOARD_L, KEYBOARD_M, SPECIAL_SHIFT,
                                             KEYBOARD_O, KEYBOARD_P, KEYBOARD_Q};

const uint16_t shiftedKeycodes[] =         {KEYBOARD_RIGHT, KEYBOARD_LEFT, KEYBOARD_UP, KEYBOARD_DOWN,  KEYBOARD_E, 
                                            KEYBOARD_F, KEYBOARD_G, KEYBOARD_H, KEYBOARD_I, KEYBOARD_J, 
                                            KEYBOARD_K, KEYBOARD_L, KEYBOARD_M, SPECIAL_SHIFT,
                                             KEYBOARD_O, KEYBOARD_P, KEYBOARD_Q};

#define CTL_COUNT 14

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  struct keyboardHID_t keyboardHID;
  keyboardHID.id = 1;
  keyboardHID.modifiers = 0;
  keyboardHID.key1 = 0;
  keyboardHID.key2 = 0;
  keyboardHID.key3 = 0;
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
  MX_USART3_UART_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    //read gpio port c
    // if(HAL_GPIO_ReadPin(LeftShift_GPIO_Port,LeftShift_Pin) == GPIO_PIN_RESET )
    // {
    //   press_report[0] |= 0x02;
    //   HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
    // }
    
    // if(HAL_GPIO_ReadPin(RightShift_GPIO_Port,RightShift_Pin) == GPIO_PIN_RESET )
    // {
    //   press_report[0] |= 0x20;
    //   HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
    // }

    //clear the press report
    for(int i = 0; i < PRESS_REPORT_SIZE; i++)
    {
      press_report[i] = 0x00;
    }

    bool keyDown = false;
    uint32_t reportIndex = 2;

    bool useShiftedKeycodes = false;
    //check for Shift key
    if (HAL_GPIO_ReadPin(ioPorts[userControlsIndex[Shift]], ioPins[userControlsIndex[Shift]]) == GPIO_PIN_RESET)
    {
        useShiftedKeycodes = true;
    }


    for (int i = 0; i < CTL_COUNT; i++)
    {
        if (HAL_GPIO_ReadPin(ioPorts[userControlsIndex[i]], ioPins[userControlsIndex[i]]) == GPIO_PIN_RESET)
        {
            uint16_t keycode = mameKeycodes[i];

            if(keycode == 0)
            {
                press_report[reportIndex] = shiftedKeycodes[i];
                reportIndex++;
            }
            else if(keycode >= KEYBOARD_LCTRL && keycode <= KEYBOARD_RGUI)
            {
                press_report[0] |= (0x01 << (keycode - 0xE0));
            }
            else
            {
                press_report[reportIndex] = mameKeycodes[i];
                reportIndex++;
            }

            HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
            keyDown = true;
            
        }

        if (reportIndex == PRESS_REPORT_SIZE)
        {
            reportIndex = 2;
        }
    }

  //led off if no flipper down
    if(keyDown == false)
    {
      HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
    }

    //read in all other buttons

    //start game

    //credit

    //plunger

    //credit 2

    //left/right mag save

    //mame - eb buyin, coin3 coin4, door, cancel, up,down,enter

    USBD_HID_SendReport(&hUsbDeviceFS, press_report, PRESS_REPORT_SIZE);
    HAL_Delay(20);     
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  RCC_OscInitStruct.PLL.PLLR = 2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LeftShift_Pin RightShift_Pin */
  GPIO_InitStruct.Pin = LeftShift_Pin|RightShift_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


  for(int i = 0; i < CTL_COUNT; i++)
  {
    GPIO_InitStruct.Pin = ioPins[userControlsIndex[i]];
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(ioPorts[userControlsIndex[i]], &GPIO_InitStruct);
  }

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
