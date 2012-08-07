#ifndef _RTC_MODE_
#define _RTC_MODE_
#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"
#include "entry.h"
#include "msgfor_usb.h"

#ifdef __C51__
typedef struct
{
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minutes;
    u8 second;
    u8 date;
}RTC_TIME;

typedef struct
{
    u8 hour;
    u8 minutes;
}ALM_TIME;

enum{
	ALM_SOUR_BEEP,
	ALM_SOUR_USB,
	ALM_SOUR_FM,
};
#define TRUE 1
#define FALSE 0

#define	ONEDAY 86400	//86400
#define ONEHOUR 3600		//3600
#define ONEMIN	60

#define YEAR 2010
#define MONTH 1
#define DAY 1
#define HOUR 0
#define MINUTES 0
#define SECOND 0

#define SDATE 6

#define YEARCOM	   	(LCDCOLUMN-10*8)/2+0
#define MONTHCOM	(LCDCOLUMN-10*8)/2+40
#define DAYCOM		(LCDCOLUMN-10*8)/2+64
#define HOURCOM		(LCDCOLUMN-10*8)/2+0
#define MINCOM		(LCDCOLUMN-10*8)/2+24
#define SECCOM		(LCDCOLUMN-10*8)/2+48

#define ALMSWITCH   (LCDCOLUMN-9*8)/2+48
#define HOURACOM	(LCDCOLUMN-5*8)/2+0
#define MINACOM		(LCDCOLUMN-5*8)/2+24

#define RTC_PLAY_MODE	0
#define RTC_SET_MODE    1
#define ALM_SET_MODE    2
#define ALM_UP_MODE     3

void check_alm(void);
void rtc_function(void);
bool init_rtc(void);
void fond_alm_clk(void);
bool alm_bell(void);
u8 alm_bell_mode(void);
void close_alm_bell(void);
void get_curr_date(void);
#endif



#endif
