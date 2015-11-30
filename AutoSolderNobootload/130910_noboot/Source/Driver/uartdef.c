#include "uartdef.h"
#include "nvimdef.h"
#include "gpiodef.h"

void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
{
	uint32_t tmpreg = 0x00, apbclock = 0x00;
	uint32_t integerdivider = 0x00;
	uint32_t fractionaldivider = 0x00;
	RCC_ClocksTypeDef RCC_ClocksStatus;


	// * The hardware flow control is available only for USART1, USART2, USART3 and USART6 *
	if (USART_InitStruct->USART_HardwareFlowControl != USART_HardwareFlowControl_None)
	{

	}

	// *---------------------------- USART CR2 Configuration -----------------------*
	tmpreg = USARTx->CR2;

	// * Clear STOP[13:12] bits *
	tmpreg &= (uint32_t)~((uint32_t)USART_CR2_STOP);

	// * Configure the USART Stop Bits, Clock, CPOL, CPHA and LastBit :
	// Set STOP[13:12] bits according to USART_StopBits value *
	tmpreg |= (uint32_t)USART_InitStruct->USART_StopBits;

	// * Write to USART CR2 *
	USARTx->CR2 = (uint16_t)tmpreg;

	// *---------------------------- USART CR1 Configuration -----------------------*
	tmpreg = USARTx->CR1;

	// * Clear M, PCE, PS, TE and RE bits *
	tmpreg &= (uint32_t)~((uint32_t)CR1_CLEAR_MASK);

	// * Configure the USART Word Length, Parity and mode: 
	//   Set the M bits according to USART_WordLength value 
	//   Set PCE and PS bits according to USART_Parity value
	//   Set TE and RE bits according to USART_Mode value *
	tmpreg |= (uint32_t)USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity |
			USART_InitStruct->USART_Mode;

	// * Write to USART CR1 *
	USARTx->CR1 = (uint16_t)tmpreg;

	// *---------------------------- USART CR3 Configuration -----------------------*
	tmpreg = USARTx->CR3;

	// * Clear CTSE and RTSE bits *
	tmpreg &= (uint32_t)~((uint32_t)CR3_CLEAR_MASK);

	// * Configure the USART HFC : 
	//    Set CTSE and RTSE bits according to USART_HardwareFlowControl value *
	tmpreg |= USART_InitStruct->USART_HardwareFlowControl;

	// * Write to USART CR3 *
	USARTx->CR3 = (uint16_t)tmpreg;

	// *---------------------------- USART BRR Configuration -----------------------*
	// * Configure the USART Baud Rate *
	RCC_GetClocksFreq(&RCC_ClocksStatus);

	if ((USARTx == USART1) || (USARTx == USART6))
	{
		apbclock = RCC_ClocksStatus.PCLK2_Frequency;
	}
	else
	{
		apbclock = RCC_ClocksStatus.PCLK1_Frequency;
	}

	// * Determine the integer part *
	if ((USARTx->CR1 & USART_CR1_OVER8) != 0)
	{
		// * Integer part computing in case Oversampling mode is 8 Samples *
		integerdivider = ((25 * apbclock) / (2 * (USART_InitStruct->USART_BaudRate)));    
	}
	else // if ((USARTx->CR1 & USART_CR1_OVER8) == 0)
	{
		// * Integer part computing in case Oversampling mode is 16 Samples *
		integerdivider = ((25 * apbclock) / (4 * (USART_InitStruct->USART_BaudRate)));    
	}
	tmpreg = (integerdivider / 100) << 4;

	// * Determine the fractional part *
	fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

	// * Implement the fractional part in the register *
	if ((USARTx->CR1 & USART_CR1_OVER8) != 0)
	{
		tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);
	}
	else // if ((USARTx->CR1 & USART_CR1_OVER8) == 0) 
	{
		tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) & ((uint8_t)0x0F);
	}

	// * Write to USART BRR register *
	USARTx->BRR = (uint16_t)tmpreg;
}
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState)
{
	uint32_t usartreg = 0x00, itpos = 0x00, itmask = 0x00;
	uint32_t usartxbase = 0x00;

	/* The CTS interrupt is not available for UART4 and UART5 */
	if (USART_IT == USART_IT_CTS)
	{

	} 

	usartxbase = (uint32_t)USARTx;

	// * Get the USART register index *
	usartreg = (((uint8_t)USART_IT) >> 0x05);

	// * Get the interrupt position *
	itpos = USART_IT & IT_MASK;
	itmask = (((uint32_t)0x01) << itpos);

	if (usartreg == 0x01) // * The IT is in CR1 register *
	{
		usartxbase += 0x0C;
	}
	else if (usartreg == 0x02) // * The IT is in CR2 register *
	{
		usartxbase += 0x10;
	}
	else // * The IT is in CR3 register *
	{
		usartxbase += 0x14; 
	}

	if (NewState != DISABLE)
	{
		*(__IO uint32_t*)usartxbase  |= itmask;
	}
	else
	{
		*(__IO uint32_t*)usartxbase &= ~itmask;
	}
}

void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Enable the selected USART by setting the UE bit in the CR1 register *
		USARTx->CR1 |= USART_CR1_UE;
	}
	else
	{
		// * Disable the selected USART by clearing the UE bit in the CR1 register *
		USARTx->CR1 &= (uint16_t)~((uint16_t)USART_CR1_UE);
	}
}


void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{
	// * Transmit Data *
	USARTx->DR = (Data & (uint16_t)0x01FF);
}

FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG)
{
	FlagStatus bitstatus = RESET;

	// * The CTS flag is not available for UART4 and UART5 *
	if (USART_FLAG == USART_FLAG_CTS)
	{

	}

	if ((USARTx->SR & USART_FLAG) != (uint16_t)RESET)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
}




#define TBUF_SIZE   256	     // *** Must be a power of 2 (2,4,8,16,32,64,128,256,512,...) ***
#define RBUF_SIZE   256      // *** Must be a power of 2 (2,4,8,16,32,64,128,256,512,...) ***

// *----------------------------------------------------------------------------
//  *----------------------------------------------------------------------------*
#if TBUF_SIZE < 2
#error TBUF_SIZE is too small.  It must be larger than 1.
#elif ((TBUF_SIZE & (TBUF_SIZE-1)) != 0)
#error TBUF_SIZE must be a power of 2.
#endif

#if RBUF_SIZE < 2
#error RBUF_SIZE is too small.  It must be larger than 1.
#elif ((RBUF_SIZE & (RBUF_SIZE-1)) != 0)
#error RBUF_SIZE must be a power of 2.
#endif
/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
struct buf_st {
  unsigned int in;                                // Next In Index
  unsigned int out;                               // Next Out Index
  char buf [RBUF_SIZE];                           // Buffer
};

static struct buf_st rbuf = { 0, 0, };
#define SIO_RBUFLEN ((unsigned short)(rbuf.in - rbuf.out))

static struct buf_st tbuf = { 0, 0, };
#define SIO_TBUFLEN ((unsigned short)(tbuf.in - tbuf.out))

//static unsigned int tx_restart = 1;               // NZ if TX restart is required
int GetKey (void) 
{
	struct buf_st *p = &rbuf;

	if (SIO_RBUFLEN == 0)
		return (-1);

	return (p->buf [(p->out++) & (RBUF_SIZE - 1)]);
}

// RS485PORT
void USART3_IRQHandler (void) 
{
	volatile unsigned int IIR;
	struct buf_st *p;
	IIR = USART3->SR;

	if (IIR & USART_FLAG_RXNE) 
	{                  // read interrupt
		USART3->SR &= ~USART_FLAG_RXNE;	          // clear interrupt

		p = &rbuf;

		if (((p->in - p->out) & ~(RBUF_SIZE-1)) == 0) 
		{
			p->buf [p->in & (RBUF_SIZE-1)] = (USART3->DR & 0x1FF);
			p->in++;
		}
	}

	if (IIR & USART_FLAG_TXE) 
	{
		USART3->SR &= ~USART_FLAG_TXE;	          // clear interrupt

		p = &tbuf;

		if (p->in != p->out) 
		{
			USART3->DR = (p->buf [p->out & (TBUF_SIZE-1)] & 0x1FF);
			p->out++;
			//tx_restart = 0;
		}
		else 
		{
			//tx_restart = 1;
			USART3->CR1 &= ~USART_FLAG_TXE;		      // disable TX interrupt if nothing to send
		}
	}
}

static struct buf_st dbgrbuf = { 0, 0, };
#define SIO_dbgRBUFLEN ((unsigned short)(dbgrbuf.in - dbgrbuf.out))
static struct buf_st dbgtbuf = { 0, 0, };
#define SIO_dbgTBUFLEN ((unsigned short)(dbgtbuf.in - dbgtbuf.out))


int GetDBG (void) 
{
	struct buf_st *p = &dbgrbuf;

	if (SIO_dbgRBUFLEN == 0)
		return (-1);

	return (p->buf [(p->out++) & (RBUF_SIZE - 1)]);
}

// debug port
void USART2_IRQHandler (void) 
{
	volatile unsigned int IIR;
	struct buf_st *p;
	IIR = USART2->SR;

	if (IIR & USART_FLAG_RXNE) 
	{                  // read interrupt
		USART2->SR &= ~USART_FLAG_RXNE;		// clear interrupt

		p = &dbgrbuf;

		if (((p->in - p->out) & ~(RBUF_SIZE-1)) == 0) 
		{
			p->buf [p->in & (RBUF_SIZE-1)] = (USART2->DR & 0x1FF);
			p->in++;
		}
	}

	if (IIR & USART_FLAG_TXE) 
	{
		USART2->SR &= ~USART_FLAG_TXE;		// clear interrupt

		p = &dbgtbuf;

		if (p->in != p->out) 
		{
			USART2->DR = (p->buf [p->out & (TBUF_SIZE-1)] & 0x1FF);
			p->out++;
			//tx_restart = 0;
		}
		else 
		{
			//tx_restart = 1;
			USART2->CR1 &= ~USART_FLAG_TXE;		// disable TX interrupt if nothing to send
		}
	}
}

static struct buf_st th465rbuf = { 0, 0, };
#define SIO_th465rBUFLEN ((unsigned short)(th465rbuf.in - th465rbuf.out))
static struct buf_st th465tbuf = { 0, 0, };
#define SIO_th465tBUFLEN ((unsigned short)(th465tbuf.in - th465tbuf.out))

int Getth465 (void) 
{
	struct buf_st *p = &th465rbuf;

	if (SIO_th465rBUFLEN == 0)
		return (-1);

	return (p->buf [(p->out++) & (RBUF_SIZE - 1)]);
}

// debug port


void USART1_IRQHandler (void) 
{
	volatile unsigned int IIR;
	struct buf_st *p;
	IIR = USART1->SR;

	if (IIR & USART_FLAG_RXNE) 
	{                  // read interrupt
		USART1->SR &= ~USART_FLAG_RXNE;		// clear interrupt

		p = &th465rbuf;

		if (((p->in - p->out) & ~(RBUF_SIZE-1)) == 0) 
		{
			p->buf [p->in & (RBUF_SIZE-1)] = (USART1->DR & 0x1FF);
			p->in++;
		}
	}

	if (IIR & USART_FLAG_TXE) 
	{
		USART1->SR &= ~USART_FLAG_TXE;		// clear interrupt

		p = &th465tbuf;

		if (p->in != p->out) 
		{
			USART1->DR = (p->buf [p->out & (TBUF_SIZE-1)] & 0x1FF);
			p->out++;
			//tx_restart = 0;
		}
		else 
		{
			//tx_restart = 1;
			USART1->CR1 &= ~USART_FLAG_TXE;		// disable TX interrupt if nothing to send
		}
	}
}

void USART_IO_Config (void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC, ENABLE);	

	//#ifdef DRT_SAF4051
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, DISABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2|RCC_APB1Periph_USART3, DISABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2|RCC_APB1Periph_USART3, ENABLE);
	//#else	
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3|RCC_APB2Periph_USART6, ENABLE);
	//#endif

	GPIO_PinAFConfig(DEBUGTX_PORT, DEBUGTX_PINSOURCE,DEBUGGPIOAF);
	GpioBPortInit(DEBUGTX_PORT, DEBUGTX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );
	GPIO_PinAFConfig(DEBUGRX_PORT, DEBUGRX_PINSOURCE,DEBUGGPIOAF);
	GpioBPortInit(DEBUGRX_PORT, DEBUGRX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );

	GPIO_PinAFConfig(TOUCHTX_PORT, TOUCHTX_PINSOURCE,TOUCHGPIOAF);	
	GpioBPortInit(TOUCHTX_PORT, TOUCHTX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );
	GPIO_PinAFConfig(TOUCHRX_PORT, TOUCHRX_PINSOURCE,TOUCHGPIOAF);	
	GpioBPortInit(TOUCHRX_PORT, TOUCHRX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );


	GPIO_PinAFConfig(RS485TX_PORT, RS485TX_PINSOURCE,RS485GPIOAF);	
	GpioBPortInit(RS485TX_PORT, RS485TX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );
	GPIO_PinAFConfig(RS485RX_PORT, RS485RX_PINSOURCE,RS485GPIOAF);	
	GpioBPortInit(RS485RX_PORT, RS485RX_PIN,GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP );
}

void USART_Configuration(USART_TypeDef* USARTx,uint32_t Bps, byte RX_EN , byte TX_EN)    
{   	
	USART_InitTypeDef USART_InitStructure;  
	
	USART_InitStructure.USART_BaudRate = Bps;      
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;      
	USART_InitStructure.USART_StopBits = USART_StopBits_1;      
	USART_InitStructure.USART_Parity = USART_Parity_No;      
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;      

	if (TX_EN == 1)  // TX Modex
		USART_InitStructure.USART_Mode |= USART_Mode_Tx ;

	if (RX_EN ==1)  // RX Mode
		USART_InitStructure.USART_Mode |= USART_Mode_Rx ;
		     
	USART_Init(USARTx, &USART_InitStructure); 

	if (RX_EN ==1)  // RX interrupt Enabel
		USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);      

	USART_Cmd(USARTx, ENABLE);      
}

void SendUart(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData(USARTx, (uint8_t)Data); 

	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET); 
}

