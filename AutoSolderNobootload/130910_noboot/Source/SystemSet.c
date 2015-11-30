#include "custmodel.h"
//#include "stm32f4_discovery.h"
#include "gpiodef.h"
#include "timerdef.h"
// System ����
#include "stm32f4xx.h"



/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to use external SRAM mounted
     on STM324xG_EVAL board as data memory  */
/* #define DATA_IN_ExtSRAM */

/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field.  This value must be a multiple of 0x200. */  // boot loader No test
//#define VECT_TAB_OFFSET  0x4000 /*!< Vector Table base offset field.  This value must be a multiple of 0x200. */  // boot loader use

/******************************************************************************/

/************************* PLL Parameters *************************************/
/* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N */
#define PLL_M      25
#define PLL_N      336

/* SYSCLK = PLL_VCO / PLL_P */
#define PLL_P      2

/* USB OTG FS, SDIO and RNG Clock =  PLL_VCO / PLLQ */
#define PLL_Q      7

/******************************************************************************/

static void SetSysClock(void);


void SystemInit(void)
{
	//RCC->AHB1ENR |= RCC_AHB1Periph_GPIOB;

	//GpioBPortInit(GPIOB,9,GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL );

	//TimerInit(1);

	// * FPU settings ------------------------------------------------------------*
//#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
	SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));	// set CP10 and CP11 Full Access 
//#endif

	// * Reset the RCC clock configuration to the default reset state ------------*
	// * Set HSION bit *
	RCC->CR |= (uint32_t)0x00000001;
	
	// * Reset CFGR register *
	RCC->CFGR = 0x00000000;
	
	// * Reset HSEON, CSSON and PLLON bits *
	RCC->CR &= (uint32_t)0xFEF6FFFF;
	
	// * Reset PLLCFGR register *
	RCC->PLLCFGR = 0x24003010;
	
	// * Reset HSEBYP bit *
	RCC->CR &= (uint32_t)0xFFFBFFFF;
	
	// * Disable all interrupts *
	RCC->CIR = 0x00000000;

	// * Configure the System clock source, PLL Multiplier and Divider factors, 
	//    AHB/APBx prescalers and Flash settings ----------------------------------*
	SetSysClock();

	// * Configure the Vector Table location add offset address ------------------*
	SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */

}

static void SetSysClock(void)
{
	// ******************************************************************************
	// *			  PLL (clocked by HSE) used as System clock source				  *
	// ******************************************************************************
	  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

	/* Enable HSE */
	RCC->CR |= ((uint32_t)RCC_CR_HSEON);

	// * Wait till HSE is ready and if Time out is reached exit *
	do
	{
		HSEStatus = RCC->CR & RCC_CR_HSERDY;
		StartUpCounter++;
	} while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

	if ((RCC->CR & RCC_CR_HSERDY) != RESET)
	{
		HSEStatus = (uint32_t)0x01;
	}
	else
	{
		HSEStatus = (uint32_t)0x00;
	}

	if (HSEStatus == (uint32_t)0x01)
	{
		// * Select regulator voltage output Scale 1 mode, System frequency up to 168 MHz *
		RCC->APB1ENR |= RCC_APB1ENR_PWREN;
		PWR->CR |= PWR_CR_VOS;

		// * HCLK = SYSCLK / 1*
		RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

		// * PCLK2 = HCLK / 2*
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;

		// * PCLK1 = HCLK / 4*
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

		// * Configure the main PLL *
		RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
		 (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);

		// * Enable the main PLL *
		RCC->CR |= RCC_CR_PLLON;

		// * Wait till the main PLL is ready *
		while((RCC->CR & RCC_CR_PLLRDY) == 0)
		{
		}

		// * Configure Flash prefetch, Instruction cache, Data cache and wait state *
		FLASH->ACR = FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

		// * Select the main PLL as system clock source *
		RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
		RCC->CFGR |= RCC_CFGR_SW_PLL;

		// * Wait till the main PLL is used as system clock source *
		while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
		{
		}
	}
	else
	{
		// * If HSE fails to start-up, the application will have wrong clock
		//    configuration. User can add here some code to deal with this error *
	}

}


