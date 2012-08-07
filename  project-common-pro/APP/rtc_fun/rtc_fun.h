#ifndef _RTC_FUN_
#define _RTC_FUN_

#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"
#include "rtc_mode.h"
#ifdef __C51__

u16 nowyear(u16 nyear);
u8 nowmonth(u8 nmonth,u16 nyear);
u8 leapyear(u16 year);

u32 date_sec(RTC_TIME *time,bit flag);
void sec_date(RTC_TIME *now_time,u32 sec);
void curr_date_plus();
void curr_date_minus();
void alm_time_plus();
void alm_time_minus();
#endif


#endif