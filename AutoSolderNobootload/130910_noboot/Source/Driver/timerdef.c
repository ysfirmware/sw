#include "custmodel.h"
#include <stdint.h>
#include "timerdef.h"
#include "schedule.h"
#include "nvimdef.h"

#include "gpiodef.h"		// TIMER Test ¿ë


#define __XTAL				(25000000UL)    // * Oscillator frequency             *

//#define __SYSTEM_CLOCK    (4*__XTAL)
#define __SYSTEM_CLOCK		(168000000UL)	// * System CLOCK = After PLL

// ** 100usec
#define _CLOCK_Prescale_		84 - 1
#define _Period_Of_100usec_		100 - 1


//#define TIM_ARR                (15*1)-1 //        (5*1) - 1 //  (uint16_t)1999
//#define TIM_CCR                          ((uint16_t)1000)

//void TimerInit(uint16_t numOfMilleseconds)
void TimerInit(void)
{	
	////////////////////////////////////////////
	// Timer 2
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	// * TIM2 clock enable *
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	// * Time base configuration *
	
	//TIM_TimeBaseStructure.TIM_Period = _Period_Of_100usec_ - 1; // 1 MHz down to 1 KHz (1 ms)
	TIM_TimeBaseStructure.TIM_Period = _Period_Of_100usec_; // 1 MHz down to 1 KHz (1 ms)
	//TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1; // 24 MHz Clock down to 1 MHz (adjust per your clock)
	//TIM_TimeBaseStructure.TIM_Prescaler = 106-1; //168MHz Clock should be down to 1MHz
	TIM_TimeBaseStructure.TIM_Prescaler = _CLOCK_Prescale_; //168MHz Clock should be down to 1MHz 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	// * TIM IT enable *
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

	// * TIM2 enable counter *
	//TIM_Cmd(TIM2, DISABLE);


	////////////////////////////////////////////
	// Timer 3

	// * TIM3 clock enable *
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// * Time base configuration *
	//TIM_TimeBaseStructure.TIM_Period = _Period_Of_100usec_ - 1; // 1 MHz down to 1 KHz (1 ms)
	TIM_TimeBaseStructure.TIM_Period = _Period_Of_100usec_; // 1 MHz down to 1 KHz (1 ms)
	//TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1; // 24 MHz Clock down to 1 MHz (adjust per your clock)
	//TIM_TimeBaseStructure.TIM_Prescaler = 106-1; //168MHz Clock should be down to 1MHz
	TIM_TimeBaseStructure.TIM_Prescaler = _CLOCK_Prescale_; //168MHz Clock should be down to 1MHz 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	// * TIM IT enable *
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	// * TIM3 enable counter *
	TIM_Cmd(TIM3, ENABLE);
 	

}



void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
	uint16_t tmpcr1 = 0;

	tmpcr1 = TIMx->CR1;  

	if((TIMx == TIM1) || (TIMx == TIM8)||
		(TIMx == TIM2) || (TIMx == TIM3)||
		(TIMx == TIM4) || (TIMx == TIM5)) 
	{
		// * Select the Counter Mode *
		tmpcr1 &= (uint16_t)(~(TIM_CR1_DIR | TIM_CR1_CMS));
		tmpcr1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_CounterMode;
	}

	if((TIMx != TIM6) && (TIMx != TIM7))
	{
		// * Set the clock division *
		tmpcr1 &=  (uint16_t)(~TIM_CR1_CKD);
		tmpcr1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_ClockDivision;
	}

	TIMx->CR1 = tmpcr1;

	// * Set the Autoreload value *
	TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period ;

	// * Set the Prescaler value *
	TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;

	if ((TIMx == TIM1) || (TIMx == TIM8))  
	{
		// * Set the Repetition Counter value *
		TIMx->RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;
	}

	// * Generate an update event to reload the Prescaler 
	//    and the repetition counter(only for TIM1 and TIM8) value immediatly *
	TIMx->EGR = TIM_PSCReloadMode_Immediate;          
}

void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT)
{
	// * Clear the IT pending Bit *
	TIMx->SR = (uint16_t)~TIM_IT;
}
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
{  
	if (NewState != DISABLE)
	{
		/* Enable the Interrupt sources */
		TIMx->DIER |= TIM_IT;
	}
	else
	{
		/* Disable the Interrupt sources */
		TIMx->DIER &= (uint16_t)~TIM_IT;
	}
}
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		/* Enable the TIM Counter */
		TIMx->CR1 |= TIM_CR1_CEN;
	}
	else
	{
		/* Disable the TIM Counter */
		TIMx->CR1 &= (uint16_t)~TIM_CR1_CEN;
	}
}

ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT)
{
	ITStatus bitstatus = RESET;  
	uint16_t itstatus = 0x0, itenable = 0x0;

	itstatus = TIMx->SR & TIM_IT;

	itenable = TIMx->DIER & TIM_IT;
	if ((itstatus != (uint16_t)RESET) && (itenable != (uint16_t)RESET))
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
}


uint32_t TIM_GetCapture1(TIM_TypeDef* TIMx)
{
	/* Get the Capture 1 Register value */
	return TIMx->CCR1;
}
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint32_t Compare1)
{

	/* Set the Capture Compare1 Register value */
	TIMx->CCR1 = Compare1;
}
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint32_t Autoreload)
{

	/* Set the Autoreload Register value */
	TIMx->ARR = Autoreload;
}

// Time2 Handler
// DoEvery OVF
uint16_t capture = 0;
__IO uint16_t CCR_Val = 333;//16826;

//uint16_t Timer_Test;		// TIMER Test ¿ë


void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
	
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		Time3Fun();

		capture = TIM_GetCapture1(TIM2);
		TIM_SetCompare1(TIM2,  10);
		TIM_SetAutoreload(TIM2,  200);
		
	
	}
}

void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		
	/*
		if (Timer_Test ==1)
			Timer_Test = 0 ;
		else
			Timer_Test = 1 ;		
		SetIO(SYSLED_PORT,SYSLED_PIN,Timer_Test);
	*/
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		
		Time2Fun();

		capture = TIM_GetCapture1(TIM3);
		//TIM_SetCompare1(TIM2,  TIM_CCR/12);
		TIM_SetCompare1(TIM3,  10);
		//TIM_SetAutoreload(TIM2,  TIM_ARR);
		TIM_SetAutoreload(TIM3,  _Period_Of_100usec_);
	

		
	}
}



