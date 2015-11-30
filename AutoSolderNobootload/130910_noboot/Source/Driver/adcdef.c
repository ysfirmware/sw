#include "adcdef.h"
#include "nvimdef.h"
#include "gpiodef.h"
#include "dmadef.h"

#define ADC1_DR_ADDRESS     ((uint32_t)0x4001204C) 
//#define ADC3_DR_ADDRESS     ((uint32_t)0x4001224C) 


ADC_InitTypeDef       ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;

//__IO uint16_t ADC1ConvertedValue[ADC_CHECKNUM];
__IO uint16_t ADC1ConvertedValue;
//__IO uint32_t ADC1ConvertedVoltage = 0;



void ADCSetGPIO(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | IO_CURRENT_HEAT_RCC_PORT|IO_VMON_HEAT_RCC_PORT, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	GpioBPortInit(IO_CURRENT_HEAT_PORT,IO_CURRENT_HEAT_PIN, GPIO_Mode_AN, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
	GpioBPortInit(IO_VMON_HEAT_PORT, IO_VMON_HEAT_PIN, GPIO_Mode_AN, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );
}

void ADC_DeInit(void)
{
	// * Enable all ADCs reset state *
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC, ENABLE);

	// * Release all ADCs from reset state *
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC, DISABLE);
}


void ADC_CommonInit(ADC_CommonInitTypeDef* ADC_CommonInitStruct)
{
	uint32_t tmpreg1 = 0;

	// *---------------------------- ADC CCR Configuration -----------------*
	// * Get the ADC CCR value *
	tmpreg1 = ADC->CCR;

	// * Clear MULTI, DELAY, DMA and ADCPRE bits *
	tmpreg1 &= CR_CLEAR_MASK;

	// * Configure ADCx: Multi mode, Delay between two sampling time, ADC prescaler
	//    and DMA access mode for multimode */
	// * Set MULTI bits according to ADC_Mode value *
	// * Set ADCPRE bits according to ADC_Prescaler value *
	// * Set DMA bits according to ADC_DMAAccessMode value *
	// * Set DELAY bits according to ADC_TwoSamplingDelay value *
	tmpreg1 |= (uint32_t)(ADC_CommonInitStruct->ADC_Mode | 
				ADC_CommonInitStruct->ADC_Prescaler | 
				ADC_CommonInitStruct->ADC_DMAAccessMode | 
				ADC_CommonInitStruct->ADC_TwoSamplingDelay);
                        
	// * Write to ADC CCR *
	ADC->CCR = tmpreg1;
}
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
{
	uint32_t tmpreg1 = 0;
	uint8_t tmpreg2 = 0;

	// *---------------------------- ADCx CR1 Configuration -----------------*
	// * Get the ADCx CR1 value *
	tmpreg1 = ADCx->CR1;

	// * Clear RES and SCAN bits *
	tmpreg1 &= CR1_CLEAR_MASK;

	// * Configure ADCx: scan conversion mode and resolution *
	// * Set SCAN bit according to ADC_ScanConvMode value *
	// * Set RES bit according to ADC_Resolution value *
	tmpreg1 |= (uint32_t)(((uint32_t)ADC_InitStruct->ADC_ScanConvMode << 8) | \
				ADC_InitStruct->ADC_Resolution);
	// * Write to ADCx CR1 *
	ADCx->CR1 = tmpreg1;
	// *---------------------------- ADCx CR2 Configuration -----------------*
	// * Get the ADCx CR2 value *
	tmpreg1 = ADCx->CR2;

	// * Clear CONT, ALIGN, EXTEN and EXTSEL bits *
	tmpreg1 &= CR2_CLEAR_MASK;

	// * Configure ADCx: external trigger event and edge, data alignment and 
	//    continuous conversion mode */
	// * Set ALIGN bit according to ADC_DataAlign value *
	// * Set EXTEN bits according to ADC_ExternalTrigConvEdge value *
	// * Set EXTSEL bits according to ADC_ExternalTrigConv value *
	// * Set CONT bit according to ADC_ContinuousConvMode value *
	tmpreg1 |= (uint32_t)(ADC_InitStruct->ADC_DataAlign | \
				ADC_InitStruct->ADC_ExternalTrigConv | 
				ADC_InitStruct->ADC_ExternalTrigConvEdge | \
				((uint32_t)ADC_InitStruct->ADC_ContinuousConvMode << 1));

	// * Write to ADCx CR2 *
	ADCx->CR2 = tmpreg1;
	// *---------------------------- ADCx SQR1 Configuration -----------------*
	// * Get the ADCx SQR1 value *
	tmpreg1 = ADCx->SQR1;

	// * Clear L bits *
	tmpreg1 &= SQR1_L_RESET;

	// * Configure ADCx: regular channel sequence length *
	// * Set L bits according to ADC_NbrOfConversion value *
	tmpreg2 |= (uint8_t)(ADC_InitStruct->ADC_NbrOfConversion - (uint8_t)1);
	tmpreg1 |= ((uint32_t)tmpreg2 << 20);

	// * Write to ADCx SQR1 *
	ADCx->SQR1 = tmpreg1;
}
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime)
{
	uint32_t tmpreg1 = 0, tmpreg2 = 0;

	if (ADC_Channel > ADC_Channel_9)
	{
		// *** if ADC_Channel_10 ... ADC_Channel_18 is selected ***
		// * Get the old register value *
		tmpreg1 = ADCx->SMPR1;

		// * Calculate the mask to clear *
		tmpreg2 = SMPR1_SMP_SET << (3 * (ADC_Channel - 10));

		// * Clear the old sample time *
		tmpreg1 &= ~tmpreg2;

		// * Calculate the mask to set *
		tmpreg2 = (uint32_t)ADC_SampleTime << (3 * (ADC_Channel - 10));

		// * Set the new sample time *
		tmpreg1 |= tmpreg2;

		// * Store the new register value *
		ADCx->SMPR1 = tmpreg1;
	}
	else
	{
		// *** ADC_Channel include in ADC_Channel_[0..9] ***
		// * Get the old register value *
		tmpreg1 = ADCx->SMPR2;

		// * Calculate the mask to clear *
		tmpreg2 = SMPR2_SMP_SET << (3 * ADC_Channel);

		// * Clear the old sample time *
		tmpreg1 &= ~tmpreg2;

		// * Calculate the mask to set *
		tmpreg2 = (uint32_t)ADC_SampleTime << (3 * ADC_Channel);

		// * Set the new sample time *
		tmpreg1 |= tmpreg2;

		// * Store the new register value *
		ADCx->SMPR2 = tmpreg1;
	}

	if (Rank < 7)
	{
		// *** For Rank 1 to 6 ***
		// * Get the old register value *
		tmpreg1 = ADCx->SQR3;

		// * Calculate the mask to clear *
		tmpreg2 = SQR3_SQ_SET << (5 * (Rank - 1));

		// * Clear the old SQx bits for the selected rank *
		tmpreg1 &= ~tmpreg2;

		// * Calculate the mask to set *
		tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 1));

		// * Set the SQx bits for the selected rank *
		tmpreg1 |= tmpreg2;

		// * Store the new register value *
		ADCx->SQR3 = tmpreg1;
	}
	else if (Rank < 13)
	{
		// *** For Rank 7 to 12 ***
		// * Get the old register value *
		tmpreg1 = ADCx->SQR2;

		// * Calculate the mask to clear *
		tmpreg2 = SQR2_SQ_SET << (5 * (Rank - 7));

		// * Clear the old SQx bits for the selected rank *
		tmpreg1 &= ~tmpreg2;

		// * Calculate the mask to set *
		tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 7));

		// * Set the SQx bits for the selected rank *
		tmpreg1 |= tmpreg2;

		// * Store the new register value *
		ADCx->SQR2 = tmpreg1;
	}
	else
	{
		// *** For Rank 13 to 16 ***
		// * Get the old register value *
		tmpreg1 = ADCx->SQR1;

		// * Calculate the mask to clear *
		tmpreg2 = SQR1_SQ_SET << (5 * (Rank - 13));

		// * Clear the old SQx bits for the selected rank *
		tmpreg1 &= ~tmpreg2;

		// * Calculate the mask to set *
		tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 13));

		// * Set the SQx bits for the selected rank *
		tmpreg1 |= tmpreg2;

		// * Store the new register value *
		ADCx->SQR1 = tmpreg1;
	}
}
void ADC_DMARequestAfterLastTransferCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Enable the selected ADC DMA request after last transfer *
		ADCx->CR2 |= (uint32_t)ADC_CR2_DDS;
	}
	else
	{
		// * Disable the selected ADC DMA request after last transfer *
		ADCx->CR2 &= (uint32_t)(~ADC_CR2_DDS);
	}
}
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Enable the selected ADC DMA request *
		ADCx->CR2 |= (uint32_t)ADC_CR2_DMA;
	}
	else
	{
		// * Disable the selected ADC DMA request *
		ADCx->CR2 &= (uint32_t)(~ADC_CR2_DMA);
	}
}
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// * Set the ADON bit to wake up the ADC from power down mode *
		ADCx->CR2 |= (uint32_t)ADC_CR2_ADON;
	}
	else
	{
		// * Disable the selected ADC peripheral *
		ADCx->CR2 &= (uint32_t)(~ADC_CR2_ADON);
	}
}
void ADC_SoftwareStartConv(ADC_TypeDef* ADCx)
{
	// * Enable the selected ADC conversion for regular group *
	ADCx->CR2 |= (uint32_t)ADC_CR2_SWSTART;
}
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG)
{
	FlagStatus bitstatus = RESET;

	// * Check the status of the specified ADC flag *
	if ((ADCx->SR & ADC_FLAG) != (uint8_t)RESET)
	{
		// * ADC_FLAG is set *
		bitstatus = SET;
	}
	else
	{
		// * ADC_FLAG is reset *
		bitstatus = RESET;
	}

	// * Return the ADC_FLAG status *
	return  bitstatus;
}
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx)
{
	// * Return the selected ADC conversion value *
	return (uint16_t) ADCx->DR;
}

void ADC_CH_Change(uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADC_DEF,  ADC_Channel, 1, ADC_SampleTime_3Cycles);
	ADC_SoftwareStartConv(ADC_DEF);
}

void ADC_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;

	ADC_DeInit();
	ADCSetGPIO();

	// * DMA2 Stream0 channel0 configuration **************************************
	DMA_InitStructure.DMA_Channel = DMA_Channel_0;  
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC1ConvertedValue;
	DMA_InitStructure.DMA_BufferSize = ADC_CHECKNUM;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	//DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

	DMA_Init(DMA2_Stream0, &DMA_InitStructure);
	DMA_Cmd(DMA2_Stream0, ENABLE);

	// * ADC Common Init **********************************************************
	ADC_CommonInitStructure.ADC_Mode =  ADC_Mode_Independent ;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	//ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_1;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; 
	ADC_CommonInit(&ADC_CommonInitStructure);

	// * ADC Init ****************************************************************
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;  
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	ADC_Init(ADC_DEF, &ADC_InitStructure);

	// * ADC regular channel10 configuration *************************************
	//ADC_RegularChannelConfig(ADC_DEF,  ADC_Channel_8 | ADC_Channel_9| ADC_Channel_14 | ADC_Channel_15, 1, ADC_SampleTime_3Cycles);
	ADC_RegularChannelConfig(ADC_DEF,  ADC_Channel_14, 1, ADC_SampleTime_3Cycles);

	// * Enable DMA request after last transfer (Single-ADC mode) *
	ADC_DMARequestAfterLastTransferCmd(ADC_DEF, ENABLE);
	// * Enable ADC DMA *
	ADC_DMACmd(ADC_DEF, ENABLE); 

	// * Enable ADC *
	ADC_Cmd(ADC_DEF, ENABLE);
	ADC_SoftwareStartConv(ADC_DEF);
}




