#include "custmodel.h"
#include "gpiodef.h"

// GPIO 설정
/*
함수명 : GpioBPortInit
함수 인자 
  GPIO_TypeDef* GPIOx  : GPIO   ex) PORTA --> GPIOA, PORTB --> GPIOB
	int Portindex	: 포트 번호 (1~32)
	GPIOMode_TypeDef ModeDef  : GPIO port mode register
	GPIOSpeed_TypeDef SpeedDef  : GPIO port output speed register
	GPIOOType_TypeDef OTypedef  : GPIO port output type register
	GPIOPuPd_TypeDef PuPdDef     : GPIO port pull-up/pull-down register
	
datasheet : 148 Page참조	
*/
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
{
	uint32_t temp = 0x00;
	uint32_t temp_2 = 0x00;


	temp = ((uint32_t)(GPIO_AF) << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4)) ;
	GPIOx->AFR[GPIO_PinSource >> 0x03] &= ~((uint32_t)0xF << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4)) ;
	temp_2 = GPIOx->AFR[GPIO_PinSource >> 0x03] | temp;
	GPIOx->AFR[GPIO_PinSource >> 0x03] = temp_2;
}


void GpioBPortInit(GPIO_TypeDef* GPIOx,int Portindex,GPIOMode_TypeDef ModeDef, GPIOSpeed_TypeDef SpeedDef,GPIOOType_TypeDef OTypedef,GPIOPuPd_TypeDef PuPdDef )
{
	// GPIO port mode register	
	GPIOx->MODER  &= ~(GPIO_MODER_MODER0 << (Portindex * 2));
	GPIOx->MODER |= (((uint32_t)ModeDef) << (Portindex * 2));

	if ( ModeDef == GPIO_Mode_OUT || ModeDef == GPIO_Mode_AF)
	{
		GPIOx->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (Portindex * 2));
		GPIOx->OSPEEDR |= ((uint32_t)(SpeedDef) << (Portindex * 2));

		GPIOx->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)Portindex)) ;
		GPIOx->OTYPER |= (uint16_t)(((uint16_t)OTypedef) << ((uint16_t)Portindex));
	}
	GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)Portindex * 2));
	GPIOx->PUPDR |= (((uint32_t)PuPdDef) << (Portindex * 2));
}

uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;


	if (((GPIOx->IDR>>GPIO_Pin) & 0x01 ) != (uint32_t)Bit_RESET)
	{
		bitstatus = (uint8_t)Bit_SET;
	}
	else
	{
		bitstatus = (uint8_t)Bit_RESET;
	}
	return bitstatus;
}




