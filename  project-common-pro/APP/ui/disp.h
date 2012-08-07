/*--------------------------------------------------------------------------*/
/**@file   disp.h
   @brief    显示模块头文件
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef   _DISP_H_
#define  _DISP_H_

#ifdef __C51__
#include "AC209N.h"
#include "typedef.h"
#include "uart.h"
#include "main.h"

#if 0
typedef enum
{
    DISP_NULL = 0,
    DISP_PLAY,
    DISP_PAUSE,
    DISP_VOL,
    DISP_EQ,
    DISP_POWER_UP,
    DISP_PLAYMODE,
    DISP_NOFILE,
    DISP_NODEVICE,
    DISP_FILENUM,
    DISP_DWORD_NUMBER,
    DISP_WAIT,
    DISP_USBDEV,
    DISP_FREQ,
    DISP_CH_NO,
    DISP_SCAN_NO,
    DISP_USBOUT,
    DISP_SDOUT,
    DISP_AUX,
    DISP_PWR_OFF,
    DISP_START,
    DISP_RTC,
    DISP_RTC_DATE,
    DISP_RTC_POINT,
    DISP_RTC_PWD,
    DISP_ALM_UP,
    DISP_ALM_SET,
};
#endif

#define DEVICE_COLUMN 1
#define PLAYTIME_COLUMN (DEVICE_COLUMN+16+2)

#define EQ_COLUMN (DEVICE_COLUMN+16+2+29)
#define FILENUM_COLUMN (DEVICE_COLUMN+16+2+29+21)

#define FRE_4_COLUMN ((LCDCOLUMN - 8*8)/2)
#define FRE_3_COLUMN ((LCDCOLUMN - 7*8)/2)
#define FM_CHANNL_COLUMN    1
void LCD_Buff_position(u8 x,u8 y);
void Disp_Con(u8 LCDinterf);
void dispfilename(void);
void disp_file_time(void);
void Disp_Waiting(void);

#endif

#endif
