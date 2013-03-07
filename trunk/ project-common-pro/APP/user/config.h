/*--------------------------------------------------------------------------*/
/**@file     config.h
   @brief    一些基本参数的配置
   @author
   @date   2010-12-13
   @note   AC209N
*/
/*----------------------------------------------------------------------------*/
#ifndef _CONFIG_
#define _CONFIG_

#ifdef __C51__
#include "AC209N.h"
#include "intrins.h"
#include "typedef.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "entry.h"
#include "power.h"
#define chars_table_l  ((char _code *)(0xc39b))
typedef enum
{
	DIS_SD_CMD_CHK = 0,	///<在命令检测SD卡在线状态的情况下，暂停SD在线检测
	EN_SD_CMD_CHK,		///<在命令检测SD卡在线状态的情况下，恢复SD在线检测
	SET_SD_H_CHK,		///<在命令检测SD卡在线状态的情况下，SD不在线时检测100MS一次
	SET_SD_L_CHK,		///<在命令检测SD卡在线状态的情况下，SD不在线时检测1S一次
}Sd_api_cmd;

#endif
#include "Custom_config.h"

#if defined(SYS_CRYSTAL_USE_24M)
#define OSC_CLOCK		24000000L		//<<<系统晶振选择
#define _SHARE_CRYSTAL_24MHz_
#elif defined(SYS_CRYSTAL_USE_12M)
#define OSC_CLOCK		12000000L		//<<<系统晶振选择
#define _SHARE_CRYSTAL_12MHz_
#else
#define OSC_CLOCK		32768L		//<<<系统晶振选择
#define _SHARE_CRYSTAL_32KHz_
#endif

#ifdef USE_RTC_FUNCTION
#define RTC_ENABLE      1			//<<<是否需要使用RTC功能(与是否使用RTC内部的RAM无关)
#else
#define RTC_ENABLE      0			//<<<是否需要使用RTC功能(与是否使用RTC内部的RAM无关)
#endif

#ifdef OTP_MUSIC_FUNC_ENABLE
#define OTP_MUSIC_ENABLE 1			//<<<是否需要使用开机音乐
#else
#define OTP_MUSIC_ENABLE 0			//<<<是否需要使用开机音乐
#endif

#ifdef USE_RTC_RAM_FUNC
#define USE_RTC_RAM 1      //4< 1:使用RTC内部的64个字节的RAM做记忆，掉电不能记忆；0:使用EEROM做记忆
#else
#define USE_RTC_RAM 0      //4< 1:使用RTC内部的64个字节的RAM做记忆，掉电不能记忆；0:使用EEROM做记忆
#endif

/*0: DECODE EQ, 1: DSP EQ*/
#define DECODE_EQ       0
#define DSP_EQ          1

#if defined(K637_ZX_306_V001)||defined(K646_ZhuoXing_308_V001)||defined(K2012_MY_M90_V001)||defined(EQ_USE_DSP_FUNC)
#define EQ_WORK_USE     DSP_EQ
#else
#define EQ_WORK_USE     DECODE_EQ
#endif

#define  LED_DISP  1
#define  LCD_DISP  0

/*延时显示时间*/
#ifdef K2081_DM_007_V001
#define RETURN_TIME 6
#else
#define RETURN_TIME 5
#endif
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
#define RETURN_TIME_SHOW_TIME   12
#endif

/*sd检测模式**/
#if defined(NEW_SD_DETECT_MOD)
#define SDMMC_CMD_MODE   0	  ///<使用SD card 命令查询模式
#define SDMMC_CLK_MODE   1	  ///<使用SD clk 查询模式
#define SDMMC_GPIO_MODE  0	  ///<使用独立的GPIO做SD在线查询模式
#else
#define SDMMC_CMD_MODE   1	  ///<使用SD card 命令查询模式
#define SDMMC_CLK_MODE   0	  ///<使用SD clk 查询模式
#define SDMMC_GPIO_MODE  0	  ///<使用独立的GPIO做SD在线查询模式
#endif
#define FF_FR_MUSIC                      1			//在快进快退时，是否需要听到声音
#define USB_DEVICE_OTG                   0          //1：从机支持热插拔，0：只在开机时检测一下是否有从机

//#define RTC_ENABLE                       1		    //<是否需要使用RTC功能(与是否使用RTC内部的RAM无关)
//#define OTP_MUSIC_ENABLE                 0			//<是否需要使用开机音乐
#define VOICE_TIME_ENABLE                0          //语音报时功能使能；     1：打开  0：关闭
#define FM_ENABLE                        0          //fm功能使能；           1：打开  0：关闭


#define FILE_ENCRYPTION                  0          //文件加密功能使能;      1：打开  0：关闭
#define DEVICE_ENCRYPTION                0          //设备加密功能使能；     1：打开  0：关闭
#define FAT_MEMORY                       0          //设备记忆功能使能；     1：打开  0：关闭
//void Delay_us(u16 i );
#endif
