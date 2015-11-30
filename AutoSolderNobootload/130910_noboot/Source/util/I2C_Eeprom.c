#include "I2c_eeprom.h"
#include "I2CDef.h"

byte received_data[2];

void AT24C64Write(byte Slave_Addr,byte Addr ,  word Data)
{
	#if 1
	if (I2C_start(I2C1 , Slave_Addr , I2C_Direction_Transmitter)>0) //;// start a transmission in Master transmitter mode
	{
			I2C_write(I2C1, Addr); 
			I2C_write(I2C1, ((Data>>8)&0xFF)); 
			I2C_write(I2C1, ((Data)&0xFF)); 
		
		  I2C_stop(I2C1); // stop the transmission		
	}
#else
	SW_i2c1_WriteByte(0xA0, 0x10, 0xEE);
	
	#endif 
}
void  AT24C64ReadW(byte Slave_Addr,byte Addr)
{

	if (I2C_start(I2C1 , Slave_Addr , I2C_Direction_Transmitter)>0) //;// start a transmission in Master transmitter mode
	{
			I2C_write(I2C1, Addr); 			
		  I2C_stop(I2C1); // stop the transmission		
	}
	I2C_start(I2C1, Slave_Addr, I2C_Direction_Receiver); // start a transmission in Master receiver mode	
	received_data[0] = I2C_read_ack(I2C1); 	// read one byte and request another byte		
	received_data[1] = I2C_read_nack(I2C1); // read one byte and don't request another byte		
	I2C_stop(I2C1); // stop the transmission

}


