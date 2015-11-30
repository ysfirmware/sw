#ifndef __SPIDEF
#define __SPIDEF
#include "custmodel.h"

typedef struct
{
  uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_data_direction */

  uint16_t SPI_Mode;                /*!< Specifies the SPI operating mode.
                                         This parameter can be a value of @ref SPI_mode */

  uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
                                         This parameter can be a value of @ref SPI_data_size */

  uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_Clock_Polarity */

  uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_Clock_Phase */

  uint16_t SPI_NSS;                 /*!< Specifies whether the NSS signal is managed by
                                         hardware (NSS pin) or by software using the SSI bit.
                                         This parameter can be a value of @ref SPI_Slave_Select_management */
 
  uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                         used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of @ref SPI_BaudRate_Prescaler
                                         @note The communication clock is derived from the master
                                               clock. The slave clock does not need to be set. */

  uint16_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint16_t SPI_CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
}SPI_InitTypeDef;


#define GPIO_AF_SPI1          ((uint8_t)0x05)  /* SPI1 Alternate Function mapping */
#define GPIO_AF_SPI2          ((uint8_t)0x05)  /* SPI2/I2S2 Alternate Function mapping */

#define SPI_Direction_2Lines_FullDuplex ((uint16_t)0x0000)
#define SPI_Direction_2Lines_RxOnly     ((uint16_t)0x0400)
#define SPI_Direction_1Line_Rx          ((uint16_t)0x8000)
#define SPI_Direction_1Line_Tx          ((uint16_t)0xC000)

#define SPI_DataSize_16b                ((uint16_t)0x0800)
#define SPI_DataSize_8b                 ((uint16_t)0x0000)

#define SPI_CPOL_Low                    ((uint16_t)0x0000)
#define SPI_CPOL_High                   ((uint16_t)0x0002)

#define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
#define SPI_CPHA_2Edge                  ((uint16_t)0x0001)

#define SPI_NSS_Soft                    ((uint16_t)0x0200)
#define SPI_NSS_Hard                    ((uint16_t)0x0000)

#define SPI_BaudRatePrescaler_2         ((uint16_t)0x0000)
#define SPI_BaudRatePrescaler_4         ((uint16_t)0x0008)
#define SPI_BaudRatePrescaler_8         ((uint16_t)0x0010)
#define SPI_BaudRatePrescaler_16        ((uint16_t)0x0018)
#define SPI_BaudRatePrescaler_32        ((uint16_t)0x0020)
#define SPI_BaudRatePrescaler_64        ((uint16_t)0x0028)
#define SPI_BaudRatePrescaler_128       ((uint16_t)0x0030)
#define SPI_BaudRatePrescaler_256       ((uint16_t)0x0038)

#define SPI_FirstBit_MSB                ((uint16_t)0x0000)
#define SPI_FirstBit_LSB                ((uint16_t)0x0080)

#define SPI_Mode_Master                 ((uint16_t)0x0104)
#define SPI_Mode_Slave                  ((uint16_t)0x0000)

#define  SPI_I2SCFGR_I2SE                    ((uint16_t)0x0400)            /*!<I2S Enable */
#define  SPI_I2SCFGR_I2SMOD                  ((uint16_t)0x0800)            /*!<I2S mode selection */

#define  SPI_CR1_SPE                         ((uint16_t)0x0040)            /*!<SPI Enable */
#define  SPI_CR1_LSBFIRST                    ((uint16_t)0x0080)            /*!<Frame Format */
#define  SPI_CR1_SSI                         ((uint16_t)0x0100)            /*!<Internal slave select */
#define  SPI_CR1_SSM                         ((uint16_t)0x0200)            /*!<Software slave management */
#define  SPI_CR1_RXONLY                      ((uint16_t)0x0400)            /*!<Receive only */
#define  SPI_CR1_DFF                         ((uint16_t)0x0800)            /*!<Data Frame Format */
#define  SPI_CR1_CRCNEXT                     ((uint16_t)0x1000)            /*!<Transmit CRC next */
#define  SPI_CR1_CRCEN                       ((uint16_t)0x2000)            /*!<Hardware CRC calculation enable */
#define  SPI_CR1_BIDIOE                      ((uint16_t)0x4000)            /*!<Output enable in bidirectional mode */
#define  SPI_CR1_BIDIMODE                    ((uint16_t)0x8000)            /*!<Bidirectional data mode enable */

#define SPI_I2S_FLAG_RXNE               ((uint16_t)0x0001)
#define SPI_I2S_FLAG_TXE                ((uint16_t)0x0002)
#define I2S_FLAG_CHSIDE                 ((uint16_t)0x0004)
#define I2S_FLAG_UDR                    ((uint16_t)0x0008)
#define SPI_FLAG_CRCERR                 ((uint16_t)0x0010)
#define SPI_FLAG_MODF                   ((uint16_t)0x0020)
#define SPI_I2S_FLAG_OVR                ((uint16_t)0x0040)
#define SPI_I2S_FLAG_BSY                ((uint16_t)0x0080)
#define SPI_I2S_FLAG_TIFRFE             ((uint16_t)0x0100)


/****************************************************/
// ROM_SPI
#define _SPI_FREQ_DontCare_			0		// 
#define _SPI2_FREQ_21MHz_			1
#define _SPI2_FREQ_10_5MHz_			2
#define _SPI2_FREQ_5_25MHz_			3
#define _SPI2_FREQ_2_625MHz_		4
#define _SPI2_FREQ_LOW_				5		// 1.3MHz를 최소로 설정
/****************************************************/


//#define SPI_FLAG_TIMEOUT         6 //((uint32_t)0x1000)
#define SPI_FLAG_TIMEOUT         ((uint32_t)0x1000)

//void SPI_InitPort(SPI_TypeDef* SPIx);
//void SPI_InitPort(SPI_TypeDef* SPIx, uint8_t ucEnable, uint8_t ucFreqT);
void INT_SPI_InitPort(SPI_TypeDef* SPIx, uint8_t ucEnable, uint8_t ucFreqT);


//byte SPI_WriteReadByte(SPI_TypeDef* SPIx, byte *Data,byte *readSPI);
void SPI_WriteByte(SPI_TypeDef* SPIx,byte  Setbyte);
uint8_t SPI_ReadByte(SPI_TypeDef* SPIx);
//byte SPI_Restart(SPI_TypeDef* SPIx);

#endif // __SPIDEF

