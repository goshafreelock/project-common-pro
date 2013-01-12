/*--------------------------------------------------------------------------*/
/**@file   key.h
   @brief  按键消息扫描头文件
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef	_KEY_H_
#define _KEY_H_
#include "custom_config.h"

//#define IR_DEBUG
//#define JOY_STICK_DEBUG
//#define ADKEY_DEBUG


#define _MY_IR_KEY_
#ifdef __C51__
#include "config.h"

#ifdef MATRIX_KEY_ENABLE
#if  defined(K015_JLH_2946_V001)
#define KEY_PORT_NUM	3
#elif defined(K627_LHGC_627_V001)
#define KEY_PORT_NUM	4
#endif
#define KEY_DUM			0x00
typedef enum{

	DIR_SET_ONE_CLS_ALL,
	DIR_CLS_ONE_SET_ALL,
}DIR_CMD;
typedef enum{

	PORT_SET_ALL,
	PORT_CLS_ALL,
}GPIO_CMD;
typedef enum{

	K_DIR,
	K_PU,
	K_PD,
	K_PORT
	
}KEY_REG_TYPE;

typedef enum{

	BIT_SET,
	BIT_CLS,
	GET_DATA
}KEY_CMD;

typedef enum{

	PORT_0,
	PORT_1,
	PORT_2,
	PORT_3
	
}KEY_PORT;

typedef struct{
	KEY_PORT KP_PORT;
	u8 KP_PMASK;
}KEY_STRUCT;
#endif


#define adc_start() ADCCON |= 0x80;

void keyInit(void);
void keyScan(void);
#if defined(ADKEY_NEW_METHOD)
u8 get_adkey_1_value(void);
u8 get_adkey_2_value(void);
#endif
#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
bool get_radio_freq_tune_protect();
#endif	
#if defined(TWO_ADKEY_ENABLE)
void keyScan_ADKEY(void);
#endif
void adc_scan(void);
u8 ldoin_voltage(void);
#if defined(USE_BAT_MANAGEMENT)
void bmt_hdlr(void);
void charger_iphone_ctrl(void);
#endif
void dac_sw_check();
#ifdef MATRIX_KEY_ENABLE
void key_matrix_scan(void);
#endif
#ifdef JOG_STICK_FUNC
void JogDetect(void);
#ifdef K523_DeYun_523_V001
void JogDetect_c(void);
#endif
#endif

#if defined(AD_MEASURE_TEMP_FUNC)
void adc_diode_temp_measure_hdlr();
#endif

#if defined(AD_DETECT_OUTSIDE_SOURCE)
bool adc_signal_online_judge();
#endif

#ifdef USB_SD_PORTABLE_BAT_CHARGER
void cell_output_charge_enable(bool f_g);
void cell_level_disp_if(u8 cmd);
#endif

#ifdef USE_CUSTOMIED_GPIO_KEY
void gpio_key_scan_one_or_two();
bool get_pwr_on_rsp();
#endif

#ifdef LOW_BAT_POWER_OFF_MODE
bool get_low_bat_power_lock();
#endif

#ifdef IMPROVED_BAT_MEASURE
void bat_val_arg(void);
#endif

#endif
#include "gpio_config.h"
#if 0
#define ADC_KEY_IO     0x4e
#define ADC_VDD_12     0x48
#define ADC_LDOIN      0x49
#define ADC_MAX_USED   0x03
#endif



#define KEY_BASE_CNT  	6
#define KEY_LONG_CNT  	(150/2)
#define KEY_HOLD_CNT  	15//15


#define  NO_KEY              0xff
#define  NO_MSG              0xff

#if defined(MULTI_MEDIA_BOX)
#define  INFO_SUB_PLUS               0x00
#define  INFO_SUB_MINUS             0x01
#define  INFO_TRE_PLUS                0x02
#define  INFO_TRE_MINUS		      0x03
#define  INFO_SW_PLUS          	      0x04
#define  INFO_SW_MINUS             	0x05
#define  INFO_EQ_CLASS             	0x06
#define  INFO_EQ_JAZZ             	0x07
#define  INFO_EQ_ROCK             	0x08
#define  INFO_EQ_NORMAL            	0x09
#else
#define  INFO_0             0x00
#define  INFO_1             0x01
#define  INFO_2             0x02
#define  INFO_3             0x03
#define  INFO_4             0x04
#define  INFO_5             0x05
#define  INFO_6             0x06
#define  INFO_7             0x07
#define  INFO_8             0x08
#define  INFO_9             0x09
#endif

#if defined(KEY_100_ENABLE)||defined(KEY_10_ENABLE)
#define  INFO_100         0x1d
#else 
#define  INFO_100         0xFF
#endif

#define  INFO_PLAY          		0x0a
#define  INFO_CH_UP         	0x0b
#define  INFO_CH_DOWN       	0x0c
#define  INFO_VOL_PLUS      	0x0d
#define  INFO_VOL_MINUS     	0x0e
#define  INFO_MUTE        		0x0f
#define  INFO_FRE_UP        	0xFF
#define  INFO_STOP      		0x10
#define  INFO_FRE_DOWN      	0xFF
#define  INFO_NEXT_FIL      	0x11
#define  INFO_PREV_FIL      	0x12
#define  INFO_EQ_UP		    	0x13
#define  INFO_EQ_DOWN		0x14
#define  INFO_PICK_SONG	    	0x15
#define  INFO_PICK_FRE		0x16
#define  INFO_MODE			0x17
#define  INFO_PLAY_MODE	0x18
#ifdef KEY_200_ENABLE
#define  INFO_200         	0x19
#define  INFO_10_PLUS	0x1a
#else
#define  INFO_PLUS          	0x19
#define  INFO_MINUS         0x1a
#endif

#ifdef USE_2CH_FUNC
#define INFO_RESET			0x29
#define INFO_DSP			0x30
#define INFO_BASS_UP		0x3b
#define INFO_BASS_DN		0x3c
#define INFO_TREB_UP		0x33
#define INFO_TREB_DN		0x34
#define INFO_OKVOL_UP		0x35
#define INFO_OKVOL_DN		0x36
#define INFO_SWVOL_UP		0x37
#define INFO_SWVOL_DN 		0x38
#define INFO_LOUDNESS 		0x39
#define INFO_SPECT_MODE	0x3a
#endif

#define INFO_CUS_KEY_1		0x35
#define INFO_CUS_KEY_2		0x36
#define INFO_ADVOL_ADJ		0x37

#define  INFO_POWER         0x1b
#define INFO_ALM_BELL		0x1c

#define  INFO_SECOND	     0x1e
#define  INFO_HALF_SECOND	 0x1f
#define  INFO_SPECTRUM_UPDATE	 0xFA

#define  INFO_AUX_MOD	 0x20
#define  INFO_MP3_MOD	 0x21
#define  INFO_FM_MOD	 0x22
#define  INFO_RTC_MOD	 0x30
#define  INFO_WM_MOD	 0x31
#ifdef BLUE_TOOTH_FUNC
#define  INFO_BT_MOD	 0x29
#endif
#define INFO_CH_NEXT	 0x23
#define INFO_CH_PREV	 0x24
#define INFO_RESTORE_SCREEN	0x25
#define INFO_REP_ONE		0x26
#define INFO_REP_ALL		0x27
#define INFO_PC_HOTPLUG	0x28



#define MSG_USB_DISK_IN         0xf0
#define MSG_USB_DISK_OUT        0xf1
#define MSG_USB_PC_IN           0xf2
#define MSG_USB_PC_OUT          0xf3
#define MSG_SDMMC_IN            0xf4
#define MSG_SDMMC_OUT           0xf5
#define MSG_PC_MUTE             0xF6
#define MSG_PC_UNMUTE           0xF7
#define MSG_AUX_IN              0xfd
#define MSG_AUX_OUT             0xfe
#define MSG_IPOD_IN              0xf8
#define MSG_IPOD_OUT             0xf9
#define MSG_MIC_IN              0xfa
#define MSG_MIC_OUT             0xfb
/**/
#define  KEY_HOLD			 0x40
#define  KEY_LONG			 0x60
#define  KEY_SHORT_UP		 0x80
#define  KEY_LONG_UP		 0x00


#define  SEL_GIVEN_DEVICE_GIVEN_FILE        0xE0
#define  SEL_CUR_DEVICE_GIVEN_FILE          0xE1
#define  SEL_GIVEN_FILE                     0xE2
#define  INIT_PLAY                          0xE3
#define  INFO_AUTO_NEXTFILE                 0xe4
#define  INFO_DISP_FILENAME                 0xe5
#define  INFO_DEF_DEVICE                    0xe7
#define  INFO_NEWFILE		                0xe8
#define  INFO_NEWDEVICE		                0xe9
#define  INFO_NEXTMODE		                0xea
#define  INFO_NO_DEV 		  0xeb
//#define  INFO_NO_DEV  		  0xec
#define  INFO_SYS_IDLE  		  0xed
#define  INFO_ALM_ON						0xee
#define INFO_TIMER_OFF		0xec

#define  MAXMSG_CNT                         32

//与解码有关的消息，从0xD0~0xDF,有些是在lib中调用，不能随便修改
#define MUSIC_DEF_NUMBER     0xD0
#define DECODE_MSG_FILE_END  0xD1
#define DECODE_MSG_DISK_ERR  0xD2




#define IR_KEY_1	   INFO_PLAY
#define IR_KEY_2	   INFO_FRE_DOWN
#define IR_KEY_3	   INFO_FRE_UP

#define IR_KEY_4	   INFO_EQ_UP
#define IR_KEY_5	   INFO_VOL_MINUS
#define IR_KEY_6	   INFO_VOL_PLUS

#define IR_KEY_7	   INFO_PREV_FIL
#define IR_KEY_8	   INFO_NEXT_FIL
#define IR_KEY_9	   INFO_MODE

#define IR_KEY_10	   INFO_0
#define IR_KEY_11	   INFO_1
#define IR_KEY_12	   INFO_2
#define IR_KEY_13	   INFO_3
#define IR_KEY_14	   INFO_4
#define IR_KEY_15	   INFO_5
#define IR_KEY_16	   INFO_6
#define IR_KEY_17	   INFO_7
#define IR_KEY_18	   INFO_8
#define IR_KEY_19	   INFO_9
#define IR_KEY_20	   INFO_PICK_SONG
#define IR_KEY_21	   INFO_PICK_FRE



#define  BIT_SDREMOVE       0//BIT(0)
#define  BIT_SDINSERT       1//BIT(1)
#define  BIT_USBREMOVE      2//BIT(4)
#define  BIT_USBINSERT      3//BIT(5)


#define IR_00	INFO_0
#define IR_01	INFO_1
#define IR_02	INFO_2
#define IR_03	INFO_3
#define IR_04	INFO_4
#define IR_05	INFO_5
#define IR_06	INFO_6
#define IR_07	INFO_7
#define IR_08	INFO_8
#define IR_09	INFO_9

#define IR_10	INFO_PLAY
#define IR_11	INFO_PREV_FIL
#define IR_12	INFO_NEXT_FIL

#define IR_13	INFO_EQ_UP
#define IR_14	INFO_VOL_MINUS
#define IR_15	INFO_VOL_PLUS

#define IR_16	INFO_FRE_DOWN
#define IR_17	INFO_FRE_UP

#define IR_18	INFO_PICK_SONG
#define IR_19	INFO_MODE
#define IR_20	INFO_PICK_FRE

#define NO_IR 0xFF

#if defined(USE_ADKEY_FOR_AUX_HP_DETECTION)
#ifdef LARGE_RES_VALUE_FOR_AD_AUX_HP_DETECTION
#define RES_OFFSET				0x0A
#define AD_VOLT_FOR_DET		(0xD0)
#define AD_VOLT_FOR_AUX		(0xE0)
#define AD_VOLT_FOR_HP			(0xEF)
#else
#define RES_OFFSET				0x00
#define AD_VOLT_FOR_DET		(0xC0)
#define AD_VOLT_FOR_AUX		(0xD0-12)
#define AD_VOLT_FOR_HP			(0xE7-12)
#endif
#endif

#if defined(NEW_RES_VALUE_CACULATING)

#if defined( K000_TC_901_V001)
#define RES_PULL_UP			3300		/// 3.3K
#define RES_1				0
#define RES_2				2000
#define RES_3				3900	
#define RES_4				6800
#define RES_5				12000
#define RES_6				20000
#define RES_7				30000
#define RES_8				100000
#elif defined(CUSTOME_GW_RES_VALUE)
#define RES_PULL_UP			3300		/// 3.3K
#define RES_1				0
#define RES_2				1500
#define RES_3				5100	
#define RES_4				7500
#define RES_5				16000
#define RES_6				30000
#define RES_7				36000
#define RES_8				500000
#elif defined(CUSTOME_GW_RES_VALUE_2)
#define RES_PULL_UP			22000		/// 3.3K
#define RES_1				7500
#define RES_2				12000
#define RES_3				16000	
#define RES_4				24000
#define RES_5				36000
#define RES_6				51000
#define RES_7				91000
#define RES_8				220000
#elif defined(CUSTOME_W_SIR_RES_VALUE)
#define RES_PULL_UP			22000		/// 22K
#define RES_1				6200
#define RES_2				9100
#define RES_3				33000	
#define RES_4				51000
#define RES_5				100000
#define RES_6				100000
#define RES_7				100000
#define RES_8				100000
#elif defined(DEFAULT_RES_VALUE_3)
#define RES_PULL_UP			22000		/// 3.3K
#define RES_1				0
#define RES_2				3000
#define RES_3				6200	
#define RES_4				9100
#define RES_5				33000
#define RES_6				51000
#define RES_7				220000
#define RES_8				330000
#elif defined(DEFAULT_RES_VALUE_2)
#define RES_PULL_UP			22000		/// 3.3K
#define RES_1				0
#define RES_2				3000
#define RES_3				6200	
#define RES_4				9100
#define RES_5				36000
#define RES_6				15000
#define RES_7				24000
#define RES_8				33000
#elif defined(DEFAULT_INTERNAL_PULL_RES_VALUE)
#define RES_PULL_UP			10000		/// 3.3K
#define RES_1				100
#define RES_2				2000
#define RES_3				4700	
#define RES_4				7500
#define RES_5				22000
#define RES_6				330000
#define RES_7				330000
#define RES_8				330000
#elif defined(DEFAULT_RES_VALUE_10_RES)
#define RES_PULL_UP			22000		/// 22K
#define RES_1				0
#define RES_2				3000
#define RES_3				6200	
#define RES_4				9100
#define RES_5				15000
#define RES_6				24000
#define RES_7				33000
#define RES_8				51000
#else
#define RES_PULL_UP			3300		/// 3.3K
#define RES_1				0
#define RES_2				470
#define RES_3				1000	
#define RES_4				2000
#define RES_5				3300
#define RES_6				5600
#define RES_7				10000
#define RES_8				33000
#endif

#define RES_VOLT_1			(((255*RES_2)/(RES_2+RES_PULL_UP)+(255*RES_1)/(RES_1+RES_PULL_UP))/2)
#define RES_VOLT_2			(((255*RES_3)/(RES_3+RES_PULL_UP)+(255*RES_2)/(RES_2+RES_PULL_UP))/2)	
#define RES_VOLT_3			(((255*RES_4)/(RES_4+RES_PULL_UP)+(255*RES_3)/(RES_3+RES_PULL_UP))/2)	
#define RES_VOLT_4			(((255*RES_5)/(RES_5+RES_PULL_UP)+(255*RES_4)/(RES_4+RES_PULL_UP))/2)
#define RES_VOLT_5			(((255*RES_6)/(RES_6+RES_PULL_UP)+(255*RES_5)/(RES_5+RES_PULL_UP))/2)
#define RES_VOLT_6			(((255*RES_7)/(RES_7+RES_PULL_UP)+(255*RES_6)/(RES_6+RES_PULL_UP))/2)
#define RES_VOLT_7			(((255*RES_8)/(RES_8+RES_PULL_UP)+(255*RES_7)/(RES_7+RES_PULL_UP))/2)
#define RES_VOLT_NO_KEY	0xF0
#endif

#if defined( CUSTOMER_DEFINED_ADKEY_RESISTOR)

#if defined(NEW_RES_VALUE_CACULATING)
/*Customer define adkey value */
#define ADKEY_RES_1		RES_VOLT_1
#define ADKEY_RES_2		RES_VOLT_2
#define ADKEY_RES_3		RES_VOLT_3
#define ADKEY_RES_4		RES_VOLT_4
#define ADKEY_RES_5		RES_VOLT_5
#define ADKEY_RES_6		RES_VOLT_6
#define ADKEY_RES_7		RES_VOLT_7	
#define ADKEY_RES_NOKEY		RES_VOLT_NO_KEY	/*NO KEY*/
#elif defined(K302_ZhengYang_ZY302_V001)
/*Customer define adkey value */
#define ADKEY_RES_1		0x10
#define ADKEY_RES_2		0x30
#define ADKEY_RES_3		0x4d
#define ADKEY_RES_4		0x6d
#define ADKEY_RES_5		0x8c
#define ADKEY_RES_6		0xae
#define ADKEY_RES_7		0xD0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K777_SW_777_V001)
#define ADKEY_RES_1		0x0C
#define ADKEY_RES_2		0x20
#define ADKEY_RES_3		0x32
#define ADKEY_RES_4		0x44
#define ADKEY_RES_5		0x57
#define ADKEY_RES_6		0x6B
#define ADKEY_RES_7		0x82	/**/
#define ADKEY_RES_8		0x96
#define ADKEY_RES_9		0xA9
#define ADKEY_RES_10	0xC6	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(ADKEY_NEW_METHOD)
#define ADKEY_RES_1		0x0F
#define ADKEY_RES_2		0x2A
#define ADKEY_RES_3		0x41
#define ADKEY_RES_4		0x58
#define ADKEY_RES_5		0x73
#define ADKEY_RES_6		0x8E
#define ADKEY_RES_7		0xA5	/**/
#define ADKEY_RES_8		0xC0
#define ADKEY_RES_9		0xDB
#define ADKEY_RES_10	0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K000_KT_AMFM_V001)
#define ADKEY_RES_1		0x07
#define ADKEY_RES_2		0x15
#define ADKEY_RES_3		0x24
#define ADKEY_RES_4		0x38
#define ADKEY_RES_5		0x50
#define ADKEY_RES_6		0xF0
#define ADKEY_RES_7		0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K000_HG_898_V001)
#define ADKEY_RES_1		0x10
#define ADKEY_RES_2		0x2C
#define ADKEY_RES_3		0x3C
#define ADKEY_RES_4		0x50
#define ADKEY_RES_5		0xF0
#define ADKEY_RES_6		0xF0
#define ADKEY_RES_7		0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K120_YJH_120_V001)
/*Customer define adkey value */
#define ADKEY_RES_1		0x29
#define ADKEY_RES_2		0x5F
#define ADKEY_RES_3		0x78
#define ADKEY_RES_4		0x89
#define ADKEY_RES_5		0xF0
#define ADKEY_RES_6		0xF0
#define ADKEY_RES_7		0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K585_JLH_585_V001)
#define ADKEY_RES_1		0x29
#define ADKEY_RES_2		0x5F
#define ADKEY_RES_3		0x78
#define ADKEY_RES_4		0x89
#define ADKEY_RES_5		0xF0
#define ADKEY_RES_6		0xF0
#define ADKEY_RES_7		0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K000_JLH_309F_V001)
#define ADKEY_RES_1		0x07
#define ADKEY_RES_2		0x1E
#define ADKEY_RES_3		0x2F
#define ADKEY_RES_4		0xF0
#define ADKEY_RES_5		0xF0
#define ADKEY_RES_6		0xF0
#define ADKEY_RES_7		0xF0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#else
/*Customer define adkey value */
#define ADKEY_RES_1		0x10
#define ADKEY_RES_2		0x30
#define ADKEY_RES_3		0x50
#define ADKEY_RES_4		0x70
#define ADKEY_RES_5		0x90
#define ADKEY_RES_6		0xB0
#define ADKEY_RES_7		0xD0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/
#endif

#else
/*Default adkey value */
#define ADKEY_RES_1		0x10
#define ADKEY_RES_2		0x30
#define ADKEY_RES_3		0x50
#define ADKEY_RES_4		0x70
#define ADKEY_RES_5		0x90
#define ADKEY_RES_6		0xB0
#define ADKEY_RES_7		0xD0	/**/
#define ADKEY_RES_NOKEY		0xF0	/*NO KEY*/

#endif

#if defined( CUSTOMER_DEFINED_ADKEY_RESISTOR)

#if defined(SW_V001)||defined(K0000_GW_138B_V001)||defined(SW_V002_CUSTOMED_V001)||defined(SW_V002_CUSTOMED_V003)||defined(SW_V002_CUSTOMED_V002)||defined(SW_V002)||defined(SW_V002_747)||defined(K109_SW001D_V001)||defined(K002_SW_002_Zhuoxin_V001)	//4 交换NEXT PREV按键
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL 
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(CUSTOME_W_SIR_RES_VALUE)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PLAY
#define ADKEY_4		INFO_MODE
#define ADKEY_5		NO_KEY
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K401_KM_401_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_VOL_PLUS
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		INFO_VOL_MINUS
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_JK_HY_SM001_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_STOP
#define ADKEY_6		INFO_EQ_DOWN
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2086_AJR_LS091_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_FM_MOD
#define ADKEY_6		NO_KEY
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K4006_SES_4321_V001)
/*Default adkey value */
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_STOP
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2083_KPL_2083_V001)||defined(K2083_SW_2083_V001)||defined(K2083_SW_2083_V002)||defined(K2083_KPL_2083_V002)||defined(K2083_KPL_2083_V003)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_CUS_KEY_1
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1173_ZK_ALK936_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PLAY
#define ADKEY_4		INFO_EQ_UP
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_6
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_ZG_HA8919_BT_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_PLAY_MODE
#define ADKEY_6		INFO_EQ_UP
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_JK_PORTABLE_CHARGER_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_CUS_KEY_1
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K6037_SES_6037_V001)||defined(K2059_SES_6038_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_PLAY_MODE
#define ADKEY_6		INFO_FM_MOD
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_ZG_HA8918_NOR_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_PLAY_MODE
#define ADKEY_6		INFO_EQ_UP
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1168_YHD_Y003_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_2
#define ADKEY_5		INFO_4
#define ADKEY_6		INFO_5
#define ADKEY_7		INFO_7
#define ADKEY_8		INFO_8
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_GW_168C_V001)
#define ADKEY_1		NO_KEY
#define ADKEY_2		NO_KEY
#define ADKEY_3		INFO_PLAY_MODE
#define ADKEY_4		INFO_NEXT_FIL
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_MODE
#define ADKEY_7		NO_KEY
#define ADKEY_8		INFO_PLAY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_GW_118B_V001)||defined(K0000_GW_ZX015_V001)
#define ADKEY_1		NO_KEY
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		NO_KEY
#define ADKEY_6		INFO_MODE
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_QG_Q6_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		NO_KEY
#define ADKEY_3		NO_KEY
#define ADKEY_4		NO_KEY
#define ADKEY_5		NO_KEY
#define ADKEY_6		NO_KEY
#define ADKEY_7		INFO_PREV_FIL
#define ADKEY_8		INFO_NEXT_FIL
#define ADKEY_NOKEY	NO_KEY
#elif defined(K586_DCX_586_V001)
#define ADKEY_1		INFO_VOL_PLUS
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_0
#define ADKEY_6		INFO_9
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1132_ZK_963_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_MODE
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_2
#define ADKEY_5		INFO_4
#define ADKEY_6		INFO_5
#define ADKEY_7		INFO_7
#define ADKEY_8		INFO_8
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_BT_CHT909_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_PLAY_MODE
#define ADKEY_6		INFO_POWER
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_BT_CHT909_V002)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_STOP
#define ADKEY_6		INFO_POWER
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_BT_CHT909_V003)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_CUS_KEY_1
#define ADKEY_6		INFO_POWER
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1229_WXD_1229_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_FM_MOD
#define ADKEY_6		INFO_MP3_MOD
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_Q16A_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_FM_MOD
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_UST_U51_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PLAY_MODE
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_NEXT_FIL
#define ADKEY_5		INFO_PLAY
#define ADKEY_6		INFO_MODE
#define ADKEY_7		INFO_POWER
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K010_XFW_931_V001)||defined(K3015_XFW_931_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		NO_KEY
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_FMC3_V001)
#define ADKEY_1		INFO_POWER
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_FM_MOD
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_GW_300G_V001)
#define ADKEY_1		INFO_EQ_DOWN
#define ADKEY_2		INFO_PLAY_MODE
#define ADKEY_3		INFO_EQ_UP
#define ADKEY_4		INFO_NEXT_FIL
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_MODE
#define ADKEY_7		INFO_STOP
#define ADKEY_8		INFO_PLAY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_GW_238_V001)
#define ADKEY_1		INFO_EQ_UP
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		INFO_PLAY_MODE
#define ADKEY_6		INFO_MODE
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1115_WXD_1115_V001)
#define ADKEY_1		INFO_3
#define ADKEY_2		INFO_6
#define ADKEY_3		INFO_9
#define ADKEY_4		INFO_0
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_VOL_PLUS
#define ADKEY_7		INFO_NEXT_FIL
#define ADKEY_8		INFO_VOL_MINUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2035_SES_2035_V002)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_STOP
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1097_WK_1097_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PLAY
#define ADKEY_4		INFO_VOL_MINUS
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_6
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2045_AJR_2045_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_RTC_MOD
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_XXX_SX_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_MODE
#define ADKEY_4		INFO_VOL_MINUS
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K779_YJH_779_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_CUS_KEY_1
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_TC_901_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PLAY_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_MODE
#define ADKEY_7		INFO_EQ_DOWN
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_TC_3006_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_EQ_DOWN
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_JLH_2402_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_CUS_KEY_1
#define ADKEY_8		INFO_CUS_KEY_2
#define ADKEY_NOKEY	NO_KEY
#elif defined(K820_LHD_820_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_EQ_DOWN
#define ADKEY_5		INFO_CUS_KEY_1
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_XingChuang_X824_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		NO_KEY
#define ADKEY_8		INFO_POWER 
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1029_JINYI_1029_V001)
#define ADKEY_1		INFO_MODE
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_2
#define ADKEY_5		INFO_3
#define ADKEY_6		INFO_6
#define ADKEY_7		INFO_7
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_JR_210_V001)
#define ADKEY_1		INFO_MODE
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PLAY
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_MUTE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_XinLei_LC2092_V005) ||defined(K000_XinLei_LC2092_V006)||defined(K000_XinLei_LC2092_V005_A8B)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_3
#define ADKEY_4		INFO_4
#define ADKEY_5		INFO_5
#define ADKEY_6		INFO_6
#define ADKEY_7		INFO_7
#define ADKEY_8		INFO_8
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1007_JinYiHeLi_1007_V001) 
#define ADKEY_1		INFO_NEXT_FIL
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_VOL_MINUS
#define ADKEY_4		INFO_VOL_PLUS
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_4
#define ADKEY_NOKEY	NO_KEY
#elif defined(K791_YJH_791_V001)

#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K777_SW_777_V001)
#define ADKEY_1		INFO_9
#define ADKEY_2		INFO_5
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_VOL_MINUS
#define ADKEY_5		INFO_PLAY
#define ADKEY_6		INFO_PREV_FIL
#define ADKEY_7		INFO_VOL_PLUS
#define ADKEY_8		INFO_2
#define ADKEY_9		INFO_6
#define ADKEY_10	INFO_0
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K4010_MY_1258_V001)
#define ADKEY_1		INFO_3
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		INFO_PLAY
#define ADKEY_6		INFO_NEXT_FIL
#define ADKEY_7		INFO_MODE
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K4009_MY_1258_V001)
#define ADKEY_1		INFO_0
#define ADKEY_2		INFO_4
#define ADKEY_3		INFO_5
#define ADKEY_4		INFO_6
#define ADKEY_5		INFO_7
#define ADKEY_6		INFO_8
#define ADKEY_7		INFO_9
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(ADKEY_NEW_METHOD)

#if defined(K1069_AJE_1069_V001)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_6
#define ADKEY_4		INFO_7
#define ADKEY_5		INFO_MUTE
#define ADKEY_6		INFO_PREV_FIL
#define ADKEY_7		INFO_NEXT_FIL
#define ADKEY_8		INFO_POWER
#define ADKEY_9		INFO_PLAY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K4005_AJR_105_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		INFO_POWER
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K5038_JK_5038_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_FM_MOD
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_POWER
#define ADKEY_8		NO_KEY
#define ADKEY_9		NO_KEY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K3031_AP_668_V001)
#define ADKEY_1		INFO_MODE
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_VOL_PLUS
#define ADKEY_5		INFO_VOL_MINUS
#define ADKEY_6		INFO_PLAY
#define ADKEY_7		INFO_RTC_MOD
#define ADKEY_8		NO_KEY
#define ADKEY_9		NO_KEY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1069_ZK_982_V001)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_6
#define ADKEY_4		INFO_7
#define ADKEY_5		INFO_MUTE
#define ADKEY_6		INFO_PREV_FIL
#define ADKEY_7		INFO_NEXT_FIL
#define ADKEY_8		INFO_POWER
#define ADKEY_9		INFO_PLAY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K3021_AP_LG836_V001)
#define ADKEY_1		INFO_MODE
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		INFO_PLUS
#define ADKEY_6		INFO_MINUS
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_9		INFO_VOL_PLUS
#define ADKEY_10	INFO_VOL_MINUS
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1169_ZK_ALK982_V001)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_6
#define ADKEY_4		INFO_7
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_NEXT_FIL
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_9		INFO_PLAY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_TK19_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		INFO_POWER
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1147_JLH_1234_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_2
#define ADKEY_5		INFO_6
#define ADKEY_6		INFO_7
#define ADKEY_7		INFO_8
#define ADKEY_8		INFO_EQ_DOWN
#define ADKEY_9		INFO_MODE
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1147_DCX_D955_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_2
#define ADKEY_5		INFO_6
#define ADKEY_6		INFO_7
#define ADKEY_7		INFO_8
#define ADKEY_8		INFO_RTC_MOD
#define ADKEY_9		INFO_MODE
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_AP16_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		INFO_POWER
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2321_JM_2321_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		INFO_POWER
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_L2A_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		NO_KEY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_M73A_V001)||defined(K0000_MC_H2_V001)||defined(NOR_ADKEY_DEFINITION)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		NO_KEY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_MC_Q18A_V001)||defined(K0000_MC_Q18A_V002)||defined(K0000_MC_Q21_V001)||defined(K0000_MC_DYJ_V001)||defined(K0000_MC_TK19_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_FM_MOD
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_9		NO_KEY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_JLH_938_V001)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_3
#define ADKEY_4		INFO_4
#define ADKEY_5		INFO_5
#define ADKEY_6		INFO_6
#define ADKEY_7		INFO_7
#define ADKEY_8		INFO_8
#define ADKEY_9		INFO_9
#define ADKEY_10	INFO_0
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1069_AJE_1069_V002)
#define ADKEY_1		INFO_1
#define ADKEY_2		INFO_2
#define ADKEY_3		INFO_6
#define ADKEY_4		INFO_7
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_NEXT_FIL
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_9		INFO_PLAY
#define ADKEY_10	NO_KEY
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#else
#define ADKEY_1		INFO_9
#define ADKEY_2		INFO_5
#define ADKEY_3		INFO_1
#define ADKEY_4		INFO_VOL_MINUS
#define ADKEY_5		INFO_PLAY
#define ADKEY_6		INFO_PREV_FIL
#define ADKEY_7		INFO_VOL_PLUS
#define ADKEY_8		INFO_2
#define ADKEY_9		INFO_6
#define ADKEY_10	INFO_0
#define ADKEY_11	NO_KEY
#define ADKEY_NOKEY	NO_KEY
#endif

#elif defined(K800_MingYang_800_V001)
#define ADKEY_1		NO_KEY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_PLAY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2013_JIELONG_2013_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_CUS_KEY_1
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1123_WXD_1123_V001)
#define ADKEY_1		INFO_MODE
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_1
#define ADKEY_5		INFO_2
#define ADKEY_6		INFO_3
#define ADKEY_7		NO_KEY
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1116_WXD_1116_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_1
#define ADKEY_6		INFO_2
#define ADKEY_7		INFO_3
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_TIANYUN_2096_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_STOP
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_KT_AMFM_V001)
#define ADKEY_1		INFO_PREV_FIL 
#define ADKEY_2		INFO_PLAY
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_STOP
#define ADKEY_6		INFO_EQ_UP
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K188_YJH_188_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_VOL_PLUS
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K181_LY_181_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL 
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_PLUS//INFO_EQ_UP
#define ADKEY_6		INFO_MINUS//INFO_PLAY_MODE
#define ADKEY_7		INFO_POWER 
#define ADKEY_8		INFO_MUTE
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_AOKAILIN_535B_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_1
#define ADKEY_7		INFO_6
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_XingChuang_x819_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_POWER
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#elif defined(K180_LY_180_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL 
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_MINUS//INFO_EQ_UP
#define ADKEY_6		INFO_PLUS //INFO_PLAY_MODE
#define ADKEY_7		INFO_POWER 
#define ADKEY_8		INFO_MUTE
#define ADKEY_NOKEY	NO_KEY
#elif defined(K302_ZhengYang_ZY302_V001)
#define ADKEY_1		INFO_PREV_FIL
#define ADKEY_2		INFO_EQ_DOWN 
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP//INFO_EQ_UP
#define ADKEY_6		INFO_PLAY //INFO_PLAY_MODE
#define ADKEY_7		INFO_PLAY_MODE
#define ADKEY_8		INFO_STOP
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1022_WXD_1322_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_VOL_PLUS
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER 
#define ADKEY_NOKEY	NO_KEY
#elif defined(K755_JinYeHeLi_755_V001)||defined(K755_AnJieEr_755_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_VOL_PLUS
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER 
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_AOKAILIN_G01_V001)
#define ADKEY_1		INFO_NEXT_FIL
#define ADKEY_2		NO_KEY
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_POWER
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY

#elif defined(K1144_DCX_956_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_VOL_PLUS
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K1091_XFW_1091_V001)
#define ADKEY_1		INFO_4
#define ADKEY_2		INFO_5
#define ADKEY_3		INFO_9
#define ADKEY_4		INFO_0
#define ADKEY_5		INFO_PREV_FIL
#define ADKEY_6		INFO_PLAY
#define ADKEY_7		INFO_NEXT_FIL
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K2150_HF_1234_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_FM_MOD
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K0000_JK_KHT_830E_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_VOL_PLUS
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K728_SUOERSI_728_V001)||defined(K583_ZX_583_V001)||defined(USE_ONLY_POWER_HOLD_CTRL)
/*Default adkey value */
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K756_JinYiHeLi_756_V001)||defined(K762_JinYiHeLi_762_V001)||defined(K763_JinYiHeLi_763_V001)
#define ADKEY_1		INFO_VOL_PLUS
#define ADKEY_2		INFO_3
#define ADKEY_3		INFO_2
#define ADKEY_4		INFO_1
#define ADKEY_5		INFO_NEXT_FIL
#define ADKEY_6		INFO_PREV_FIL
#define ADKEY_7		INFO_MODE
#define ADKEY_8		INFO_POWER
#define ADKEY_NOKEY	NO_KEY
#elif defined(K120_YJH_120_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_EQ_UP
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_PREV_FIL 
#define ADKEY_5		INFO_MODE
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_JLH_309F_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE 
#define ADKEY_5		NO_KEY
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K000_HG_898_V001)
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_STOP
#define ADKEY_4		INFO_PREV_FIL
#define ADKEY_5		INFO_MODE
#define ADKEY_6		NO_KEY
#define ADKEY_7		NO_KEY
#define ADKEY_8		NO_KEY
#define ADKEY_NOKEY	NO_KEY
#elif defined(K801_TC_801_V002)
/*Default adkey value */
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_EQ_DOWN
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#else
/*Default adkey value */
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_NEXT_FIL
#define ADKEY_3		INFO_PREV_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#endif
#else
/*Default adkey value */
#define ADKEY_1		INFO_PLAY
#define ADKEY_2		INFO_PREV_FIL
#define ADKEY_3		INFO_NEXT_FIL
#define ADKEY_4		INFO_MODE
#define ADKEY_5		INFO_EQ_UP
#define ADKEY_6		INFO_PLAY_MODE
#define ADKEY_7		INFO_VOL_MINUS
#define ADKEY_8		INFO_VOL_PLUS
#define ADKEY_NOKEY	NO_KEY
#endif

#if defined(TWO_ADKEY_ENABLE)
#if defined( CUSTOMER_DEFINED_ADKEY_RESISTOR)

#if defined(K585_YJH_585_V001)||defined(K586_DCX_586_V001)||defined(K756_JinYiHeLi_756_V001)||defined(K762_JinYiHeLi_762_V001)||defined(K763_JinYiHeLi_763_V001)||defined(K1007_JinYiHeLi_1007_V001)
#define ADKEY2_RES_1		0x10
#define ADKEY2_RES_2		0x30
#define ADKEY2_RES_3		0x50
#define ADKEY2_RES_4		0x70
#define ADKEY2_RES_5		0x90
#define ADKEY2_RES_6		0xB0
#define ADKEY2_RES_7		0xD0	/**/
#define ADKEY2_RES_NOKEY		0xF0	/*NO KEY*/
#elif defined(K777_SW_777_V001)
#define ADKEY2_RES_1		0x0C
#define ADKEY2_RES_2		0x20
#define ADKEY2_RES_3		0x32
#define ADKEY2_RES_4		0x44
#define ADKEY2_RES_5		0x57
#define ADKEY2_RES_6		0x6B
#define ADKEY2_RES_7		0x82	/**/
#define ADKEY2_RES_8		0x96
#define ADKEY2_RES_9		0xA9
#define ADKEY2_RES_10		0xC6	/**/
#define ADKEY2_RES_NOKEY	0xF0	/*NO KEY*/
#elif defined(ADKEY_NEW_METHOD)
#define ADKEY2_RES_1		0x0F
#define ADKEY2_RES_2		0x2A
#define ADKEY2_RES_3		0x41
#define ADKEY2_RES_4		0x58
#define ADKEY2_RES_5		0x73
#define ADKEY2_RES_6		0x8E
#define ADKEY2_RES_7		0xA5	/**/
#define ADKEY2_RES_8		0xC0
#define ADKEY2_RES_9		0xDB
#define ADKEY2_RES_10		0xF0	/**/
#define ADKEY2_RES_NOKEY	0xF0	/*NO KEY*/
#else
/*Default adkey value */
#define ADKEY2_RES_1		0x10
#define ADKEY2_RES_2		0x30
#define ADKEY2_RES_3		0x50
#define ADKEY2_RES_4		0x70
#define ADKEY2_RES_5		0x90
#define ADKEY2_RES_6		0xB0
#define ADKEY2_RES_7		0xD0	/**/
#define ADKEY2_RES_NOKEY		0xF0	/*NO KEY*/
#endif

#else
/*Default adkey value */
#define ADKEY2_RES_1		0x10
#define ADKEY2_RES_2		0x30
#define ADKEY2_RES_3		0x50
#define ADKEY2_RES_4		0x70
#define ADKEY2_RES_5		0x90
#define ADKEY2_RES_6		0xB0
#define ADKEY2_RES_7		0xD0	/**/
#define ADKEY2_RES_NOKEY		0xF0	/*NO KEY*/
#endif

#if defined( CUSTOMER_DEFINED_ADKEY_RESISTOR)

#if defined(K585_YJH_585_V001)||defined(K586_DCX_586_V001)
#define ADKEY2_1		INFO_1
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_4
#define ADKEY2_5		INFO_5
#define ADKEY2_6		INFO_6
#define ADKEY2_7		INFO_7
#define ADKEY2_8		INFO_8
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1123_WXD_1123_V001)
#define ADKEY2_1		INFO_4
#define ADKEY2_2		INFO_5
#define ADKEY2_3		INFO_6
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1173_ZK_ALK936_V001)
#define ADKEY2_1		INFO_PLAY_MODE
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		INFO_MODE
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1168_YHD_Y003_V001)
#define ADKEY2_1		INFO_MODE
#define ADKEY2_2		INFO_PLAY
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_VOL_MINUS
#define ADKEY2_5		INFO_6
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_VOL_PLUS
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1132_ZK_963_V001)
#define ADKEY2_1		INFO_PREV_FIL
#define ADKEY2_2		INFO_NEXT_FIL
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_VOL_PLUS
#define ADKEY2_5		INFO_6
#define ADKEY2_6		INFO_VOL_MINUS
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_0
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1116_WXD_1116_V001)
#define ADKEY2_1		INFO_4
#define ADKEY2_2		INFO_5
#define ADKEY2_3		INFO_6
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1115_WXD_1115_V001)
#define ADKEY2_1		INFO_1
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_4
#define ADKEY2_4		INFO_5
#define ADKEY2_5		INFO_7
#define ADKEY2_6		INFO_8
#define ADKEY2_7		INFO_PLAY
#define ADKEY2_8		INFO_MODE
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1097_WK_1097_V001)
#define ADKEY2_1		INFO_VOL_PLUS
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		INFO_MODE
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K0000_XXX_SX_V001)
#define ADKEY2_1		INFO_4
#define ADKEY2_2		INFO_5
#define ADKEY2_3		INFO_6
#define ADKEY2_4		INFO_0
#define ADKEY2_5		INFO_7
#define ADKEY2_6		INFO_8
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_VOL_PLUS
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K791_YJH_791_V001)
#define ADKEY2_1		INFO_4
#define ADKEY2_2		INFO_5
#define ADKEY2_3		INFO_6
#define ADKEY2_4		INFO_VOL_MINUS
#define ADKEY2_5		INFO_7
#define ADKEY2_6		INFO_8
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_0
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1091_XFW_1091_V001)
#define ADKEY2_1		INFO_1
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_6
#define ADKEY2_5		INFO_7
#define ADKEY2_6		INFO_8
#define ADKEY2_7		INFO_PLAY_MODE
#define ADKEY2_8		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K000_XinLei_LC2092_V005)||defined(K000_XinLei_LC2092_V006) ||defined(K000_XinLei_LC2092_V005_A8B)
#define ADKEY2_1		INFO_0
#define ADKEY2_2		INFO_PREV_FIL
#define ADKEY2_3		INFO_NEXT_FIL
#define ADKEY2_4		INFO_MODE
#define ADKEY2_5		INFO_EQ_UP
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_VOL_MINUS
#define ADKEY2_8		INFO_VOL_PLUS
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1029_JINYI_1029_V001)
#define ADKEY2_1		INFO_PLAY
#define ADKEY2_2		INFO_NEXT_FIL
#define ADKEY2_3		INFO_4
#define ADKEY2_4		INFO_5
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K000_AOKAILIN_535B_V001)
#define ADKEY2_1		INFO_0
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_4
#define ADKEY2_5		INFO_5
#define ADKEY2_6		INFO_7
#define ADKEY2_7		INFO_8
#define ADKEY2_8		INFO_9
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K777_SW_777_V001)
#define ADKEY2_1		INFO_100
#define ADKEY2_2		INFO_7
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_EQ_UP
#define ADKEY2_5		INFO_NEXT_FIL
#define ADKEY2_6		INFO_MODE
#define ADKEY2_7		INFO_REP_ONE
#define ADKEY2_8		INFO_4
#define ADKEY2_9		INFO_8
#define ADKEY2_10		INFO_REP_ALL
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K4010_MY_1258_V001)
#define ADKEY2_1		INFO_4
#define ADKEY2_2		INFO_5
#define ADKEY2_3		INFO_6
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_8
#define ADKEY2_6		INFO_9
#define ADKEY2_7		INFO_0
#define ADKEY2_8		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K4009_MY_1258_V001)
#define ADKEY2_1		NO_KEY
#define ADKEY2_2		INFO_MODE
#define ADKEY2_3		INFO_NEXT_FIL
#define ADKEY2_4		INFO_PLAY
#define ADKEY2_5		INFO_PREV_FIL
#define ADKEY2_6		INFO_1
#define ADKEY2_7		INFO_2
#define ADKEY2_8		INFO_3
#define ADKEY2_NOKEY	NO_KEY
#elif defined(ADKEY_NEW_METHOD)

#if defined(K1069_AJE_1069_V001)
#define ADKEY2_1		INFO_3
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_8
#define ADKEY2_5		INFO_9
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_MINUS
#define ADKEY2_8		INFO_PLUS
#define ADKEY2_9		INFO_MODE
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K3031_AP_668_V001)
#define ADKEY2_1		INFO_1
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_4
#define ADKEY2_5		INFO_5
#define ADKEY2_6		INFO_6
#define ADKEY2_7		INFO_7
#define ADKEY2_8		INFO_8
#define ADKEY2_9		INFO_9
#define ADKEY2_10		INFO_0
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1069_ZK_982_V001)
#define ADKEY2_1		INFO_3
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_8
#define ADKEY2_5		INFO_9
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_VOL_PLUS
#define ADKEY2_8		INFO_FM_MOD
#define ADKEY2_9		INFO_RTC_MOD
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1169_ZK_ALK982_V001)
#define ADKEY2_1		INFO_3
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_8
#define ADKEY2_5		INFO_9
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_VOL_PLUS
#define ADKEY2_8		INFO_FM_MOD
#define ADKEY2_9		INFO_RTC_MOD
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1147_JLH_1234_V001)
#define ADKEY2_1		INFO_VOL_MINUS
#define ADKEY2_2		INFO_VOL_PLUS
#define ADKEY2_3		INFO_PLAY
#define ADKEY2_4		INFO_3
#define ADKEY2_5		INFO_4
#define ADKEY2_6		INFO_5
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_0
#define ADKEY2_9		INFO_POWER
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1147_DCX_D955_V001)
#define ADKEY2_1		INFO_NEXT_FIL
#define ADKEY2_2		INFO_VOL_MINUS
#define ADKEY2_3		INFO_VOL_PLUS
#define ADKEY2_4		INFO_3
#define ADKEY2_5		INFO_4
#define ADKEY2_6		INFO_5
#define ADKEY2_7		INFO_9
#define ADKEY2_8		INFO_0
#define ADKEY2_9		INFO_POWER
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K000_JLH_938_V001)
#define ADKEY2_1		INFO_VOL_MINUS
#define ADKEY2_2		INFO_PREV_FIL
#define ADKEY2_3		INFO_PLAY
#define ADKEY2_4		INFO_NEXT_FIL
#define ADKEY2_5		INFO_VOL_PLUS
#define ADKEY2_6		INFO_MODE
#define ADKEY2_7		NO_KEY
#define ADKEY2_8		NO_KEY
#define ADKEY2_9		NO_KEY
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K0000_MC_M73A_V001)||defined(K0000_MC_L2A_V001)
#define ADKEY2_1		INFO_0
#define ADKEY2_2		INFO_1
#define ADKEY2_3		INFO_2
#define ADKEY2_4		INFO_3
#define ADKEY2_5		INFO_4
#define ADKEY2_6		INFO_5
#define ADKEY2_7		INFO_6
#define ADKEY2_8		INFO_7
#define ADKEY2_9		INFO_8
#define ADKEY2_10		INFO_9
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K0000_MC_Q18A_V001)||defined(K0000_MC_Q18A_V002)||defined(K0000_MC_Q21_V001)||defined(K0000_MC_TK19_V001)
#define ADKEY2_1		INFO_0
#define ADKEY2_2		INFO_1
#define ADKEY2_3		INFO_2
#define ADKEY2_4		INFO_3
#define ADKEY2_5		INFO_4
#define ADKEY2_6		INFO_5
#define ADKEY2_7		INFO_6
#define ADKEY2_8		INFO_7
#define ADKEY2_9		INFO_8
#define ADKEY2_10		INFO_9
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K1069_AJE_1069_V002)
#define ADKEY2_1		INFO_3
#define ADKEY2_2		INFO_4
#define ADKEY2_3		INFO_5
#define ADKEY2_4		INFO_8
#define ADKEY2_5		INFO_9
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_VOL_PLUS
#define ADKEY2_8		INFO_FM_MOD
#define ADKEY2_9		INFO_RTC_MOD
#define ADKEY2_10		NO_KEY
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#else
#define ADKEY2_1		INFO_100
#define ADKEY2_2		INFO_7
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_EQ_UP
#define ADKEY2_5		INFO_NEXT_FIL
#define ADKEY2_6		INFO_MODE
#define ADKEY2_7		INFO_REP_ONE
#define ADKEY2_8		INFO_4
#define ADKEY2_9		INFO_8
#define ADKEY2_10		INFO_REP_ALL
#define ADKEY2_11		NO_KEY
#define ADKEY2_NOKEY	NO_KEY
#endif

#elif defined(K1007_JinYiHeLi_1007_V001)
#define ADKEY2_1		INFO_5
#define ADKEY2_2		INFO_6
#define ADKEY2_3		INFO_7
#define ADKEY2_4		INFO_8
#define ADKEY2_5		INFO_9
#define ADKEY2_6		INFO_0
#define ADKEY2_7		INFO_MODE
#define ADKEY2_8		INFO_POWER
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K756_JinYiHeLi_756_V001)||defined(K762_JinYiHeLi_762_V001)||defined(K763_JinYiHeLi_763_V001)
#define ADKEY2_1		INFO_0
#define ADKEY2_2		INFO_9
#define ADKEY2_3		INFO_8
#define ADKEY2_4		INFO_7
#define ADKEY2_5		INFO_VOL_MINUS
#define ADKEY2_6		INFO_6
#define ADKEY2_7		INFO_5
#define ADKEY2_8		INFO_4
#define ADKEY2_NOKEY	NO_KEY
#elif defined(K000_KT_AMFM_V001)
#define ADKEY2_1		INFO_1
#define ADKEY2_2		INFO_2
#define ADKEY2_3		INFO_3
#define ADKEY2_4		INFO_4
#define ADKEY2_5		INFO_5
#define ADKEY2_6		INFO_6
#define ADKEY2_7		INFO_7
#define ADKEY2_8		INFO_8
#define ADKEY2_NOKEY	NO_KEY
#endif
#else
/*Default adkey value */
#define ADKEY2_1		INFO_PLAY
#define ADKEY2_2		INFO_PREV_FIL
#define ADKEY2_3		INFO_NEXT_FIL
#define ADKEY2_4		INFO_MODE
#define ADKEY2_5		INFO_EQ_UP
#define ADKEY2_6		INFO_PLAY_MODE
#define ADKEY2_7		INFO_VOL_MINUS
#define ADKEY2_8		INFO_VOL_PLUS
#define ADKEY2_NOKEY	NO_KEY
#endif

#endif
#endif
