/*--------------------------------------------------------------------------*/
/**@file   key.c
   @brief  按键消息扫描模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "key.h"
#include "clock.h"
#include "main.h"

extern void P0IE_ctl(u8, u8);
extern u8 bP0IE;
extern xd_u8 my_music_vol;
extern u8 play_status;	
extern void putbyte(u8);
extern xd_u8 return_cnt;
extern void Delay_us(u16 i );
extern _xdata SYS_WORK_MODE work_mode;
#ifdef _MY_IR_KEY_
#include "my_IR_key.h"
extern _code MY_IR_KEY_STRUCT My_IRTab[];       /*user code is 0xFF*/
#if defined(USE_TWO_IR_REMOTE)	
extern _code MY_IR_KEY_STRUCT My_IRTab_2[];       /*user code is 0xFF*/
extern u8 get_my_IR2_key_MAX();
u16 _idata MAX_IR2_KEY = 0;
#endif
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
extern bool sys_pwr_on_led_protect_bit;
#endif

#if defined(USE_ADKEY_FOR_AUX_HP_DETECTION)
extern bool earphone_plugged_flag;
extern bool aux_online;
#endif

#if defined(CHARGE_STATE_FOR_LED_PROTECTION)
extern bool sys_led_protect_bit;
#endif

#if defined(VOL_TUNE_FREQ_VOL)||defined(VOL_TUNE_FREQ_ONLY)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
static bool radio_freq_tune_protect=0;
bool get_radio_freq_tune_protect()
{
	if(radio_freq_tune_protect){
		radio_freq_tune_protect=0;
		return  1;
	}
	return 0;
}

#endif
extern u8 get_my_IR_key_MAX();
u16 _idata MAX_IR_KEY = 0;
bool IR_KEY_Detect =0;
#endif
#ifdef MATRIX_KEY_ENABLE
u8 key_gpio_scan_parse(u8 K_mask,KEY_CMD k_cmd,KEY_REG_TYPE k_reg,KEY_PORT k_port);
void config_gpio_dir(DIR_CMD k_cmd,u8 dir_idx);
void config_gpio_port(GPIO_CMD k_cmd);
#endif
bool key_voice_disable;
u8 keyBack;  ///<上一次按键扫描结果
u8 keyCnt;   ///<连续有效的按键扫描计数
u16 _idata user_code;   ///<红外遥控提取的用户码
u8 _idata irStep;      ///<IR当前状态
u16 _idata irBuffer;   ///<IR读取读取出的数据
u8 power_down_cnt;
xd_u8 dac_cnt =0;
#if 0
_code u8 IRTab03[] = 	   /*user code is 0x00*/
{
    /**		0	    1		 2		3	  4		5	    6		 7	    8		 9	     A	  B		C	   D		E	    F
    /*0*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_14, IR_04,  IR_13, NO_IR, NO_IR, IR_01, NO_IR, NO_IR, NO_IR,
    /*1*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_15,  IR_00, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_05, NO_IR, NO_IR, NO_IR,
    /*2*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*3*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*4*/    IR_12,  NO_IR, IR_07, IR_10,  IR_11,  IR_16,  IR_19,  IR_17, NO_IR, NO_IR, IR_09, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*5*/    NO_IR, NO_IR, IR_08, NO_IR,  NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_06, NO_IR, NO_IR, NO_IR, IR_03, NO_IR,

};
#endif
/**/
#if 0
_code u8 IRTab02[] =       /*user code is 0x02*/
{
    IR_KEY_1 ,IR_KEY_2 ,IR_KEY_3 ,NO_KEY,
    IR_KEY_4 ,IR_KEY_5 ,IR_KEY_6 ,NO_KEY,
    IR_KEY_7 ,IR_KEY_8 ,IR_KEY_9 ,NO_KEY,
    IR_KEY_10,IR_KEY_11,IR_KEY_12,NO_KEY,
    IR_KEY_13,IR_KEY_14,IR_KEY_15,NO_KEY,
    IR_KEY_16,IR_KEY_17,IR_KEY_18,NO_KEY,
    IR_KEY_19,IR_KEY_20,IR_KEY_21,NO_KEY,
};

_code u8 IRTab00[] = 	   /*user code is 0x00*/
{
    /*0*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_06, IR_15, IR_08, NO_IR, NO_IR, IR_12, IR_11, NO_IR, NO_IR,
    /*1*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_07, IR_09, NO_IR, IR_13, IR_10, NO_IR, NO_IR, IR_16, NO_IR, NO_IR, NO_IR,
    /*2*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*3*/    NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*4*/    IR_04, IR_18, NO_IR, IR_05, IR_03, IR_00, IR_01, IR_02, NO_IR, NO_IR, IR_20, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR,
    /*5*/    NO_IR, NO_IR, IR_19, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, NO_IR, IR_17, NO_IR, NO_IR, NO_IR, IR_14, NO_IR,

};
#endif
u8 adc_vdd12;
u8 adc_vddio;
u8 adc_vdd12l;
u8 adc_vddiol;
u8 key_value;
#if defined(AD_MEASURE_TEMP_FUNC)
xd_u8  adc_temp=0;
xd_u8 curr_temp=0;
void adc_measure_stragic();
#endif
#if defined(TWO_ADKEY_ENABLE)
u8 key_value_2;
u8 ad_key=0;
#endif
#ifdef ADC_DETECT_LINE_IN
volatile u8 line_in_level,level_last_time= 0,temp_level=0;
u8 line_level_cnt_1=0,line_level_cnt_2=0;
bool Line_In_Detect =0;
#endif
/*------------
----------------------------------------------------------------*/
/**@brief  LDO IN 电量检测
   @param  无
   @return 无
   @note   u8 ldoin_voltage(void)
*/
/*----------------------------------------------------------------------------*/
u8 ldoin_voltage(void)
{
    return (((u16)adc_vddio*(248+5)/10)/adc_vdd12);
}
#if defined(USE_BAT_MANAGEMENT)
#include "led.h"
extern _xdata u8 LED_BUFF[5];
extern bool pwr_up_flag;


#if defined(USB_SD_PORTABLE_BAT_CHARGER)

// 3v3 = 65    3V=  60   2v7 = 54	2v5 = 50
#define BAT_LOW_VOLT   	35
#define BAT_LOW_ALERT  	31
#define BAT_FULL_VOLT	43
#define BAT_HALF_VOLT  	38

#elif defined( BAT_LEVEL_MEASURE_BY_GPIO)
// 3v3 = 65    3V=  60   2v7 = 54	2v5 = 50
#define BAT_LOW_VOLT   	58
#define BAT_LOW_ALERT  	54
#define BAT_FULL_VOLT	62
#define BAT_HALF_VOLT  	61



#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)

#define BAT_FULL_VOLT	40
#define BAT_HALF_VOLT  	36
#define BAT_LOW_VOLT   	33
#define BAT_LOW_ALERT  	30

#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)

#define BAT_FULL_VOLT	40
#define BAT_HALF_VOLT  	38
#define BAT_LOW_VOLT   	35
#define BAT_LOW_1_VOLT   	33
#define BAT_LOW_ALERT  	30


#else

#if defined(K015_983_SW005_ZhuoXin_JR001_V001)||defined(K637_ZX_306_V001)||defined(K646_ZhuoXing_308_V001)||defined(K171_ZX_SW012_ET1013FM_V001)
#define BAT_LOW_VOLT   	32/*LDOIN=3.3V*/ //(41/*LDOIN=3.5V*/) (43/*LDOIN=3.7V*/) (45/*LDOIN=3.8V*/) (46/*LDOIN=3.9V*/) (47/*LDOIN=4.0V*/) (48/*LDOIN=4.1V*/) (49/*LDOIN=4.1V*/) 
#elif defined(K728_SUOERSI_728_V001)||defined(K745_SUOERSI_745_V001)||defined(K000_XinLei_LC2092_V001)||defined(K000_XinLei_LC2092_V002)||defined(K000_XinLei_LC2092_V006)
#define BAT_LOW_VOLT   	35
#elif defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)
#define BAT_LOW_VOLT   	33
#elif defined(K000_JLH_2402_V001)||defined(K2041_XFW_2041_V001)||defined(K2041_XFW_2041_V002)
#define BAT_LOW_VOLT   	35
#define BAT_LOW_ALERT  	32
#elif defined(K0000_MC_Q16A_V001)||defined(K0000_MC_Q18A_V001)||defined(K0000_MC_Q18A_V002)||defined(MEI_CHENG_BAT_PARA)
#define BAT_LOW_VOLT   	37
#define BAT_LOW_ALERT  	35
#elif defined(K1032_ZHONGKAI_1032_V001)||defined(BAT_LEVEL_LED_ICON_IND)
#define BAT_LOW_VOLT   	36
#define BAT_LOW_ALERT  	33
#else
#define BAT_LOW_VOLT   	32
#endif

#define BAT_FULL_VOLT	42
#define BAT_HALF_VOLT  	36
#ifndef  BAT_LOW_ALERT  	
#define BAT_LOW_ALERT  	33
#endif

#define BAT_LOW_POWER_OFF_VOLT	30
#endif

#if defined(NEW_BAT_ICON_DISP)||defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)||defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)
xd_u8 bat_level=0;
#endif
xd_u8 LDO_IN_Volt=0;
bool low_bat_lock=0;
extern u8 play_status;
extern bool key_pwr_up_flag;
#if defined(LOW_VOLT_SPARK_BAT_ICON)	
static bool low_volt_spark=0;
#endif

#ifdef IMPROVED_BAT_MEASURE
#define BAT_AVG_VALUE	6
xd_u8 bat_val[BAT_AVG_VALUE]={0};
void bat_val_arg(void)
{
	u8 i=0;
	static u8 bat_timer=0;
	u16 bat_arg=0;
	
	bat_val[bat_timer++]=ldoin_voltage();

	if(bat_timer ==BAT_AVG_VALUE){
		bat_timer=0;
		for(i=0;i<BAT_AVG_VALUE;i++){
			bat_arg=bat_arg+bat_val[i];
 		}
		LDO_IN_Volt = (u8)(bat_arg/BAT_AVG_VALUE);
 		//printf("IMPROVED_BAT_MEASURE value %d \r\n",(u16)((LDO_IN_Volt)));
	}
}
#endif

#ifdef LOW_BAT_POWER_OFF_MODE

#ifdef FAST_LOW_BAT_PWR_OFF
#define LOW_BAT_POWER_CNT		3
#else
#define LOW_BAT_POWER_CNT		20
#endif

bool low_bat_power_lock=0;
bool get_low_bat_power_lock()
{
	return low_bat_power_lock;
}
#endif


#if defined(CHARGER_DETECT_INDICATOR)


#if defined(K745_SUOERSI_745_V001)||defined(CHARGER_DET_USE_P07)
#define CHARGER_PORT	P07
#elif defined(K591_JiaLe_591_V001)||defined(CHARGER_DET_USE_P02)
#define CHARGER_PORT	P02
#elif defined(K723_LUOMAO_723_V001)||defined(K000_AOKAILIN_535B_V001)||defined(CHARGER_DET_USE_P17)
#define CHARGER_PORT	P17
#elif defined(CHARGER_DET_USE_VPP)
#define CHARGER_PORT	(WKUPPND&BIT(7))
#elif defined(DC_DETECT_USE_P05)
#define CHARGER_PORT	P05
#elif defined(DC_DETECT_USE_P33)
#define CHARGER_PORT	P33
#elif defined(CHARGER_DET_USE_P24)
#define CHARGER_PORT	P24
#else
#define CHARGER_PORT	P04
#endif
bool charger_in_flag=0;
bool charger_detect(void)
{
#if defined(CHARGER_FLASH_TYPE_2)||defined(CHARGER_FLASH_TYPE_3)
    static u8 charger_step=0;
#else
    static bool charger_det=0;
#endif

#if defined(K745_SUOERSI_745_V001)||defined(CHARGER_DET_USE_P07)

    P07 =0;
    P0PU  &= ~(BIT(7));
    P0PD|= (BIT(7));
    P0DIR |= (BIT(7));
#elif defined(CHARGER_DET_USE_VPP)

    WKUPPND|=BIT(6);

#elif defined(K723_LUOMAO_723_V001)||defined(K000_AOKAILIN_535B_V001)||defined(CHARGER_DET_USE_P17)

    P17 =0;
    P1PU  &= ~(BIT(7));
    P1PDA |= (BIT(7));	
    P1DIR |= (BIT(7));
#elif defined(CHARGER_DET_USE_P02)	
    P02 =0;
    P0PU  &= ~(BIT(2));
    P0PD|= (BIT(2));
    P0DIR |= (BIT(2));
#ifdef AC209_28PIN
	P3DIR |= BIT(4);P3PU &= ~(BIT(4));P3PD&= ~(BIT(4));
#endif
#elif defined(DC_DETECT_USE_P05)

   	P05_source_select(0);
       P0PU &=~(BIT(5));
       P0DIR |=(BIT(5));
       P0PD  |=(BIT(5));
#elif defined(DC_DETECT_USE_P33)
       P3PU &=~(BIT(3));
       P3DIR |=(BIT(3));
       P3PD  |=(BIT(3));	   
#elif defined(CHARGER_DET_USE_P24)
	DACCON0|=0x40;
	P24 =0;
    	P2PU  &= ~(BIT(4));
    	P2DIR |= (BIT(4));
	   
#else

    P04 =0;
    P0PU  &= ~(BIT(4));
    P0DIR |= (BIT(4));
    P0PD |= (BIT(4));

#endif

     if(CHARGER_PORT){

		charger_in_flag =1;
#ifdef LOW_BAT_POWER_OFF_MODE
		low_bat_power_lock =0;		
#endif

#if defined(CHARGE_STATE_FOR_LED_PROTECTION)
		sys_led_protect_bit =1;
#endif

#if defined(CHARGER_FLASH_TYPE_1)

		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			LED_STATUS |= LED_BAT_L2;
#if defined(K723_LUOMAO_723_V001)|defined(FULL_BAT_DISP_ALL_ICON)
			LED_STATUS |= LED_BAT_L1;
#endif
			
			charger_in_flag =0;
		}
		else{
			charger_det =~charger_det;
			if(charger_det){
				LED_STATUS |= LED_BAT_L1;
				LED_STATUS &= ~LED_BAT_L2;
			}
			else{
				LED_STATUS &=~LED_BAT_L1;
				LED_STATUS |= LED_BAT_L2;
			}
		}
#elif defined(CHARGER_FLASH_TYPE_2)
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			LED_STATUS |= LED_BAT_L2;
			charger_in_flag =0;
		}
		else{
			
			charger_step++;
			if(charger_step==1){
				//LED_STATUS &= ~LED_BAT_L1;
				LED_STATUS &= ~LED_BAT_L2;
			}
			else if(charger_step==2){

				LED_STATUS |= LED_BAT_L1;
			}
			else if(charger_step==3){

				LED_STATUS |= LED_BAT_L2;
			}
			else if(charger_step==4){
				LED_STATUS &= ~LED_BAT_L1;
				charger_step =0;
			}
		}
#elif defined(CHARGER_FLASH_TYPE_3)
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			LED_STATUS |= LED_BAT_L2;
			charger_in_flag =0;
		}
		else{
			
			charger_step++;
			if(charger_step==1){
				LED_STATUS &= ~LED_BAT_L1;
				LED_STATUS &= ~LED_BAT_L2;
			}
			else if(charger_step==2){

				LED_STATUS |= LED_BAT_L1;
			}
			else if(charger_step==3){

				LED_STATUS |= LED_BAT_L2;
				charger_step =0;				
			}
		}
#elif defined(NEW_BAT_ICON_DISP)
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			charger_in_flag =0;
			bat_level=3;
		}
		else{
			bat_level++;
			
			if(bat_level>3){
				bat_level=0;
			}
		}
#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			charger_in_flag =0;
			bat_level=3;
		}
		else{
			bat_level++;
			
			if(bat_level>3){
				bat_level=0;
			}
		}
#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
			charger_in_flag =0;
			bat_level=4;
		}
		else{
			bat_level++;
			
			if(bat_level>4){
				bat_level=0;
			}
		}		
#elif defined(DC_CHARGE_GPIO_DRV_LED_IND_2)
		DC_CHARGE_LED_INIT();
		DC_CHARGE_LED_H();		

#elif defined(DC_CHARGE_GPIO_DRV_LED_IND)


		DC_CHARGE_LED_INIT();
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
#ifdef REVERSE_DC_CHARGER_LED_IND
			DC_CHARGE_LED_L();		

#else
			DC_CHARGE_LED_H();		
#endif
			charger_in_flag =0;
		}
		else{
			charger_det =~charger_det;
			if(charger_det){
				//sys_printf("DC_CHARGE_LED_H ");
				DC_CHARGE_LED_H();				
			}
			else{
				//sys_printf("DC_CHARGE_LED_L ");	
				DC_CHARGE_LED_L();	

			}
		}
#else

#if defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)
		if(LDO_IN_Volt>=42){

			LED_STATUS |= LED_BAT_L2;
			return ;
		}
		else if(LDO_IN_Volt>BAT_LOW_VOLT){

			LED_STATUS |= LED_BAT_L2;
		}

#endif
		charger_det =~charger_det;
		if(charger_det){
			LED_STATUS &=~LED_BAT_L1;
		}
		else{
			LED_STATUS |=LED_BAT_L1;
		}
#endif		
		return 1;
     }
	charger_in_flag =0;
#if defined(CHARGE_STATE_FOR_LED_PROTECTION)
		sys_led_protect_bit =0;
#endif
#ifdef K0000_MY_FT18_BT_V001
	return 0;
#endif
#if defined(DC_CHARGE_GPIO_DRV_LED_IND)
		DC_CHARGE_LED_L();		
#endif

	return 0;
}
#endif

#ifdef USB_SD_PORTABLE_BAT_CHARGER

xd_u8 batt_level_exit_timer=0;
//#define BATT_PLAY_DEBUG
#if 0
#define BATT_CHARGER_PORT_INIT()	P1DIR |=(BIT(6)|BIT(7));	P1PU|=(BIT(6)|BIT(7))
#define BATT_CHRG_PORT				P16
#define BATT_STBY_PORT				P17

#define OUTPUT_CHARGER_PORT_INIT()	P1DIR &=~(BIT(4));P14=0;P1DIR |=(BIT(4));P1PU &=~(BIT(4));P1PDA&=~(BIT(4))
#define OUTPUT_CHRG_PORT_EN()			P0DIR &=~(BIT(3));P03=1
#define OUTPUT_CHRG_PORT_DIS()			P0DIR &=~(BIT(3));P03=0
#define OUTPUT_STBY_PORT				P14

#define OUTPUT_DEVICE_PORT_INIT()		P1DIR &=~(BIT(5));P15=0;P1DIR |=(BIT(5));P1PU &=~(BIT(5));P1PDA&=~(BIT(5))
#define OUTPUT_DEVICE_PORT				P15
#endif
enum{

	BATT_CHARG_IDLE=0,
	BATT_CHARG_FULL,
	BATT_CHARG_CHARGING,
};
enum{
	LEVEL_LED_ALL_OFF=0,
	LEVEL_LED_ALL_ON,
	LEVEL_LED_PLAY,
	LEVEL_LED_LEVEL_IND,		
	LEVEL_LED_CHRG_IND,		
};
xd_u8 cell_battary_status=0,cell_level_disp_timer=0,cell_level_ind=0;
xd_u8 output_charger_status=0,output_charger_timer=0;
static bool output_discharge_en=0;
void cell_output_charge_enable(bool f_g)
{
	output_discharge_en=f_g;
}
bool get_cell_output_charge_status(void)
{
	return output_discharge_en;
}
void cell_level_measure(void)
{

	//printf("portable_charger_hdlr  VOLT  %u \r\n",(u16)LDO_IN_Volt);

	if(LDO_IN_Volt>=BAT_FULL_VOLT){
		cell_level_ind = 4;
	}
	else if(LDO_IN_Volt>=BAT_HALF_VOLT){
		cell_level_ind = 3;
	}
	else if(LDO_IN_Volt>=BAT_LOW_VOLT){
		cell_level_ind = 2;
	}
	else if(LDO_IN_Volt>=BAT_LOW_ALERT){
		cell_level_ind = 1;
	}
	else{
		cell_level_ind = 0;
	}
}
void cell_level_disp_if(u8 cmd)
{
	static bool led_spark=0;

	EA = 0;
	if(play_status == MUSIC_PLAY){
		
		if(batt_level_exit_timer >2*30){
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_WHEN_CHARGER_LEVEL_0
		    	sys_pwr_on_led_protect_bit=1;
#endif		
		}
		else{
			batt_level_exit_timer++;
			cmd =LEVEL_LED_PLAY;
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_WHEN_CHARGER_LEVEL_0
	    		sys_pwr_on_led_protect_bit=0;
#endif		
		}
	}
	else{

		batt_level_exit_timer=0;
#ifdef SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_WHEN_CHARGER_LEVEL_0
	    sys_pwr_on_led_protect_bit=1;
#endif		
	}
#ifdef BATT_PLAY_DEBUG
	//sys_printf(" ----------------------------->cell_level_disp_if ");
	//printf(" ----------------------------->cell_level_disp_if     %x \r\n",(u16)cmd);
#endif

	P1DIR &=~(0x0F);
	if(cmd==LEVEL_LED_ALL_OFF){

		P1	|=(0x0F);
	}
	else if(cmd ==LEVEL_LED_ALL_ON){
		
		P1	&=~(0x0F);
	}
	else if(cmd == LEVEL_LED_PLAY){

		P1	|=(0x0E);
	}
	else if(cmd == LEVEL_LED_LEVEL_IND){

		P1	|=(0x0F);
		P1	&=~(0x0F>>(4-cell_level_ind));
	}
	else{		

		P1	|=(0x0F);
		P1	&=~(0x0F>>(4-cell_level_ind));
		
		led_spark=~led_spark;

		if(cell_level_ind==0){
			if(led_spark){
				P1&=~(BIT(0));
			}
			else{
				P1|=(BIT(0));
			}
		}
		else{
				
			if(led_spark){	
				P1|=(BIT(cell_level_ind-1));
			}
		}			
	}
	EA = 1;
}
void portable_charger_hdlr()
{
	cell_level_measure();

#ifdef BATT_PLAY_DEBUG
	printf("portable_charger_hdlr  LEVEL %u \r\n",(u16)cell_level_ind);
#endif

	//4 BATTARY CHARGE PHASE...BEGIN...
	BATT_CHARGER_PORT_INIT();
	
	if(BATT_CHRG_PORT){
		if(BATT_STBY_PORT){
			cell_battary_status =BATT_CHARG_FULL;
			cell_level_disp_if(LEVEL_LED_ALL_ON);			
		}
		else{
			cell_battary_status =BATT_CHARG_CHARGING;
		}
	}
	else{
		cell_battary_status =BATT_CHARG_IDLE;
	}
	//4 BATTARY CHARGE PHASE...END..
	

#ifdef BATT_OUTPUT_CHARGER_DETECTION

	//4 OUTPUT CHARGE PHASE...BEGIN...
	OUTPUT_CHARGER_PORT_INIT();
	OUTPUT_DEVICE_PORT_INIT();
	
	if(output_discharge_en){
	//if(OUTPUT_DEVICE_PORT){

		
		if(OUTPUT_STBY_PORT){

			OUTPUT_CHRG_PORT_EN();
			
#ifdef BATT_PLAY_DEBUG
			sys_printf(" OUT PUT -->BATT_CHARG_CHARGING ");
#endif
			output_charger_timer=0;
			output_charger_status =BATT_CHARG_CHARGING;
		}
		else{
			if(output_charger_timer>=12){		
				
#ifdef BATT_PLAY_DEBUG
				sys_printf(" OUT PUT -->BATT_CHARG_FULL ");
#endif				
				OUTPUT_CHRG_PORT_DIS();			
				output_charger_status =BATT_CHARG_FULL;
			}
			else{

#ifdef BATT_PLAY_DEBUG
				sys_printf(" OUT PUT -->DEVICE DISCONNECT  ");
#endif
				output_charger_timer++;

			}
		}
	}
	else{

#ifdef BATT_PLAY_DEBUG
		sys_printf(" OUT PUT -->  BATT_CHARG_IDLE  ");
#endif

		//OUTPUT_CHRG_PORT_DIS();
		output_charger_timer=0;
		output_charger_status =BATT_CHARG_IDLE;
	}
	//4 OUTPUT  CHARGE PHASE...END...
#endif


	if(cell_battary_status ==BATT_CHARG_IDLE){
#ifdef BATT_PLAY_DEBUG
		sys_printf(" BATT_CHARG_IDLE ");
#endif
		cell_level_disp_if(LEVEL_LED_LEVEL_IND);
	}
	else if(cell_battary_status ==BATT_CHARG_CHARGING){
#ifdef BATT_PLAY_DEBUG
		sys_printf(" BATT_CHARG_CHARGING ");
#endif
		cell_level_disp_if(LEVEL_LED_CHRG_IND);
	}
	else if(cell_battary_status ==BATT_CHARG_FULL){
#ifdef BATT_PLAY_DEBUG
		sys_printf(" BATT_CHARG_FULL ");
#endif
		cell_level_disp_if(LEVEL_LED_ALL_ON);
	}
}
#endif

void bmt_hdlr(void)
{
	static u8 low_volt_cnt=0,high_volt_cnt=0;
#ifdef USB_SD_PORTABLE_BAT_CHARGER
	portable_charger_hdlr();
#endif

#if defined(CHARGER_DETECT_INDICATOR)
	if(charger_detect()){

#if defined(CHARGER_FLASH_TYPE_1)||defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)
		return;
#else
		if(LDO_IN_Volt>=BAT_FULL_VOLT){
#if defined(BAT_LEVEL_LED_ICON_IND)			
			LED_STATUS |= LED_BAT_L2;
#endif			
		}
		return;
#endif
	}
#endif

#if defined(BAT_LEVEL_GPIO_DRV_LED_IND)

		BAT_LEVEL_LED_INIT();

		if(LDO_IN_Volt>BAT_LOW_VOLT){
			//sys_printf(" > >>> BAT_LOW_VOLT");
			BAT_LEVEL_LED_1_L();
			BAT_LEVEL_LED_2_H();

		}
		else if(LDO_IN_Volt>=BAT_LOW_ALERT){
			//sys_printf(" > >>> BAT_LOW_ALERT");
			
			BAT_LEVEL_LED_1_H();
			BAT_LEVEL_LED_2_L();
		}
		else{

			low_volt_cnt++;

#ifdef USE_LOW_BAT_SLEEP_MODE
			if(low_volt_cnt>=20){
				low_volt_cnt=0;
				put_msg_fifo(INFO_POWER | KEY_SHORT_UP);
			}
#endif

			if((low_volt_cnt%2)==0){
				//sys_printf(" BAT_LEVEL_LED_2_LLLLLL");
				BAT_LEVEL_LED_2_L();
			}
			else{
				//sys_printf(" BAT_LEVEL_LED_2_HHHH");
				BAT_LEVEL_LED_2_H();
			}

		}

#endif

#ifdef LOW_BAT_POWER_OFF_MODE
		if(LDO_IN_Volt<=BAT_LOW_POWER_OFF_VOLT){

			low_volt_cnt++;			
			if(low_volt_cnt>=LOW_BAT_POWER_CNT){
				//low_volt_cnt=0;

				low_bat_power_lock =1;							

#ifdef USE_POWER_KEY
				sys_power_down();	
#else
				if(work_mode == SYS_IDLE){
					put_msg_fifo(INFO_SYS_IDLE);	
				}
				else{
					put_msg_fifo(INFO_POWER | KEY_SHORT_UP);	
				}
#endif				
			}
		}
		else{
			low_volt_cnt=0;

		}
#endif
  	//  printf("LDO_IN_Volt %d \r\n",(u16)LDO_IN_Volt);
	//  printf("adc_vdd12 %d \r\n",(u16)adc_vdd12);
#if defined(K015_983_SW005_ZhuoXin_JR001_V001)||defined(K637_ZX_306_V001)||defined(K646_ZhuoXing_308_V001)||defined(K171_ZX_SW012_ET1013FM_V001)
	if(LDO_IN_Volt<=BAT_LOW_VOLT){
		
		if(low_volt_cnt++>6){
			low_volt_cnt =0;
			high_volt_cnt =0;
            		if (play_status){
                    		put_msg_fifo(INFO_PLAY | KEY_SHORT_UP);
				low_bat_lock =1;							
			}
		}		
	}
	else{
		
		if(high_volt_cnt++>6){
			high_volt_cnt =0;
			low_volt_cnt =0;
			 if ((!play_status)&&(low_bat_lock)){
                    		put_msg_fifo(INFO_PLAY | KEY_SHORT_UP);
	 			low_bat_lock =0;
			 }
		}
	}
#endif	

#if defined(NEW_BAT_ICON_DISP)
	if(LDO_IN_Volt>=BAT_FULL_VOLT){
		bat_level =3;
	}
	else if(LDO_IN_Volt>=BAT_HALF_VOLT){
		bat_level =2;
	}
	else if(LDO_IN_Volt>=BAT_LOW_VOLT){
		bat_level =1;
	}
	else if(LDO_IN_Volt>BAT_LOW_ALERT){
		bat_level =0;
	}
	
#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)

	if(LDO_IN_Volt>=BAT_FULL_VOLT){
		bat_level =3;
	}
	else if(LDO_IN_Volt>=BAT_HALF_VOLT){
		bat_level =2;
	}
	else if(LDO_IN_Volt>=BAT_LOW_VOLT){
		bat_level =1;
	}
	else if(LDO_IN_Volt>BAT_LOW_ALERT){
		bat_level =0;
	}
#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)
	if(LDO_IN_Volt>=BAT_FULL_VOLT){
		bat_level =4;
	}
	else if(LDO_IN_Volt>=BAT_HALF_VOLT){
		bat_level =3;
	}
	else if(LDO_IN_Volt>=BAT_LOW_VOLT){
		bat_level =2;
	}
	else if(LDO_IN_Volt>=BAT_LOW_1_VOLT){
		bat_level =1;
	}	
	else if(LDO_IN_Volt>BAT_LOW_ALERT){
		bat_level =0;
	}
#else

#if defined(BAT_LEVEL_LED_ICON_IND)||defined(K000_AOKAILIN_508_V001)||defined(K2041_XFW_2041_V001)||defined(K000_XinLei_LC2092_V002)||defined(K000_XinLei_LC2092_V001)||defined(K000_AOKAILIN_535B_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K1025_AIPU_1025_V001)||defined(K1007_JinYiHeLi_1007_V001)||defined(K591_JiaLe_591_V001)||defined(K795_JinYeHeLi_795_V001)||defined(K796_JinYeHeLi_796_V001)||defined(K762_JinYiHeLi_762_V001)||defined(K745_SUOERSI_745_V001)||defined(K763_JinYiHeLi_763_V001)||defined(K585_YJH_585_V001)||defined(K000_AOKAILIN_G01_V001)||defined(K756_JinYiHeLi_756_V001)||defined(K223_BTL_CP153_V001)||defined(K728_SUOERSI_728_V001)||defined(K737_JinYiHeLi_737_V001)

#if defined(USE_PWR_KEY_LONG_PWR_ON)||defined(POWER_KEY_ON_WAIT_FOR_3_SEC)||defined(USE_ONLY_POWER_HOLD_CTRL)
	if(!key_pwr_up_flag)return;
#endif

#ifndef NO_LED_DISPLAY
	if(LDO_IN_Volt<BAT_LOW_VOLT){

			LED_STATUS |= LED_BAT_L1;
			LED_STATUS &= ~LED_BAT_L2;

#if defined(LOW_VOLT_SPARK_BAT_ICON)	

			if(LDO_IN_Volt< BAT_LOW_ALERT){
				
				low_volt_spark=~low_volt_spark;
				#if 0
				if(low_volt_spark){
					LED_STATUS |= LED_BAT_L1;
				}
				else{
					LED_STATUS &=~LED_BAT_L1;
				}				
				#endif
			}
#endif			
	}
	else{

			LED_STATUS &=~LED_BAT_L1;
			LED_STATUS |= LED_BAT_L2;
#if defined(FULL_BAT_DISP_ALL_ICON)
			LED_STATUS |= LED_BAT_L1;
#endif
		
	}
#endif	
#endif	

#endif	
}

#if defined(K000_XingChuang_x821_V001)
extern void wkup_pin_ctrl(bool dir);
void charger_iphone_ctrl(void)
{
	if(LDO_IN_Volt<=52){
		wkup_pin_ctrl(1);
	}
	else{
    		wkup_pin_ctrl(0);
	}
}
#endif

void Bat_icon_chk()
{
#if defined(CHARGER_DETECT_INDICATOR)
#if !defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)&&!defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)
	if(charger_in_flag)return;
#endif	
#endif	

#if defined(USE_PWR_KEY_LONG_PWR_ON)||defined(POWER_KEY_ON_WAIT_FOR_3_SEC)||defined(USE_ONLY_POWER_HOLD_CTRL)
	if(!key_pwr_up_flag)return;
#endif

	if(pwr_up_flag)return;

#ifdef LOW_BAT_POWER_OFF_MODE
	if(low_bat_power_lock)return;		
#endif

#if defined(K723_LUOMAO_723_V001)
	LED_STATUS &=~LED_BAT_L1;
	return;
#endif

#ifndef NO_LED_DISPLAY

#if defined(NEW_BAT_ICON_DISP_AT_LEVEL_THREE)

	LED_STATUS &= ~LED_BAT_L3;
	LED_STATUS &= ~LED_BAT_L2;
	LED_STATUS &= ~LED_BAT_L1;

	if(bat_level==3){
		LED_STATUS |= LED_BAT_L1;
		LED_STATUS |= LED_BAT_L2;
		LED_STATUS |= LED_BAT_L3;
	}
	else if(bat_level==2){
		LED_STATUS |= LED_BAT_L1;
		LED_STATUS |= LED_BAT_L2;
	}
	else if(bat_level==1){
		LED_STATUS |= LED_BAT_L1;
	}
#elif defined(NEW_BAT_ICON_DISP_AT_LEVEL_FOUR)

#elif defined(BAT_LEVEL_LED_ICON_IND)

	if(LDO_IN_Volt<=BAT_LOW_VOLT){

		LED_STATUS |= LED_BAT_L1;
		LED_STATUS &= ~LED_BAT_L2;
		
#if defined(LOW_VOLT_SPARK_BAT_ICON)	

		if(LDO_IN_Volt< BAT_LOW_ALERT){
				
			if(low_volt_spark){
				LED_STATUS |= LED_BAT_L1;
			}
			else{
				LED_STATUS &=~LED_BAT_L1;
			}				
		}
#endif	

	}
	else{

		LED_STATUS &=~LED_BAT_L1;
		LED_STATUS |= LED_BAT_L2;
#if defined(FULL_BAT_DISP_ALL_ICON)
			LED_STATUS |= LED_BAT_L1;
#endif	
	}

#endif	
#endif	
}
#endif
void dac_sw_check()
{
	if(dac_cnt >25){
		dac_cnt =0;
		dac_sw(0);
	}
}
/*----------------------------------------------------------------------------*/
/**@brief  按键遥控初始化keyInit
   @param  无
   @return 无
   @note   void keyInit(void)
*/
/*----------------------------------------------------------------------------*/
void keyInit(void)
{
    ADCCON = 0xf8;
    adc_clock();
    key_value = 0xff;
    //P3PU  &= ~(1<<4);
    //P3DIR |= (1<<4);
#ifdef _MY_IR_KEY_
     MAX_IR_KEY = get_my_IR_key_MAX();
#if defined(USE_TWO_IR_REMOTE)	
     MAX_IR2_KEY = get_my_IR2_key_MAX();
#endif
#endif

}
#ifdef CUSTOM_DEFINE_ADPORT_FUNC
void use_adkey_port_for_voice_det(u8 volt)
{	
	static xd_u8 volt_timer_1=0,volt_timer_2=0;
	
	if(volt>3){
		
		if(volt_timer_1++>30){
			volt_timer_2 =0;
			volt_timer_1 =0;
			P1DIR &=~(BIT(1)| BIT(2));
			P1PU |=(BIT(1)|BIT(2));
			P11 =0;
			P12 = 1;
		}
	}
	else{
		
		if(volt_timer_2++>30){
			volt_timer_1 =0;			
			volt_timer_2 =0;
			P1DIR &=~(BIT(1)| BIT(2));
			P1PU |=(BIT(1)|BIT(2));
			P12 =0;
			P11 =1;			
		}
	}
}

#endif
/*----------------------------------------------------------------------------*/
/**@brief  ADC循环扫描程序 2MS被调用一次,分别扫描VDD1.2
   @param  无
   @return 无
   @note   void adc_scan(void)
*/
/*----------------------------------------------------------------------------*/
#ifdef ADC_DETECT_LINE_IN
void adc_scan(void)
{
    static u8 cnt=0;

    if (cnt == 0)
    {
        adc_vdd12 = ADCDATH;//
        adc_vdd12l = ADCDATL;
        ADCCON = ADC_LDOIN;
    }
    else if (cnt == 1)
    {
        adc_vddio = ADCDATH;//
        adc_vddiol = ADCDATL;//
        ADCCON = ADC_KEY_IO; //
        P0IE &= ~(BIT(6));
    }
    else if (cnt == 2)
    {
        key_value = ADCDATH;//READ VDDIO

        P0PU  |= (BIT(2)); 
	 P0PD  |=(BIT(2));
	 P0DIR |= (BIT(2));
        ADCCON = ADC_LINE_IN;		
        P0IE &= ~(BIT(2));		
		
    }
    else if(cnt == 3)
    {
        line_in_level = ADCDATH;//READ 
        ADCCON = ADC_VDD_12;

#ifdef ADC_DETECT_LINE_IN

	if(work_mode ==SYS_AUX){

		if(line_in_level>level_last_time){
			temp_level = line_in_level - level_last_time;
		}
		else{
			temp_level =level_last_time -  line_in_level;
		}

		level_last_time= line_in_level;

		 if((temp_level>5)){
			
			if(line_level_cnt_1++>16){
				line_level_cnt_1 =0;
				line_level_cnt_2 = 0;	
				
				Line_In_Detect =0;
			}
		 }
		 else{
		 	
			if(line_level_cnt_2++>180){
				line_level_cnt_1 =0;
				line_level_cnt_2 = 0;	

				Line_In_Detect =1;			
			}
		 }

	}
#endif	
    }
    else
    {
        cnt = 0;
    }
    adc_clock();
    cnt++;
    if (cnt >= ADC_MAX_USED)
        cnt = 0;
}
#else
void adc_scan(void)
{
    static u8 cnt=0;

    if (cnt == 0)
    {
        adc_vdd12 = ADCDATH;//
        adc_vdd12l = ADCDATL;
#if defined(BAT_MEASURE_USE_P04_PORT)
        ADCCON = ADC_BAT_IO; //
        P0IE &= ~(BIT(4));
	 P0PU &=~(BIT(4));
#elif defined(BAT_MEASURE_USE_P02_PORT)
        ADCCON = ADC_BAT_IO; //
        P0IE &= ~(BIT(2));
	 P0PU &=~(BIT(2)); 	 
#else
        ADCCON = ADC_LDOIN;		
#endif
    }
    else if (cnt == 1)
    {
        adc_vddio = ADCDATH;//
        adc_vddiol = ADCDATL;//
        ADCCON = ADC_KEY_IO; //
#if defined(ADKEY_USE_P07_PORT)
        P0IE &= ~(BIT(7));
	 P0PU &=~(BIT(7));
#elif defined(ADKEY_USE_P05_PORT)
        P0IE &= ~(BIT(5));
	 P0PU &=~(BIT(5)); 	 
#elif defined(ADKEY_USE_P04_PORT)
        P0IE &= ~(BIT(4));
	 P0PU &=~(BIT(4)); 
#else
	 P0PU &=~(BIT(6));
        P0IE &= ~(BIT(6));
#endif
    }
    else if (cnt == 2)
    {
        key_value = ADCDATH;//READ VDDIO
#ifdef CUSTOM_DEFINE_ADPORT_FUNC
	use_adkey_port_for_voice_det(key_value);
#endif
        
#if defined(TWO_ADKEY_ENABLE)

#if defined(TWO_ADKEY_USE_PORT_P07)
        ADCCON = ADC_KEY_IO_2;
	 P0PU &=~(BIT(7)); 
        P0IE &= ~(BIT(7));
#elif defined(TWO_ADKEY_USE_PORT_P02)
        ADCCON = ADC_KEY_IO_2;
	 P0PU &=~(BIT(2)); 
        P0IE &= ~(BIT(2));		
#else
        ADCCON = ADC_KEY_IO_2;//P04
	 P0PU &=~(BIT(4)); 
        P0IE &= ~(BIT(4));
#endif

#elif defined(AD_MEASURE_TEMP_FUNC)

#if 1
	adc_measure_stragic();
#else
        ADCCON = ADC_TEMP_IO;//P04
	 P0PU &=~(BIT(2)); 
        P0IE &= ~(BIT(2));
#endif
		
#else        
        ADCCON = ADC_VDD_12;
#endif
    }
#if defined(TWO_ADKEY_ENABLE)
    else if (cnt == 3)
    {
        key_value_2 = ADCDATH;//READ VDDIO
        ADCCON = ADC_VDD_12;
    }
#elif defined(AD_MEASURE_TEMP_FUNC)
    else if (cnt == 3)
    {
        //((u8 *)(&adc_temp))[0]=ADCDATH;
        //((u8 *)(&adc_temp))[1]=ADCDATL;
	 adc_temp=ADCDATH;
	 ADCCON = ADC_VDD_12;
    }
#endif	
    else
    {
        cnt = 0;
    }
    adc_clock();
    cnt++;
    if (cnt >= ADC_MAX_USED)
        cnt = 0;
}
#endif

#if defined(AD_MEASURE_TEMP_FUNC)
static bool adc_port_sel=0;
xd_u8 adc_temp_buf[2]={0};
void adc_measure_stragic()
{

	adc_temp_buf[adc_port_sel]=adc_temp;
	
	adc_port_sel=~adc_port_sel;
	if(adc_port_sel){

		P0DIR |=(BIT(2));
	       P0PU  &=~ (BIT(2)); 
	       P0PD&=~ (BIT(2)); 

	       P0PU  &=~ (BIT(3)); 
		P0PD  |=(BIT(3));
		P0DIR &=~(BIT(3));

		P03 =0;
		_nop_();
		_nop_();
		_nop_();		
       	ADCCON = ADC_TEMP_IO_A;//P02
	 	P0PU &=~(BIT(2)); 
        	P0IE &= ~(BIT(2));
	}
	else{

		P0DIR |=(BIT(3));
	       P0PU  &=~ (BIT(3)); 
	       P0PD&=~ (BIT(3)); 

	       P0PU  &=~ (BIT(2)); 
		P0PD  |=(BIT(2));
		P0DIR &=~(BIT(2));
		
		P02 =0;
		_nop_();
		_nop_();
		_nop_();
	       ADCCON = ADC_TEMP_IO_B;//P03
		P0PU &=~(BIT(3)); 
	       P0IE &= ~(BIT(3));
	}
}
extern void Disp_temp(void);
void adc_diode_temp_measure_hdlr()
{
	u8 temp_1=0,temp_2=0;

	temp_1 = adc_temp_buf[1]-18;
	temp_2 = adc_temp_buf[0]-61;

	curr_temp = (temp_1+temp_2)>>1;
	Disp_temp();
	
	//printf("adc_diode_temp_measure_hdlr %x   ---> %x \r\n",(u16)adc_temp_buf[0],(u16)adc_temp_buf[1]);
	printf("adc_diode_temp_measure_hdlr %d   \r\n",(u16)curr_temp);
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief  读取键值keyDetect
   @param  无
   @return 无
   @note   u8 keyDetect(void)
*/
/*----------------------------------------------------------------------------*/

/* for get ir user code
u16 debug_ir;
*/
u8 keyDetect(void)
{
#ifdef _MY_IR_KEY_
    u8 key_index;

    if (irStep == 32)
    {	
 	if(USER_CODE == user_code)
	{
		for(key_index = 1;key_index <MAX_IR_KEY;key_index++){
	            if((My_IRTab[key_index].IR_Key_Value)==(irBuffer & 0xff)){
			//	   printf("keyDetect %x \r\n",(irBuffer & 0xff));
				Delay_us(1);// 莫名其妙
			#if defined(K015_983_SW005_ZhuoXin_FB001_V001)
				if((My_IRTab[key_index].APP_Key ==INFO_PLUS)||(My_IRTab[key_index].APP_Key ==INFO_MINUS)||(My_IRTab[key_index].APP_Key ==INFO_PREV_FIL)||(My_IRTab[key_index].APP_Key ==INFO_NEXT_FIL))
				IR_KEY_Detect =1;
			#else				
				if((My_IRTab[key_index].APP_Key ==INFO_PREV_FIL)||(My_IRTab[key_index].APP_Key ==INFO_NEXT_FIL)||(My_IRTab[key_index].APP_Key ==INFO_PLAY)
#if defined(IR_INFO_EQ_DOWN_SCAN)||defined(IR_INFO_EQ_DOWN_FOR_INTRO_MODE)
				||(My_IRTab[key_index].APP_Key ==INFO_EQ_DOWN)
#elif defined(USE_IR_POWER_KEY_TO_POWER_OFF)				
				||(My_IRTab[key_index].APP_Key ==INFO_POWER)
#elif defined(SEPARATED_FAST_FORDWORD_KEY)				
				||(My_IRTab[key_index].APP_Key ==INFO_PLUS)||(My_IRTab[key_index].APP_Key ==INFO_MINUS)
#endif					
				)
				IR_KEY_Detect =1;
			#endif				
				return (My_IRTab[key_index].APP_Key);
		     }
		}
	}

#if defined(USE_TWO_IR_REMOTE)	
	else if(USER_CODE_2 == user_code)
	{
		for(key_index = 1;key_index <MAX_IR2_KEY;key_index++){
	            if((My_IRTab_2[key_index].IR_Key_Value)==(irBuffer & 0xff)){
			//	   printf("keyDetect %x \r\n",(irBuffer & 0xff));
				Delay_us(1);// 莫名其妙
				if((My_IRTab_2[key_index].APP_Key ==INFO_PREV_FIL)||(My_IRTab_2[key_index].APP_Key ==INFO_NEXT_FIL)||(My_IRTab_2[key_index].APP_Key ==INFO_PLAY))
				IR_KEY_Detect =1;
				return (My_IRTab_2[key_index].APP_Key);
		     }
		}
	}
#endif	
    }
	return NO_KEY;
#else
    u8 keyTemp;
    keyTemp = NO_KEY;
    if (irStep == 32)
    {
        /*
        for get ir user code
        debug_ir = user_code;
        */
        if (0xff00 == user_code)
        {
            keyTemp = IRTab00[irBuffer & 0xff];
        }
        else if (0xfd02 == user_code)
        {
            keyTemp = IRTab02[irBuffer & 0xff];
        }
    }
    return keyTemp;
#endif	
}
#ifdef  USE_POWER_KEY
u8 key_power(void)
{
#if defined(USE_ONLY_POWER_HOLD_CTRL)

#else
    Pwr_Key_input();
    if (GPIO_POWER_KEY)
    {
       return INFO_POWER;
    }
#endif	
    return NO_KEY;
}
#endif

#ifdef USE_CUSTOMIED_GPIO_KEY
bool gpio_key_scan_bit=0;
static bool power_on_rsp=0;
bool get_pwr_on_rsp()
{
	return power_on_rsp;
}
#if defined(K0000_XP_TN891_V001)
u8 _code custom_vol[3]={18,23,30};
void gpio_key_scan_one_or_two()
{
	static bool gpio_k1_edge=0;
	static bool gpio_k2_edge=0;
	static bool gpio_k3_edge=0;
	static xd_u8 k1_timer=0;
	static u8 vol_index=0;
	
	GPIO_KEY_INIT();
	
	if(GPIO_KEY_1_PORT){

		if(k1_timer++>6){

			k1_timer=0;
			if(!gpio_k1_edge){
				gpio_k1_edge=1;

				vol_index = read_info(MEM_FOR_CUST);

				vol_index++;
				if(vol_index>3)vol_index=0;
				my_music_vol =custom_vol[vol_index];
				my_main_vol(my_music_vol);
			       write_info(MEM_FOR_CUST,vol_index);
	        		write_info(MEM_VOL,my_music_vol);
				   
				if(play_status==MUSIC_STOP)
			       	put_msg_fifo(INFO_PLAY|KEY_SHORT_UP);
			}
		}
	}
	else{

		k1_timer=0;
		gpio_k1_edge=0;
	}


	if(GPIO_KEY_2_PORT){

		if(!gpio_k2_edge){
			gpio_k2_edge=1;
		       put_msg_fifo(INFO_NEXT_FIL|KEY_SHORT_UP);
		}
	}
	else{
		gpio_k2_edge=0;
	}


	if(GPIO_KEY_3_PORT){

		power_on_rsp =1;
		if(!gpio_k3_edge){
			gpio_k3_edge=1;
		       put_msg_fifo(INFO_STOP|KEY_SHORT_UP);
		}
	}
	else{

		power_on_rsp =0;
		if(gpio_k3_edge){
			gpio_k3_edge=0;
		       put_msg_fifo(INFO_PLAY|KEY_SHORT_UP);
		}	
	}	
}
#else
void gpio_key_scan_one_or_two()
{
	static bool gpio_pin_edge=0;
	GPIO_KEY_INIT();
	
	if(!GPIO_KEY_PORT){

		if(!gpio_pin_edge){
			gpio_pin_edge=1;
		       put_msg_fifo(INFO_NEXT_FIL|KEY_SHORT_UP);
		}
	}
	else{
		gpio_pin_edge=0;
	}
}
#endif
#endif
void key_tone(void)
{
    power_down_cnt = 0;
	dac_cnt = 0;
    if (key_voice_disable)
    {
        return ;
    }

    sys_clock_pll();//(MAIN_CLK_PLL);
#ifdef _KEY_TONE_ENABEL_   
    dac_sw(1);			//不降频的用户需注掉
    write_dsp(-6, 5, 0x10);
#endif
}
#ifdef JOG_STICK_FUNC
xd_u8 touchkeyval;
xd_u8 keyval_buf;
xd_u8  JogBuf;
#if defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
extern bool new_vol_feature;
#endif
void JogDetect(void)
{
	u8 port_val=0;
	
    touchkeyval = 0;
#if defined(K523_DeYun_523_V001)
    P0DIR &= ~(BIT(2)|(BIT(3)));    //P11, P12
    P0 |=(BIT(2)|(BIT(3)));
    P0PU	|= (BIT(2)|(BIT(3)));
    P0DIR |= (BIT(2)|(BIT(3)));    //P11, P12
    Delay_us(1);
    port_val =(P0&(BIT(2)|(BIT(3))));
    touchkeyval = ((port_val & (BIT(2)))>>2)|((port_val & (BIT(3)))>>2);
#elif defined(K0000_MC_FMC3_V001)||defined(K0000_MC_DYJ_V001)

    WKUPPND|=BIT(6);
    P1DIR &= ~(BIT(7));    //P11, P12
    P1 |=(BIT(7));
    P1PU	|= (BIT(7));
    P1DIR |= (BIT(7));    //P11, P12
    Delay_us(3);
    port_val =(P1&(BIT(7)))>>7;
    if((WKUPPND&BIT(7))>0){
	port_val|=0x02;
    }
    touchkeyval = port_val;	
#elif defined(K1123_WXD_1123_V001)
    P0DIR &= ~(BIT(4));    
    P3DIR &= ~(BIT(4));    
    P0 |=(BIT(4));
    P3 |=(BIT(4));
    P0PU	|= (BIT(4));
    P3PU	|= (BIT(4));
    P0DIR |= (BIT(4));    //P11, P12
    P3DIR |= (BIT(4));    //P11, P12
    Delay_us(1);
    port_val =(P0&(BIT(4)));
    touchkeyval = ((port_val & (BIT(4)))>>4)|((P3&(BIT(4)))>>3);	
#elif defined(K000_JR_210_V001)||defined(K2321_JM_2321_V001)||defined(K6037_SES_6037_V001)||defined(K2083_KPL_2083_V001)||defined(K2086_AJR_LS091_V001)
    P0DIR &= ~(BIT(2)|(BIT(4)));    //P11, P12
    P0 |=(BIT(2)|(BIT(4)));
    P0PU	|= (BIT(2)|(BIT(4)));
    P0DIR |= (BIT(2)|(BIT(4)));    //P11, P12
    Delay_us(1);
    port_val =(P0&(BIT(2)|(BIT(4))));
    touchkeyval = ((port_val & (BIT(2)))>>2)|((port_val & (BIT(4)))>>3);	
#elif defined(K000_KT_AMFM_V001)
    DACCON0 |=0x80;
    P2DIR &= ~(BIT(6)|(BIT(7)));    //P11, P12
    P2 |=(BIT(6)|(BIT(7)));
    P2PU	|= (BIT(6)|(BIT(7)));
    P2DIR |= (BIT(6)|(BIT(7)));    //P11, P12
    Delay_us(1);
    port_val =(P2&(BIT(6)|(BIT(7))));
    touchkeyval = ((port_val & (BIT(6)))>>6)|((port_val & (BIT(7)))>>6);
#else
    P0DIR &= ~(BIT(2)|(BIT(4)));    //P11, P12
    P0 |=(BIT(2)|(BIT(4)));
    P0PU	|= (BIT(2)|(BIT(4)));
    P0DIR |= (BIT(2)|(BIT(4)));    //P11, P12
    Delay_us(1);
    port_val =(P0&(BIT(2)|(BIT(4))));
    touchkeyval = ((port_val & (BIT(2)))>>2)|((port_val & (BIT(4)))>>3);
#endif

#ifdef JOY_STICK_DEBUG
	printf(" ---> JogDetect %x \r\n",(u16)touchkeyval);
#endif

	if((touchkeyval == 0x00) || (touchkeyval == 0x03))
    {										
        if(touchkeyval == keyval_buf)
        {
            JogBuf = 0;
        }
        else
        {
            keyval_buf = touchkeyval;
            if (touchkeyval == 0x00)
            {
                if (JogBuf == 0x02)
                {
                    // Increase
#ifdef JOY_STICK_DEBUG                    
			printf(" Increase \r\n");
#endif
	             //put_msg_fifo(INFO_VOL_PLUS);
#ifdef K523_DeYun_523_V001
		if(work_mode == SYS_FMREV){
	             put_msg_fifo(INFO_CH_UP|KEY_SHORT_UP);
		}
		else{
	             put_msg_fifo(INFO_NEXT_FIL|KEY_SHORT_UP);
		}
#elif defined(VOL_TUNE_FREQ_ONLY)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
		     radio_freq_tune_protect =1;
	             put_msg_fifo(INFO_MINUS);
		}		
#elif defined(VOL_TUNE_FREQ_VOL)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE			
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
		     radio_freq_tune_protect =1;
	             put_msg_fifo(INFO_MINUS);
		}
		else{
	             put_msg_fifo(INFO_VOL_MINUS);
		}
#elif defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)

		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
			if(new_vol_feature){
		             put_msg_fifo(INFO_VOL_MINUS);
			}
			else{
			     	radio_freq_tune_protect =1;
		             	put_msg_fifo(INFO_MINUS);
			}
		}
		else{
			new_vol_feature=1;
	             put_msg_fifo(INFO_VOL_MINUS);
		}			
#elif defined(K000_KT_AMFM_V001)||defined(VOL_TUNE_CH_VOL)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE			
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
	             put_msg_fifo(INFO_NEXT_FIL|KEY_SHORT_UP);
		}
		else{
	             put_msg_fifo(INFO_VOL_MINUS);
		}
#else		             
	             put_msg_fifo(INFO_VOL_MINUS);
#endif
					
                    JogBuf = 0;
                }
                if (JogBuf == 0x01)
                {
                    // Decrease
#ifdef JOY_STICK_DEBUG                    
			printf(" Decrease \r\n");
#endif

#ifdef K523_DeYun_523_V001
		if(work_mode == SYS_FMREV){
	             put_msg_fifo(INFO_CH_DOWN|KEY_SHORT_UP);
		}
		else{
                    put_msg_fifo(INFO_PREV_FIL|KEY_SHORT_UP);
		}
		
#elif defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)

		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
			if(new_vol_feature){
		             put_msg_fifo(INFO_VOL_PLUS);
			}
			else{
			     	radio_freq_tune_protect =1;
		             	put_msg_fifo(INFO_PLUS);
			}
		}
		else{
		      new_vol_feature=1;
	             put_msg_fifo(INFO_VOL_PLUS);
		}	

#elif defined(VOL_TUNE_FREQ_ONLY)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
		     radio_freq_tune_protect =1;
	             put_msg_fifo(INFO_PLUS);
		}
#elif defined(VOL_TUNE_FREQ_VOL)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
		     radio_freq_tune_protect =1;
	             put_msg_fifo(INFO_PLUS);
		}
		else{
	             put_msg_fifo(INFO_VOL_PLUS);
		}		
#elif defined(K000_KT_AMFM_V001)||defined(VOL_TUNE_CH_VOL)
		if((work_mode == SYS_FMREV)
#ifdef RADIO_AM_WM_ENABLE						
		   ||(work_mode == SYS_AMREV)
#endif			
		)
		{
	             put_msg_fifo(INFO_PREV_FIL|KEY_SHORT_UP);
		}
		else{
	             put_msg_fifo(INFO_VOL_PLUS);
		}		
#else			
                    put_msg_fifo(INFO_VOL_PLUS);
#endif
	             //put_msg_fifo(INFO_VOL_MINUS);
                    JogBuf = 0;
                }
            }
            else
            {
                if (JogBuf == 0x02)
                {
			//printf(" ------Decrease \r\n");
                    JogBuf = 0;
                }
                if (JogBuf == 0x01)
                {			
			//printf(" -----Increase \r\n");
                    JogBuf = 0;
                }					
            }
        }
    }
	else
	{
		JogBuf = touchkeyval;
    }
}
#ifdef K523_DeYun_523_V001
xd_u8 touchkeyval_c;
xd_u8 keyval_buf_c;
xd_u8  JogBuf_c;
void JogDetect_c(void)
{
	u8 port_val_c=0;
	
    touchkeyval_c = 0;
	
    P0DIR &= ~(BIT(4)|(BIT(5)));    //P11, P12
    P0 |=(BIT(4)|(BIT(5)));
    P0PU	|= (BIT(4)|(BIT(5)));
    P0DIR |= (BIT(4)|(BIT(5)));    //P11, P12
    Delay_us(1);
    port_val_c =(P0&(BIT(4)|(BIT(5))));
    touchkeyval_c = ((port_val_c & (BIT(4)))>>4)|((port_val_c & (BIT(5)))>>4);

	if((touchkeyval_c == 0x00) || (touchkeyval_c == 0x03))
    {										
        if(touchkeyval_c == keyval_buf_c)
        {
            JogBuf_c = 0;
        }
        else
        {
            keyval_buf_c = touchkeyval_c;
            if (touchkeyval_c == 0x00)
            {
                if (JogBuf_c == 0x02)
                {
                    // Increase
			//printf(" Increase00000000000 \r\n");
	             //put_msg_fifo(INFO_VOL_PLUS);
			if(work_mode == SYS_FMREV){	             
	             		put_msg_fifo(INFO_PREV_FIL|KEY_SHORT_UP);
			}
					
                    JogBuf_c = 0;
                }
                if (JogBuf_c == 0x01)
                {
                    // Decrease

			//printf(" Decrease 0000000000\r\n");
			if(work_mode == SYS_FMREV){	             			
                    		put_msg_fifo(INFO_NEXT_FIL|KEY_SHORT_UP);
			}
	             //put_msg_fifo(INFO_VOL_MINUS);
                    JogBuf_c = 0;
                }
            }
            else
            {
                if (JogBuf_c == 0x02)
                {

                    // Decrease
			//printf(" ------Decrease \r\n");
                    JogBuf_c = 0;
                }
                if (JogBuf_c == 0x01)
                {			
                    // Increase 
			//printf(" -----Increase \r\n");
                    JogBuf_c = 0;
                }					
            }
        }
    }
	else
	{
		JogBuf_c = touchkeyval_c;
    }
}
#endif
#endif
/*----------------------------------------------------------------------------*/
/**@brief  处理扫描到的按键，长按、短按、HOLD按键状态等在这里进行 ；按键音也在这里处理
   @param  无
   @return 无
   @note void keyScan(void)
   @note 开发板ADKEY结果：
   @note VOL-(0v): 0
   @note VOL+(0.43v): 0x21
   @note PREV(0.82v): 0x3F
   @note NEXT(1.237v): 0x5F
   @note PLAY(1.616v): 0x7C
   @note FM/MP3(2.05v): 0x9E
   @note EQ(2.50v): 0xC1
   @note PlayMode(2.93v): 0xE2
*/
/*----------------------------------------------------------------------------*/
#if defined(ADKEY_NEW_METHOD)
u8 get_adkey_1_value(void)
{
#ifndef USE_ADKEY_FOR_AUX_HP_DETECTION_AT_SECOND_ADKEY

#if defined(USE_ADKEY_FOR_AUX_HP_DETECTION)

#ifdef USE_ADKEY_DETECT_HP
	static xd_u8 det_timer_1=0;
#endif

#ifdef USE_ADKEY_DETECT_AUX				
	static xd_u8 det_timer_2=0;
#endif
	if(key_value<ADKEY_RES_NOKEY){

		if(key_value>AD_VOLT_FOR_DET){

			if(key_value>AD_VOLT_FOR_HP){

#ifdef USE_ADKEY_DETECT_AUX						
			 	if (aux_online)
		        	{
					det_timer_2 =0;
		            		put_msg_lifo(MSG_AUX_OUT);
		            		aux_online = 0;
		        	}
#endif		
				
#ifdef USE_ADKEY_DETECT_HP
				if(det_timer_1++>10){

					det_timer_1 =0;

					if(!earphone_plugged_flag){
						earphone_plugged_flag =1;
					}
				}
#endif				
			}
			else if(key_value>AD_VOLT_FOR_AUX){

#ifdef USE_ADKEY_DETECT_HP		
				if(earphone_plugged_flag){
					det_timer_1 =0;
					earphone_plugged_flag =0;
				}
#endif		
				
#ifdef USE_ADKEY_DETECT_AUX				
				if(det_timer_2++>10){
					det_timer_2 =0;
			            if (!aux_online)
			            {
			                put_msg_lifo(MSG_AUX_IN);
			                aux_online = 1;
			            }
				}
#endif				
			}
			else{

#ifdef USE_ADKEY_DETECT_HP
				if(det_timer_1++>10){

					det_timer_1 =0;

					if(!earphone_plugged_flag){
						earphone_plugged_flag =1;
					}
				}
#endif				

#ifdef USE_ADKEY_DETECT_AUX				
				if(det_timer_2++>10){
					det_timer_2 =0;
			            if (!aux_online)
			            {
			                put_msg_lifo(MSG_AUX_IN);
			                aux_online = 1;
			            }
				}
#endif				
			}
			return NO_KEY;
		}
	}	
	else{
#ifdef USE_ADKEY_DETECT_AUX						
	 	if (aux_online)
        	{
			det_timer_2 =0;
            		put_msg_lifo(MSG_AUX_OUT);
            		aux_online = 0;
        	}
#endif		
#ifdef USE_ADKEY_DETECT_HP		
		if(earphone_plugged_flag){
			det_timer_1 =0;
			earphone_plugged_flag =0;
		}
#endif		
	}
#endif
#endif

  	if(key_value>ADKEY_RES_NOKEY)
      	   	return NO_KEY;
#if defined(EXTENDED_ADKEY_NUM)	
     	else if(key_value>ADKEY_RES_10)
          	return ADKEY_11;
    	else if(key_value>ADKEY_RES_9)
          	return ADKEY_10;
  	else if(key_value>ADKEY_RES_8)
          	return ADKEY_9;
#endif	
 	else if(key_value>ADKEY_RES_7)
      	  	return ADKEY_8;
 	else if(key_value>ADKEY_RES_6)
        	return ADKEY_7;
 	else if(key_value>ADKEY_RES_5)
        	return ADKEY_6;
 	else if(key_value>ADKEY_RES_4)
        	return ADKEY_5;
 	else if(key_value>ADKEY_RES_3)
        	return ADKEY_4;
 	else if(key_value>ADKEY_RES_2)
        	return ADKEY_3;
 	else if(key_value>ADKEY_RES_1)
        	return ADKEY_2;
  	else 
        	return ADKEY_1;  
} 

#if defined(TWO_ADKEY_ENABLE)
u8 get_adkey_2_value(void)
{
#if defined(USE_ADKEY_FOR_AUX_HP_DETECTION_AT_SECOND_ADKEY)
#if defined(USE_ADKEY_FOR_AUX_HP_DETECTION)

#ifdef USE_ADKEY_DETECT_HP
	static xd_u8 det_timer_1=0;
#endif

#ifdef USE_ADKEY_DETECT_AUX				
	static xd_u8 det_timer_2=0;
#endif
	if(key_value_2<ADKEY2_RES_NOKEY){

		if(key_value_2>AD_VOLT_FOR_DET){

			if(key_value_2>AD_VOLT_FOR_HP){

#ifdef USE_ADKEY_DETECT_AUX						
			 	if (aux_online)
		        	{
					det_timer_2 =0;
		            		put_msg_lifo(MSG_AUX_OUT);
		            		aux_online = 0;
		        	}
#endif		
				
#ifdef USE_ADKEY_DETECT_HP
				if(det_timer_1++>10){

					det_timer_1 =0;

					if(!earphone_plugged_flag){
						earphone_plugged_flag =1;
					}
				}
#endif				
			}
			else if(key_value_2>AD_VOLT_FOR_AUX){

#ifdef USE_ADKEY_DETECT_HP		
				if(earphone_plugged_flag){
					det_timer_1 =0;
					earphone_plugged_flag =0;
				}
#endif		
				
#ifdef USE_ADKEY_DETECT_AUX				
				if(det_timer_2++>10){
					det_timer_2 =0;
			            if (!aux_online)
			            {
			                put_msg_lifo(MSG_AUX_IN);
			                aux_online = 1;
			            }
				}
#endif				
			}
			else{

#ifdef USE_ADKEY_DETECT_HP
				if(det_timer_1++>10){

					det_timer_1 =0;

					if(!earphone_plugged_flag){
						earphone_plugged_flag =1;
					}
				}
#endif				

#ifdef USE_ADKEY_DETECT_AUX				
				if(det_timer_2++>10){
					det_timer_2 =0;
			            if (!aux_online)
			            {
			                put_msg_lifo(MSG_AUX_IN);
			                aux_online = 1;
			            }
				}
#endif				
			}
			return NO_KEY;
		}
	}	
	else{
#ifdef USE_ADKEY_DETECT_AUX						
	 	if (aux_online)
        	{
			det_timer_2 =0;
            		put_msg_lifo(MSG_AUX_OUT);
            		aux_online = 0;
        	}
#endif		
#ifdef USE_ADKEY_DETECT_HP		
		if(earphone_plugged_flag){
			det_timer_1 =0;
			earphone_plugged_flag =0;
		}
#endif		
	}
#endif

#endif

  	if(key_value_2>ADKEY2_RES_NOKEY)
      	   	return NO_KEY;
#if defined(EXTENDED_ADKEY_NUM)		
     	else if(key_value_2>ADKEY2_RES_10)
          	return ADKEY2_11;
    	else if(key_value_2>ADKEY2_RES_9)
          	return ADKEY2_10;
  	else if(key_value_2>ADKEY2_RES_8)
          	return ADKEY2_9;
#endif	
 	else if(key_value_2>ADKEY2_RES_7)
      	  	return ADKEY2_8;
 	else if(key_value_2>ADKEY2_RES_6)
        	return ADKEY2_7;
 	else if(key_value_2>ADKEY2_RES_5)
        	return ADKEY2_6;
 	else if(key_value_2>ADKEY2_RES_4)
        	return ADKEY2_5;
 	else if(key_value_2>ADKEY2_RES_3)
        	return ADKEY2_4;
 	else if(key_value_2>ADKEY2_RES_2)
        	return ADKEY2_3;
 	else if(key_value_2>ADKEY2_RES_1)
        	return ADKEY2_2;
  	else 
        	return ADKEY2_1;  
} 


#endif
#else

void keyScan(void);
#if defined(TWO_ADKEY_ENABLE)
void keyScan_ADKEY(void);
#endif

#endif

#ifdef MATRIX_KEY_ENABLE
u8 matrix_key_value=0;

#if  defined(K015_JLH_2946_V001)
#define MAX_MATRIX_KEY		4
_code u8 Key_Tab[MAX_MATRIX_KEY][2]=
{
	{0x00,INFO_PLAY},			
	{0x01,INFO_NEXT_FIL},			
	{0x02,INFO_PREV_FIL},	
	{0x20,INFO_PLAY},
};
_code KEY_STRUCT KEY_MAP[KEY_PORT_NUM] = 
{
	PORT_2,BIT(6),
	PORT_2,BIT(7),
	PORT_0,BIT(6),
};
#elif defined(K627_LHGC_627_V001)
#define MAX_MATRIX_KEY		4
_code u8 Key_Tab[MAX_MATRIX_KEY][2]=
{
	{0x00,INFO_PLAY},			
	{0x01,INFO_NEXT_FIL},			
	{0x02,INFO_PREV_FIL},	
	{0x03,INFO_PLAY_MODE},
};
_code KEY_STRUCT KEY_MAP[KEY_PORT_NUM] = 
{
	PORT_2,BIT(4),
	PORT_2,BIT(5),
	PORT_2,BIT(6),
	PORT_2,BIT(7),
};
#endif
void key_matrix_scan(void)
{
	u8 i=0,j=0,k=0,Key_Port=0;

#if  defined(K015_JLH_2946_V001)
	DACCON0|=0x80;
#elif defined(K627_LHGC_627_V001)
	DACCON0|=0xC0;
#endif
	for(i=0;i<KEY_PORT_NUM;i++){

		config_gpio_dir(DIR_CLS_ONE_SET_ALL,i);		
		key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_SET,K_PU,KEY_MAP[i].KP_PORT);
		config_gpio_port(PORT_SET_ALL);		
		config_gpio_dir(DIR_SET_ONE_CLS_ALL,i);		

		Delay_us(1);	
		Key_Port =key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,GET_DATA,K_DIR,KEY_MAP[i].KP_PORT);
		
 		if((Key_Port&(KEY_MAP[i].KP_PMASK)) ==0x00){
				Delay_us(12);	
				Key_Port =key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,GET_DATA,K_DIR,KEY_MAP[i].KP_PORT);
			if((Key_Port&(KEY_MAP[i].KP_PMASK)) ==0x00){
					//printf("---22222----iii ==%x--->P1== %x \r\n",(u16)(i),(u16)Key_Port);
					goto _PARSE_KEY;			
			}
 		}
	}
	
	for(i=0;i<KEY_PORT_NUM;i++){

		config_gpio_dir(DIR_CLS_ONE_SET_ALL,i);		
		key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_SET,K_PU,KEY_MAP[i].KP_PORT);
		key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_CLS,K_PD,KEY_MAP[i].KP_PORT);		
		config_gpio_port(PORT_SET_ALL);
		config_gpio_dir(DIR_SET_ONE_CLS_ALL,i);		

		for(j=0;j<KEY_PORT_NUM;j++){
				
 				if(j==i)continue;	
				
				key_gpio_scan_parse(KEY_MAP[j].KP_PMASK,BIT_CLS,K_PORT,KEY_MAP[j].KP_PORT);
					
				Delay_us(1);	
				Key_Port =key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,GET_DATA,K_DIR,KEY_MAP[i].KP_PORT);
			 	if((Key_Port&(KEY_MAP[i].KP_PMASK)) ==0x00){
						
						Delay_us(12);	
						Key_Port =key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,GET_DATA,K_DIR,KEY_MAP[i].KP_PORT);
 
					if((Key_Port&(KEY_MAP[i].KP_PMASK)) ==0x00){

						i=((j<<4)|i);
						//printf("---444----JJJ ==%x--->III ==%x \r\n",(u16)j,(u16)i);
						goto _PARSE_KEY;				
					}
				}

				key_gpio_scan_parse(KEY_MAP[j].KP_PMASK,BIT_SET,K_PORT,KEY_MAP[j].KP_PORT);				
		}
					
 	}

	matrix_key_value =NO_KEY;
	return ;
	
_PARSE_KEY:

	//printf("---key index ----iii ==%x\r\n",(u16)i);
	for(k=0;k<MAX_MATRIX_KEY;k++){
		if(Key_Tab[k][0]==i){
			//printf("---key index ----iii ==%x\r\n",(u16)i);
			matrix_key_value = Key_Tab[k][1];
			break;
		}
	}
	//printf("---key matrix_key_value  ==%x\r\n",(u16)matrix_key_value);
}
void config_gpio_dir(DIR_CMD k_cmd,u8 dir_idx)
{
	u8 i;
	if(k_cmd == DIR_SET_ONE_CLS_ALL){

		key_gpio_scan_parse(KEY_MAP[dir_idx].KP_PMASK,BIT_SET,K_DIR,KEY_MAP[dir_idx].KP_PORT);
		for(i=0;i<KEY_PORT_NUM;i++){

			if(i==dir_idx)continue;
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_CLS,K_DIR,KEY_MAP[i].KP_PORT);

		}
	}
	else{
		key_gpio_scan_parse(KEY_MAP[dir_idx].KP_PMASK,BIT_CLS,K_DIR,KEY_MAP[dir_idx].KP_PORT);

		for(i=0;i<KEY_PORT_NUM;i++){

			if(i==dir_idx)continue;
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_SET,K_DIR,KEY_MAP[i].KP_PORT);

		}
	}
}
void config_gpio_port(GPIO_CMD k_cmd)
{
	u8 i;
	if(k_cmd == PORT_SET_ALL){
		
		for(i=0;i<KEY_PORT_NUM;i++){
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_SET,K_PORT,KEY_MAP[i].KP_PORT);
		}
	}
	else{
		
		for(i=0;i<KEY_PORT_NUM;i++){
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_CLS,K_PORT,KEY_MAP[i].KP_PORT);
		}
	}
}
void config_gpio_pullup(GPIO_CMD k_cmd)
{
	u8 i;
	if(k_cmd == PORT_SET_ALL){
		
		for(i=0;i<KEY_PORT_NUM;i++){
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_SET,K_PU,KEY_MAP[i].KP_PORT);
		}
	}
	else{
		
		for(i=0;i<KEY_PORT_NUM;i++){
			key_gpio_scan_parse(KEY_MAP[i].KP_PMASK,BIT_CLS,K_PU,KEY_MAP[i].KP_PORT);
		}
	}
}
u8 key_gpio_scan_parse(u8 K_mask,KEY_CMD k_cmd,KEY_REG_TYPE k_reg,KEY_PORT k_port)
{
	u8 key_port=0;

	if(k_cmd == GET_DATA){
		
		switch(k_port)
		{
			case PORT_0:
				key_port	= P0;
				return key_port;
			case PORT_1:
				key_port	= P1;
				return key_port;
			case PORT_2:
				key_port	= P2;
				return key_port;
			case PORT_3:
				key_port	= P3;
				return key_port;				
		}
		return 0x00;
	}
	
	if(k_reg ==  K_DIR){		
		switch(k_port)
		{
			case PORT_0:
				if(k_cmd){
					P0DIR &=~K_mask;
				}
				else{
					P0DIR |= K_mask;
				}
				break;
			case PORT_1:
				if(k_cmd){
					P1DIR &=~K_mask;
				}
				else{
					P1DIR |=K_mask;
				}
				break;
			case PORT_2:
				if(k_cmd){
					P2DIR &=~K_mask;
				}
				else{
					P2DIR |=K_mask;
				}
				break;
			case PORT_3:
				if(k_cmd){
					P3DIR &=~K_mask;
				}
				else{
					P3DIR |=K_mask;
				}
				break;				
		}
	}
	else if(k_reg ==  K_PU){		
		switch(k_port)
		{
			case PORT_0:
				if(k_cmd){
					P0PU&=~K_mask;
				}
				else{
					P0PU |= K_mask;
				}
				break;
			case PORT_1:
				if(k_cmd){
					P1PU &=~K_mask;
				}
				else{
					P1PU |=K_mask;
				}
				break;
			case PORT_2:
				if(k_cmd){
					P2PU &=~K_mask;
				}
				else{
					P2PU |=K_mask;
				}
				break;
			case PORT_3:
				if(k_cmd){
					P3PU &=~K_mask;
				}
				else{
					P3PU |=K_mask;
				}
				break;				
		}
	}
	else if(k_reg ==  K_PD){		
		switch(k_port)
		{
			case PORT_0:
				if(k_cmd){
					P0PD&=~K_mask;
				}
				else{
					P0PD |= K_mask;
				}
				break;
			case PORT_1:
				if(k_cmd){
					P1PDA&=~K_mask;
				}
				else{
					P1PDA |=K_mask;
				}
				break;
			case PORT_2:
				#if 0
				if(k_cmd){
					P2PD &=~K_mask;
				}
				else{
					P2PD |=K_mask;
				}
				#endif
				break;
			case PORT_3:
				if(k_cmd){
					P3PD&=~K_mask;
				}
				else{
					P3PD|=K_mask;
				}
				break;				
		}
	}	
	else if(k_reg ==  K_PORT){
	
		switch(k_port)
		{
			case PORT_0:
				if(k_cmd){
					P0&=~K_mask;
				}
				else{
					P0 |= K_mask;
				}
				break;
			case PORT_1:
				if(k_cmd){
					P1&=~K_mask;
				}
				else{
					P1 |=K_mask;
				}
				break;
			case PORT_2:
				if(k_cmd){
					P2 &=~K_mask;
				}
				else{
					P2 |=K_mask;
				}
				break;
			case PORT_3:
				if(k_cmd){
					P3&=~K_mask;
				}
				else{
					P3|=K_mask;
				}
				break;				
		}
	}
	
	return 0xFF;	
}
#endif


