#include "spidef.h"
#include "gpiodef.h"
#include "nvimdef.h"
#include "util.h"

__IO uint32_t  SPITimeout = SPI_FLAG_TIMEOUT;



void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
{
	uint16_t tmpreg = 0;

	// *---------------------------- SPIx CR1 Configuration ------------------------ *
	// * Get the SPIx CR1 value *
	tmpreg = SPIx->CR1;
	// * Clear BIDIMode, BIDIOE, RxONLY, SSM, SSI, LSBFirst, BR, MSTR, CPOL and CPHA bits *
	tmpreg &= CR1_CLEAR_MASK;

	// * Configure SPIx: direction, NSS management, first transmitted bit, BaudRate prescaler
	//	master/salve mode, CPOL and CPHA *
	// * Set BIDImode, BIDIOE and RxONLY bits according to SPI_Direction value *
	// * Set SSM, SSI and MSTR bits according to SPI_Mode and SPI_NSS values *
	// * Set LSBFirst bit according to SPI_FirstBit value *
	// * Set BR bits according to SPI_BaudRatePrescaler value *
	// * Set CPOL bit according to SPI_CPOL value *
	// * Set CPHA bit according to SPI_CPHA value *
	tmpreg |= (uint16_t)((uint32_t)SPI_InitStruct->SPI_Direction | SPI_InitStruct->SPI_Mode |
			SPI_InitStruct->SPI_DataSize | SPI_InitStruct->SPI_CPOL |  
			SPI_InitStruct->SPI_CPHA | SPI_InitStruct->SPI_NSS |  
			SPI_InitStruct->SPI_BaudRatePrescaler | SPI_InitStruct->SPI_FirstBit);

	// * Write to SPIx CR1 *
	SPIx->CR1 = tmpreg;

	// * Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) *
	SPIx->I2SCFGR &= (uint16_t)~((uint16_t)SPI_I2SCFGR_I2SMOD);
	// *---------------------------- SPIx CRCPOLY Configuration --------------------*
	// * Write to SPIx CRCPOLY *
	SPIx->CRCPR = SPI_InitStruct->SPI_CRCPolynomial;
}

void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Enable the selected SPI peripheral *
		SPIx->CR1 |= SPI_CR1_SPE;
	}
	else
	{
		// * Disable the selected SPI peripheral *
		SPIx->CR1 &= (uint16_t)~((uint16_t)SPI_CR1_SPE);
	}
}
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
	FlagStatus bitstatus = RESET;

	// * Check the status of the specified SPI flag *
	if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
	{
		// * SPI_I2S_FLAG is set *
		bitstatus = SET;
	}
	else
	{
		// * SPI_I2S_FLAG is reset *
		bitstatus = RESET;
	}
	// * Return the SPI_I2S_FLAG status *
	return  bitstatus;
}
uint32_t SPI_TIMEOUT_UserCallback(void)
{
	// * MEMS Accelerometer Timeout error occured *
	return 0;

	//while (1)
	//{   
	//}

}
void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
	// * Write in the DR register the data to be sent *
	SPIx->DR = Data;
}
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
	// * Return the data in the DR register *
	return SPIx->DR;
}




void SPI_WriteByte(SPI_TypeDef* SPIx, byte Setbyte)
{
	uint8_t ucWaste;		// Write 시에도 SPIx->DR 의 값을 Clear 해줘야 함 

	// SCK 21MHz에서 Byte사이의 시간은 155ns (while문)
	SPITimeout = SPI_FLAG_TIMEOUT;
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET)
	{
		if((SPITimeout--) == 0)
		{
			//return SPI_TIMEOUT_UserCallback();
			return;
		}
	}		

	SPIx->DR = Setbyte;

	SPITimeout = SPI_FLAG_TIMEOUT;
	while((SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET))
	{
		if((SPITimeout--) == 0)
		{
			//return SPI_TIMEOUT_UserCallback();
			return;
		}
	}

	ucWaste = SPIx->DR;
	SPITimeout = ucWaste;		// Avoid Warning
}

uint8_t SPI_ReadByte(SPI_TypeDef* SPIx)
{
	// SCK 21MHz에서 Byte사이의 시간은 155ns (while문)
	SPITimeout = SPI_FLAG_TIMEOUT;
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET)
	{
		if((SPITimeout--) == 0)
		{
			return SPI_TIMEOUT_UserCallback();
		}
	}		

	SPIx->DR = 0x00;

	SPITimeout = SPI_FLAG_TIMEOUT;		
	while((SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET))
	{
		if((SPITimeout--) == 0)
		{
			return SPI_TIMEOUT_UserCallback();
		}
	}

	//while(!(SPIx->SR & 0x0001));
	return (uint8_t)SPIx->DR;
}

void INT_SPI_InitPort(SPI_TypeDef* SPIx, uint8_t ucEnable, uint8_t ucFreqT)
{
	SPI_InitTypeDef  SPI_InitStructure;
//	SPI_GPIOInit(SelectChannel);

	// ***** SPI1
	if (ucEnable == ENABLE)
	{
		// ** SPI Peripheral
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
		// * Enable SCK, MOSI and MISO GPIO clocks *
		RCC_AHB1PeriphClockCmd(ROM_SCK_RCC_GPIO | ROM_MISO_RCC_GPIO | ROM_MOSI_RCC_GPIO, ENABLE);
		GPIO_PinAFConfig(ROM_SCK_PORT, ROM_SCK_PIN_SOURCE, GPIO_AF_SPI1);  // SCK
		GPIO_PinAFConfig(ROM_MISO_PORT, ROM_MOSI_PIN_SOURCE, GPIO_AF_SPI1);
		GPIO_PinAFConfig(ROM_MOSI_PORT, ROM_MISO_PIN_SOURCE, GPIO_AF_SPI1); // MOSI

		// * SPI MOSI pin configuration *
		GpioBPortInit(ROM_SCK_PORT, ROM_SCK_PIN, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
		GpioBPortInit(ROM_MISO_PORT, ROM_MISO_PIN, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP );
		GpioBPortInit(ROM_MOSI_PORT, ROM_MOSI_PIN, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP );
		GpioBPortInit(IO_ROM_CS_PORT, IO_ROM_CS_PIN, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP );
		GpioBPortInit(IO_TEMP_CS_PORT, IO_TEMP_CS_PIN, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP );

		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft ; // set the NSS management to internal and pull internal NSS high
		
		// Pre-Scale의 기준값은 AHB버스의 Freq임. [SPI1=APB2(84MHz)],  [SPI2=APB1(42MHz)]
		//SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;		// About 42MHz
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;		// About 21MHz
		//SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		// About 323.8KHz
		//SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;		// About 637.7KHz
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_InitStructure.SPI_CRCPolynomial = 7;
		// * Initializes the SPI communication *
		SPI_Init(SPIx, &SPI_InitStructure);
		SPI_Cmd(SPIx, ENABLE);

	}
	else
	{
		// ** GPIO
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, DISABLE);
		// * Enable SCK, MOSI and MISO GPIO clocks *
		//RCC_AHB1PeriphClockCmd(ROM_SCK_RCC_GPIO | ROM_MISO_RCC_GPIO | ROM_MOSI_RCC_GPIO, DISABLE);
		//GPIO_PinAFConfig(ROM_SCK_PORT, ROM_SCK_PIN_SOURCE, GPIO_AF_SPI1);  // SCK
		//GPIO_PinAFConfig(ROM_MISO_PORT, ROM_MOSI_PIN_SOURCE, GPIO_AF_SPI1);
		//GPIO_PinAFConfig(ROM_MOSI_PORT, ROM_MISO_PIN_SOURCE, GPIO_AF_SPI1); // MOSI

		// * SPI MOSI pin configuration *
		GpioBPortInit(ROM_SCK_PORT, ROM_SCK_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
		GpioBPortInit(ROM_MISO_PORT, ROM_MISO_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
		GpioBPortInit(ROM_MOSI_PORT, ROM_MOSI_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
		GpioBPortInit(IO_ROM_CS_PORT, IO_ROM_CS_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_UP );
		GpioBPortInit(IO_TEMP_CS_PORT, IO_TEMP_CS_PIN, GPIO_Mode_IN, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_UP );
	
		SPI_Cmd(SPIx, DISABLE);
	}

}

