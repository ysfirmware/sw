#include "i2cdef.h"
#include "gpiodef.h"
#include "nvimdef.h"

#define FLAG_TIMEOUT             ((uint32_t)0x10)

#define LONG_TIMEOUT             ((uint32_t)(5 * FLAG_TIMEOUT))   // 50



#if 1

void I2C_DeInit(I2C_TypeDef* I2Cx)
{

	if (I2Cx == I2C1)
	{
		/* Enable I2C1 reset state */

		RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
		/* Release I2C1 from reset state */
		RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);    
	}
	else if (I2Cx == I2C2)
	{
		/* Enable I2C2 reset state */
		RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, ENABLE);
		/* Release I2C2 from reset state */
		RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, DISABLE);      
	}
	else 
	{
		if (I2Cx == I2C3)
		{
			/* Enable I2C3 reset state */
			RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C3, ENABLE);
			/* Release I2C3 from reset state */
			RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C3, DISABLE);
		}
	}
}

void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
	uint16_t tmpreg = 0, freqrange = 0;
	uint16_t result = 0x04;
	uint32_t pclk1 = 8000000;
	RCC_ClocksTypeDef  rcc_clocks;

	// *---------------------------- I2Cx CR2 Configuration ------------------------*
	// Get the I2Cx CR2 value 
	tmpreg = I2Cx->CR2;
	// Clear frequency FREQ[5:0] bits 
	tmpreg &= (uint16_t)~((uint16_t)I2C_CR2_FREQ);
	// Get pclk1 frequency value 
	RCC_GetClocksFreq(&rcc_clocks);
	pclk1 = rcc_clocks.PCLK1_Frequency;
	// Set frequency bits depending on pclk1 value 
	freqrange = (uint16_t)(pclk1 / 1000000);
	tmpreg |= freqrange;
	// Write to I2Cx CR2 
	I2Cx->CR2 = tmpreg;

	// *---------------------------- I2Cx CCR Configuration ------------------------*
	// Disable the selected I2C peripheral to configure TRISE 
	I2Cx->CR1 &= (uint16_t)~((uint16_t)I2C_CR1_PE);
	// Reset tmpreg value --Clear F/S, DUTY and CCR[11:0] bits 
	tmpreg = 0;

	if (I2C_InitStruct->I2C_ClockSpeed <= 100000)
	{
		// * Configure speed in standard mode *

		// Standard mode speed calculate 
		result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed << 1));
		// Test if CCR value is under 0x4
		if (result < 0x04)
		{
			// Set minimum allowed value 
			result = 0x04;  
		}
		// Set speed value for standard mode 
		tmpreg |= result;	  
		// Set Maximum Rise Time for standard mode 
		I2Cx->TRISE = freqrange + 1; 
	}
	else /*(I2C_InitStruct->I2C_ClockSpeed <= 400000)*/
	{
		// * Configure speed in fast mode *
		// To use the I2C at 400 KHz (in fast mode), the PCLK1 frequency 
		//(I2C peripheral input clock) must be a multiple of 10 MHz 

		if (I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_2)
		{
			// Fast mode speed calculate: Tlow/Thigh = 2 
			result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 3));
		}
		else // I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_16_9
		{
			// Fast mode speed calculate: Tlow/Thigh = 16/9 
			result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 25));
			// Set DUTY bit 
			result |= I2C_DutyCycle_16_9;
		}

		// Test if CCR value is under 0x1
		if ((result & I2C_CCR_CCR) == 0)
		{
			// Set minimum allowed value 
			result |= (uint16_t)0x0001;  
		}
		// Set speed value and set F/S bit for fast mode 
		tmpreg |= (uint16_t)(result | I2C_CCR_FS);
		// Set Maximum Rise Time for fast mode 
		I2Cx->TRISE = (uint16_t)(((freqrange * (uint16_t)300) / (uint16_t)1000) + (uint16_t)1);  
	}

	// Write to I2Cx CCR 
	I2Cx->CCR = tmpreg;
	// Enable the selected I2C peripheral 
	I2Cx->CR1 |= I2C_CR1_PE;

	// *---------------------------- I2Cx CR1 Configuration ------------------------*
	// Get the I2Cx CR1 value 
	tmpreg = I2Cx->CR1;
	// Clear ACK, SMBTYPE and  SMBUS bits 
	tmpreg &= CR1_CLEAR_MASK;
	// * Configure I2Cx: mode and acknowledgement *
	// Set SMBTYPE and SMBUS bits according to I2C_Mode value 
	// Set ACK bit according to I2C_Ack value 
	tmpreg |= (uint16_t)((uint32_t)I2C_InitStruct->I2C_Mode | I2C_InitStruct->I2C_Ack);
	// Write to I2Cx CR1 
	I2Cx->CR1 = tmpreg;

	// *---------------------------- I2Cx OAR1 Configuration -----------------------
	// Set I2Cx Own Address1 and acknowledged address 
	I2Cx->OAR1 = (I2C_InitStruct->I2C_AcknowledgedAddress | I2C_InitStruct->I2C_OwnAddress1);
}
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
	// *---------------- Reset I2C init structure parameters values ----------------*
	// initialize the I2C_ClockSpeed member 
	I2C_InitStruct->I2C_ClockSpeed = 5000;
	// Initialize the I2C_Mode member 
	I2C_InitStruct->I2C_Mode = I2C_Mode_I2C;
	// Initialize the I2C_DutyCycle member 
	I2C_InitStruct->I2C_DutyCycle = I2C_DutyCycle_2;
	// Initialize the I2C_OwnAddress1 member 
	I2C_InitStruct->I2C_OwnAddress1 = 0;
	// Initialize the I2C_Ack member 
	I2C_InitStruct->I2C_Ack = I2C_Ack_Enable;
	// Initialize the I2C_AcknowledgedAddress member 
	I2C_InitStruct->I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
}
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
	// * Check the parameters *
	if (NewState != DISABLE)
	{
		// Enable the selected I2C peripheral 
		I2Cx->CR1 |= I2C_CR1_PE;
	}
	else
	{
		// Disable the selected I2C peripheral 
		I2Cx->CR1 &= (uint16_t)~((uint16_t)I2C_CR1_PE);
	}
}
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
	// * Check the parameters *
	if (NewState != DISABLE)
	{
		// Generate a START condition 
		I2Cx->CR1 |= I2C_CR1_START;
	}
	else
	{
		// Disable the START condition generation 
		I2Cx->CR1 &= (uint16_t)~((uint16_t)I2C_CR1_START);
	}
}
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// Generate a STOP condition 
		I2Cx->CR1 |= I2C_CR1_STOP;
	}
	else
	{
		// Disable the STOP condition generation 
		I2Cx->CR1 &= (uint16_t)~((uint16_t)I2C_CR1_STOP);
	}
}
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT)
{
	uint32_t lastevent = 0;
	uint32_t flag1 = 0, flag2 = 0;
	ErrorStatus status = ERROR;


	// * Read the I2Cx status register *
	flag1 = I2Cx->SR1;
	flag2 = I2Cx->SR2;
	flag2 = flag2 << 16;

	// * Get the last event value from I2C status register *
	lastevent = (flag1 | flag2) & FLAG_MASK;

	// * Check whether the last event contains the I2C_EVENT *
	if ((lastevent & I2C_EVENT) == I2C_EVENT)
	{
		// SUCCESS: last event is equal to I2C_EVENT 
		status = SUCCESS;
	}
	else
	{
		// ERROR: last event is different from I2C_EVENT 
		status = ERROR;
	}
	// * Return status *
	return status;
}
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
	// * Test on the direction to set/reset the read/write bit *
	if (I2C_Direction != I2C_Direction_Transmitter)
	{
		// Set the address bit0 for read 
		Address |= I2C_OAR1_ADD0;
	}
	else
	{
		// Reset the address bit0 for write 
		Address &= (uint8_t)~((uint8_t)I2C_OAR1_ADD0);
	}
	// * Send the address *
	I2Cx->DR = Address;
}
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data)
{
	// * Write in the DR register the data to be sent *
	I2Cx->DR = Data;
}
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx)
{
	// * Return the data in the DR register *
	return (uint8_t)I2Cx->DR;
}


__IO uint32_t  Timeout = LONG_TIMEOUT;   

uint32_t _TIMEOUT_UserCallback(void)
{   
	return (0);
}
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Enable the acknowledgement *
		I2Cx->CR1 |= I2C_CR1_ACK;
	}
	else
	{
		// * Disable the acknowledgement *
		I2Cx->CR1 &= (uint16_t)~((uint16_t)I2C_CR1_ACK);
	}
}
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG)
{
	FlagStatus bitstatus = RESET;
	__IO uint32_t i2creg = 0, i2cxbase = 0;


	// * Get the I2Cx peripheral base address *
	i2cxbase = (uint32_t)I2Cx;

	// * Read flag register index *
	i2creg = I2C_FLAG >> 28;

	// * Get bit[23:0] of the flag *
	I2C_FLAG &= FLAG_MASK;

	if(i2creg != 0)
	{
		// Get the I2Cx SR1 register address 
		i2cxbase += 0x14;
	}
	else
	{
		// Flag in I2Cx SR2 Register
		I2C_FLAG = (uint32_t)(I2C_FLAG >> 16);
		// Get the I2Cx SR2 register address 
		i2cxbase += 0x18;
	}

	if(((*(__IO uint32_t *)i2cxbase) & I2C_FLAG) != (uint32_t)RESET)
	{
		// I2C_FLAG is set 
		bitstatus = SET;
	}
	else
	{
		// I2C_FLAG is reset 
		bitstatus = RESET;
	}

	// * Return the I2C_FLAG status *
	return  bitstatus;
}



uint8_t I2C_start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction)
{

	I2C_GenerateSTART(I2Cx, ENABLE);

	// wait for I2C1 EV5 --> Slave has acknowledged start condition

	Timeout = LONG_TIMEOUT;
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((Timeout--) == 0)
			break; // return _TIMEOUT_UserCallback();
	}


	I2C_Send7bitAddress(I2Cx, address, direction);

	Timeout = LONG_TIMEOUT;	
	if(direction == I2C_Direction_Transmitter)
	{
		while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			if((Timeout--) == 0)
				break; //return _TIMEOUT_UserCallback();
		}
	}
	else if(direction == I2C_Direction_Receiver)
	{
		while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			if((Timeout--) == 0)
				break; //return _TIMEOUT_UserCallback();
		}
	}
	return 1;
}


/* This function transmits one byte to the slave device
 * Parameters:
 *		I2Cx --> the I2C peripheral e.g. I2C1
 *		data --> the data byte to be transmitted
 */


void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{
  
	if (NewState != DISABLE)
	{
		// Enable the selected I2C interrupts 
		I2Cx->CR2 |= I2C_IT;
	}
	else
	{
		// Disable the selected I2C interrupts 
		I2Cx->CR2 &= (uint16_t)~I2C_IT;
	}
}
uint8_t I2C_write(I2C_TypeDef* I2Cx, uint8_t data)
{
	I2C_SendData(I2Cx, data);
	// wait for I2C1 EV8_2 --> byte has been transmitted
	Timeout = LONG_TIMEOUT;	
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		if((Timeout--) == 0)
			return _TIMEOUT_UserCallback();
	}
	return 1;
}

/* This function reads one byte from the slave device
 * and acknowledges the byte (requests another byte)
 */
uint8_t I2C_read_ack(I2C_TypeDef* I2Cx)
{
	uint8_t data;
	// enable acknowledge of recieved data
	I2C_AcknowledgeConfig(I2Cx, ENABLE);
	// wait until one byte has been received
	Timeout = LONG_TIMEOUT;
	while( !I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED))
	{
		if((Timeout--) == 0)
			return _TIMEOUT_UserCallback();
	}
	// read data from I2C data register and return data byte
	data = I2C_ReceiveData(I2Cx);
	return data;
}

/* This function reads one byte from the slave device
 * and doesn't acknowledge the recieved data
 */
uint8_t I2C_read_nack(I2C_TypeDef* I2Cx)
{
	uint8_t data;

	// disabe acknowledge of received data
	I2C_AcknowledgeConfig(I2Cx, DISABLE);
	// wait until one byte has been received
	Timeout = LONG_TIMEOUT;
	while( !I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) )
	{
		if((Timeout--) == 0)
			return _TIMEOUT_UserCallback();
	}
	// read data from I2C data register and return data byte
	data = I2C_ReceiveData(I2Cx);
	return data;
}

/* This funtion issues a stop condition and therefore
 * releases the bus
 */
void I2C_stop(I2C_TypeDef* I2Cx)
{
	// Send I2C1 STOP Condition
	I2C_GenerateSTOP(I2Cx, ENABLE);
}




void I2C_GPIO(int EnabelLavel)
{
	switch ( EnabelLavel)
	{
		case 1:
			// INT_HW_I2C
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE); 
			RCC_AHB1PeriphClockCmd(INT_SCL_RCC_GPIO|INT_SDA_RCC_GPIO, ENABLE);
			GPIO_PinAFConfig(INT_SCL_PORT, INT_SCL_PIN_SOURCE,GPIO_AF_I2C1);	
			GPIO_PinAFConfig(INT_SDA_PORT, INT_SDA_PIN_SOURCE,GPIO_AF_I2C1);	
			// I2C1 SCL	
			GpioBPortInit(INT_SCL_PORT, INT_SCL_PIN,GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL );
			// I2C1 SDA
			GpioBPortInit(INT_SCL_PORT, INT_SDA_PIN,GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL );
			break;
		case 2:
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
			break;
		case 3:
			#if 0
			// EXT_HW_I2C
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C3, ENABLE); 
			RCC_AHB1PeriphClockCmd(EXT_SCL_RCC_GPIO|EXT_SDA_RCC_GPIO, ENABLE);
			GPIO_PinAFConfig(EXT_SCL_PORT, EXT_SCL_PIN_SOURCE,GPIO_AF_I2C1);	
			GPIO_PinAFConfig(EXT_SDA_PORT, EXT_SDA_PIN_SOURCE,GPIO_AF_I2C1);	
			// I2C1 SCL	
			GpioBPortInit(EXT_SCL_PORT, EXT_SCL_PIN,GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL );
			// I2C1 SDA
			GpioBPortInit(EXT_SCL_PORT, EXT_SDA_PIN,GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL );
			#endif 
		break;
	}

	// * Enable SYSCFG clock *
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

void Init_I2C(I2C_TypeDef* I2Cx)
{
	I2C_InitTypeDef I2C_InitStruct;

	I2C_DeInit(I2Cx);	

	// configure I2C1	
	//I2C_InitStruct.I2C_Mode = I2C_Mode_SMBusHost ; //I2C_Mode_I2C;			// I2C mode
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;			// I2C mode
	//I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;	// 50% duty cycle --> standard
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_16_9;	// 50% duty cycle --> standard
	I2C_InitStruct.I2C_OwnAddress1 = 0xFE;			// own address, not relevant in master mode
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;		// disable acknowledge when reading (can be changed later on)
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // set address length to 7 bit addresses
	I2C_InitStruct.I2C_ClockSpeed = 100000;
	I2C_Init(I2Cx, &I2C_InitStruct);				// init I2C1
	I2C_AcknowledgeConfig(I2Cx, ENABLE);

	// I2C_ITConfig(GPIOB, I2C_IT_EVT | I2C_IT_ERR| I2C_IT_BUF, ENABLE);//| I2C_IT_ERR very importan ,or I2C can not be work 

	I2C_Cmd(I2Cx, ENABLE);
// enable I2C1

}

#else 

/* ============================ End HW I2C ============================ */
/* ================================================================= */



/* ================================================================= */
/* ============================ Start SW I2C ============================ */






#define I2C1_SCL_OUTPUT GpioBPortInit(I2C1_SCL_PORT,I2C1_SCL_PIN,GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );

#define I2C1_SDA_INPUT GpioBPortInit(I2C1_SDA_PORT,I2C1_SDA_PIN,GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_UP );   //GPIO_OType_OD
#define I2C1_SDA_OUTPUT GpioBPortInit(I2C1_SDA_PORT,I2C1_SDA_PIN,GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );  
#define I2C1_READ_SDA GPIO_ReadInputDataBit(I2C1_SDA_PORT,I2C1_SDA_PIN)


void SW_i2c1Delay(void)
{

}
void SW_i2c1Delay2(void)
{
	byte ucDelayCnt2 = 1;	//reset loop counter

	while (ucDelayCnt2--) ;
	
}



void SW_i2c1_SDAInput(void)
{
	I2C1_SDA_INPUT;	
}
void SW_i2c1_SDAOutput(void)
{
	I2C1_SDA_OUTPUT;
}
void SW_i2c1_SCLOutput(void)
{
	I2C1_SCL_OUTPUT;
}
void SW_i2c1_SetSDA(void)
{
	SetIO(GPIOB , SW_I2C1_SDA,1);	
}
void SW_i2c1_ClrSDA(void)
{
	SetIO(GPIOB , SW_I2C1_SDA,0);	
}
void SW_i2c1_SetSCL(void)
{
	SetIO(GPIOB , SW_I2C1_SCL,1);	
	SW_i2c1Delay();
}
void SW_i2c1_ClrSCL(void)
{
	SetIO(GPIOB , SW_I2C1_SCL,0);	
	SW_i2c1Delay();
}
byte SW_i2c1_GetSDA(void)
{
	byte ucSDA;

	ucSDA = I2C1_READ_SDA;
	return ucSDA;
}
void SW_i2c1Start(void)
{
	// Ready
	SW_i2c1_SetSDA();
	SW_i2c1_SetSCL();
	SW_i2c1Delay2();			// Start waiting time

	// Start
	SW_i2c1_ClrSDA();		// Clear SDA
	SW_i2c1Delay2();			// Start hold time
	SW_i2c1_ClrSCL();		// Clear SCL
	SW_i2c1Delay2();			// Start waiting time
}

void SW_i2c1Stop(void)
{
	SW_i2c1_ClrSDA();
	SW_i2c1_ClrSCL();
	SW_i2c1Delay2();


	SW_i2c1_SetSCL();	// Set SCL and check.
	SW_i2c1Delay2();
	SW_i2c1_SetSDA();		// Set SDA
	//SW_i2c1Delay2();
}
byte SW_i2c1GetAck(void)
{
	byte ucAck;
	byte ucAckWaitCnt;
	
	SW_i2c1_SetSDA();

	SW_i2c1_SDAInput();		// Set SDA
	SW_i2c1Delay2();

	
	//wait 400us..
	for(ucAckWaitCnt = 0; ucAckWaitCnt < MAX_SWI2C_ACK_WAIT; ucAckWaitCnt++)
	{
		//SW_i2c1Delay2();
		ucAck = SW_i2c1_GetSDA();	// Check SDA line
		//if(ucAck == SWI2C_ACK)
		if(ucAck == I2C_OK)
			break;
	}
	

	SW_i2c1_SetSCL();				// Clear SCL
	SW_i2c1Delay2();
	SW_i2c1_ClrSCL();
	SW_i2c1Delay2();
	SW_i2c1_SDAOutput();	
	return (ucAck);				// Return SDA status

}

//******************************************************************
// FUNCTION     :   i2cTransmit
// USAGE        :   Write a data byte to slave through I2C bus
//                  and wait for ACK from slave
// DESCRIPTION  :   Sends a eight bit data to the slave and checks
//                  for slave acknoledge. If acknoledge is received
//                  that means the slave has accepted the data. If
//                  not acknoledge is not received slave is busy.
//
// INPUT        :   Value to send
// OUTPUT       :   Returns OK if ACK received
//                  or BUSY if not
// GLOBALS      :   None
// USED_REGS    :   None directly
//******************************************************************
byte SW_i2c1_Transmit(byte senddata)
{
	byte BitSelect;
	byte Get_ACK;

	BitSelect = 0x80;
	while (BitSelect)
	{
		if (BitSelect & senddata)	// Check data bit
			SW_i2c1_SetSDA();		// Set SDA
		else
			SW_i2c1_ClrSDA();		// Clear SDA

		SW_i2c1_ClrSCL();			// Clear SCL
		SW_i2c1Delay2();
		SW_i2c1_SetSCL();			// Set SCL
		SW_i2c1Delay2();
		SW_i2c1_ClrSCL();			// Clear SCL

		BitSelect >>= 1;		// Shift bit position to right
	}

	Get_ACK = SW_i2c1GetAck();
	// Check I2C ACK
	//if (SW_i2cGetAck())			// If ACK not seen
	if (Get_ACK==1)			// If ACK not seen
	{
		SW_i2c1Stop();				// Issue I2C STOP
		return I2C_BUSY;
	}
	else
		return I2C_OK;
}

byte SW_i2c1_WriteByte(byte Device, byte address, byte ucData)
{
	byte WR_Control;
	byte startLimit = MAX_SWI2C_Start_WAIT;
	byte Get_WACK;

	WR_Control = Device | I2C_WR;

	SW_i2c1Start();

	Get_WACK = I2C_ERR;
	//while(INT_SW_i2c_Transmit(WR_Control) != I2C_OK)	// I2C Start, Wait while device is busy
	while(Get_WACK != I2C_OK)	// I2C Start, Wait while device is busy
	{
		Get_WACK = SW_i2c1_Transmit(WR_Control);
		startLimit--;
		if (!startLimit)
		{
			return I2C_ERR;
		}
	}

	Get_WACK = SW_i2c1_Transmit(address);
	//if (INT_SW_i2c_Transmit(address))	//
	if (Get_WACK)	//
		return I2C_ERR;

	Get_WACK = SW_i2c1_Transmit(ucData);
	//if (INT_SW_i2c_Transmit(ucData))	//
	if (Get_WACK)	//
		return I2C_ERR;

	SW_i2c1Stop();

	SW_i2c1Delay2();
	return I2C_OK;
}
void Init_I2C1(void)
{
	SW_i2c1_SCLOutput();
	SW_i2c1_SDAOutput();
	SW_i2c1Stop();
}


#endif 

/* ===================================================================== */
/* ============================ Start INT(SW) I2C ============================ */
//#define INT_SCL_OUTPUT GpioBPortInit(INT_SCL_PORT,INT_SCL_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
#define INT_SCL_OUTPUT GpioBPortInit(INT_SCL_PORT, INT_SCL_PIN, GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_UP );

//#define INT_SDA_OUTPUT GpioBPortInit(INT_SDA_PORT,INT_SDA_PIN,GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );  
#define INT_SDA_OUTPUT GpioBPortInit(INT_SDA_PORT, INT_SDA_PIN, GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_UP );
#define INT_SDA_INPUT GpioBPortInit(INT_SDA_PORT, INT_SDA_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_OD, GPIO_PuPd_UP );   //GPIO_OType_OD
#define INT_READ_SDA GPIO_ReadInputDataBit(INT_SDA_PORT, INT_SDA_PIN)

// ** About 400KHz
// bit 구분
void INT_SW_i2cDelay(void)
{
	//uint8_t ucDelayCnt1 = 16;	//reset loop counter
	uint8_t ucDelayCnt1 = 12;	//reset loop counter

	while (ucDelayCnt1--) ;
}
// Start,Slave등 항목 구분
void INT_SW_i2cDelay2(void)
{
	uint8_t ucDelayCnt2 = 22;	//reset loop counter

	while (ucDelayCnt2--) ;
}


void INT_SW_i2c_SDAInput(void)
{
	INT_SDA_INPUT;	
}
void INT_SW_i2c_SDAOutput(void)
{
	INT_SDA_OUTPUT;
}
void INT_SW_i2c_SCLOutput(void)
{
	INT_SCL_OUTPUT;
}
void INT_SW_i2c_SetSDA(void)
{
	SetIO(INT_SDA_PORT , INT_SDA_PIN,1);	
}
void INT_SW_i2c_ClrSDA(void)
{
	SetIO(INT_SDA_PORT , INT_SDA_PIN,0);	
}
void INT_SW_i2c_SetSCL(void)
{
	SetIO(INT_SCL_PORT , INT_SCL_PIN,1);	
	INT_SW_i2cDelay();
}
void INT_SW_i2c_ClrSCL(void)
{
	SetIO(INT_SCL_PORT , INT_SCL_PIN,0);	
	INT_SW_i2cDelay();
}
uint8_t INT_SW_i2c_GetSDA(void)
{
	uint8_t ucSDA;

	ucSDA = INT_READ_SDA;
	return ucSDA;
}
void INT_SW_i2cStart(void)
{
	// Ready
	INT_SW_i2c_SetSDA();
	INT_SW_i2c_SetSCL();
	INT_SW_i2cDelay2();			// Start waiting time

	// Start
	INT_SW_i2c_ClrSDA();		// Clear SDA
	INT_SW_i2cDelay2();			// Start hold time
	INT_SW_i2c_ClrSCL();		// Clear SCL
	INT_SW_i2cDelay2();			// Start waiting time
}

void INT_SW_i2cStop(void)
{
	INT_SW_i2c_ClrSDA();
	INT_SW_i2c_ClrSCL();
	INT_SW_i2cDelay2();

	INT_SW_i2c_SetSCL();	// Set SCL and check.
	INT_SW_i2cDelay2();
	INT_SW_i2c_SetSDA();		// Set SDA
	//SW_i2cDelay2();
}
uint8_t INT_SW_i2cGetAck(void)
{
	uint8_t ucAck;
	uint8_t ucAckWaitCnt;

	INT_SW_i2c_SetSDA();
	INT_SW_i2c_SDAInput(); 	// Set SDA
	INT_SW_i2cDelay2();

	INT_SW_i2c_SetSCL();				// Clear SCL
	//INT_SW_i2cDelay2();
	//wait 400us..
	for(ucAckWaitCnt = 0; ucAckWaitCnt < MAX_SWI2C_ACK_WAIT; ucAckWaitCnt++)
	{
		//SW_i2c1Delay2();
		ucAck = INT_SW_i2c_GetSDA();	// Check SDA line
		//if(ucAck == SWI2C_ACK)
		if(ucAck == I2C_OK)
			break;
	}

	//INT_SW_i2c_SetSCL();				// Clear SCL
	//INT_SW_i2cDelay2();
	INT_SW_i2c_ClrSCL();
	INT_SW_i2cDelay2();
	INT_SW_i2c_SDAOutput();	
	
	return (ucAck);				// Return SDA status

}

void INT_SW_i2cSendAck(void)
{
	INT_SW_i2c_ClrSDA();
	INT_SW_i2c_SetSCL();
	//INT_SW_i2cDelay2();
	INT_SW_i2cDelay();
	INT_SW_i2c_ClrSCL();
}


//******************************************************************
// FUNCTION     :   i2cTransmit
// USAGE        :   Write a data byte to slave through I2C bus
//                  and wait for ACK from slave
// DESCRIPTION  :   Sends a eight bit data to the slave and checks
//                  for slave acknoledge. If acknoledge is received
//                  that means the slave has accepted the data. If
//                  not acknoledge is not received slave is busy.
//
// INPUT        :   Value to send
// OUTPUT       :   Returns OK if ACK received
//                  or BUSY if not
// GLOBALS      :   None
// USED_REGS    :   None directly
//******************************************************************
uint8_t INT_SW_i2c_Transmit(uint8_t senddata)
{
	uint8_t BitSelect;
	uint8_t Get_ACK;

	BitSelect = 0x80;

	INT_SW_i2c_ClrSCL();			// Clear SCL - START 조건이 걸리지 않게
	INT_SW_i2cDelay();

	while (BitSelect)
	{
		//INT_SW_i2c_SetSCL();			// Set SCL
		//INT_SW_i2cDelay2();

		if (BitSelect & senddata)	// Check data bit
			INT_SW_i2c_SetSDA();		// Set SDA
		else
			INT_SW_i2c_ClrSDA();		// Clear SDA

		INT_SW_i2cDelay();				// bit 밀리지 말라고 쳐놓은 Dummy Delay

		INT_SW_i2c_SetSCL();			// Set SCL
		INT_SW_i2cDelay2();
		INT_SW_i2c_ClrSCL();			// Clear SCL
		INT_SW_i2cDelay();

		BitSelect >>= 1;		// Shift bit position to right
	}

	Get_ACK = INT_SW_i2cGetAck();
	// Check I2C ACK
	//if (SW_i2cGetAck())			// If ACK not seen
	if (Get_ACK==1)			// If ACK not seen
	{
		INT_SW_i2cStop();				// Issue I2C STOP
		INT_SW_i2cDelay();
		return I2C_BUSY;
	}
	else
		return I2C_OK;
}

#if 1
uint8_t INT_SW_i2c_Reveive(void)
{
	uint8_t readData, BitSelect;

	readData = 0;				// Init data
	BitSelect = 0x80;

	INT_SW_i2c_ClrSCL();
	//INT_SW_i2cDelay2();
	//INT_SW_i2cDelay();

	INT_SW_i2c_SetSDA();				// Set SDA
	INT_SW_i2c_SDAInput();

	while (BitSelect)
	{
		INT_SW_i2cDelay2();				//High clock pulse width time
		//INT_SW_i2c_SetSCL_Chk();		//Set SCL and check.
		INT_SW_i2c_SetSCL();
		INT_SW_i2cDelay();				//High clock pulse width time

		if (INT_SW_i2c_GetSDA())
			readData |= BitSelect;	//Set data bit
		else
			readData &= ~BitSelect;	//Clear data bit

		BitSelect >>= 1;		//Shift bit position to right

		INT_SW_i2c_ClrSCL();			//Clear SCL
		//INT_SW_i2cDelay2();				//Low clock pulse width time
		//INT_SW_i2cDelay2();				//Low clock pulse width time
	}

	INT_SW_i2c_SDAOutput();
	//SW_i2cDelay();
printf ("INT_SW R_I2C READ %x \r\n",readData);
	return readData;
}
#endif

uint8_t INT_SW_i2c_WriteByte(uint8_t Device, word address, word ucData)
{
	uint8_t WR_Control;
	uint8_t startLimit = MAX_SWI2C_Start_WAIT;
	uint8_t Get_WACK;
	
	WR_Control = Device | I2C_WR;

	Get_WACK = I2C_ERR;
	// Send Start & SLAVE
	while(Get_WACK != I2C_OK)	// I2C Start, Wait while device is busy
	{
		INT_SW_i2cStart();

		Get_WACK = INT_SW_i2c_Transmit(WR_Control);
		startLimit--;
		if (!startLimit)
		{
			printf ("INT_SW W_I2C SLV er\r\n");
			return I2C_ERR;
		}

		if (Get_WACK != I2C_OK)
		{
			//SW_i2cStop();
			//SW_i2cDelay2();
			INT_SW_i2cDelay2();
		}
	}

	// Send Address 
	Get_WACK = INT_SW_i2c_Transmit((address>>8)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C addr er\r\n");
		return I2C_ERR;
	}
	
	Get_WACK = INT_SW_i2c_Transmit((address)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C addr er\r\n");
		return I2C_ERR;
	}
	

	// Send Data
	Get_WACK = INT_SW_i2c_Transmit((ucData>>8)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C Data er\r\n");
		return I2C_ERR;
	}
	
	Get_WACK = INT_SW_i2c_Transmit((ucData)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C Data er\r\n");
		return I2C_ERR;
	}
	

	INT_SW_i2cStop();

	INT_SW_i2cDelay2();
	return I2C_OK;
}

uint8_t INT_SW_I2C_ReadBytes(uint8_t Device,word address, uint8_t *ucData, uint8_t ucLength)
{
	uint8_t RD_Control;
	uint8_t startLimit = MAX_SWI2C_Start_WAIT;
	uint8_t Get_RACK;
	uint8_t Get_WACK;
	uint8_t WR_Control;
	
	RD_Control = Device | I2C_RD;
	WR_Control = Device | I2C_WR;

	Get_WACK = I2C_ERR;
	// Send Start & SLAVE
	while(Get_WACK != I2C_OK)	// I2C Start, Wait while device is busy
	{
		INT_SW_i2cStart();

		Get_WACK = INT_SW_i2c_Transmit(WR_Control);
		startLimit--;
		if (!startLimit)
		{
			printf ("INT_SW W_I2C SLV er\r\n");
			return I2C_ERR;
		}

		if (Get_WACK != I2C_OK)
		{
			//SW_i2cStop();
			//SW_i2cDelay2();
			INT_SW_i2cDelay2();
		}
	}

	// Send Address 
	// Send Address 
	Get_WACK = INT_SW_i2c_Transmit((address>>8)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C addr er\r\n");
		return I2C_ERR;
	}
	
	Get_WACK = INT_SW_i2c_Transmit((address)&0xFF);
	if (Get_WACK)	//
	{
		printf ("INT_SW W_I2C addr er\r\n");
		return I2C_ERR;
	}


	INT_SW_i2cStop();

	INT_SW_i2cDelay2();
	
	
	
	Get_RACK = I2C_ERR;
	// Send Start & SLAVE
	while(Get_RACK != I2C_OK)	// I2C Start, Wait while device is busy
	{
		INT_SW_i2cStart();
		Get_RACK = INT_SW_i2c_Transmit(RD_Control);
		startLimit--;
		if (!startLimit)
		{
			printf ("INT_SW R_I2C SLV er\r\n");
			return I2C_ERR;
		}
		if (Get_RACK != I2C_OK)
		{
			//INT_SW_i2cStop();
			//INT_SW_i2cDelay2();
			INT_SW_i2cDelay2();
		}
	}
	//delay_ms(2);

	// ...
	while(ucLength--)
	{
		*ucData++ = INT_SW_i2c_Reveive();  // Read data 

		if (ucLength > 0)
			INT_SW_i2cSendAck();
		else 
		{
			INT_SW_i2c_SetSDA();
			INT_SW_i2c_SetSCL();
			//INT_SW_i2cDelay2();
			INT_SW_i2cDelay();
			INT_SW_i2c_ClrSCL();
			INT_SW_i2cDelay();
			INT_SW_i2c_SetSCL();
		}
	}

	//INT_i2cSendAck();
	INT_SW_i2cStop();

	return I2C_OK;

}


void INT_SW_i2c_Init(void)
{
	INT_SW_i2c_SCLOutput();
	INT_SW_i2c_SDAOutput();
	INT_SW_i2cDelay2();

	INT_SW_i2cStop();
	INT_SW_i2cDelay2();
}

/* ============================ END INT(SW) I2C ============================ */


