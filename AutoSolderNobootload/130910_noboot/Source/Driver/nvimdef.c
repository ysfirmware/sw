#include "nvimdef.h"

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __I uint8_t APBAHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)


//void InitInterrupt(uint8_t IRQchanel, int group)
void InitInterrupt(uint8_t IRQchanel, int group, uint8_t Priority)
{
	/* Enable the TIM3 gloabal Interrupt */

	NVIC_InitTypeDef NVIC_InitStructure;
	//Enable the TIM2 gloabal Interrupt 

	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitStructure.NVIC_IRQChannel = IRQchanel;
	//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = Priority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
	NVIC_Init(&NVIC_InitStructure);
}

void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
{
	uint8_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;

	if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
	{
		// * Compute the Corresponding IRQ Priority --------------------------------*
		tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
		tmppre = (0x4 - tmppriority);
		tmpsub = tmpsub >> tmppriority;

		tmppriority = NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
		tmppriority |=  (uint8_t)(NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub);

		tmppriority = tmppriority << 0x04;

		NVIC->IP[NVIC_InitStruct->NVIC_IRQChannel] = tmppriority;

		// * Enable the Selected IRQ Channels --------------------------------------*
		NVIC->ISER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
			(uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
	}
	else
	{
		// * Disable the Selected IRQ Channels -------------------------------------*
		NVIC->ICER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
			(uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
	}
}

/**
  * @brief  Returns the frequencies of different on chip clocks; SYSCLK, HCLK, 
  *         PCLK1 and PCLK2.       
  * 
  * @note   The system frequency computed by this function is not the real 
  *         frequency in the chip. It is calculated based on the predefined 
  *         constant and the selected clock source:
  * @note     If SYSCLK source is HSI, function returns values based on HSI_VALUE(*)
  * @note     If SYSCLK source is HSE, function returns values based on HSE_VALUE(**)
  * @note     If SYSCLK source is PLL, function returns values based on HSE_VALUE(**) 
  *           or HSI_VALUE(*) multiplied/divided by the PLL factors.         
  * @note     (*) HSI_VALUE is a constant defined in stm32f4xx.h file (default value
  *               16 MHz) but the real value may vary depending on the variations
  *               in voltage and temperature.
  * @note     (**) HSE_VALUE is a constant defined in stm32f4xx.h file (default value
  *                25 MHz), user has to ensure that HSE_VALUE is same as the real
  *                frequency of the crystal used. Otherwise, this function may
  *                have wrong result.
  *                
  * @note   The result of this function could be not correct when using fractional
  *         value for HSE crystal.
  *   
  * @param  RCC_Clocks: pointer to a RCC_ClocksTypeDef structure which will hold
  *          the clocks frequencies.
  *     
  * @note   This function can be used by the user application to compute the 
  *         baudrate for the communication peripherals or configure other parameters.
  * @note   Each time SYSCLK, HCLK, PCLK1 and/or PCLK2 clock changes, this function
  *         must be called to update the structure's field. Otherwise, any
  *         configuration based on this function will be incorrect.
  *    
  * @retval None
  */

/*
void RCC_MCO1Config(uint32_t RCC_MCO1Source, uint32_t RCC_MCO1Div)
{
  uint32_t tmpreg = 0;
  
  // * Check the parameters *
  assert_param(IS_RCC_MCO1SOURCE(RCC_MCO1Source));
  assert_param(IS_RCC_MCO1DIV(RCC_MCO1Div));  

  tmpreg = RCC->CFGR;

  // * Clear MCO1[1:0] and MCO1PRE[2:0] bits *
  tmpreg &= CFGR_MCO1_RESET_MASK;

  // * Select MCO1 clock source and prescaler *
  tmpreg |= RCC_MCO1Source | RCC_MCO1Div;

  // * Store the new value *
  RCC->CFGR = tmpreg;  
}
*/

void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->APB2RSTR |= RCC_APB2Periph;
	}
	else
	{
		RCC->APB2RSTR &= ~RCC_APB2Periph;
	}
}


void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->APB1ENR |= RCC_APB1Periph;
	}
	else
	{
		RCC->APB1ENR &= ~RCC_APB1Periph;
	}
}
void RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->AHB1ENR |= RCC_AHB1Periph;
	}
	else
	{
		RCC->AHB1ENR &= ~RCC_AHB1Periph;
	}
}

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->APB2ENR |= RCC_APB2Periph;
	}
	else
	{
		RCC->APB2ENR &= ~RCC_APB2Periph;
	}
}

void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->APB1RSTR |= RCC_APB1Periph;
	}
	else
	{
		RCC->APB1RSTR &= ~RCC_APB1Periph;
	}
}



/**
  * @brief  Forces or releases AHB1 peripheral reset.
  * @param  RCC_AHB1Periph: specifies the AHB1 peripheral to reset.
  *          This parameter can be any combination of the following values:
  *            @arg RCC_AHB1Periph_GPIOA:   GPIOA clock
  *            @arg RCC_AHB1Periph_GPIOB:   GPIOB clock 
  *            @arg RCC_AHB1Periph_GPIOC:   GPIOC clock
  *            @arg RCC_AHB1Periph_GPIOD:   GPIOD clock
  *            @arg RCC_AHB1Periph_GPIOE:   GPIOE clock
  *            @arg RCC_AHB1Periph_GPIOF:   GPIOF clock
  *            @arg RCC_AHB1Periph_GPIOG:   GPIOG clock
  *            @arg RCC_AHB1Periph_GPIOG:   GPIOG clock
  *            @arg RCC_AHB1Periph_GPIOI:   GPIOI clock
  *            @arg RCC_AHB1Periph_CRC:     CRC clock
  *            @arg RCC_AHB1Periph_DMA1:    DMA1 clock
  *            @arg RCC_AHB1Periph_DMA2:    DMA2 clock
  *            @arg RCC_AHB1Periph_ETH_MAC: Ethernet MAC clock
  *            @arg RCC_AHB1Periph_OTG_HS:  USB OTG HS clock
  *                  
  * @param  NewState: new state of the specified peripheral reset.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RCC_AHB1PeriphResetCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		RCC->AHB1RSTR |= RCC_AHB1Periph;
	}
	else
	{
		RCC->AHB1RSTR &= ~RCC_AHB1Periph;
	}
}



void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks)
{
	uint32_t tmp = 0, presc = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;

	// * Get SYSCLK source -------------------------------------------------------*
	tmp = RCC->CFGR & RCC_CFGR_SWS;

	switch (tmp)
	{
		case 0x00:  // * HSI used as system clock source *
			RCC_Clocks->SYSCLK_Frequency = HSI_VALUE;
			break;
		case 0x04:  // * HSE used as system clock  source *
			RCC_Clocks->SYSCLK_Frequency = HSE_VALUE;
			break;
		case 0x08:  // * PLL used as system clock  source *

			// * PLL_VCO = (HSE_VALUE or HSI_VALUE / PLLM) * PLLN
			// SYSCLK = PLL_VCO / PLLP
			// */    
			pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
			pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

			if (pllsource != 0)
			{
				// * HSE used as PLL clock source *
				pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
			}
			else
			{
				// * HSI used as PLL clock source *
				pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);      
			}

			pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
			RCC_Clocks->SYSCLK_Frequency = pllvco/pllp;
			break;
		default:
			RCC_Clocks->SYSCLK_Frequency = HSI_VALUE;
			break;
	}
	/* Compute HCLK, PCLK1 and PCLK2 clocks frequencies ------------------------*/

	// * Get HCLK prescaler *
	tmp = RCC->CFGR & RCC_CFGR_HPRE;
	tmp = tmp >> 4;
	presc = APBAHBPrescTable[tmp];
	// * HCLK clock frequency *
	RCC_Clocks->HCLK_Frequency = RCC_Clocks->SYSCLK_Frequency >> presc;

	// * Get PCLK1 prescaler *
	tmp = RCC->CFGR & RCC_CFGR_PPRE1;
	tmp = tmp >> 10;
	presc = APBAHBPrescTable[tmp];
	// * PCLK1 clock frequency *
	RCC_Clocks->PCLK1_Frequency = RCC_Clocks->HCLK_Frequency >> presc;

	// * Get PCLK2 prescaler *
	tmp = RCC->CFGR & RCC_CFGR_PPRE2;
	tmp = tmp >> 13;
	presc = APBAHBPrescTable[tmp];
	// * PCLK2 clock frequency *
	RCC_Clocks->PCLK2_Frequency = RCC_Clocks->HCLK_Frequency >> presc;
}
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup)
{

	// * Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value *
	SCB->AIRCR = AIRCR_VECTKEY_MASK | NVIC_PriorityGroup;
}





