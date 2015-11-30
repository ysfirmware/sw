#ifndef __CUSTMODELDEF
#define __CUSTMODELDEF
#include <stdio.h>
#include "stm32f4xx.h"


/****************************************************/
/* 										*/
#define _bit_7_			0x80
#define _bit_6_			0x40
#define _bit_5_			0x20
#define _bit_4_			0x10

#define _bit_3_			0x08
#define _bit_2_			0x04
#define _bit_1_			0x02
#define _bit_0_			0x01
/****************************************************/

///////////////////////////////////////////////////////////////////
// 이건 Default 그냥 두면 됨 
/********************************* *******************/
/* 				SYSTEM Resource						*/
// ** AHB1
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

#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM3              ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM4              ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM5              ((uint32_t)0x00000008)
#define RCC_APB1Periph_TIM6              ((uint32_t)0x00000010)
#define RCC_APB1Periph_TIM7              ((uint32_t)0x00000020)
#define RCC_APB1Periph_TIM12             ((uint32_t)0x00000040)
#define RCC_APB1Periph_TIM13             ((uint32_t)0x00000080)
#define RCC_APB1Periph_TIM14             ((uint32_t)0x00000100)
#define RCC_APB1Periph_WWDG              ((uint32_t)0x00000800)
#define RCC_APB1Periph_SPI2              ((uint32_t)0x00004000)
#define RCC_APB1Periph_SPI3              ((uint32_t)0x00008000)
#define RCC_APB1Periph_USART2            ((uint32_t)0x00020000)
#define RCC_APB1Periph_USART3            ((uint32_t)0x00040000)
#define RCC_APB1Periph_UART4             ((uint32_t)0x00080000)
#define RCC_APB1Periph_UART5             ((uint32_t)0x00100000)
#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_I2C2              ((uint32_t)0x00400000)
#define RCC_APB1Periph_I2C3              ((uint32_t)0x00800000)
#define RCC_APB1Periph_CAN1              ((uint32_t)0x02000000)
#define RCC_APB1Periph_CAN2              ((uint32_t)0x04000000)
#define RCC_APB1Periph_PWR               ((uint32_t)0x10000000)
#define RCC_APB1Periph_DAC               ((uint32_t)0x20000000)

// ** AHB2
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



// ** 
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

/****************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************************/
/* 					SYSTEM IO						*/
// SYS LED 

// GPIO Setting 값 Define 변경  Port , PIN 으로 정의 
#define IO_M1_HOME_PORT     GPIOC
#define IO_M1_HOME_PIN     	13

#define IO_M1_DIR_PORT		GPIOC
#define IO_M1_DIR_PIN		 14
#define IO_M1_MS1_PORT		GPIOC
#define IO_M1_MS1_PIN		 15
#define IO_M1_MS2_PORT		GPIOF
#define IO_M1_MS2_PIN		 0
#define IO_M1_ENABLE_PORT	GPIOF
#define IO_M1_ENABLE_PIN	 1

#define IO_M1_SLEEP_PORT		GPIOF
#define IO_M1_SLEEP_PIN		2
#define IO_M1_RESET_PORT		GPIOF
#define IO_M1_RESET_PIN		 3

#define IO_M1_STEP_PORT		GPIOF
#define IO_M1_STEP_PIN		 6


#define IO_PWD_HEAT_PORT		GPIOF
#define IO_PWD_HEAT_PIN		 7







#define IO_TIP_UP_VALUE_PORT  GPIOD     
#define IO_TIP_UP_VALUE_PIN  9      

#define IO_TIP_DN_VALUE_PORT  GPIOD	
#define IO_TIP_DN_VALUE_PIN  10	

#define IO_N2_EN_VALUE_PORT  GPIOD
#define IO_N2_EN_VALUE_PIN  11

#define IO_RESERVE_VOUT_PORT  GPIOD
#define IO_RESERVE_VOUT_PIN  12

#define IO_RESERVE_VIN_PORT	GPIOD
#define IO_RESERVE_VIN_PIN	13


#define IO_TIP_UP_SENSOR_PORT	GPIOD
#define IO_TIP_UP_SENSOR_PIN	15

#define IO_TIP_DN_SENSOR_PORT	GPIOG
#define IO_TIP_DN_SENSOR_PIN	2

#define IO_RESERVE_TIN_PORT		GPIOG
#define IO_RESERVE_TIN_PIN		3

#define IO_RESERVE_TOUT_PORT		GPIOG
#define IO_RESERVE_TOUT_PIN		4

#define IO_RESERVE_FOUT1_PORT		GPIOG
#define IO_RESERVE_FOUT1_PIN		6

#define IO_RESERVE_FOUT2_PORT		GPIOG
#define IO_RESERVE_FOUT2_PIN		7

#define IO_FEED_WIRE_DET_PORT		GPIOG
#define IO_FEED_WIRE_DET_PIN		8


#define IO_RESERVE_FIN1_PORT		GPIOC
#define IO_RESERVE_FIN1_PIN		6

#define IO_RESERVE_FIN2_PORT		GPIOC
#define IO_RESERVE_FIN2_PIN		7


#define IO_SUB_PWR_ON1_PORT		GPIOG
#define IO_SUB_PWR_ON1_PIN		13

#define IO_SUB_PWR_ON2_PORT		GPIOG
#define IO_SUB_PWR_ON2_PIN		15

#define IO_SYS_LED_PORT		GPIOE
#define IO_SYS_LED_PIN		1



#define IO_RS485_EN_PORT		GPIOC
#define IO_RS485_EN_PIN		12

#define ADC_DEF 			ADC1


#define IO_CURRENT_HEAT_PORT GPIOC
#define IO_CURRENT_HEAT_RCC_PORT  RCC_AHB1Periph_GPIOC
#define IO_CURRENT_HEAT_PIN 4

#define IO_VMON_HEAT_PORT GPIOC
#define IO_VMON_HEAT_RCC_PORT	RCC_AHB1Periph_GPIOC
#define IO_VMON_HEAT_PIN 5





#define ID 0x30




//#define ADC_CHECKNUM		4
#define ADC_CHECKNUM		1		// 한번에 1개 Read

/****************************************************/

/****************************************************/
/*	 					UART						*/
// ** UART DEBUG
#define DEBUGPORT		USART2
#define DEBUGGPIOAF		GPIO_AF_USART2
	#define DEBUGTX_PINSOURCE		GPIO_PinSource2
		#define DEBUGTX_PORT		GPIOA
		#define DEBUGTX_PIN		2
	#define DEBUGRX_PINSOURCE		GPIO_PinSource3
		#define DEBUGRX_PORT		GPIOA
		#define DEBUGRX_PIN		3


		

// ** UART TOUCH PANEL
#define TOUCHPORT		USART1
#define TOUCHGPIOAF		GPIO_AF_USART1
	#define TOUCHTX_PINSOURCE		GPIO_PinSource6
		#define TOUCHTX_PORT		GPIOB
		#define TOUCHTX_PIN		6
	#define TOUCHRX_PINSOURCE		GPIO_PinSource7
		#define TOUCHRX_PORT		GPIOB
		#define TOUCHRX_PIN 	7



// ** UART SYSTEM -RS485
#define RS485PORT		USART3
#define RS485GPIOAF		GPIO_AF_USART3
	#define RS485TX_PINSOURCE		GPIO_PinSource10
		#define RS485TX_PORT		GPIOC
		#define RS485TX_PIN		10
		#define RS485RX_PINSOURCE		GPIO_PinSource11
		#define RS485RX_PORT		GPIOC
		#define RS485RX_PIN		11




/****************************************************/

/****************************************************/
/* 					I2C (SW구동)						*/
// ** INT_I2C(I2C1, 400KHz)
#define INT_I2C		I2C1
#define INT_SCL_RCC_GPIO		RCC_AHB1Periph_GPIOB
	#define INT_SCL_PIN_SOURCE		GPIO_PinSource9
		#define INT_SCL_PORT		GPIOB
		#define INT_SCL_PIN		9
#define INT_SDA_RCC_GPIO		RCC_AHB1Periph_GPIOB
	#define INT_SDA_PIN_SOURCE		GPIO_PinSource8
		#define INT_SDA_PORT		GPIOB
		#define INT_SDA_PIN		8



/****************************************************/

/****************************************************/
/*						SPI							*/
// ** INT SPI(ROM, 37MHz)
#define ROM_SPI		SPI1
#define ROM_SCK_RCC_GPIO		RCC_AHB1Periph_GPIOA
	#define ROM_SCK_PIN_SOURCE		GPIO_PinSource5
		#define ROM_SCK_PORT		GPIOA
		#define ROM_SCK_PIN			5
#define ROM_MISO_RCC_GPIO		RCC_AHB1Periph_GPIOA
	#define ROM_MISO_PIN_SOURCE		GPIO_PinSource6
		#define ROM_MISO_PORT		GPIOA
		#define ROM_MISO_PIN		6
#define ROM_MOSI_RCC_GPIO		RCC_AHB1Periph_GPIOA
	#define ROM_MOSI_PIN_SOURCE		GPIO_PinSource7
		#define ROM_MOSI_PORT		GPIOA
		#define ROM_MOSI_PIN		7

#define IO_ROM_CS_PORT		GPIOF
#define IO_ROM_CS_PIN		11


#define IO_TEMP_CS_PORT GPIOF
#define IO_TEMP_CS_PIN 12



///////////////////////////////
#define I2C_OK			0
#define I2C_BUSY		1
#define I2C_ERR			2

////////////////////////////////////
#define IO_HIGH 		1
#define IO_LOW			0


//#define I2C_WP 4
//////////////////////////////////////////


#define		Open_Short_PIN_MAX			15  

#define     RELAY_DLY           20          // 10mSEC RTN 
#define     SWICH_TIME           10          // 10mSEC RTN              
#define     DELAY_TESTING        20       // OS쪽 붙이고 1mSEC Rtn 

#define     VOLTAGECHECK_DLY           2          // 20ms --> 50ms
#define     SHILD_OHM_TESTVAL   10      
#define     DELAY_SYSLED_ENGMODE    3       // 엔지니어 모드일때 시스템 LED 깜박임 100msSEC Rtn
#define     DELAY_SYSLED_NORMODE    7       // 테스트 모드일때 시스템 LED 깜박임 100msSEC Rtn

#define     OS_RESULT_RINGPASSCOUNT    2
#define     OS_RESULT_RINGFAILCOUNT    5

#define     bin_RESULT_RINGPASSCOUNT    10
#define     bin_RESULT_RINGFAILCOUNT    70


#define     DELAY_KEYCHECKTIME      20
#define		LCDSHOW_TIME	6
#define     ENGLCDSHOW_TIME 3
//#define		DELAY_RESULT	1500   
#define     DELAY_AIR       300         // 스위치 누르면 에어 들어가가지 전 시간 
#define     DELAY_TEST      300          // 에어 들어가고  테ㅔ스트 전 시간
                              
//#define     DELAY_WAIT     200
//#define     DELAY_WAIT     100
#define     DELAY_WAIT     10

//#define     DELAY_RELAY        200
#define     DELAY_RELAY        10		// Default O/S Path

//#define		DELAY_PWR		10
#define		DELAY_PWR		2
//#define		DELAY_PWR		50		// Test Code
//#define		DELAY_IO		3
#define		DELAY_IO		1

#define		DELAY_PWR_IST_		50
#define		DELAY_IO_IST_		30

//#define     DELAY_USB_SIG    100
//#define     DELAY_USB_PWR    100



#define     DELAY_TEST_STEP		5      // 1mSEC Rtn
#define     DELAY_RESULT		5

//#define		PIN_LED_FP					13		// LED PIN의 Open/Short 검사 Skip하기 위함

//#define		_LED_FP_PWR_Discharge_		10
#define		_LED_FP_PWR_Discharge_		2

//#define		_LED_FP_RELAY_CHATT_		200
#define		_LED_FP_RELAY_CHATT_		10


#define		_LED_FP_FORCE_ON_CNT		3000		// <y120629A> 3s


/************************************/
// UI System  State     
/*
#define     IDLE_S      0   // 대기 상태 
#define     INIT_S      1   // 대기중 표시 
#define     PROC_S      2   // 처리중 표시 
#define     RESULT_S    3   // 처리 결과 표시 
#define     FAIL_S      4   // 장비 Fail
*/
#define IDLE_S				0
#define INIT_S				1

#define OS_STATUS_S			11
#define OS_PROC_S			12
#define OS_RESULT_S			13
#define OS_FINNISH_S		14

#define bin_STATUS_S		31		// Erase/Program/Verify
#define bin_PROC_S			32		// Progress
#define bin_RESULT_S		33		// PASS/FAIL
#define bin_FINNISH_S		34		// 

////////////////////////////////////////////////////////////////
//****************************************************************
// Uart0
#define TX_BUFFER_SIZE0 512
#define RX_BUFFER_SIZE0 512

#define RX_Data_SIZE0 256
#define TX_Data_SIZE0 256

//#define RD_Bin_SIZE0 256
//#define WR_Bin_SIZE0 256
#define RW_Bin_PageSize		256

// #########################################################
//	Define Alphabet & Number
#define _NUMBER_0		0x30
#define _NUMBER_1		0x31
#define _NUMBER_2		0x32
#define _NUMBER_3		0x33
#define _NUMBER_4		0x34
#define _NUMBER_5		0x35
#define _NUMBER_6		0x36
#define _NUMBER_7		0x37
#define _NUMBER_8		0x38
#define _NUMBER_9		0x39

#define _String_sp		0x20
#define _String_dot		0x2E

#define _ALPHABET_A		0x41
#define _ALPHABET_B		0x42
#define _ALPHABET_C		0x43
#define _ALPHABET_D		0x44
#define _ALPHABET_E		0x45
#define _ALPHABET_F		0x46
#define _ALPHABET_G		0x47
#define _ALPHABET_H		0x48
#define _ALPHABET_I		0x49
#define _ALPHABET_J		0x4A
#define _ALPHABET_K		0x4B
#define _ALPHABET_L		0x4C
#define _ALPHABET_M		0x4D
#define _ALPHABET_N		0x4E
#define _ALPHABET_O		0x4F
#define _ALPHABET_P		0x50
#define _ALPHABET_Q		0x51
#define _ALPHABET_R		0x52
#define _ALPHABET_S		0x53
#define _ALPHABET_T		0x54
#define _ALPHABET_U		0x55
#define _ALPHABET_V		0x56
#define _ALPHABET_W		0x57
#define _ALPHABET_X		0x58
#define _ALPHABET_Y		0x59
#define _ALPHABET_Z		0x5A

#define _FONT_Rectengle_		0xFF

// #########################################################

// #########################################################
// Define F/W Version (APP)
#define _FW_VER_H			1
#define _FW_VER_Point		_String_dot
#define _FW_VER_M			3
#define _FW_VER_L			4

// #########################################################
//****************************************************************
//      TEST Process (u_Univasal_Mode) - 통신 프로토콜상의 CMD와 분리
//****************************************************************
#define _CMD_TEST_Idle_				0		// IDLE
//
#define _CMD_TEST_OST_				11		// Open/Short Test (BD_Test, Open/Short)
//
#define _CMD_TEST_IFLASH_ERS_		21		// Erase Internal Flash (CHIP_ER, 64KB_ER, 32KB_ER, 4KB_ER)
#define _CMD_TEST_IFLASH_Prog_		22		// Program Internal Flash (Unit:256Byte)
#define _CMD_TEST_IFLASH_READ_		23		// Read Internal Flash (Unit:256Byte)
//
#define _CMD_TEST_TARGET_ERS_		31		// EraseTarget 
#define _CMD_TEST_TARGET_Prog_		32		// Program Target
	#define _COMM_Trans_Size_Prog_MAX_		9
#define _CMD_TEST_TARGET_READ_		33		// Read Target (Unit:256Byte)
#define _CMD_TEST_TARGET_COPY_		34		// Copy Target to INT_FLASH
//
#define _CMD_TEST_ID_MAPPING_		101		// ID-MAPPING (READ FUSE ID)
	#define _CMD_Trans_Size_JF_ID_			10		// J-Project ID-MAPPING (READ FUSE ID) ; [FUSE_ID_CNT + 1] 양불판정 

//
#define _CMD_TEST_SELF_TEST_		201		// Self Test in JIG
	#define _COMM_Trans_Size_SELF_T_MAX_	16



// #########################################################


typedef enum 
{
	CK_OS = 0 ,
	CK_VCH1 ,
	CK_VCH2 ,
	CK_VCH3 ,
	CK_VCH4	
} ADCStatus;

typedef struct
{
  uint32_t SYSCLK_Frequency; /*!<  SYSCLK clock frequency expressed in Hz */
  uint32_t HCLK_Frequency;   /*!<  HCLK clock frequency expressed in Hz */
  uint32_t PCLK1_Frequency;  /*!<  PCLK1 clock frequency expressed in Hz */
  uint32_t PCLK2_Frequency;  /*!<  PCLK2 clock frequency expressed in Hz */
}RCC_ClocksTypeDef;

//uint32_t
//size of char = 1
//size of short = 2
//size of long = 4
//size of int = 4

typedef unsigned char	byte;
//typedef unsigned int  word;
typedef unsigned short  word;
typedef unsigned long	dword;

typedef struct {

  signed short Duty_Period;
  signed short Duty_Ratio;
  signed short Duty_Count;
}DUTY;
typedef struct {
  
  float Set;
  float Meas;
  byte Mode;
  int Temp_Digit;
  int IO_Digit;
  float inc;
  byte In;
}VALUE;



//PID Constant
#if 0
#define Kp  90.3    
#define Ki  90.1
#define Kd  200.0
#define dt  0.005

#else
#define Kp  1    
#define Ki  1
#define Kd  1
#define dt  0.01
#endif 
//
#define 	HEAT_Duty_Period		100
#define 	PID_OFFSET 6
#define   MAX_TEMP	400
	


#define CR1_CLEAR_MASK            ((uint16_t)(USART_CR1_M | USART_CR1_PCE | \
                                              USART_CR1_PS | USART_CR1_TE | \
                                              USART_CR1_RE))

/*!< USART CR2 register clock bits clear Mask ((~(uint16_t)0xF0FF)) */
#define CR2_CLOCK_CLEAR_MASK      ((uint16_t)(USART_CR2_CLKEN | USART_CR2_CPOL | \
                                              USART_CR2_CPHA | USART_CR2_LBCL))

/*!< USART CR3 register clear Mask ((~(uint16_t)0xFCFF)) */
#define CR3_CLEAR_MASK            ((uint16_t)(USART_CR3_RTSE | USART_CR3_CTSE))



#define Temp_Hi       400
#define Temp_Lo       20




#define	SIZE_COM0_BUF	64	
#define	SIZE_COM0_PKT	64		// Max packet size for RX/TX
#define	TIMEOUT_RX_PKT	100		// 100ms packet time out
#define	N_DATA_SINGLE	4		// 4 data bytes for single register command
								// Addr H & L, No.of Reg. H & L

typedef	struct {
  byte	RdPtr;				// Data read pointer
  byte	WrPtr;				// Data write pointer
  byte	Step;				// step
  byte	PCnt;				// Packet counter
  byte	DPtr;				// Data pointer
  byte	Buf[SIZE_COM0_BUF];	// Comm. Buffer
  byte	Pkt[SIZE_COM0_PKT];	// Packet buffer
  word	Crc16;				// CRC16
  byte	Cmd;				// Command
  byte	PktTO;				// Packet time out
  byte	RtCnt;				// Retry counter
} S_COMM0;			

extern S_COMM0 RX0, TX0;

extern byte isHeating;
extern float ReadInternal;
extern float ReadThermocouple;
extern float ReadModebusBuf[10];
extern byte isheatflag;
extern signed short T_Offset;
extern byte received_data[2];
#endif //CUSTMODELDEF

