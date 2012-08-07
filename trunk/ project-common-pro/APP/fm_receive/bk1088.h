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
#define REG_RW_I2C_MODE
#include "gpio_config.h"


#define CHIP_DEV_ID 0x80

#if 0
#define BK_DATA_HIGH() iic_data_h()   //P02=1;
#define BK_DATA_LOW()  iic_data_l() //  P02=0;
#define BK_DATA_READ() iic_data_r() //    P02
#define SDADIROUT()      iic_data_out() // P0DIR &= ~(1<<2);P0PU |= (1<<2)
#define SDADIRIN()      iic_data_in()  //  P0DIR |= (1<<2);P0PU |= (1<<2)

#define SCLDIROUT()      iic_clk_out() //  P0DIR &= ~(1<<3);P0PU |= (1<<3)
#define BK_CLK_HIGH()    iic_clk_h() // P03=1;
#define BK_CLK_LOW()   iic_clk_l() //   P03=0;
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
#define MW_CHANNEL_STEP 9


#define REGb_READ_CHAN  0x0b

u16 BK1088_Get_ID();
void BK1088_SetGPIO2(bool mute);
void BK1088_SetGPIO1(bool mute);

void BK1088_Intialization(bool init_fmam);

void BK1088_SetMute(bool mute);

void BK1088_PowerOffProc();

void  BK1088_SetFreq(u16 curFreq);

bool BK1088_FMValidStop(u16 freq,u16 start_freq);
bool BK1088_AMValidStop(u16 freq,u16 start_freq);

void BEKEN_I2c_Read(u8 reg,u8 *pBuf,u8 len);
void BEKEN_I2c_Write(u8 reg,u8 *pBuf,u8 len);

void BK1088_SetVolume(u8 vol);

#endif



