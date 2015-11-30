#ifndef __PROCESSDEF
#define __PROCESSDEF
#include "custmodel.h"


#define V_HEAT_MONTOR_CH	ADC_Channel_15
#define C_HEAT_MONTOR_CH	ADC_Channel_14

extern VALUE Val;
void MonitorADCFun(void);
void PID_Process(void);

void COMMProcess (void);
void RXACK(byte CMD);


void Init_VAR(void);

#endif //__PROCESSDEF
