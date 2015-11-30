
#include <string.h>
#include <stdio.h>
#include "max31855.h"
#include "spidef.h"
#include "process.h"

float ReadModebusBuf[10];
byte ReadModusbusCnt = 0 ; 
float ReadThermocouple= 0 ;

float ReadInternal  = 0 ;



void INT_Max31855_CS(uint8_t ucON)
{
	if (ucON == _INT_TEMP_CS_ON_)
	{
		SetIO(IO_ROM_CS_PORT, IO_ROM_CS_PIN ,1);
		SetIO(IO_TEMP_CS_PORT, IO_TEMP_CS_PIN ,0); // 둘중 하나만 
	}
	else
	{
		SetIO(IO_TEMP_CS_PORT, IO_TEMP_CS_PIN ,1);
	}

	//delay_us(1);
}



void Read_Templature(void)
{
	byte ReadTemp[4];
	word ReadW = 0 ;



 
  VALUE *v = &Val;


  
	
	INT_Max31855_CS(_INT_TEMP_CS_ON_);	
	ReadTemp[0] = SPI_ReadByte(ROM_SPI);
	ReadTemp[1] = SPI_ReadByte(ROM_SPI);
	ReadTemp[2] = SPI_ReadByte(ROM_SPI);
	ReadTemp[3] = SPI_ReadByte(ROM_SPI);

	// 열전대 
	ReadW = (ReadTemp[0]<<6 |  ((ReadTemp[1] >> 2) & 0x3F)) &0x3FFF;

	if (( (ReadW >> 13) & 0x01)  ==0)  // 양수 
		ReadThermocouple = (float)ReadW/4;
	else 
	{
		ReadW = (~ReadW)&0x3FFFF ;		
		ReadThermocouple = ((float)ReadW/4)*-1;
	}
	
	// 접촉식  
	ReadW = (ReadTemp[2]<<4 |  ((ReadTemp[3] >> 4) & 0x0F)) &0x0FFF;

	if (( (ReadW >> 11) & 0x01)  ==0)  // 양수 
		ReadInternal = (float)ReadW/16;
	else 
	{
		ReadW = (~ReadW)&0x3FFFF ;		
		ReadInternal = ((float)ReadW/16)*-1;
	}
	
	


	INT_Max31855_CS(_INT_TEMP_CS_OFF_);

	

	ReadModebusBuf[ReadModusbusCnt++] = ReadThermocouple;
	if (ReadModusbusCnt >=10)ReadModusbusCnt = 0 ;
		

	

	v->Meas = ReadThermocouple;
	if (isheatflag ==1)
	{
		if (v->Set < v->Meas)
			isHeating = 1;
		else
			isHeating = 0;
	}
	else isHeating = 0;
}

