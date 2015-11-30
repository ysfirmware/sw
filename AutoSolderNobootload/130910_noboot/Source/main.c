#include "custmodel.h"
#include "systemcontrol.h"
#include "modbus_comm.h"

#include "schedule.h"

#include "process.h"
#include "uartproc.h"

#include "gpiodef.h"
#include "util.h"
#include "serial_flash.h"
#include "max31855.h"

#define __RCC_CR_VAL               0x01010082
#define __RCC_CFGR_VAL             0x001D8402
#define __HSE                      25000000


//__IO uint16_t ADC1ConvertedValue[ADC_CHECKNUM];
//__IO uint32_t ADC1ConvertedVoltage = 0;


int main(void)
{
	InitGPIOControl();
	APP_InitSystem();
	Init_VAR();
	InitValue();





	

#if 0
	delay_ms(10);
	Init_Flash();
	delay_ms(20);
	
	delay_ms(1000);
#endif 

	while (1)
	{
		
		Time2Schedule();
		RS485PORT_RxProtocol();
		ModbusRx_Protocol();
		Read_Templature();
		if (isheatflag ==1)
		{
			PID_Process();
			
		}
		//if (isheatflag ==0)
		//	SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_LOW);
	}

}



