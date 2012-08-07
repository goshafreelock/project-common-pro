#ifndef _RTC_CPU_
#define _RTC_CPU_

#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"

#ifdef __C51__
#define IRTC_CSEN 	IRTCON|=BIT(0)
#define IRTC_CSDIS 	IRTCON&=~(BIT(0))
void enable_alm(void);
void disable_alm(void);
void send_alm_sec(u32 sec);
u32 read_alm_sec(void);
void send_rtc_sec(u32 sec);
u32 read_rtc_sec(void);
u8 read_rtc_reg(void);
void write_rtc_reg(u8 cmd);

//#define WKUP_PIN_HIGH() 	write_rtc_reg((read_rtc_reg()|0x10))
//#define WKUP_PIN_LOW()	 	write_rtc_reg((read_rtc_reg()&0xef))

#endif


#define WRITE_RTC_SEC 			0x50
#define READ_RTC_SEC  			0x40
#define WRITE_RTC_ALM 			0x38
#define READ_RTC_ALM  			0x39
#define WRITE_RTC_REG  			0x3a
#define READ_RTC_REG  			0x3b
#define WRITE_RTC_RAM  			0x3c
#define READ_RTC_RAM 		 	0x3d



#endif

