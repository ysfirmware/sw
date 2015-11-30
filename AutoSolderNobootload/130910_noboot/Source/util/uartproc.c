
#include <string.h>
#include <stdio.h>
#include "uartproc.h"
#include "uartdef.h"
#include "modbus_comm.h"

_Comm Rxd3 , Txd3;
byte f_RxErr0;
void USART3_COMM_RESET(void)
{

	Rxd3.IsProcessing = 0  ;
	Rxd3.Step =0;
	Rxd3.CMD = RXD0STX;
	Rxd3.Length =0;
	Rxd3.proccnt = 0 ;
	Rxd3.BCC = 0x00;	

}

void APP_INIT_UART_VAR(void)
{


	USART3_COMM_RESET();
	ModbusRX0_Init();
	
}


void RS485PORTTx  (void)
{
	#if 1
	byte i;
	SetIO(IO_RS485_EN_PORT,IO_RS485_EN_PIN,IO_HIGH);
	Txd3.BCC = 0x00;
	SendUart(RS485PORT,(uint8_t)STX);  // STX
	SendUart(RS485PORT,(uint8_t)ID);   // ID
	SendUart(RS485PORT,(uint8_t)Txd3.Length );  // LEN  ( DATA)
	SendUart(RS485PORT,(uint8_t)Txd3.CMD); Txd3.BCC ^=Txd3.CMD; // CMD
	// DATA
	for ( i = 0 ; i < Txd3.Length ; i++)
	{
		SendUart(RS485PORT,(uint8_t)Txd3.DATA[i]); 
		Txd3.BCC ^=Txd3.DATA[i]; 
	}
	SendUart(RS485PORT,(uint8_t)Txd3.Length );  // BCC
	SendUart(RS485PORT,(uint8_t)ETX );  // BCC
	
	SetIO(IO_RS485_EN_PORT,IO_RS485_EN_PIN,IO_LOW);
	#else  // test debug 
	SetIO(IO_RS485_EN_PORT,IO_RS485_EN_PIN,IO_HIGH);
	SendUart(RS485PORT,(uint8_t)0x31); 
	SetIO(IO_RS485_EN_PORT,IO_RS485_EN_PIN,IO_LOW);
	#endif 
}

void RS485PORT_RxProtocol(void)
{
	int rxd;

	if (Rxd3.IsProcessing ==1) return ; // 아직 처리중이면 Rx 대기중이자 
	rxd = GetKey ();

	if ( rxd >= 0)
	{
		f_RxErr0 = 0 ;
		printf ( "rs465-%d-%x\n",Rxd3.Step , rxd);
		switch (Rxd3.Step)
		{
			case RXD0STX:
				if (rxd == STX)
				{
					Rxd3.Step = RXD0ID;
				}
				else
				{
					f_RxErr0 = 1;
				}
				break;
			case RXD0ID:
				if (rxd == ID)		// 0x00
				{
					Rxd3.Step = RXD0LEN;
					
				}
				else
				{
					f_RxErr0 = 1;
				}
				break;
			case RXD0LEN:
				Rxd3.Step = RXD0CMD;
				Rxd3.BCC = 0x00;					
				Rxd3.Length = rxd;
				Rxd3.proccnt = 0 ;				
				break;
			case RXD0CMD:
				switch (rxd)
				{
					case 'S':  // Set Command
					case 'T':
					case 'M':
					case 'O':
						Rxd3.CMD = rxd;
						Rxd3.BCC ^= rxd;
						Rxd3.Step = RXD0DAT;
						break;
					default :
						f_RxErr0 = 1;
						break;
				}
				break;
			case RXD0DAT:
				Rxd3.DATA[Rxd3.proccnt ++] = rxd;
				Rxd3.BCC ^= rxd;

				if ( Rxd3.proccnt >= Rxd3.Length)
				{
					Rxd3.Step = RXD0ECC;
				}
				break;				
			case RXD0ECC:
				Rxd3.Step = RXD0ETX;
				
				break;
			case RXD0ETX :	
				if (rxd == ETX)
				{
					Rxd3.IsProcessing =1; 
					Rxd3.Step = RXD0STX;
				}
				else
				{
					f_RxErr0 = 1;
				}
				break;

			default:
				break;	
		}
		if (f_RxErr0)
		{			  
			USART3_COMM_RESET();
		}
		
	}


	
}




