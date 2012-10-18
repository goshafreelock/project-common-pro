#ifndef _LED_H_
#define	_LED_H_

#include "Custom_config.h"

#ifdef __C51__

#if defined(LED_USE_PLAY_MODE)

#if defined(LED_USE_PLAY_MODE_NORMAL)||defined(K0000_MC_Q16A_V001)||defined(K2056_AJR_2056_V001)||defined(K1140_AJR_1140_V001)||defined(K0000_MC_TK19_V001)||defined(K0000_MC_Q21_V001)||defined(K0000_MC_Q18A_V002)||defined(K586_DCX_586_V001)||defined(K0000_MC_Q18A_V001)||defined(K223_BTL_CP153_V001)||defined(K2041_XFW_2041_V001)||defined(K000_XinLei_LC2092_V004)||defined(K1051_JIAMEI_1051C_V001)||defined(K1051_JIAMEI_1051_V001)||defined(K000_XinLei_LC2092_V001)||defined(K000_XinLei_LC2092_V002)||defined(K1007_JinYiHeLi_1007_V001)||defined(K1025_AIPU_1025_V001)||defined(K591_JiaLe_591_V001)||defined(K795_JinYeHeLi_795_V001)||defined(K796_JinYeHeLi_796_V001)||defined(K737_JinYiHeLi_737_V001)||defined(K763_JinYiHeLi_763_V001)||defined(K585_YJH_585_V001)||defined(K756_JinYiHeLi_756_V001)||defined(K000_AOKAILIN_508_V001)||defined(K762_JinYiHeLi_762_V001)
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_C)
#define LED_USB		 BIT(LED_E)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_G)
//#define LED_AUX		 BIT(LED_F)
#define LED_BAT_L2		 BIT(LED_B)
#define LED_BAT_L1		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_H)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K2083_KPL_2083_V001)||defined(K2083_SW_2083_V001)||defined(KPL_BIG_LED_MODULE)
#define LED_AUX	 	BIT(LED_B)
#define LED_FM		BIT(LED_A)|BIT(LED_D)

#define LED_AM		BIT(LED_H)
#define LED_STATUS_AM   LED_BUFF[0]

#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_H)
#define LED_STATUS_SD   LED_BUFF[3]

#define LED_2POINT	 BIT(LED_H)
#define LED_STATUS_COL   LED_BUFF[1]

#define LED_BAT_L3		 BIT(LED_E)
#define LED_BAT_L2		 BIT(LED_F)
#define LED_BAT_L1		 BIT(LED_G)
#define LED_MP3		 0//BIT(LED_H)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K1161_ZK_ALK935_V001)||defined(K1166_ZK_ALK980_V001)||defined(LED_MODE_EXCHANGE_TF_USB_ICON)
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_C)
#define LED_USB		 BIT(LED_D)
#define LED_SD		 BIT(LED_E)
#define LED_2POINT	 BIT(LED_G)
//#define LED_AUX		 BIT(LED_F)
#define LED_BAT_L2		 BIT(LED_B)
#define LED_BAT_L1		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_H)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K769_JinRui_769_V001)
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_E)
#define LED_USB		 BIT(LED_G)
#define LED_SD		 BIT(LED_C)
#define LED_2POINT	 BIT(LED_F)

#define LED_MP3		 BIT(LED_B)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K1119_LS_1119_V001)
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_E)
#define LED_USB		 BIT(LED_G)
#define LED_SD		 BIT(LED_C)
#define LED_2POINT	 BIT(LED_F)
//#define LED_AUX		 BIT(LED_F)
//#define LED_MP3		 BIT(LED_F)
#define LED_MP3		 BIT(LED_B)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)
#define LED_AUX	 	BIT(LED_D)
#define LED_FM		BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_A)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_F)
#define LED_BAT_L2		 BIT(LED_G)
#define LED_BAT_L1		 BIT(LED_F)
//#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K0000_MC_L2A_V001)||defined(K0000_MC_H2_V001)||defined(K0000_MC_DYJ_V001)
#define LED_AUX	 	BIT(LED_F)
#define LED_FM		BIT(LED_G)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_F)
#define LED_BAT_L2		 BIT(LED_A)
#define LED_BAT_L1		 BIT(LED_B)
//#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K0000_WK_S638_V001)||defined(K0000_MC_M73A_V001)
#define LED_AUX	 	BIT(LED_D)
#define LED_FM		BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_A)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_F)
#define LED_BAT_L2		 BIT(LED_F)
#define LED_BAT_L1		 BIT(LED_G)
//#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#elif defined(LED_REVERSE_VIEW)
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_C)|BIT(LED_F)
#define LED_USB		 BIT(LED_E)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_B)
#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#elif defined(LED_MODE_EXCHANGE_TF_AUX_ICON)
#define LED_AUX	 	BIT(LED_D)
#define LED_FM		BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_A)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
//#define LED_MP3		 BIT(LED_F)
#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K0000_GW_168C_V001)//||defined(K0000_GW_ZX015_V001)
#define LED_AUX	 	0//BIT(LED_D)
#define LED_FM		BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_A)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
//#define LED_MP3		 BIT(LED_F)
#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#else
#define LED_AUX	 	BIT(LED_A)
#define LED_FM		BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
//#define LED_MP3		 BIT(LED_F)
#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#endif


#elif defined(LED_DRVER_USE_SM1628)

#define LED_AUX	 	//BIT(LED_A)
#define LED_USB		 BIT(LED_A)
#define LED_MP3		 BIT(LED_E)
#define LED_SD		 BIT(LED_D)
#define LED_PAUSE	 BIT(LED_C)
#define LED_2POINT	 BIT(LED_B)
#define LED_PLAY	 BIT(LED_G)
#define LED_FM		BIT(LED_F)

#define LED_STATUS   LED_BUFF[4]
#elif defined(LED_USE_COMMON_4X8)

#define LED_PLAY	 0//BIT(LED_A)
#define LED_PAUSE	 0//BIT(LED_B)
#define LED_USB		 0//BIT(LED_C)
#define LED_SD		 0//BIT(LED_D)
#define LED_2POINT	 BIT(LED_H)
//#define LED_AUX	 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_F)
#define LED_FM		 BIT(LED_H)

#define LED_STATUS   	LED_BUFF[1]
#define LED_STATUS_FM   LED_BUFF[2]

#elif defined(LED_USE_1X888)

#define LED_PLAY	 0//BIT(LED_A)
#define LED_PAUSE	 0//BIT(LED_B)
#define LED_USB		 0//BIT(LED_C)
#define LED_SD		 0//BIT(LED_D)
#define LED_2POINT	 0//BIT(LED_H)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_F)
#define LED_FM		 BIT(LED_H)
#define LED_STATUS   LED_BUFF[2]

#elif defined(LED_USE_ROUND_LED)

#if defined(K162_QDX_162_V001)||defined(ROUND_LED_USE_OFFEN)||defined(K1032_YJH_1032_V001)||defined(K1035_HF_1035_V001)||defined(K1052_DCX_1052_V001)||defined(K1032_JIAMEI_1032_V001)||defined(K593_YJH_593_V001)||defined(K807_YJH_807_V001)||defined(K1026_YJH_1026_V001)||defined(K1022_WXD_1322_V001)||defined(K2018_JINRUI_2018_V001)
#define LED_AUX	 		BIT(LED_H)
#define LED_FM			BIT(LED_F)
#define LED_USB		 	BIT(LED_C)
#define LED_SD		 	BIT(LED_D)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_FALL	BIT(LED_B)
#define LED_BAT_HALF 	BIT(LED_F)
#define LED_MP3		 	BIT(LED_E)
#define LED_PLAY	 	BIT(LED_A)
#define LED_PAUSE	 	BIT(LED_B)

#define LED_STATUS   LED_BUFF[4]

#elif defined(K728_SUOERSI_728_V001)

#define LED_AUX	 		BIT(LED_D)
#define LED_FM			BIT(LED_F)
#define LED_USB		 	BIT(LED_A)
#define LED_SD		 	BIT(LED_B)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_L2		BIT(LED_E)
#define LED_BAT_L1 		BIT(LED_C)

#define LED_STATUS   LED_BUFF[4]

#define LED_MP3		 BIT(LED_H)
#define LED_PLAY	 BIT(LED_H)
#define LED_PAUSE	 BIT(LED_H)
#elif defined(K619_FXK_619_V001)
#define LED_AUX	 		BIT(LED_F)
#define LED_FM			BIT(LED_H)
#define LED_USB		 	BIT(LED_C)
#define LED_SD		 	BIT(LED_D)
#define LED_2POINT	 	BIT(LED_H)

//#define LED_BAT_FALL	BIT(LED_B)
//#define LED_BAT_HALF 	BIT(LED_F)
#define LED_MP3		 BIT(LED_E)
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)

#define LED_STATUS   LED_BUFF[4]
#elif defined(K1032_AJE_1032_V001)||defined(K1032_AP_1032_V001)
#define LED_AUX	 		BIT(LED_A)
#define LED_FM			BIT(LED_C)
#define LED_USB		 	BIT(LED_E)
#define LED_SD		 	BIT(LED_D)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_L2	BIT(LED_B)
#define LED_BAT_L1 	BIT(LED_F)

#define LED_STATUS   LED_BUFF[4]

#define LED_MP3		0//T(LED_H)
#define LED_PLAY	0//T(LED_H)
#define LED_PAUSE	0//T(LED_H)
#elif defined(K1032_ZHONGKAI_1032_V001)||defined(K1032_WK_1032_V001)||defined(K1166_ZK_ALK980_V001)|defined(BAT_LEVEL_LED_ICON_IND)
#define LED_AUX	 		BIT(LED_A)
#define LED_FM			BIT(LED_C)
#define LED_USB		 	BIT(LED_D)
#define LED_SD		 	BIT(LED_E)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_L2	BIT(LED_B)
#define LED_BAT_L1 	BIT(LED_F)

#define LED_STATUS   LED_BUFF[4]

#define LED_MP3		0//T(LED_H)
#define LED_PLAY	0//T(LED_H)
#define LED_PAUSE	0//T(LED_H)
#else
#define LED_AUX	 		BIT(LED_A)
#define LED_FM			BIT(LED_C)
#define LED_USB		 	BIT(LED_E)
#define LED_SD		 	BIT(LED_D)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_FALL	BIT(LED_B)
#define LED_BAT_HALF 	BIT(LED_F)

#define LED_STATUS   LED_BUFF[4]

#define LED_MP3		 BIT(LED_H)
#define LED_PLAY	 BIT(LED_H)
#define LED_PAUSE	 BIT(LED_H)
#endif


#else

#if defined(K186_ZHHB_S30_V001)||defined(ROUND_LED_USE_OFFEN)||defined(K170_YJH_803_V001)||defined(K186_LM_186_V001)||defined(K704_JM_502_V001)||defined(K709_AOKAILIN_709_V001)||defined(K720_YJH_720_V001)
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_G)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 BIT(LED_E)
#define LED_FM		 BIT(LED_F)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K723_LUOMAO_723_V001)
#define LED_PLAY 	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_F)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_G)
#define LED_MP3		 BIT(LED_H)
#define LED_FM		 BIT(LED_E)
#define LED_BAT_L1 	 BIT(LED_C)
#define LED_BAT_L2 	 BIT(LED_H)
#define LED_STATUS   LED_BUFF[4] 
#elif (defined(EXCHANGE_FM_MP3_ICON)||defined(K010_QDX_PM21_V001)||defined(K1107_DCX_991_V001)||defined(K000_XinLei_LC2092_V005)||defined(K2035_SES_2035_V001)||defined(K1069_AJE_1069_V002)/*||defined(K1028_WOKA_1028_APPLE_V001)*/||defined(K000_XinLei_LC2092_V003)||defined(K000_XINGLEI_2092_V001)||defined(K566_JLH_566_V001)||defined(K170_QDX_170_V001)||defined(K317_ZhuoXing_317_V001)||defined(K316_ZhuoXing_316_V001)||defined(K568_JinRui_568_V001)||defined(K566_JinRui_566_V001))
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 BIT(LED_G)
#define LED_FM		 BIT(LED_F)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K000_XinLei_LC2092_V006)
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 0//BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 0//BIT(LED_G)
#define LED_FM		 BIT(LED_B)

#define LED_BAT_L2		BIT(LED_F)
#define LED_BAT_L1 		BIT(LED_G)

#define LED_STATUS   LED_BUFF[4]
#elif defined(K745_SUOERSI_745_V001)
#define LED_AUX	 		BIT(LED_D)
#define LED_FM			BIT(LED_F)
#define LED_USB		 	BIT(LED_A)
#define LED_SD		 	BIT(LED_B)
#define LED_2POINT	 	BIT(LED_G)

#define LED_BAT_L2		BIT(LED_E)
#define LED_BAT_L1 		BIT(LED_C)

#define LED_STATUS   LED_BUFF[4]

#define LED_MP3		 BIT(LED_H)
#define LED_PLAY	 BIT(LED_H)
#define LED_PAUSE	 BIT(LED_H)

#elif defined(LED_USE_PLAY_MODE_MIXED)

#if defined(K1009_DCX_915_V001)
#define LED_PLAY	 BIT(LED_G)
#define LED_PAUSE	 BIT(LED_C)
#define LED_USB		 BIT(LED_D)
#define LED_SD		 BIT(LED_A)
#define LED_2POINT	 BIT(LED_B)
#define LED_AUX		 BIT(LED_E)
#define LED_MP3		 0x00//BIT(LED_H)
#define LED_FM		 BIT(LED_F)
#define LED_STATUS   LED_BUFF[4]
#elif defined(K769_JinRui_769_V002)
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
#define LED_AUX		 0//BIT(LED_F)
#define LED_FM		 BIT(LED_F)
#define LED_MP3		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]
#else
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 BIT(LED_H)
#define LED_FM		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]

#endif
#else
#define LED_PLAY	 BIT(LED_A)
#define LED_PAUSE	 BIT(LED_B)
#define LED_USB		 BIT(LED_C)
#define LED_SD		 BIT(LED_D)
#define LED_2POINT	 BIT(LED_E)
//#define LED_AUX		 BIT(LED_F)
#define LED_MP3		 BIT(LED_F)
#define LED_FM		 BIT(LED_G)
#define LED_STATUS   LED_BUFF[4]

#endif

#endif

#endif

#if defined(EXTENDED_LED_SPECTURM)
#define SPEC_ICON_BUF	P1

#if defined(REVERSE_LED_FLASH_DIR)
#define L1_ICON_MASK	0x10
#define L2_ICON_MASK	0x08
#define L3_ICON_MASK	0x04
#define L4_ICON_MASK	0x02
#define L5_ICON_MASK	0x01
#else
#define L1_ICON_MASK	0x01
#define L2_ICON_MASK	0x02
#define L3_ICON_MASK	0x04
#define L4_ICON_MASK	0x08
#define L5_ICON_MASK	0x10
#endif
#define SPEC_PORT_INIT()	P1DIR &=~(L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK|L5_ICON_MASK);P1PU|= ((L1_ICON_MASK|L2_ICON_MASK|L3_ICON_MASK|L4_ICON_MASK|L5_ICON_MASK))


enum {
	LED_RUN_STOP,
	LED_RUN_SPECT,
	LED_RUN_ROLLING,
};

#endif

#include "gpio_config.h"

#if 0
#define led_com_out() P3DIR &= ~0x1F; P3PU |= 0x1F;
#define led_seg_out() P1DIR &= ~0xFF;P1PU |= 0xFF; 

#define LED_COM1   P30
#define LED_COM2   P31
#define LED_COM3   P32
#define LED_COM4   P33
#define LED_COM5   P34

#define LED_COM    P3
#define LED_SEG    P1
#endif

#ifdef AUX_ICON_FOR_RTC_ALM
#ifndef LED_AUX
#define LED_AUX	0
#endif
#endif


#ifdef USE_BAT_MANAGEMENT

#ifdef EXCHANGE_LED_BAT_ICON
#ifdef BAT_LEVEL_LED_ICON_IND
#ifndef LED_BAT_L1
#define LED_BAT_L1 	BIT(LED_F)
#endif

#ifndef LED_BAT_L2
#define LED_BAT_L2 	BIT(LED_G)
#endif

#endif

#else

#ifdef BAT_LEVEL_LED_ICON_IND
#ifndef LED_BAT_L1
#define LED_BAT_L1 	BIT(LED_G)
#endif

#ifndef LED_BAT_L2
#define LED_BAT_L2 	BIT(LED_F)
#endif

#endif
#endif
#endif
#define LED_A   	0
#define LED_B	1
#define LED_C	2
#define LED_D	3
#define LED_E	4
#define LED_F	5
#define LED_G	6
#define LED_H	7

void LED_scan(void);
void updateLED(void);
#ifdef LED_DRVER_USE_SM1628
extern void TM1628_display(u8 dat1,u8 dat2,u8 dat3,u8 dat4,u8 dat5);
#endif
void lcd_power_down(void);

#endif
