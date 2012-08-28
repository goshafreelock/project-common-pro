/*--------------------------------------------------------------------------*/
/**@file     iic.h
   @brief    IICÍ·ÎÄ¼þ
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"

#ifndef _IIC_H_
#define _IIC_H_


#ifdef __C51__
#include "AC209N.h"
#include "typedef.h"
#include "uart.h"

/*
#define iic_data_out()    P2DIR &= ~(1<<7);P2PU |= (1<<7)
#define iic_data_in()     P2DIR |= (1<<7);P2PU |= (1<<7)
#define iic_data_r()      (P2 & (1<<7))
#define iic_data_h()      P2 |= (1<<7)
#define iic_data_l()      P2 &= ~(1<<7)

#define iic_clk_out()    P2DIR &= ~(1<<6);P2PU |= (1<<6)
#define iic_clk_h()      P2 |= (1<<6)
#define iic_clk_l()      P2 &= ~(1<<6)
*/
#include "gpio_config.h"
#if 0
#define iic_data_out()    P0DIR &= ~(1<<2);P0PU |= (1<<2)
#define iic_data_in()     P0DIR |= (1<<2);P0PU |= (1<<2)
#define iic_data_r()      P02
#define iic_data_h()      P02 = 1
#define iic_data_l()      P02 = 0

#define iic_clk_out()    P0DIR &= ~(1<<3);P0PU |= (1<<3)
#define iic_clk_h()      P03 = 1
#define iic_clk_l()      P03 = 0
#endif

#define iic_delay()      Delay(5)
/*
#if USE_RTC_RAM
extern u8 read_rtc_ram(u8 addr);
extern void write_rtc_ram(u8 addr,u8 dat);
#define  read_info(n)    read_rtc_ram(n)
#define  write_info(n,m)      write_rtc_ram(n,m)

#else

#define  read_info(n)    read_eerom(n)
#define  write_info(n,m)      write_eerom(n,m)
#endif
*/

extern u8 read_info(u8 addr);
extern void write_info(u8 addr,u8 dat);
extern u8 read_rtc_ram(u8 addr);
extern void write_rtc_ram(u8 addr,u8 dat);

void iic_init_io(void);
void iic_start(void);
void iic_stop(void);
u8 r_ack(void);
void s_ack(u8 flag);
u8 iic_revbyte_io( void );
u8 iic_revbyte( u8 para );
void iic_sendbyte_io(u8 byteI2C);
u8 iic_sendbyte(u8 byte);

void  iic_write(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n);
void iic_readn(u8 chip_id,u8 iic_addr,u8 *iic_dat,u8 n);

u8 read_eerom(u8 iic_addr);
void write_eerom(u8 addr,u8 dat);
u16 OperationRDAFM_2w(u8 operation,u8 *R_T_data,u8 numBytes);
u8 RDAFM_write_data(u8 regaddr, u16 *Tdata, u8 datalen);
u8 RDAFM_read_data(u8 regaddr, u16 *Rdata, u8 datalen);

#endif
#define READ	1
#define WRITE	0

#define ADRW 0x20
#define ADRR 0x21
#define FM_SINGLE_REG_ADRW	0x22
#define FM_SINGLE_REG_ADRR 	0x23

#define IIC_DELAY_DEFAULT 30



#define MEM_ACTIVE_DEV     0
#define MEM_EQ_MODE        1
#define MEM_PLAY_MODE      2
#define MEM_VOL            3
#define MEM_SYSMODE        4

#define MEM_ALM_SW		   4
#define MEM_ALM_HOUR       5
#define MEM_ALM_MIN        6

#define MEM_FRE            7
#define MEM_ALL_CHANNL     8
#define MEM_FRE_CHANNL     9

#define MEM_CHANNL         35//11

#define MEM_AM_FRE            	10
#define MEM_AM_ALL_CHANNL     12
#define MEM_AM_FRE_CHANNL     13

#if defined(FM_MAX_CHANNAL_50)||defined(FM_MAX_CHANNAL_60)
#define MEM_AM_CHANNL              100
#else
#define MEM_AM_CHANNL              80
#endif

#if defined(FM_MAX_CHANNAL_50)||defined(FM_MAX_CHANNAL_60)
#ifdef EEPROM_RTC_RAM_COMPATIBLE
#undef EEPROM_RTC_RAM_COMPATIBLE
#endif
#endif

#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)			
#define MEM_SD_PLAYPOINT_INFO  15
#define MEM_USB_PLAYPOINT_INFO 17
#define MEM_USB_FRAME_CNT	19
#define MEM_USB_NEXT_FRAME  23
#define MEM_SD_FRAME_CNT	27
#define MEM_SD_NEXT_FRAME   31
#endif
#define MEM_FILENUM_USB 	15
#define MEM_FILENUM_SD 	17
#define MEM_FILENUM 		19

#define IIC_VERIFY_BYTE_ADDR	36


#define MEM_BASE			100
#define MEM_TREB 			101
#define MEM_BAL 			102
#define MEM_FADE 			103

#endif
