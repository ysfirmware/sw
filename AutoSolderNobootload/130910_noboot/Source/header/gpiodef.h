#ifndef __GPIODEF
#define __GPIODEF

typedef enum
{
	GPIO_Mode_IN   = 0x00,		// *!< GPIO Input Mode *
	GPIO_Mode_OUT  = 0x01,		// *!< GPIO Output Mode *
	GPIO_Mode_AF   = 0x02,		// *!< GPIO Alternate function Mode *
	GPIO_Mode_AN   = 0x03		// *!< GPIO Analog Mode *
}GPIOMode_TypeDef;

typedef enum
{ 
	GPIO_Speed_2MHz   = 0x00,		// *!< Low speed *
	GPIO_Speed_25MHz  = 0x01,		// *!< Medium speed *
	GPIO_Speed_50MHz  = 0x02,		// *!< Fast speed *
	GPIO_Speed_100MHz = 0x03		// *!< High speed on 30 pF (80 MHz Output max speed on 15 pF) *
}GPIOSpeed_TypeDef;

typedef enum
{ 
	GPIO_OType_PP = 0x00,		// Push-Pull ??
	GPIO_OType_OD = 0x01		// Open-Drain ??
}GPIOOType_TypeDef;

typedef enum
{ 
	GPIO_PuPd_NOPULL = 0x00,
	GPIO_PuPd_UP     = 0x01,		// Pull-Up ??
	GPIO_PuPd_DOWN   = 0x02			// Pull-Down ??
}GPIOPuPd_TypeDef;

typedef enum
{ 
	Bit_RESET = 0,
	Bit_SET
}BitAction;



#define GPIO_MODER_MODER0                    ((uint32_t)0x00000003)
#define GPIO_OSPEEDER_OSPEEDR0               ((uint32_t)0x00000003)
/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0                     ((uint32_t)0x00000001)
/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0                    ((uint32_t)0x00000003)


#if 0
#define RCC_AHB1Periph_GPIOA             ((uint32_t)0x00000001)
#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOC             ((uint32_t)0x00000004)
#define RCC_AHB1Periph_GPIOD             ((uint32_t)0x00000008)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000010)
#define RCC_AHB1Periph_GPIOF             ((uint32_t)0x00000020)
#define RCC_AHB1Periph_GPIOG             ((uint32_t)0x00000040)
#define RCC_AHB1Periph_GPIOH             ((uint32_t)0x00000080)
#define RCC_AHB1Periph_GPIOI             ((uint32_t)0x00000100)
#define RCC_AHB1Periph_CRC               ((uint32_t)0x00001000)
#define RCC_AHB1Periph_FLITF             ((uint32_t)0x00008000)
#define RCC_AHB1Periph_SRAM1             ((uint32_t)0x00010000)
#define RCC_AHB1Periph_SRAM2             ((uint32_t)0x00020000)
#define RCC_AHB1Periph_BKPSRAM           ((uint32_t)0x00040000)
#define RCC_AHB1Periph_CCMDATARAMEN      ((uint32_t)0x00100000)
#define RCC_AHB1Periph_DMA1              ((uint32_t)0x00200000)
#define RCC_AHB1Periph_DMA2              ((uint32_t)0x00400000)
#define RCC_AHB1Periph_ETH_MAC           ((uint32_t)0x02000000)
#define RCC_AHB1Periph_ETH_MAC_Tx        ((uint32_t)0x04000000)
#define RCC_AHB1Periph_ETH_MAC_Rx        ((uint32_t)0x08000000)
#define RCC_AHB1Periph_ETH_MAC_PTP       ((uint32_t)0x10000000)
#define RCC_AHB1Periph_OTG_HS            ((uint32_t)0x20000000)
#define RCC_AHB1Periph_OTG_HS_ULPI       ((uint32_t)0x40000000)

#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000001)
#define RCC_APB2Periph_TIM8              ((uint32_t)0x00000002)
#define RCC_APB2Periph_USART1            ((uint32_t)0x00000010)
#define RCC_APB2Periph_USART6            ((uint32_t)0x00000020)
#define RCC_APB2Periph_ADC               ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC2              ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC3              ((uint32_t)0x00000400)
#define RCC_APB2Periph_SDIO              ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
#define RCC_APB2Periph_SYSCFG            ((uint32_t)0x00004000)
#define RCC_APB2Periph_TIM9              ((uint32_t)0x00010000)
#define RCC_APB2Periph_TIM10             ((uint32_t)0x00020000)
#define RCC_APB2Periph_TIM11             ((uint32_t)0x00040000)
#endif

#if 0
#define GPIO_PinSource0            ((uint8_t)0x00)
#define GPIO_PinSource1            ((uint8_t)0x01)
#define GPIO_PinSource2            ((uint8_t)0x02)
#define GPIO_PinSource3            ((uint8_t)0x03)
#define GPIO_PinSource4            ((uint8_t)0x04)
#define GPIO_PinSource5            ((uint8_t)0x05)
#define GPIO_PinSource6            ((uint8_t)0x06)
#define GPIO_PinSource7            ((uint8_t)0x07)
#define GPIO_PinSource8            ((uint8_t)0x08)
#define GPIO_PinSource9            ((uint8_t)0x09)
#define GPIO_PinSource10           ((uint8_t)0x0A)
#define GPIO_PinSource11           ((uint8_t)0x0B)
#define GPIO_PinSource12           ((uint8_t)0x0C)
#define GPIO_PinSource13           ((uint8_t)0x0D)
#define GPIO_PinSource14           ((uint8_t)0x0E)
#define GPIO_PinSource15           ((uint8_t)0x0F)



#define GPIO_AF_USART1        ((uint8_t)0x07)  /* USART1 Alternate Function mapping */
#define GPIO_AF_USART2        ((uint8_t)0x07)  /* USART2 Alternate Function mapping */
#define GPIO_AF_USART3        ((uint8_t)0x07)  /* USART3 Alternate Function mapping */

#define GPIO_AF_UART4         ((uint8_t)0x08)  /* UART4 Alternate Function mapping */
#define GPIO_AF_UART5         ((uint8_t)0x08)  /* UART5 Alternate Function mapping */
#define GPIO_AF_USART6        ((uint8_t)0x08)  /* USART6 Alternate Function mapping */



#define GPIO_AF_I2C1          ((uint8_t)0x04)  /* I2C1 Alternate Function mapping */
#define GPIO_AF_I2C2          ((uint8_t)0x04)  /* I2C2 Alternate Function mapping */

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /* All pins selected */


#define sbi(Port , Bit) Port->BSRRL = (1<<Bit)
#define cbi(Port , Bit) Port->BSRRH = (1<<Bit)
#define SetIO(Port, Bit, Value) ((Value ==1) ? (Port->BSRRL = (1<<Bit)) : (Port->BSRRH = (1<<Bit)))
#endif


void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);
void GpioBPortInit(GPIO_TypeDef* GPIOx,int Portindex,GPIOMode_TypeDef ModeDef, GPIOSpeed_TypeDef SpeedDef,GPIOOType_TypeDef OTypedef,GPIOPuPd_TypeDef PuPdDef );
byte GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif // __GPIODEF
