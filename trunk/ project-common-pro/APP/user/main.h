/*--------------------------------------------------------------------------*/
/**@file     main.h
   @brief    主流程头文件
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__
#include "Custom_config.h"

#ifdef __C51__

#include "config.h"
#include "uart.h"
#include "decode.h"
#include "filesystem.h"
#include "mp3mode.h"
#include "dac.h"
#include "clock.h"


typedef enum
{
    SYS_MP3DECODE_USB,
    SYS_MP3DECODE_SD,
#if defined(EXCHANGE_FM_AUX_PRIO)    
    SYS_AUX,
    SYS_FMREV,
#ifdef RADIO_AM_WM_ENABLE
    SYS_AMREV,
#endif        
#else
    SYS_FMREV,
#ifdef RADIO_AM_WM_ENABLE
    SYS_AMREV,
#endif    
    SYS_AUX,
#endif
#ifdef USE_AUX_2
    SYS_AUX_2,
#endif
#if defined(IPONE_INDEPENDENT_MODE)	
    SYS_IPH,
#endif
#if defined(BLUE_TOOTH_FUNC)	
    SYS_BT,
#endif	
#ifdef USE_RTC_FUNCTION
    SYS_RTC,
#endif    
    SYS_IDLE,
    SYS_USBDEVICE,
}SYS_WORK_MODE;

#endif

#if RTC_ENABLE
#define MAX_WORK_MODE  RTC_MOD
#else
#define MAX_WORK_MODE  AUX_IN_MOD
#endif



#endif
