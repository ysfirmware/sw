#ifndef __SERIAL_FLASH
#define __SERIAL_FLASH
#include "custmodel.h"

#define _INT_FLASH_CS_OFF_		0
#define _INT_FLASH_CS_ON_		1

/**************************************************/
// ***************** INT FLASH CMD *****************
#define _FCMD_EQIO_				0x38		// Enable QUAD
#define _FCMD_RST_QIO_			0xFF		// Reset QUAD

#define _FCMD_WR_RST_EN_		0x99		// Reset Enable
#define _FCMD_WR_RST_			0x66		// Reset

#define _FCMD_WR_Eable_			0x06		// Write Enable
#define _FCMD_WR_Disable_		0x04		// Write Disable

#define _FCMD_WR_Status_		0x01		// Write Status
#define _FCMD_RD_Stuatus_		0x05		// Read Status

#define _FCMD_RD_JEDEC_ID_		0x9F		// Read ID

#define _FCMD_READ_				0x03		// Read Data
#define _FCMD_FAST_READ_		0x0B		// Fast Read Data

//#define _FCMD_RES			0xAB		// Read Electronic ID
//#define _FCMD_REMS			0x90		// Read Electronic Manufacture & ID
//#define _FCMD_DREAD		0x3B		// Double Output Mode CMD

#define _FCMD_Page_Prog_		0x02		// Page Program  -- Typ.=[1.3ms], MAX=[5ms]

#define _FCMD_Sector_Erase_		0x20		// Sector Erase (4KB) -- Typ.=[0.06s], MAX=[0.3s]
#define _FCMD_Block_Erase_		0xD8		// Block Erase (64KB) -- Typ.=[0.3s], MAX=[2s]
#define _FCMD_Chip_Erase_		0x60		// Chip Erase [0x60 or C7] -- Typ.=[30s], MAX=[50s]

//#define _FCMD_RDSCUR		0x2B		// Read Security Register
//#define _FCMD_WRSCUR		0x2F		// Write Security Register
//#define _FCMD_ENSO			0xB1		// Enter Security OTP
//#define _FCMD_EXSO			0xC1		// Exit Security OTP
//#define _FCMD_DP			0xB9		// Deep Power Down
//#define _FCMD_RDP			0xAB		// Release from Deep Power Down

// Read Status Register Bit Position
#define _F_SRWD_SRP_			0x80		// [Status Register Protect]"1":Protect, [OPT Sector or Status Register Protect]"1":Protect
#define _F_SRWD_WP_Diable_		0x40		// [/WP Pin Disble] "1":Disable, "0":Enable
#define _F_SRWD_BP3_			0x20		// [Block Protect]
#define _F_SRWD_BP2_			0x10		// [Block Protect]
#define _F_SRWD_BP1_			0x08		// [Block Protect]
#define _F_SRWD_BP0_			0x04		// [Block Protect]
#define _F_SRWD_WEL				0x02		// [Write Enable] "1":Enable, "0":Disable
#define _F_SRWD_WIP				0x01		// [Write In Progress] "1": BUSY, "0":Idle

/**************************************************/
#define JIG_SPI_CS_OFF		0
#define JIG_SPI_CS_ON		1

// *** Command for Flash Memory (VICTIM)
#define JIG_Read				0x03		// ~25MHz
#define JIG_HS_Read				0x0B		// High speed read 50/66MHz, 80MHz

#define JIG_4KSec_Erase			0x20		// 4KByte Sector Erase		Typ. = Winbond[30~400ms], FIDELIX[40~200ms]
#define JIG_32KBlk_Erase		0x52		// 32KByte Block Erase		Typ. = Winbond[120~800ms], FIDELIX[200~1000ms]
#define JIG_64KBlk_Erase		0xD8		// 64KByte Block Erase		Typ. = Winbond[150~1000ms], FIDELIX[300~1500ms]
#define JIG_Chip_Erase			0x60		// Chip erase				Typ. = Winbond[??s], FIDELIX[10~50s]
//#define bin_Chip_Erase_WB		0xC7		// Chip erase				Typ. = Winbond[??s]

#define JIG_Byte_Prog			0x02		// To Program One Data Byte				Typ. = Winbond[0.4~0.8ms], FIDELIX[1.5~5ms]
//#define bin_Word_Prog			0xAD		// Auto Address Increment Programming

#define JIG_Read_Status1		0x05		// Read Status Register [b07:b00]
#define JIG_Read_Status2		0x35		// Read Status Register [b15:b08]

//#define bin_Status_Write		0x50		// Enable Write Status Register
#define JIG_Write_Status		0x01		// Write Status Register
#define JIG_Module_WE			0x06		// Write Enable
#define JIG_Module_WE_VSR		0x50		// Write Enable Volatile Status Register
#define JIG_Module_WD			0x04		// Write Disable
#define JIG_Manufacture_ID		0x90		// Read Manufacture ID
#define JIG_JEDEC_ID			0x9F		// Read JEDEC ID
#define JIG_Release_ID			0xAB		// 

#define JIG_ERASE_Security		0x44		// 
#define JIG_PROG_Security		0x42		// 

#define JIG_ERnPRG_Suspend		0x75		// 
#define JIG_ERnPRG_Resume		0x7A		// 


//#define JIG_Enable_RYDY			0x70		// Enable SO to Output RY/BY Status during AAI Programming
//#define JIG_Disable_RYDY		0x80		// Disable SO to Output RY/BY Status during AAI Programming
// ***

//		Module Register Bit
#define _JIG_SRWD_WIP			0x01
#define _JIG_SRWD_WEL			0x02


//#define _FMX25L32_MAX_Addr		0x3FFFFF
#define _FData_Page				256
#define _FData_HalfPage			128

 // *************************************************************************** //

extern byte D_Model_Name[9];			 // LCD 창에 표현될 Model명
extern byte D_Model_Descript[32];		 // LCD 창에 표현될 Full Model명
extern byte D_Model_CS[2]; 			 // LCD 창에 표현될 Model Binary Code의 Check-Sum Code
extern byte D_Model_Prog_Info[31]; 	 // Program 정보 = Block별 Write 유무 판단함
 // *************************************************************************** //

 void Erase_Sector_Serial_Flash(void);

 void Erase_Serial_Flash(void);
 void FProg_Page_Serial_Flash(void);
 void FRead_Page_Serial_Flash(void);

 void Write_Page_Flash_handler(void);
 void Read_Page_Flash_handler(void);


 void Load_Model_Description(void);

 void Init_Flash(void);

// *************************************************************************** //
 void Erase_Sector_EXT_Serial_Flash(void);
 void Write_Page_EXT_Serial_Flash(void);
 void Read_Page_EXT_Serial_Flash(void);




#endif // __SERIAL_FLASH
