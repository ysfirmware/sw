#ifndef __I2CDEF
#define __I2CDEF
#include "custmodel.h"

#ifndef I2C_SPEED
 #define I2C_SPEED                        100000
#endif /* I2C_SPEED */

// ******************************************************************************************** //
#define _EXT_I2C_ENABLE_		1
#define _EXT_I2C_DISABLE_		0


#define MAX_SWI2C_ACK_WAIT			50
#define MAX_SWI2C_Start_WAIT		255

#define I2C_WR			0
#define I2C_RD			1

#define SWI2C_ACK		0
#define SWI2C_NOACK		1
// ******************************************************************************************** //


#define I2C_IT_BUF                      ((uint16_t)0x0400)
#define I2C_IT_EVT                      ((uint16_t)0x0200)
#define I2C_IT_ERR                      ((uint16_t)0x0100)


#define I2C_Mode_I2C                    ((uint16_t)0x0000)
#define I2C_Mode_SMBusDevice            ((uint16_t)0x0002)  
#define I2C_Mode_SMBusHost              ((uint16_t)0x000A)

#define I2C_DutyCycle_16_9              ((uint16_t)0x4000) /*!< I2C fast mode Tlow/Thigh = 16/9 */
#define I2C_DutyCycle_2                 ((uint16_t)0xBFFF) /*!< I2C fast mode Tlow/Thigh = 2 */

#define I2C_Ack_Enable                  ((uint16_t)0x0400)
#define I2C_Ack_Disable                 ((uint16_t)0x0000)

#define I2C_AcknowledgedAddress_7bit    ((uint16_t)0x4000)
#define I2C_AcknowledgedAddress_10bit   ((uint16_t)0xC000)

#define I2C_FLAG_DUALF                  ((uint32_t)0x00800000)
#define I2C_FLAG_SMBHOST                ((uint32_t)0x00400000)
#define I2C_FLAG_SMBDEFAULT             ((uint32_t)0x00200000)
#define I2C_FLAG_GENCALL                ((uint32_t)0x00100000)
#define I2C_FLAG_TRA                    ((uint32_t)0x00040000)
#define I2C_FLAG_BUSY                   ((uint32_t)0x00020000)
#define I2C_FLAG_MSL                    ((uint32_t)0x00010000)

#define FLAG_MASK     ((uint8_t)0x20)
#define MAX_TIMEOUT   ((uint16_t)0xFFFF)



#define  I2C_EVENT_MASTER_MODE_SELECT                      ((uint32_t)0x00030001)  /* BUSY, MSL and SB flag */

/* --EV6 */
#define  I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED        ((uint32_t)0x00070082)  /* BUSY, MSL, ADDR, TXE and TRA flags */
#define  I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED           ((uint32_t)0x00030002)  /* BUSY, MSL and ADDR flags */
/* --EV9 */
#define  I2C_EVENT_MASTER_MODE_ADDRESS10                   ((uint32_t)0x00030008)  /* BUSY, MSL and ADD10 flags */

#define  I2C_Direction_Transmitter      ((uint8_t)0x00)
#define  I2C_Direction_Receiver         ((uint8_t)0x01)

#define  I2C_EVENT_MASTER_BYTE_RECEIVED                    ((uint32_t)0x00030040)  /* BUSY, MSL and RXNE flags */

/* Master TRANSMITTER mode --------------------------*/
/* --EV8 */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTING                 ((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */
/* --EV8_2 */
#define  I2C_EVENT_MASTER_BYTE_TRANSMITTED                 ((uint32_t)0x00070084)  /* TRA, BUSY, MSL, TXE and BTF flags */


typedef struct
{
  uint32_t I2C_ClockSpeed;          /*!< Specifies the clock frequency.
                                         This parameter must be set to a value lower than 400kHz */

  uint16_t I2C_Mode;                /*!< Specifies the I2C mode.
                                         This parameter can be a value of @ref I2C_mode */

  uint16_t I2C_DutyCycle;           /*!< Specifies the I2C fast mode duty cycle.
                                         This parameter can be a value of @ref I2C_duty_cycle_in_fast_mode */

  uint16_t I2C_OwnAddress1;         /*!< Specifies the first device own address.
                                         This parameter can be a 7-bit or 10-bit address. */

  uint16_t I2C_Ack;                 /*!< Enables or disables the acknowledgement.
                                         This parameter can be a value of @ref I2C_acknowledgement */

  uint16_t I2C_AcknowledgedAddress; /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_acknowledged_address */
}I2C_InitTypeDef;

#if 1
void Init_I2C(I2C_TypeDef* I2Cx);
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
byte I2C_start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);

byte I2C_write(I2C_TypeDef* I2Cx, uint8_t data);
byte I2C_read_ack(I2C_TypeDef* I2Cx);
uint8_t I2C_read_nack(I2C_TypeDef* I2Cx);
void I2C_stop(I2C_TypeDef* I2Cx);

void I2C_GPIO(int EnabelLavel);
	

#else 
void Init_I2C1(void);
byte SW_i2c1_WriteByte(byte Device, byte address, byte ucData);

#endif 



// ******************************************************************************************** //

//uint8_t INT_SW_i2c_WriteByte(uint8_t Device, uint8_t address, uint8_t ucData);
uint8_t INT_SW_i2c_WriteByte(uint8_t Device, word address, word ucData);
//uint8_t INT_SW_I2C_ReadBytes(uint8_t Device, uint8_t *ucData, uint8_t ucLength);
uint8_t INT_SW_I2C_ReadBytes(uint8_t Device,word address, uint8_t *ucData, uint8_t ucLength);
void INT_SW_i2c_Init(void);
//void Set_Voltage_Value(void);


#endif // I2CDEF

