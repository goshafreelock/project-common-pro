#include "Custom_config.h"
#ifndef _LCDSEGMENT_H_
#define _LCDSEGMENT_H_

/*
COM1 P30
COM2 P31
COM3 P32
COM4 P33
SEG0~7   P10~P17
SEG8     P34
*/
#include "gpio_config.h"

#ifdef __C51__
#if 0
#define play_led_seg_out() P0DIR &= ~0x80;P0PU |= 0x80;
#endif

#if defined(K000_KT_AMFM_V001)

#define   com_init()      	P3PU |= (0x0F);P3PD |= (0x0F)
#define   close_com(n)    	com_init();P3DIR |= (0x0F);P3DIR &= ~(1<<(n))
#define set_dir_out(n)     	P3DIR &= (1<<(n))
#define set_dir_in(n)     	P3DIR |= ~(1<<(n))
#define	set_com(n)      	P3 |= (1<<(n))
#define   clr_com(n)       	P3 &= ~(1<<(n)) 
	
#define   seg_init()      	P1DIR = 0;P3DIR &= ~(BIT(4));P3PU &= ~(BIT(4));P3PD &= ~(BIT(4));P0DIR &= ~(BIT(2)|BIT(3));P0PU &= ~(BIT(2)|BIT(3));P0PD &= ~(BIT(2)|BIT(3))
#define   seg07_port(n)   	P1 = n
#define   seg8_port(n)	P03 = n
#define   seg9_port(n)	P02 = n
#define   seg10_port(n)	P34 = n

#define   bklt_init()	  	P3DIR &= ~(1<<0);P3 |= (1<<0);

#elif defined(K2045_AJR_2045_V001)
#define   com_init()      	P3PU |= (0x0F);P3PD |= (0x0F)
#define   close_com(n)    	com_init();P3DIR |= (0x0F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      	P3 |= (1<<(n))
#define   clr_com(n)       	P3 &= ~(1<<(n)) 
	
#define   seg_init()      	P1DIR =0;P3DIR &= ~(BIT(4));P3PU &= ~(BIT(4));P3PD &= ~(BIT(4));P0DIR &= ~(BIT(2));P0PU &= ~(BIT(2))
#define   seg07_port(n)   	P1 = n
#define   seg8_port(n)	P34 = n
#define   seg9_port(n)	P02 = n
#define   bklt_init()	  	P0DIR &= ~(BIT(7));P0PU|= (BIT(7))

#elif defined(K000_XingChuang_x821_V001)|| defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)

#define   com_init()      	P3PU |= (0x1F);P3PD |= (0x1F)
#define   close_com(n)    com_init();P3DIR |= (0x1F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      P3 |= (1<<(n))
#define   clr_com(n)       P3 &= ~(1<<(n)) 
	
#define   seg_init()      	P1DIR = 0;//P3DIR &= ~(1<<4)//;P3PU &= ~(1<<4);P3PD &= ~(1<<4)
#define   seg07_port(n)   	P1 = n
#define   bklt_init()	  	//P0DIR &= ~(1<<0);P0PU |= (1<<0);P0 |= (1<<0)
#elif defined(K1150_LS_1150_V001)
#define   com_init()      P3PU |= (0x1F);P3PD |= (0x1F)
#define   close_com(n)    com_init();P3DIR |= (0x1F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      P3 |= (1<<(n))
#define   clr_com(n)       P3 &= ~(1<<(n)) 
	
#define   seg_init()      	P1DIR = 0;P0DIR &= ~(BIT(2));P0PU &= ~(BIT(2))
#define   seg07_port(n)   	P1 = n
#define   seg8_port(n)	P02 = n
#define   bklt_init()	  	P0DIR &= ~(1<<4);P0 |= (1<<4);

#elif defined(K5018_JK_5018_V001)||defined(K5038_JK_5038_V001)
#define   com_init()      	P3PU |= (0x1F);P3PD |= (0x1F)
#define   close_com(n)    	com_init();P3DIR |= (0x1F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      	P3 |= (1<<(n))
#define   clr_com(n)       	P3 &= ~(1<<(n)) 
	
#define   seg_init()      	P1DIR =0
#define   seg07_port(n)   	P1 = n
#define   bklt_init()	  	//P0DIR &= ~(1<<4);P0 |= (1<<4);
#elif defined(K820_LHD_820_V001)
#define   com_init()      P3PU |= (0x0F);P3PD |= (0x0F)
#define   close_com(n)    com_init();P3DIR |= (0x0F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      P3 |= (1<<(n))
#define   clr_com(n)       P3 &= ~(1<<(n)) 
	
#define   seg_init()      P1DIR = 0;P3DIR &= ~(1<<4)//;P3PU &= ~(1<<4);P3PD &= ~(1<<4)
#define   seg07_port(n)   	P1 = n
#define   seg8_port(n)	P34 = n
#define   bklt_init()	  P3DIR &= ~(1<<0);P3 |= (1<<0);

#else

#define   com_init()      P3PU |= (0x1F);P3PD |= (0x1F)
#define   close_com(n)    com_init();P3DIR |= (0x1F);P3DIR &= ~(1<<(n))
    
#define	set_com(n)      P3 |= (1<<(n))
#define   clr_com(n)       P3 &= ~(1<<(n)) 
	
#define   seg_init()      P1DIR = 0;P3DIR &= ~(1<<4)//;P3PU &= ~(1<<4);P3PD &= ~(1<<4)
#define   seg07_port(n)   	P1 = n
#define   seg8_port(n)	P34 = n
#define   bklt_init()	  P3DIR &= ~(1<<0);P3 |= (1<<0);
#endif

#endif

#if defined(K000_ZhuoYue_003_V001)
#define USB_DEV_MASK	0x0040
#define REP_ONE_MASK	0x0000
#define F_USB_DEV  		lcd_buff[4]	
#define F_REP_ONE 		lcd_buff[4]

#define FM_DEV_MASK	0x0044
#define SD_DEV_MASK	0x0020
#define F_FM_DEV		(lcd_buff[0])	
#define F_SD_DEV		(lcd_buff[4])	

#define RTC_ICON_MASK	0x0010
#define F_RTC_ICON		(lcd_buff[4])

#define RTC_PM_MASK	0x0000
#define NUM_1BC_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])
#define F_NUM_1BC		(lcd_buff[1])	

#define RTC_AM_MASK	0x0000
#define AUX_DEV_MASK	0x0000
#define POINTS_MASK		0x0010
#define RTC_ALM_MASK	0x0001
#define REP_ALL_MASK	0x0000
#define F_RTC_AM		(lcd_buff[0])
#define F_AUX_DEV		(lcd_buff[4])	
#define F_POINTS		(lcd_buff[0])	
#define F_RTC_ALM		(lcd_buff[0])	
#define F_REP_ALL		(lcd_buff[0])

#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x01
#define L2_ICON_MASK	0x02
#define L3_ICON_MASK	0x04
#define L4_ICON_MASK	0x08
#elif defined(K1150_LS_1150_V001)
#define USB_DEV_MASK	0x0001
#define F_USB_DEV  		(lcd_buff[0])	

#define AUX_DEV_MASK	0x0000
#define F_AUX_DEV  		(lcd_buff[3])

#define SD_DEV_MASK	0x0008
#define F_SD_DEV		(lcd_buff[0])	

#define FM_DEV_MASK	0x0100
#define F_FM_DEV		(lcd_buff[4])	

#define POINTS_MASK		0x0010
#define F_POINTS		(lcd_buff[4])	

#define FM_MHZ_MASK	0x0000
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0040
#define F_P1_DEV		(lcd_buff[4])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0000
#define F_RTC_ALM		(lcd_buff[3])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])

#define MP3_FAT_MASK		0x0004
#define F_MP3_FAT		(lcd_buff[4])	

#define SPK_MUTE_MASK	0x0000
#define SPK_ICON		(lcd_buff[1])	

#define PLAY_ICON_MASK	0x0002
#define F_PLAY_ICON		(lcd_buff[0])	

#define PAU_ICON_MASK	0x0000
#define F_PAU_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0010
#define BAT_ICON		(lcd_buff[0])	

#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0100
#define REP_ONE_MASK	0x0100
#define REP_RND_MASK	0x0100
#define F_REP_ALL		(lcd_buff[2])
#define F_REP_ONE 		(lcd_buff[3])
#define F_REP_RND 		(lcd_buff[1])

//#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x0040
#define L1_ICON_BUF		(lcd_buff[0])
#define L2_ICON_MASK	0x0080
#define L2_ICON_BUF		(lcd_buff[0])
#define L3_ICON_MASK	0x0100
#define L3_ICON_BUF		(lcd_buff[0])
#define L4_ICON_MASK	0x0020
#define L4_ICON_BUF		(lcd_buff[0])

#elif defined(K2083_KPL_2083_V003)||defined(K2083_SW_2083_V002)

#define USB_DEV_MASK	0x0004
#define F_USB_DEV  		(lcd_buff[4])	

#define AUX_DEV_MASK	0x0001
#define F_AUX_DEV  		(lcd_buff[4])

#define SD_DEV_MASK	0x0010
#define F_SD_DEV		(lcd_buff[4])	

#define FM_DEV_MASK	0x0002
#define F_FM_DEV		(lcd_buff[0])	

#define POINTS_MASK		0x0010
#define F_POINTS		(lcd_buff[0])	

#define FM_MHZ_MASK	0x0002
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0004
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0002
#define F_P1_DEV		(lcd_buff[0])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0080
#define F_RTC_ALM		(lcd_buff[0])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])

#define MP3_FAT_MASK		0x0000
#define F_MP3_FAT		(lcd_buff[4])	

#define SPK_MUTE_MASK	0x0000
#define SPK_ICON		(lcd_buff[1])	

#define PLAY_ICON_MASK	0x0000
#define F_PLAY_ICON		(lcd_buff[0])	

#define PAU_ICON_MASK	0x0000
#define F_PAU_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0080
#define BAT_ICON		(lcd_buff[1])	

#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define REP_RND_MASK	0x0000
#define F_REP_ALL		(lcd_buff[2])
#define F_REP_ONE 		(lcd_buff[3])
#define F_REP_RND 		(lcd_buff[1])

//#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x0080
#define L1_ICON_BUF		(lcd_buff[4])
#define L2_ICON_MASK	0x0080
#define L2_ICON_BUF		(lcd_buff[3])
#define L3_ICON_MASK	0x0080
#define L3_ICON_BUF		(lcd_buff[2])
#define L4_ICON_MASK	0x0080
#define L4_ICON_BUF		(lcd_buff[2])

#elif defined(K5038_JK_5038_V001)

#define USB_DEV_MASK	0x0040
#define F_USB_DEV  		(lcd_buff[0])	

#define AUX_DEV_MASK	0x0000
#define F_AUX_DEV  		(lcd_buff[0])

#define SD_DEV_MASK	0x0020
#define F_SD_DEV		(lcd_buff[0])	

#define FM_DEV_MASK	0x0044
#define F_FM_DEV		(lcd_buff[4])	

#define AM_DEV_MASK	0x0000
#define F_AM_DEV		(lcd_buff[0])	

#define POINTS_MASK		0x0010
#define F_POINTS		(lcd_buff[4])	

#define FM_MHZ_MASK	0x0000
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define SW_MHZ_MASK	0x0000
#define F_SW_DEV		(lcd_buff[1])	

#define FM_P1_MASK		0x0004
#define F_P1_DEV		(lcd_buff[4])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0000
#define F_RTC_ALM		(lcd_buff[3])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])

#define REC_ICON_MASK	0x0000
#define REC_ICON		(lcd_buff[4])	

#define SPK_MUTE_MASK	0x0080
#define SPK_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0000
#define F_BAT_ICON_BUF	(lcd_buff[0])	


#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_REP_ALL		(lcd_buff[0])
#define F_REP_ONE 		(lcd_buff[0])

//#define L_ICON_BUF		(lcd_buff[4])
#define S1_ICON_MASK	0x0000
#define S1_ICON_BUF		(lcd_buff[0])
#define S2_ICON_MASK	0x0000
#define S2_ICON_BUF		(lcd_buff[0])
#define S3_ICON_MASK	0x0000
#define S3_ICON_BUF		(lcd_buff[0])
#define S4_ICON_MASK	0x0000
#define S4_ICON_BUF		(lcd_buff[0])
#elif defined(K5018_JK_5018_V001)

#define USB_DEV_MASK	0x0004
#define F_USB_DEV  		(lcd_buff[1])	

#define AUX_DEV_MASK	0x0000
#define F_AUX_DEV  		(lcd_buff[0])

#define SD_DEV_MASK	0x0004
#define F_SD_DEV		(lcd_buff[1])	

#define FM_DEV_MASK	0x0004
#define F_FM_DEV		(lcd_buff[0])	

#define AM_DEV_MASK	0x0002
#define F_AM_DEV		(lcd_buff[0])	

#define POINTS_MASK		0x0010
#define F_POINTS		(lcd_buff[1])	

#define FM_MHZ_MASK	0x0020
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0080
#define F_KHZ_DEV		(lcd_buff[0])	

#define SW_MHZ_MASK	0x0000
#define F_SW_DEV		(lcd_buff[1])	

#define FM_P1_MASK		0x0000
#define F_P1_DEV		(lcd_buff[3])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0000
#define F_RTC_ALM		(lcd_buff[3])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])

#define REC_ICON_MASK	0x0000
#define REC_ICON		(lcd_buff[4])	

#define SPK_MUTE_MASK	0x0040
#define SPK_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0000
#define F_BAT_ICON_BUF	(lcd_buff[0])	


#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0010
#define F_REP_ALL		(lcd_buff[0])
#define F_REP_ONE 		(lcd_buff[0])

//#define L_ICON_BUF		(lcd_buff[4])
#define S1_ICON_MASK	0x0000
#define S1_ICON_BUF		(lcd_buff[0])
#define S2_ICON_MASK	0x0000
#define S2_ICON_BUF		(lcd_buff[0])
#define S3_ICON_MASK	0x0000
#define S3_ICON_BUF		(lcd_buff[0])
#define S4_ICON_MASK	0x0000
#define S4_ICON_BUF		(lcd_buff[0])

#elif defined(K2045_AJR_2045_V001)
#define USB_DEV_MASK	0x0004
#define F_USB_DEV  		(lcd_buff[3])	

#define AUX_DEV_MASK	0x0100
#define F_AUX_DEV  		(lcd_buff[3])

#define SD_DEV_MASK	0x0001
#define F_SD_DEV		(lcd_buff[3])	

#define FM_DEV_MASK	0x0010
#define F_FM_DEV		(lcd_buff[3])	

#define POINTS_MASK		0x0200
#define F_POINTS		(lcd_buff[0])	

#define FM_MHZ_MASK	0x0040
#define F_MHZ_DEV		(lcd_buff[3])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0040
#define F_P1_DEV		(lcd_buff[3])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0000
#define F_RTC_ALM		(lcd_buff[3])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])


#define SPK_MUTE_MASK	0x0200
#define SPK_ICON		(lcd_buff[1])	

#define BATTERY_MASK	0x0100
#define BAT_ICON		(lcd_buff[0])	

#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_REP_ALL		(lcd_buff[3])
#define F_REP_ONE 		(lcd_buff[0])

//#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x0000
#define L1_ICON_BUF		(lcd_buff[0])
#define L2_ICON_MASK	0x0000
#define L2_ICON_BUF		(lcd_buff[1])
#define L3_ICON_MASK	0x0000
#define L3_ICON_BUF		(lcd_buff[2])
#define L4_ICON_MASK	0x0000
#define L4_ICON_BUF		(lcd_buff[3])
#elif defined(K000_KT_AMFM_V001)

#define USB_DEV_MASK	0x0400
#define F_USB_DEV  		(lcd_buff[1])	

#define AUX_DEV_MASK	0x0400
#define F_AUX_DEV  		(lcd_buff[3])

#define SD_DEV_MASK	0x0400
#define F_SD_DEV		(lcd_buff[2])	

#define FM_DEV_MASK	0x0200
#define F_FM_DEV		(lcd_buff[3])	

#define POINTS_MASK		0x0010
#define F_POINTS		(lcd_buff[0])	

#define FM_MHZ_MASK	0x0002
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0100
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0040
#define F_P1_DEV		(lcd_buff[0])	


#define RTC_ICON_MASK	0x0200
#define F_RTC_ICON		(lcd_buff[1])

#define RTC_ALM_MASK	0x0200
#define F_RTC_ALM		(lcd_buff[2])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[0])


#define SPK_MUTE_MASK	0x0200
#define SPK_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0004
#define BAT_ICON		(lcd_buff[0])	

#define TRADEMARK_MASK	0x0400
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0000
#define F_NUM_1BC		(lcd_buff[1])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_REP_ALL		(lcd_buff[0])
#define F_REP_ONE 		(lcd_buff[4])

//#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x04
#define L1_ICON_BUF		(lcd_buff[0])
#define L2_ICON_MASK	0x04
#define L2_ICON_BUF		(lcd_buff[1])
#define L3_ICON_MASK	0x04
#define L3_ICON_BUF		(lcd_buff[2])
#define L4_ICON_MASK	0x04
#define L4_ICON_BUF		(lcd_buff[3])

#elif defined(K000_XingChuang_x821_V001)

#define USB_DEV_MASK	0x0002
#define F_USB_DEV  		(lcd_buff[4])	

#define AUX_DEV_MASK	0x0000
#define F_AUX_DEV  		(lcd_buff[2])

#define SD_DEV_MASK	0x0004
#define F_SD_DEV		(lcd_buff[4])	

#define FM_DEV_MASK	0x0022
#define F_FM_DEV		(lcd_buff[0])	

#define POINTS_MASK		0x0008
#define F_POINTS		(lcd_buff[0])	

#define FM_MHZ_MASK	0x0000
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0000
#define F_P1_DEV		(lcd_buff[0])	


#define RTC_ICON_MASK	0x0008
#define F_RTC_ICON		(lcd_buff[4])

#define RTC_ALM_MASK	0x0080
#define F_RTC_ALM		(lcd_buff[0])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[4])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[0])


#define SPK_MUTE_MASK	0x0001
#define SPK_ICON		(lcd_buff[4])	

#define BATTERY_MASK	0x0000
#define BAT_ICON		(lcd_buff[0])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_REP_ALL		(lcd_buff[0])
#define F_REP_ONE 		(lcd_buff[0])

#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x80
#define L1_ICON_BUF		(lcd_buff[4])
#define L2_ICON_MASK	0x40
#define L2_ICON_BUF		(lcd_buff[4])
#define L3_ICON_MASK	0x20
#define L3_ICON_BUF		(lcd_buff[4])
#define L4_ICON_MASK	0x10
#define L4_ICON_BUF		(lcd_buff[4])

#elif defined(K2038_DCX_2038_V001)

#define USB_DEV_MASK	0x0008
#define F_USB_DEV  		(lcd_buff[0])	

#define AUX_DEV_MASK	0x0000
#define F_AUX_DEV  		(lcd_buff[0])

#define SD_DEV_MASK	0x0020
#define F_SD_DEV		(lcd_buff[0])	

#define FM_DEV_MASK	0x0050
#define F_FM_DEV		(lcd_buff[0])	

#define POINTS_MASK		0x0004
#define F_POINTS		(lcd_buff[0])	

#define FM_MHZ_MASK	0x0000
#define F_MHZ_DEV		(lcd_buff[0])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0000
#define F_P1_DEV		(lcd_buff[0])	


#define RTC_ICON_MASK	0x0000
#define F_RTC_ICON		(lcd_buff[0])

#define RTC_ALM_MASK	0x0000
#define F_RTC_ALM		(lcd_buff[0])	

#define RTC_PM_MASK	0x0000
#define F_RTC_PM		(lcd_buff[0])

#define RTC_AM_MASK	0x0000
#define F_RTC_AM		(lcd_buff[0])


#define MP3_FAT_MASK		0x0001
#define F_MP3_FAT		(lcd_buff[0])	

#define SPK_MUTE_MASK	0x0000
#define SPK_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0000
#define BAT_ICON		(lcd_buff[0])	

#define REP_ALL_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_REP_ALL		(lcd_buff[0])
#define F_REP_ONE 		(lcd_buff[0])

#define L_ICON_BUF		(lcd_buff[0])
#define L1_ICON_MASK	0x00
#define L1_ICON_BUF		(lcd_buff[4])
#define L2_ICON_MASK	0x00
#define L2_ICON_BUF		(lcd_buff[4])
#define L3_ICON_MASK	0x00
#define L3_ICON_BUF		(lcd_buff[4])
#define L4_ICON_MASK	0x00
#define L4_ICON_BUF		(lcd_buff[4])

#elif defined(K820_LHD_820_V001)

#define USB_DEV_MASK	0x0100
#define F_USB_DEV  		(lcd_buff[0])	

#define AUX_DEV_MASK	0x0001
#define F_AUX_DEV  		(lcd_buff[3])

#define SD_DEV_MASK	0x0001
#define F_SD_DEV		(lcd_buff[1])	

#define FM_DEV_MASK	0x0100
#define F_FM_DEV		(lcd_buff[1])	

#define POINTS_MASK		0x0004
#define F_POINTS		(lcd_buff[3])	

#define FM_MHZ_MASK	0x0100
#define F_MHZ_DEV		(lcd_buff[1])	

#define AM_KHZ_MASK	0x0000
#define F_KHZ_DEV		(lcd_buff[0])	

#define FM_P1_MASK		0x0040
#define F_P1_DEV		(lcd_buff[3])	


#define RTC_ICON_MASK	0x0001
#define F_RTC_ICON		(lcd_buff[3])

#define RTC_ALM_MASK	0x0010
#define F_RTC_ALM		(lcd_buff[3])	

#define RTC_PM_MASK	0x0100
#define F_RTC_PM		(lcd_buff[2])

#define RTC_AM_MASK	0x0100
#define F_RTC_AM		(lcd_buff[3])


#define SPK_MUTE_MASK	0x0000
#define SPK_ICON		(lcd_buff[0])	

#define BATTERY_MASK	0x0080
#define BAT_ICON		(lcd_buff[0])	

#define TRADEMARK_MASK	0x0000
#define TRADEMARK_ICON		(lcd_buff[0])	

#define NUM_1BC_MASK	0x0001
#define F_NUM_1BC		(lcd_buff[2])	

#define REP_ALL_MASK	0x0040
#define REP_ONE_MASK	0x0001
#define F_REP_ALL		(lcd_buff[3])
#define F_REP_ONE 		(lcd_buff[0])

//#define L_ICON_BUF		(lcd_buff[4])
#define L1_ICON_MASK	0x0080
#define L1_ICON_BUF		(lcd_buff[0])
#define L2_ICON_MASK	0x0080
#define L2_ICON_BUF		(lcd_buff[1])
#define L3_ICON_MASK	0x0080
#define L3_ICON_BUF		(lcd_buff[2])
#define L4_ICON_MASK	0x0080
#define L4_ICON_BUF		(lcd_buff[3])

#else

#define USB_DEV_MASK	0x0000
#define REP_ONE_MASK	0x0000
#define F_USB_DEV  		lcd_buff[0]	
#define F_REP_ONE 		lcd_buff[0]

#define FM_DEV_MASK	0x0051
#define SD_DEV_MASK	0x0000
#define F_FM_DEV		(lcd_buff[3])	
#define F_SD_DEV		(lcd_buff[1])	

#define RTC_PM_MASK	0x0000
#define NUM_1BC_MASK	0x0001
#define F_RTC_PM		(lcd_buff[2])
#define F_NUM_1BC		(lcd_buff[1])	

#define RTC_AM_MASK	0x0000
#define AUX_DEV_MASK	0x0000
#define POINTS_MASK		0x0004
#define RTC_ALM_MASK	0x0000
#define REP_ALL_MASK	0x0000
#define F_RTC_AM		(lcd_buff[3])
#define F_AUX_DEV		(lcd_buff[3])	
#define F_POINTS		(lcd_buff[3])	
#define F_RTC_ALM		(lcd_buff[3])	
#define F_REP_ALL		(lcd_buff[3])	



#define F_BAT_1			(lcd_buff[0])	
#define F_BAT_2			(lcd_buff[1])	
#define F_BAT_3			(lcd_buff[2])	
#define F_BAT_4			(lcd_buff[3])	
#endif
void lcd_gpio_scan(void);

#endif
