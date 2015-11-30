#include "Heatproc.h"
#include "Timerdef.h"
#include "Process.h "



byte isheatflag ; 
byte isHeating; 
DUTY Duty;
signed short T_Offset;
//  Heat 활성화 ./비활성화 
void OutPut_Control(byte isstatus)
{
	VALUE *v = &Val;
		
  DUTY *d = &Duty;
  //Heat_Flag = status;
  //Heating = ~Heat_Flag;

  if (v->Set ==0)
  	v->Set = 100;
  d->Duty_Period = HEAT_Duty_Period;
  d->Duty_Ratio = 50;
  isheatflag = isstatus;
  if (isstatus == 1)  TIM_Cmd(TIM2, ENABLE);  
  else
  {
	  TIM_Cmd(TIM2, DISABLE);  
	  SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_LOW);
  	}
}

void TempCelProc()
{

}

byte ishit;
// Timer 3이서 처리 
 void HeatTimer(void)
 {
 	DUTY *d = &Duty;
  // VALUE *v = &Val;
  #if 0 //TEST
	 if (ishit ==0 )
	 {
			SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_HIGH ) ;
		 ishit = 1;
	 }
	 else 
	{
			SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_LOW ) ;
		 ishit = 0;
	 }
	#else 
	if ( d->Duty_Count++ >= d->Duty_Period ) 
	{
    d->Duty_Count = 0;		
    SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_HIGH ) ;
  }
  else if ( d->Duty_Count >= d->Duty_Ratio )
	{		
		SetIO(IO_PWD_HEAT_PORT,IO_PWD_HEAT_PIN,IO_LOW);
	}
  #endif 
 }

