#include "process.h"
//#include "dacadc.h"
#include "serial_flash.h"
#include "uartproc.h"
#include "spidef.h"

#include "gpiodef.h"

#include "util.h"
#include "adcdef.h"
#include "i2cdef.h"
#include "heatproc.h"
//byte PutDB ; 

//byte LCDTImer;   
uint16_t JIG_Test_Mode;
uint16_t JIG_DLY;

uint8_t JIG_Test_Config;

uint8_t JIG_Test_Time;
uint8_t JIG_Test_Status;

/*
void Hearting_Control(){
  
  static ui count;
  if ( count++ < 200 ) Heart = 0;
  else if ( count < 500 ) Heart = 1;
  else count = 0;

}
*/
	VALUE Val;


#define _Scale_Trans_REF_12bit_			1.6384		// REF.Volt :2.5V 2500->4096
#define _Scale_Trans_HW_Devide_			2		// 1/2 Devide

/// ADC Part
byte MontorADCCnt;
uint16_t g_get_REG_Value;
uint16_t MonAdcArry[2];


void Get_Voltage_Value(void)
{
	double ADC_Buf;

	// 실제 입력이 5V가 MAX(0x0FFF)임. Vref:2.5V
	// H/W 적으로 입력에서 2:1 Devide 했기 때문
	// Trans Value = (ADC Value * 0.00061V[Step Value] * 1000[Unit = mV]) * 2[H/W Devide]
	//ADC_Buf = ((double)ADC1ConvertedValue[ucCH] / _Scale_Trans_REF_12bit_);
	ADC_Buf = ((double)ADC1ConvertedValue / _Scale_Trans_REF_12bit_);
	//ADC_Buf = ADC_Buf * _Scale_Trans_HW_Devide_;
	ADC_Buf = ADC_Buf * 1.276;

	g_get_REG_Value = (uint16_t)ADC_Buf;

//	printf ("**GET REG. ADC:%d \r\n",  ADC1ConvertedValue[ucCH]);
	//printf ("**Get_Voltage_Value REG. ADC:%d \r\n", ADC1ConvertedValue);
//printf ("**GET V:%d \r\n", g_get_REG_Value);


}

void Get_Current_Value(void)
{
	double ADC_Buf;

	// 실제 입력이 5V가 MAX(0x0FFF)임. Vref:2.5V
	// H/W 적으로 입력에서 2:1 Devide 했기 때문
	// Trans Value = (ADC Value * 0.00061V[Step Value] * 1000[Unit = mV]) * 2[H/W Devide]
	//ADC_Buf = ((double)ADC1ConvertedValue[ucCH] / _Scale_Trans_REF_12bit_);
	ADC_Buf = ((double)ADC1ConvertedValue *2.3 );
//	ADC_Buf = ADC_Buf * 3.76;

	g_get_REG_Value = (uint16_t)ADC_Buf;

//	printf ("**GET REG. ADC:%d \r\n",  ADC1ConvertedValue[ucCH]);
//	printf ("**Get_Current_Value REG. ADC:%d \r\n", ADC1ConvertedValue);
//printf ("**GET V:%d \r\n", g_get_REG_Value);


}



void MonitorADCFun(void)
{
	switch (MontorADCCnt)
	{
		case 0 :  ADC_CH_Change (V_HEAT_MONTOR_CH ); break;

		case 1 : Get_Voltage_Value(); MonAdcArry[0] = g_get_REG_Value;  break;
		case 2 :  ADC_CH_Change (C_HEAT_MONTOR_CH ); break;
		case 3 : Get_Current_Value(); MonAdcArry[1] = g_get_REG_Value; break;
	}
	if ( ++MontorADCCnt >=  4) MontorADCCnt = 0 ;

}





void JIG_INT_Flash_Write(void)
{
	/*
	for ( JIG_Test_Status = 0 ; JIG_Test_Status < (_FData_Page-1) ; JIG_Test_Status ++)
	{
		r_WRd0FPageData[JIG_Test_Status] = _JIG_Test_INTF_Write_MASK;
	}

	FProg_Page_Serial_Flash();
*/
}


// Main 함수 While에 처리하는 부분 
void Init_VAR(void)
{
	
	APP_INIT_UART_VAR();

	MontorADCCnt = 0 ;  // ADC Index init
	

}


dword waittime ; 

float preTemp ; 
float OldOut;
float PidOld;
void PID_Process(void)
{
  
  VALUE *v = &Val;
  DUTY *d = &Duty;

 
	 float CurVal;
	float Integral, Derivative, Proportional;

  signed int limit = HEAT_Duty_Period;
  float kp=0.5;
	float ki=3.5;
	float kd=2;
	float dt_1 = 1;

 CurVal =  (v->Set+T_Offset) - v->Meas; // desired - measured;
	
	//if (v->Meas >= 150)	CurVal += (CurVal *0.05);
	//else 		CurVal -=  (CurVal *0.04);
	
	if  ( CurVal > 100 || CurVal < -100 )
	{
		kp=0.5;
		ki = 0.4;		
	}
	else 
	{
		kp=0.2;
		ki = 0.6;
	}
	
 //CurVal +=  (CurVal *0.02);
 Proportional = (kp*(CurVal - preTemp))*dt_1; //비례제어값
 Integral = (ki*CurVal)/ dt_1;// 적분제어값
	Derivative = kd*(CurVal - 2*preTemp + PidOld);//미분 제어값

	d->Duty_Ratio = Proportional + Integral + Derivative + OldOut +PID_OFFSET;
	PidOld = preTemp;
	preTemp = CurVal;
	

 // 선형근사를 이용한 출력 계산식.
  if (d->Duty_Ratio < 0) { // limiting the output
   d->Duty_Ratio = 0;
  }
  if (d->Duty_Ratio > limit) {
   d->Duty_Ratio = limit;
  }


	
	
	
  

  if ((signed int) d->Duty_Ratio > HEAT_Duty_Period ) d->Duty_Ratio = HEAT_Duty_Period;
 if ((signed int)d->Duty_Ratio < 0) d->Duty_Ratio = 0;	 

	
	//d->Duty_Ratio  = 10;
}


void COMMProcess (void)
{
	
	VALUE *v = &Val;
	
	if (Rxd3.IsProcessing ==1)
	{
		switch ( Rxd3.CMD)
		{
			case 'T':  // Heating Start / Stop
				
				OutPut_Control(Rxd3.DATA[0]); // debug test
				


				RXACK(Rxd3.CMD);
				
				break;
			case 'S': // Set Temp'
				v->Set = ((Rxd3.DATA[0]-0x30)*100) + ((Rxd3.DATA[1]-0x30)*10) + ((Rxd3.DATA[2]-0x30)) ;

				// overflow 방지 
				if ( v->Set > Temp_Hi ) v->Set = Temp_Hi;
				else if ( v->Set < Temp_Lo ) v->Set = Temp_Lo;

				printf ("Set Temp=%f\n", v->Set);
				
				RXACK(Rxd3.CMD);
				break;
			case 'O': // offset
				T_Offset = ((Rxd3.DATA[1]-0x30)*10) + ((Rxd3.DATA[2]-0x30)) ;
				if ( Rxd3.DATA[0] =='-')
					T_Offset *= -1;
				
				
					INT_SW_i2c_WriteByte(0xA0, 0x0004, T_Offset );
						
						INT_SW_I2C_ReadBytes(0xA0 , 0x0004 , received_data ,2);
						
				
						printf ("Read offset =[%x][%x]\n",received_data[0], received_data[1]);
				
				RXACK(Rxd3.CMD);
				break;
			case 'M' :// SOL MOVE
				switch( Rxd3.DATA[0])
				{
					case 0x01: //UP /DN
						if (Rxd3.DATA[1] ==1) // UP
						{
							SetIO(IO_TIP_UP_VALUE_PORT,IO_TIP_UP_VALUE_PIN, 1);
							SetIO(IO_TIP_DN_VALUE_PORT,IO_TIP_DN_VALUE_PIN, 0);
						}
						else if (Rxd3.DATA[1] ==0) // DN
						{
							SetIO(IO_TIP_UP_VALUE_PORT,IO_TIP_UP_VALUE_PIN, 0);
							SetIO(IO_TIP_DN_VALUE_PORT,IO_TIP_DN_VALUE_PIN, 1);
						}
						break;
					case 0x02: //EN
						if (Rxd3.DATA[1] ==1) // UP
						{
							SetIO(IO_N2_EN_VALUE_PORT,IO_N2_EN_VALUE_PIN, 1);							
						}
						else if (Rxd3.DATA[1] ==0) // DN
						{
							SetIO(IO_N2_EN_VALUE_PORT,IO_N2_EN_VALUE_PIN, 0);
						}
						break;
					case 0x03: //EN
						if (Rxd3.DATA[1] ==1) // UP
						{
							SetIO(IO_RESERVE_VOUT_PORT,IO_RESERVE_VOUT_PIN, 1);							
						}
						else if (Rxd3.DATA[1] ==0) // DN
						{
							SetIO(IO_RESERVE_VOUT_PORT,IO_RESERVE_VOUT_PIN, 0);
						}
						break;
				}
				RXACK(Rxd3.CMD);
				break;
		}
		Rxd3.IsProcessing = 0;
	}
}


void RXACK(byte CMD)
{
	Txd3.CMD = CMD;	
	Txd3.Length = 1;				
	Txd3.DATA[0] = ACK;
	RS485PORTTx();
}
	

