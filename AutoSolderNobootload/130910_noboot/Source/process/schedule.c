#include "schedule.h"
#include "uartdef.h"
#include "adcdef.h"
#include "I2c_eeprom.h"
#include "gpiodef.h"
#include "process.h"
#include "spidef.h"
//#include "dacadc.h"
#include "uartproc.h"
#include "heatproc.h"


int    r_Cnt_1ms, r_Cnt_10ms, r_Cnt_100ms;
char   r_Cnt_1ms_Soft,r_Cnt_10ms_Soft,r_Cnt_100ms_Soft;
char   f_On_1ms_Soft,f_On_10ms_Soft,f_On_100ms_Soft,f_On_500ms_Soft;
char BlinkLED;
byte r_100usCNT ; 

// every 100us
void Time2Fun(void)
{
	if (++r_100usCNT > 9)
	{
		r_100usCNT = 0 ;

		DoTime2_1ms();
		if( ++r_Cnt_1ms > 9 ) 
		{
			r_Cnt_1ms  = 0;
			DoTime2_10ms();
		}

		if( ++r_Cnt_10ms >= 99 ) 
		{
			r_Cnt_10ms = 0;
			DoTime2_100ms();
		}

		if( ++r_Cnt_100ms >= 499 ) 
		{
			r_Cnt_100ms = 0;
			DoTime2_500ms();
		}

//==============================================================================
//         Software Clock Process
//==============================================================================
		f_On_1ms_Soft = 1;
		if( ++r_Cnt_1ms_Soft > 9 ) 
		{
			f_On_10ms_Soft  = 1;
			r_Cnt_1ms_Soft = 0;
			if( ++r_Cnt_10ms_Soft > 9 ) 
			{
				r_Cnt_10ms_Soft = 0;
				f_On_100ms_Soft = 1;
				if( ++r_Cnt_100ms_Soft > 4 ) 
				{
					r_Cnt_100ms_Soft = 0;
					f_On_500ms_Soft  = 1;
				}
			}
		}
	}
}

void Time2Schedule(void)
{
	if( f_On_1ms_Soft )
	{
		SoftTime2_1ms();
		f_On_1ms_Soft = 0;
	}

	if( f_On_10ms_Soft )
	{
		SoftTime2_10ms();
		f_On_10ms_Soft = 0;
	}

	if( f_On_100ms_Soft )
	{
		SoftTime2_100ms();
		f_On_100ms_Soft = 0;
	}

	if( f_On_500ms_Soft )
	{
		SoftTime2_500ms();
		f_On_500ms_Soft = 0;
	}
}



void	DoTime2_1ms			( void )
{
	
}
void	DoTime2_10ms			( void )
{
}
void	DoTime2_100ms	    ( void )
{


}

void	DoTime2_500ms		( void )
{

	if (BlinkLED ==1)
		BlinkLED = 0 ;
	else
		BlinkLED = 1 ;		
	SetIO(IO_SYS_LED_PORT,IO_SYS_LED_PIN,BlinkLED);
	
}
void SoftTime2_1ms ( void )
{
	
	MonitorADCFun();  // 전압 전류 모니터링 ( ADC)
	COMMProcess();

	//if (isheatflag ==1)
	//		PID_Process();
		
}

void SoftTime2_10ms ( void )
{
	
}

void SoftTime2_100ms ( void )
{
}

//extern byte received_data[2];

//float Stpevolt ;


extern float ReadThermocouple ;
extern float ReadInternal   ;

void SoftTime2_500ms ( void )
{
	
	VALUE *v = &Val;
	printf ("T=[%f] V=%d=, i=%d-[%d,%d,%d]--[%f][%f],[%d], [%d,%x]\n" ,  ReadThermocouple,MonAdcArry[0] , MonAdcArry[1],Duty.Duty_Count , Duty.Duty_Period , Duty.Duty_Ratio, v->Set , v->Meas+T_Offset,isheatflag,T_Offset,T_Offset);
	//RS485PORTTx();
}




void Time3Fun(void)
{
   // 타이머 3번 정의 
	// PWM


   HeatTimer();
  
	
   
}
