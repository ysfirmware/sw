#ifndef __UARTPROC
#define __UARTPROC
#include "custmodel.h"

//****************************************************************
//      RS-232 PROTOCOL HEAD
//****************************************************************
#define STX     0x02   // 응답 Start
#define ENQ     0x05    // 요구 Frame 시작 코드 
#define ACK     0x06
#define NAK     0x15
#define EOT     0x04    // dyrma Frame 마감 코드
#define ETX     0x03    // 응답 Frame 마감코드
#define CR      0x0D
#define LF      0x0A
#define SP      0x20     
#define BEL     0x07    // SMS 수신시 Header

#define NUM_0     0x30   // 


//****************************************************************
//      RS-232 PROTOCOL Command (PC->Writer)
//****************************************************************
#define P2T_CMD_ID_MAPPING		0x49		// "I"

#define P2T_CMD_Open_Short		0x4F		// "O"


#define P2T_CMD_REG_Value		0x56		// "V"

#define P2T_CMD_SPI_F_Erase		0x45		// "E"	Serial Flash Erase
#define P2T_CMD_SPI_F_Prog		0x46		// "F"	Serial Flash Program
#define P2T_CMD_SPI_F_Verf		0x52		// "R"	Serial Flash Verify


#define P2T_CMD_Prog_Module		0x50		// "P"	Program Camera Module
#define P2T_CMD_Veri_Module		0x59		// "Y"	Verify Camera Module

#define P2T_CMD_Copy_Binary		0x43		// "C"	Binary Copy Module to Flash Memory

#define P2T_CMD_SelfTest_JIG	0x4A		// "J"	Self Test LOOP
#define P2T_CMD_InSYS_TEST		0x73		// "s"	In-System Self Test LOOP


#define P2T_CMD_FW_Version		0x57		// "W"	F/W Version (APP Ver.)

#define P2T_CMD_Ignore			0xFF

//****************************************************************
//      RS-232 Err Code (Writer->PC)
//****************************************************************
#define T2P_Protocol_OK			0X41		// "A"
#define T2P_CMD_Err				0x42		// "B"
#define T2P_DATA_Err			0x43		// "C"
#define T2P_ECC_Err				0x44		// "D"

//	Test Code
#define T2P_ID1_Err				0x44		// "D"
#define T2P_ID2_Err				0x45		// "E"
#define T2P_DT1_Err				0x46		// "F"
#define T2P_DT2_Err				0x47		// "G"


//****************************************************************
//      RS-232 PROTOCOL SEQUENCE
//****************************************************************
#define     RXD0STX			0
#define     RXD0ID			RXD0STX + 1
#define     RXD0LEN			RXD0STX + 2
#define     RXD0CMD			RXD0STX + 3
#define     RXD0DAT			10
#define     RXD0ECC			200			
#define     RXD0ETX			RXD0ECC + 1


//****************************************************************
#define RD_Bin_Addr0 3
#define WR_Bin_Addr0 3

//****************************************************************





typedef struct 
{
	byte IsProcessing ;
	byte Step;
	byte CMD;
	byte Length;
	byte proccnt;
	byte DATA[128];
	byte BCC;	

} _Comm ;


extern _Comm Rxd3 , Txd3;


//****************************************************************

void USART3_COMM_RESET(void);

void APP_INIT_UART_VAR(void);

void RS485PORTTx (void);
void RS485PORT_RxProtocol(void);

#endif //__UARTPROC
