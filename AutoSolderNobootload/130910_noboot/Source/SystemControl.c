#include "systemcontrol.h"

#include "gpiodef.h"
#include "nvimdef.h"
#include "adcdef.h"
#include "i2cdef.h"
#include "uartdef.h"
#include "spidef.h"
#include "timerdef.h"
#include "i2cdef.h"

#include "schedule.h"
//#include "uartproc.h"
#include "process.h"



/*
//	--> System clock Test Code
#define CFGR_MCO1_RESET_MASK      ((uint32_t)0xF89FFFFF)
#define RCC_MCO1Source_PLLCLK            ((uint32_t)0x00600000)
#define RCC_MCO1Div_1                    ((uint32_t)0x00000000)

// <--
*/
void InitGPIOControl(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);

	
	// STEP MOTOR PART
	GpioBPortInit(IO_M1_HOME_PORT,IO_M1_HOME_PIN,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_DIR_PORT,IO_M1_DIR_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_MS1_PORT,IO_M1_MS1_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_MS2_PORT,IO_M1_MS2_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_ENABLE_PORT,IO_M1_ENABLE_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_SLEEP_PORT,IO_M1_SLEEP_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_RESET_PORT,IO_M1_RESET_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_M1_STEP_PORT,IO_M1_STEP_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );

	// HEATER - PWN 
	GpioBPortInit(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_DOWN );
	//GpioBPortInit(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_DOWN );		//yyyy

	// SPI CS
	GpioBPortInit(IO_ROM_CS_PORT,IO_ROM_CS_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_TEMP_CS_PORT,IO_TEMP_CS_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	
	// SOL VALVE	
	GpioBPortInit(IO_TIP_UP_VALUE_PORT,IO_TIP_UP_VALUE_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_TIP_DN_VALUE_PORT,IO_TIP_DN_VALUE_PIN ,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_N2_EN_VALUE_PORT,IO_N2_EN_VALUE_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_VOUT_PORT,IO_RESERVE_VOUT_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_VIN_PORT,IO_RESERVE_VIN_PIN,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	


	GpioBPortInit(IO_TIP_UP_SENSOR_PORT,IO_TIP_UP_SENSOR_PIN,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_TIP_DN_SENSOR_PORT,IO_TIP_DN_SENSOR_PIN ,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_TIN_PORT,IO_RESERVE_TIN_PIN,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_TOUT_PORT,IO_RESERVE_TOUT_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_FOUT1_PORT,IO_RESERVE_FOUT1_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_RESERVE_FOUT2_PORT,IO_RESERVE_FOUT2_PIN ,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_FEED_WIRE_DET_PORT,IO_FEED_WIRE_DET_PIN,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	

	GpioBPortInit(IO_RESERVE_FIN1_PORT,IO_RESERVE_FIN1_PIN ,GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL ); 
	GpioBPortInit(IO_RESERVE_FIN2_PORT,IO_RESERVE_FIN2_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_SUB_PWR_ON1_PORT,IO_SUB_PWR_ON1_PIN , GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	
	GpioBPortInit(IO_SUB_PWR_ON2_PORT,IO_SUB_PWR_ON2_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );	

	
	// SYS LED
		GpioBPortInit(IO_SYS_LED_PORT,IO_SYS_LED_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	


	GpioBPortInit(IO_RS485_EN_PORT,IO_RS485_EN_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );

	
	


}


void APP_InitSystem(void)
{


	// STEP MOTOR PART
	SetIO (IO_M1_HOME_PORT,IO_M1_HOME_PIN , IO_LOW);
	SetIO (IO_M1_MS1_PORT , IO_M1_MS1_PIN , IO_LOW);

	SetIO (IO_M1_MS2_PORT ,IO_M1_MS2_PIN  , IO_LOW);
	SetIO (IO_M1_ENABLE_PORT,IO_M1_ENABLE_PIN , IO_LOW);
	SetIO (IO_M1_SLEEP_PORT, IO_M1_SLEEP_PIN, IO_LOW);
	SetIO (IO_M1_RESET_PORT ,IO_M1_RESET_PIN , IO_LOW);
	SetIO (IO_M1_STEP_PORT ,IO_M1_STEP_PIN  , IO_LOW);


	// HEATER - PWN 
	SetIO (IO_PWD_HEAT_PORT ,IO_PWD_HEAT_PIN, IO_LOW);

	

	// SOL VALVE	
	SetIO (IO_TIP_UP_VALUE_PORT ,IO_TIP_UP_VALUE_PIN, IO_LOW);
	SetIO (IO_TIP_DN_VALUE_PORT ,IO_TIP_DN_VALUE_PIN, IO_LOW);
	
	SetIO (IO_N2_EN_VALUE_PORT ,IO_N2_EN_VALUE_PIN, IO_LOW);
	SetIO (IO_RESERVE_VOUT_PORT ,IO_RESERVE_VOUT_PIN, IO_LOW);
	SetIO (IO_RESERVE_VIN_PORT,IO_RESERVE_VIN_PIN, IO_LOW);
	SetIO (IO_RESERVE_TOUT_PORT ,IO_TIP_UP_SENSOR_PIN, IO_LOW);
	SetIO (IO_RESERVE_FOUT1_PORT ,IO_RESERVE_FOUT1_PIN, IO_LOW);
	SetIO (IO_RESERVE_FOUT2_PORT ,IO_RESERVE_FOUT2_PIN, IO_LOW);

	
	SetIO (IO_SYS_LED_PORT ,IO_SYS_LED_PIN, IO_LOW);

	SetIO (IO_RS485_EN_PORT ,IO_RS485_EN_PIN, IO_LOW);
					
	
	// ** Timer2 Interrupt 등록
	
	InitInterrupt(TIM2_IRQn, 1, 0);
	InitInterrupt(TIM3_IRQn, 2, 1);
		
	// Timer2 
	TimerInit();
	
	
	// ** Debug Serial Port 
	USART_IO_Config ();
	// DEBUG 설정 
	// DEBUG Interrupt 등록 
	
	// TOUCH PANEL Serial Port
	// Usart6 설정 
	InitInterrupt(USART1_IRQn, 3, 2);
	USART_Configuration(TOUCHPORT, 19200,1,1);  // DEF , BPS , RX_EN , TX_EN

	InitInterrupt(USART3_IRQn, 4, 3);
	USART_Configuration(RS485PORT, 38400,1,1);  // DEF , BPS , RX_EN , TX_EN

	InitInterrupt(USART2_IRQn, 5, 4);
	USART_Configuration(DEBUGPORT, 115200,0,1); // DEF , BPS , RX_EN , TX_EN

	// OS ,전압 모니터링 
	// ACD1 설정 
	ADC_Configuration();

	// SPI CS
	SetIO (IO_ROM_CS_PORT ,IO_ROM_CS_PIN, IO_HIGH);
	SetIO (IO_TEMP_CS_PORT ,IO_TEMP_CS_PIN, IO_HIGH);
    INT_SPI_InitPort(ROM_SPI, ENABLE, _SPI_FREQ_DontCare_);		// 무조건 MAX
	//Init_Flash();
	SetIO (IO_SUB_PWR_ON1_PORT ,IO_SUB_PWR_ON1_PIN, IO_HIGH);  // MAIN24V
	SetIO (IO_SUB_PWR_ON2_PORT ,IO_SUB_PWR_ON2_PIN, IO_HIGH);  // MOTOR 24V 
	
	// I2C Init
	INT_SW_i2c_Init();
	//I2C_GPIO(1);
	//Init_I2C(INIT_I2C);
}

void InitValue (void)
{
	
	
	isHeating = 0 ;
	INT_SW_I2C_ReadBytes(0xA0 , 0x0004 , received_data ,2);
	
	T_Offset = received_data[0]<<8 | received_data[1];
	printf ( "Start offset[%x][%x]==[%d] ",received_data[0],received_data[1],T_Offset);

}

