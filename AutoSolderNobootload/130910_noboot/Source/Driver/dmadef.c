#include "dmadef.h"

void DMA_Init(DMA_Stream_TypeDef* DMAy_Streamx, DMA_InitTypeDef* DMA_InitStruct)
{
	uint32_t tmpreg = 0;

	// *------------------------- DMAy Streamx CR Configuration ------------------*
	// * Get the DMAy_Streamx CR value *
	tmpreg = DMAy_Streamx->CR;

	// * Clear CHSEL, MBURST, PBURST, PL, MSIZE, PSIZE, MINC, PINC, CIRC and DIR bits *
	tmpreg &= ((uint32_t)~(DMA_SxCR_CHSEL | DMA_SxCR_MBURST | DMA_SxCR_PBURST | \
			DMA_SxCR_PL | DMA_SxCR_MSIZE | DMA_SxCR_PSIZE | \
			DMA_SxCR_MINC | DMA_SxCR_PINC | DMA_SxCR_CIRC | \
			DMA_SxCR_DIR));

	// * Configure DMAy Streamx: *
	// * Set CHSEL bits according to DMA_CHSEL value *
	// * Set DIR bits according to DMA_DIR value *
	// * Set PINC bit according to DMA_PeripheralInc value *
	// * Set MINC bit according to DMA_MemoryInc value *
	// * Set PSIZE bits according to DMA_PeripheralDataSize value *
	// * Set MSIZE bits according to DMA_MemoryDataSize value *
	// * Set CIRC bit according to DMA_Mode value *
	// * Set PL bits according to DMA_Priority value *
	// * Set MBURST bits according to DMA_MemoryBurst value *
	// * Set PBURST bits according to DMA_PeripheralBurst value *
	tmpreg |= DMA_InitStruct->DMA_Channel | DMA_InitStruct->DMA_DIR |
		DMA_InitStruct->DMA_PeripheralInc | DMA_InitStruct->DMA_MemoryInc |
		DMA_InitStruct->DMA_PeripheralDataSize | DMA_InitStruct->DMA_MemoryDataSize |
		DMA_InitStruct->DMA_Mode | DMA_InitStruct->DMA_Priority |
		DMA_InitStruct->DMA_MemoryBurst | DMA_InitStruct->DMA_PeripheralBurst;

	// * Write to DMAy Streamx CR register */
	DMAy_Streamx->CR = tmpreg;

	// * ------------------------- DMAy Streamx FCR Configuration -----------------*
	// * Get the DMAy_Streamx FCR value *
	tmpreg = DMAy_Streamx->FCR;

	// * Clear DMDIS and FTH bits *
	tmpreg &= (uint32_t)~(DMA_SxFCR_DMDIS | DMA_SxFCR_FTH);

	// * Configure DMAy Streamx FIFO: 
	//    Set DMDIS bits according to DMA_FIFOMode value 
	//    Set FTH bits according to DMA_FIFOThreshold value *
	tmpreg |= DMA_InitStruct->DMA_FIFOMode | DMA_InitStruct->DMA_FIFOThreshold;

	// * Write to DMAy Streamx CR *
	DMAy_Streamx->FCR = tmpreg;

	// * ------------------------- DMAy Streamx NDTR Configuration ----------------*
	// * Write to DMAy Streamx NDTR register *
	DMAy_Streamx->NDTR = DMA_InitStruct->DMA_BufferSize;

	// * ------------------------- DMAy Streamx PAR Configuration -----------------*
	// * Write to DMAy Streamx PAR *
	DMAy_Streamx->PAR = DMA_InitStruct->DMA_PeripheralBaseAddr;

	// *------------------------- DMAy Streamx M0AR Configuration ----------------*
	// * Write to DMAy Streamx M0AR */
	DMAy_Streamx->M0AR = DMA_InitStruct->DMA_Memory0BaseAddr;
}
void DMA_Cmd(DMA_Stream_TypeDef* DMAy_Streamx, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		// Enable the selected DMAy Streamx by setting EN bit *
		DMAy_Streamx->CR |= (uint32_t)DMA_SxCR_EN;
	}
	else
	{
		// Disable the selected DMAy Streamx by clearing EN bit *
		DMAy_Streamx->CR &= ~(uint32_t)DMA_SxCR_EN;
	}
}

