/*--------------------------------------------------------------------------------------
*This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
*****************
Compiler:uVision2 2.40
*****************
* website: http://www.bekencorp.com
---------------------------------------------------------------------------------------*/
#ifdef __C51__

#include "typedef.h"
#define CODE code
#define XTAL_CLOCK
#define REG_RW_I2C_MODE



#define CHIP_DEV_ID 0x80

#include "gpio_config.h"

#if 0
#define BK_DATA_HIGH()   P02=1;
#define BK_DATA_LOW()    P02=0;
#define BK_DATA_READ()    P02
#define SDADIROUT()       P0DIR &= ~(1<<2);P0PU |= (1<<2)
#define SDADIRIN()        P0DIR |= (1<<2);P0PU |= (1<<2)

#define SCLDIROUT()        P0DIR &= ~(1<<3);P0PU |= (1<<3)
#define BK_CLK_HIGH()     P03=1;
#define BK_CLK_LOW()      P03=0;
#endif

//Chip tag
#define CHIP_ADDR 0xc0  //0x60<<1
#define READ_OP 0x20

//BK108X register map
#define REG0_DEVICE_ID 0x00
#define REG1_CHIP_ID   0x01
#define REG2_POWER_CFG 0x02
#define REG3_CHANNEL   0x03
#define REG4_SYS_CONF1 0x04
#define REG5_SYS_CONF2 0x05
#define REG6_SYS_CONF3 0x06

#define REG7_TEST1     0x07
#define REG8_TEST2     0x08
#define REG9_BOOT_CFG  0x09
#define REGa_STATUS_RSSI  0x0a
	#define RDSR_BIT 15
	#define STC_BIT 14
	#define SF_BL_BIT 13
	#define AFCRL_BIT 12


#define REGb_READ_CHAN  0x0b

u16 BK1080_Get_ID();


void BK1080_Intialization();

void BK1080_SetMute(bool mute);

void BK1080_PowerOffProc();

void  BK1080_SetFreq(u16 curFreq);

bool BK1080_ValidStop(u16 freq,u16 start_freq);

void BEKEN_I2c_Read(u8 reg,u8 *pBuf,u8 len);
void BEKEN_I2c_Write(u8 reg,u8 *pBuf,u8 len);

void BK1080_SetVolume(u8 vol);


#endif

