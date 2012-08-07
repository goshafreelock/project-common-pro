#ifndef _FM_REV_
#define _FM_REV_

#include "Custom_config.h"

#define MAX_FRE    1080
#define MIN_FRE	   870

#if defined(K731_YJH_820_V001)||defined(FM_MINI_FRE_875)
#undef MIN_FRE 	
#define MIN_FRE	   875
#endif

#ifdef USE_BK1088_FM
#define AM_MAX_FRE    1710
#define AM_MIN_FRE	   522
#else
#define AM_MAX_FRE    1710
#define AM_MIN_FRE	   504
#endif

#define AM_FREQ_MAGIC_NUM		0x80
#if defined(FM_MAX_CHANNAL_50)
#define MAX_CHANNL 50

#ifdef EEPROM_RTC_RAM_COMPATIBLE
#undef EEPROM_RTC_RAM_COMPATIBLE
#endif


#elif defined(FM_MAX_CHANNAL_60)
#define MAX_CHANNL 60

#ifdef EEPROM_RTC_RAM_COMPATIBLE
#undef EEPROM_RTC_RAM_COMPATIBLE
#endif

#ifdef RADIO_AM_WM_ENABLE
#define MAX_AM_CHANNL  20
#endif
#else
#define MAX_CHANNL 30
#endif

#ifdef __C51__
#include "fm_api.h"
#include "typedef.h"
#include "key.h"
#include "display_common.h"
#include "msgfor_hot.h"
#include "rtc_mode.h"

void fm_radio(void);
void fm_rev( void );
void scan_fre(void);
void dealmsgforfm(u8 msg);
void enter_fm_rev(void);
#ifdef RADIO_AM_WM_ENABLE
void FM_AM_chip_mode_sel(u8 modsel);
void Save_AM_Freq(u16 am_freq,u8 ch);
u16 Read_AM_Freq(u8 ch);
#endif
#endif

#define RDAFM_ID	0x5888
#define RDAFM_ID1	0x5801
#define RDAFM_ID2	0x5802
#define RDAFM_ID3	0x5803
#define RDAFM_ID4	0x5804
#define RDAFM_ID5	0x5808

#define CL6017G_ID	0x0A
#define BK1080_ID	0x1080
#define BK1088_ID	0x1080
#define SP3777_ID	0x07
#define QN8035_ID	0x84
#define KT0830EQ_ID	0xb002
#define AR1000_ID	0x1010

typedef enum {

	SEARCH_UP =0,
	SEARCH_DN,
}AUTO_DIR;

enum{

	RADIO_FM,
	RADIO_AM,
};
enum{

	FM_GPIO_1,
	FM_GPIO_2,
	FM_GPIO_3,
};

#endif
