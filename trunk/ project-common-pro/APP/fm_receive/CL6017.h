#ifndef	_CL6017_H_
#define _CL6017_H_
/*--------------------------------------------------------------------------------------
*This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
*****************
Compiler:uVision2 2.40
*****************
* website: http://www.bekencorp.com
---------------------------------------------------------------------------------------*/

#include "iic.h"
#include "typedef.h"

#define CODE code
//#define XTAL_CLOCK

//#define _BK1080_clock_32K_
//#if 0
//#define _BK1080_clock_24M_
//
//
//
//#define CHIP_DEV_ID 0x80
//
//
////Chip tag
//#define CHIP_ADDR 0xc0  //0x60<<1
//#define READ_OP 0x20
//
////BK108X register map
//#define REG0_DEVICE_ID 0x00
//#define REG1_CHIP_ID   0x01
//#define REG2_POWER_CFG 0x02
//#define REG3_CHANNEL   0x03
//#define REG4_SYS_CONF1 0x04
//#define REG5_SYS_CONF2 0x05
//#define REG6_SYS_CONF3 0x06
//
//#define REG7_TEST1     0x07
//#define REG8_TEST2     0x08
//#define REG9_BOOT_CFG  0x09
//#define REGa_STATUS_RSSI  0x0a
//	
//#define RDSR_BIT 15
//#define STC_BIT 14
//#define SF_BL_BIT 13
//#define AFCRL_BIT 12
//
//#define REGb_READ_CHAN  0x0b
//#endif





void init_CL6017G(void);
void CL6017G_TUNE (u16 curFreq);
bool CL6017G_ValidStop(u16 unFreq);
void MuteCL6017(bool flag);
void CL6017G_PowerOff(void);
u16 CL6017G_Read_ID(void);
//u8 BK1080_SearchByTune(u16* searched_freq);
#endif
