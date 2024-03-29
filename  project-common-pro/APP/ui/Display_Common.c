/*--------------------------------------------------------------------------
   @file   display_common.c
   @brief    显示模块头文件
   @details
   @author
   @date   2010-04-20
   @note

----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "config.h"
#include "lcd.h"
#include "led.h"
#include "lcdsegment.h"

#if defined(USE_LCD_DRV_HT1621)
#include "lcd_ht1621_drv.h"
#elif defined(USE_LCD_DRV_TM1721)
#include "lcd_tm1721_drv.h"
#elif defined(LED_DRV_USE_SM1628)
#include "led_drv.h"
#elif defined(LED_1651_DRV)
#include "led_1651.h"
extern void disp_scan_1651(void);
#endif

#if defined(TIME_FORCE_SHOW_ON_SCREEN)
volatile xd_u8 time_show_return_cnt; 
#endif
volatile u8 return_cnt;         ///<显示界面返回计数，当在非主界面的时候会置零，当计数到RETURN_TIME时会返回当前模式的主界面
xd_u8 curr_menu;          ///<当前界面

extern void disp_buf_clear();
extern void Disp_Null();
extern void Disp_CLR();
extern void Disp_Num();
extern void Disp_Filenum();
extern void Disp_Nofile();
extern void Disp_Nodevice();
extern void Disp_Stop();
extern void Disp_Play();
extern void Disp_Pause();
extern void Disp_File_Name();
extern void Disp_Vol();
extern void Disp_Eq();
#ifdef SUPPORT_PT2313
extern void Disp_Treble();
extern void Disp_Bass();
extern void Disp_Balence();
extern void Disp_loudness();
extern void Disp_Fade(void);
extern void Disp_Sw_Vol(void);
extern void Disp_Mic_Vol(void);
extern void Disp_Echo(void);
#endif
extern void Disp_Power_up();
extern void Disp_Playmode(void);
extern void Disp_Waiting();
extern void Disp_USB_Slave();
extern void Disp_Freq();
extern void Disp_CH_NO();
extern void Disp_Scan_NO();
extern void Disp_Sch(void);
extern void Disp_AUX();
extern void Disp_Load(void);
extern void Disp_Start();
extern void Disp_Error(void);
extern void Disp_PwrOFF();
#ifdef USE_TIMER_POWER_OFF_FUNC
extern void Disp_Timer_OFF(void);
#endif
#if defined(IPONE_DOCK_FUNC_ENABLE)
extern void Disp_IPOD(void);
#endif
#ifdef DISP_DEV_STR_BEFOR_PLAY
extern void Disp_curr_Dev();
#endif
#if defined(BLUE_TOOTH_FUNC)
extern void Disp_BT(void);
extern void Disp_BT_Vol(void);
#endif
#ifdef USE_RTC_FUNCTION
extern void Disp_RTC_POINT();
extern void Disp_RTC();
extern void Disp_RTC_Date();
extern void Disp_Alm_Up();
#endif
#ifdef USE_MICPHONE_GPIO_DETECTION
extern void Disp_Mic();
#endif
#if defined(PLAY_STATUS_LED_SHARE_WITH_IIC_SCL)
extern bool iic_busy;
#endif

#if defined(USE_SPECTRUM_PARTTERN)
extern void Disp_Patern();
#endif

#ifdef USB_SD_DEV_PLUG_MEM
extern xd_u8 last_plug_dev;
#endif

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
extern bool mute_on_flash_enable;
#endif
#if defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
extern bool pause_flash_enable;
extern void disp_buf_figure_buf();
#endif

#ifdef LED_DRV_MUTE_ON_FLASH_WHOLE_SCREEN
extern void led_drv_spark_all();
#endif

#if defined(SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION)||defined(SYS_LED_PROTECTION_UNTILL_PWR_ON)
bool sys_pwr_on_led_protect_bit=0;
#endif

#if defined(CHARGE_STATE_FOR_LED_PROTECTION)
bool sys_led_protect_bit=0;
#endif

#if defined(LCD_GPIO_DRV)
extern void lcd_buf_icon_disp_update();
#endif
extern u8 _idata  my_music_vol;

extern _xdata SYS_WORK_MODE work_mode;
extern xd_u8 IR_Type;
extern bool earphone_plugged_flag;
static u8 LED_Flash_mode =0xFF;
#if defined(NEW_CUSTOMIZED_LED_METHOD)

#define PORT_P0		0X80
#define PORT_P1		0X90
#define PORT_P2		0XA0
#define PORT_P3		0XB0
#define PORT_N		0XFF

#ifdef K202_WEISI_KL202_V001000
bool led_enable_flag=0;
void set_led_enable_bit(bool led)
{
	led_enable_flag=led;
}
#endif
typedef struct {

	SYS_WORK_MODE led_mode;
	u8 led_port_bit;
	u8 led_port;
#ifdef EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL
	u8 led_port_bit_2;
	u8 led_port_2;
#endif
}mode_led;
static u8 last_led_work_mode=0x0F;
#if defined(K202_WEISI_KL202_V001)
#define LED_MAX_NUM	3

mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(7),PORT_P2,
	SYS_MP3DECODE_SD,		BIT(4),PORT_P2,
	SYS_FMREV,				BIT(5),PORT_P2,
};
#elif defined(K0000_JK_QGAC18_V001)
#define LED_MAX_NUM	5
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(7),PORT_P2, 
	SYS_MP3DECODE_SD,		BIT(7),PORT_P2, 
	SYS_FMREV,				BIT(7),PORT_N,
 	SYS_AUX,				BIT(2),PORT_P0, 
	SYS_IDLE,				BIT(2),PORT_P0,
};
#elif defined(K000_JK_HY_SM001_V001)
#define LED_MAX_NUM	3
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(1),PORT_P0,
	SYS_MP3DECODE_SD,		BIT(7),PORT_P2,
	SYS_IDLE,				BIT(0),PORT_N,
};
#elif defined(K0000_ZG_BT260_V001)
#define LED_MAX_NUM	4
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(5),PORT_P1, 
	SYS_MP3DECODE_SD,		BIT(4),PORT_P1, 
	SYS_FMREV,				BIT(7),PORT_P0,
 	SYS_AUX,				BIT(6),PORT_P1, 	
};
#elif defined(K000_XC_BC_BT_V001)
#define LED_MAX_NUM	6
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(1),PORT_P1,BIT(2),PORT_P1,
	SYS_MP3DECODE_SD,		BIT(1),PORT_P1,BIT(0),PORT_N,
	SYS_FMREV,				BIT(5),PORT_N,BIT(0),PORT_N,
	SYS_AUX,				BIT(1),PORT_P1,BIT(2),PORT_P1,
	SYS_BT,					BIT(2),PORT_P1,BIT(0),PORT_N,		
	SYS_IDLE,				BIT(1),PORT_P1,BIT(2),PORT_P1,

};
#elif defined(K1162_AJR_1162_V001)
#define LED_MAX_NUM	4
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(7),PORT_P2,BIT(0),PORT_N,
	SYS_MP3DECODE_SD,		BIT(7),PORT_P2,BIT(0),PORT_N,
	SYS_FMREV,				BIT(5),PORT_P0,BIT(0),PORT_N,
	SYS_AUX,				BIT(7),PORT_P2,BIT(5),PORT_P0,		
};
#elif defined(K2078_MY_2078_V001)
#define LED_MAX_NUM	5
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(7),PORT_P0,
	SYS_MP3DECODE_SD,		BIT(7),PORT_P0,
	SYS_FMREV,				BIT(7),PORT_P0,
	SYS_AUX,				BIT(7),PORT_P0,		
	SYS_BT,					BIT(3),PORT_P1,		
};
#elif defined(K1106_SD_1106_V001)
#define LED_MAX_NUM	4

mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(2),PORT_P0,
	SYS_MP3DECODE_SD,		BIT(2),PORT_P0,
	SYS_FMREV,				BIT(7),PORT_P2,
	SYS_AUX,				BIT(6),PORT_P2,		
};
#elif defined(K0000_BT_CHT909_V001)
#define LED_MAX_NUM	5
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(4),PORT_P1,
	SYS_MP3DECODE_SD,		BIT(4),PORT_P1,
	SYS_FMREV,				BIT(6),PORT_P1,
	SYS_AUX,				BIT(7),PORT_P1,	
	SYS_AUX_2,				BIT(5),PORT_P1,	
};
#elif defined(K0000_BT_CHT909_V002)
#define LED_MAX_NUM	7
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(5),PORT_P1,BIT(6),PORT_P1,
	SYS_MP3DECODE_SD,		BIT(5),PORT_P1,BIT(6),PORT_P1,
	SYS_FMREV,				BIT(6),PORT_P1,BIT(0),PORT_N,
	SYS_AUX,				BIT(5),PORT_P1,BIT(0),PORT_N,	
	SYS_AUX_2,				BIT(7),PORT_P1,BIT(6),PORT_P1,	
	SYS_BT,					BIT(7),PORT_P1,BIT(5),PORT_P1,	
	SYS_IDLE,				BIT(7),PORT_P1,BIT(0),PORT_N,		
};
#elif defined(K0000_BT_CHT909_V003)
#define LED_MAX_NUM	6
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(1),PORT_P1,BIT(0),PORT_N,
	SYS_MP3DECODE_SD,		BIT(2),PORT_P1,BIT(0),PORT_N,
	SYS_FMREV,				BIT(0),PORT_P1,BIT(1),PORT_P1,
	SYS_AUX,				BIT(0),PORT_P1,BIT(2),PORT_P1,	
	SYS_AUX_2,				BIT(1),PORT_P1,BIT(2),PORT_P1,	
	SYS_IDLE,				BIT(0),PORT_P1,BIT(0),PORT_N,		
};
#elif defined(K000_QY_200_V001)
#define LED_MAX_NUM	5
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(7),PORT_P2,
	SYS_MP3DECODE_SD,		BIT(7),PORT_P2,
	SYS_FMREV,				BIT(6),PORT_P2,
	SYS_AUX,				BIT(7),PORT_P2,	
	SYS_IDLE,				BIT(7),PORT_P2,	
};
#else
#define LED_MAX_NUM	5
mode_led _code mode_led_tab[LED_MAX_NUM]=
{
	SYS_MP3DECODE_USB,		BIT(0),PORT_P3,
	SYS_MP3DECODE_SD,		BIT(0),PORT_P3,
	SYS_FMREV,				BIT(3),PORT_P3,
	SYS_AUX,				BIT(2),PORT_P3,	
	SYS_IPH,					BIT(1),PORT_P3,	

};
#endif

void new_led_gpio_init()
{
	u8 led_port=0,i=0;
	for(i=0;i<LED_MAX_NUM;i++){
		
		if(mode_led_tab[i].led_port ==PORT_P0){

			P0DIR &=~(mode_led_tab[i].led_port_bit);
			P0PU |=(mode_led_tab[i].led_port_bit);
	#if defined(LED_CTRL_LEVEL_NORMAL)
				P0 &=~(mode_led_tab[i].led_port_bit);				
	#else
				P0 |=(mode_led_tab[i].led_port_bit);							
	#endif	
#ifdef AC209_28PIN
		if((mode_led_tab[i].led_port_bit)==BIT(2)){
			P3DIR |= BIT(4);P3PU &= ~(BIT(4));P3PD&= ~(BIT(4));	
		}
#endif
		}
		else if(mode_led_tab[i].led_port ==PORT_P1){
			
			P1DIR &=~(mode_led_tab[i].led_port_bit);
			P1PU |=(mode_led_tab[i].led_port_bit);
	#if defined(LED_CTRL_LEVEL_NORMAL)
				P1 &=~(mode_led_tab[i].led_port_bit);				
	#else
				P1 |=(mode_led_tab[i].led_port_bit);							
	#endif			
		}
		else if(mode_led_tab[i].led_port ==PORT_P2){


			if((mode_led_tab[i].led_port_bit)>=BIT(6)){
				DACCON0|=0x80;
			}
			else if((mode_led_tab[i].led_port_bit)>=BIT(4)){
				DACCON0|=0x40;
			}

			DACCON0|=0x80;

			P2DIR &=~(mode_led_tab[i].led_port_bit);	
			P2PU |=(mode_led_tab[i].led_port_bit);
	#if defined(LED_CTRL_LEVEL_NORMAL)
				P2 &=~(mode_led_tab[i].led_port_bit);				
	#else
				P2 |=(mode_led_tab[i].led_port_bit);							
	#endif			
		}
		else if(mode_led_tab[i].led_port ==PORT_P3){

			P3DIR &=~(mode_led_tab[i].led_port_bit);	
			P3PU |=(mode_led_tab[i].led_port_bit);	
	#if defined(LED_CTRL_LEVEL_NORMAL)
				P3 &=~(mode_led_tab[i].led_port_bit);				
	#else
				P3 |=(mode_led_tab[i].led_port_bit);							
	#endif
		}
	}
}
void turn_off_last_working_led()
{
#ifndef LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
	if(last_led_work_mode>SYS_IDLE)return;
#endif	
		if(mode_led_tab[last_led_work_mode].led_port ==PORT_P0){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P0 &=~(mode_led_tab[last_led_work_mode].led_port_bit);				
#else
			P0 |=(mode_led_tab[last_led_work_mode].led_port_bit);							
#endif			
		}
		else if(mode_led_tab[last_led_work_mode].led_port ==PORT_P1){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P1 &=~(mode_led_tab[last_led_work_mode].led_port_bit);				
#else
			P1 |=(mode_led_tab[last_led_work_mode].led_port_bit);							
#endif			
		}
		else if(mode_led_tab[last_led_work_mode].led_port ==PORT_P2){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P2 &=~(mode_led_tab[last_led_work_mode].led_port_bit);				
#else
			P2 |=(mode_led_tab[last_led_work_mode].led_port_bit);							
#endif			
		}
		else if(mode_led_tab[last_led_work_mode].led_port ==PORT_P3){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P3 &=~(mode_led_tab[last_led_work_mode].led_port_bit);				
#else
			P3 |=(mode_led_tab[last_led_work_mode].led_port_bit);							
#endif
		}		
//1 begin  of  extend gpio		
#ifdef EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL
		if(mode_led_tab[last_led_work_mode].led_port_2==PORT_P0){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P0 &=~(mode_led_tab[last_led_work_mode].led_port_bit_2);				
#else
			P0 |=(mode_led_tab[last_led_work_mode].led_port_bit_2);							
#endif
		}
		else if(mode_led_tab[last_led_work_mode].led_port_2==PORT_P1){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P1 &=~(mode_led_tab[last_led_work_mode].led_port_bit_2);				
#else
			P1 |=(mode_led_tab[last_led_work_mode].led_port_bit_2);							
#endif			
		}
		else if(mode_led_tab[last_led_work_mode].led_port_2==PORT_P2){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P2 &=~(mode_led_tab[last_led_work_mode].led_port_bit_2);				
#else
			P2 |=(mode_led_tab[last_led_work_mode].led_port_bit_2);							
#endif			
		}
		else if(mode_led_tab[last_led_work_mode].led_port_2==PORT_P3){

#if defined(LED_CTRL_LEVEL_NORMAL)
			P3 &=~(mode_led_tab[last_led_work_mode].led_port_bit_2);				
#else
			P3 |=(mode_led_tab[last_led_work_mode].led_port_bit_2);							
#endif
		}
#endif
//1 end of  extend gpio		
}
 void led_set_new_method(u8 led_cmd)
{	
	switch(mode_led_tab[work_mode].led_port){

		case PORT_P0:

			if(led_cmd>0)
				P0 |=(mode_led_tab[work_mode].led_port_bit);			
			else 
				P0 &=~(mode_led_tab[work_mode].led_port_bit);	
			break;
		case PORT_P1:

			if(led_cmd>0)
				P1 |=(mode_led_tab[work_mode].led_port_bit);			
			else 
				P1 &=~(mode_led_tab[work_mode].led_port_bit);			
			break;
		case PORT_P2:

			if(led_cmd>0)
				P2 |=(mode_led_tab[work_mode].led_port_bit);			
			else 
				P2 &=~(mode_led_tab[work_mode].led_port_bit);			
			break;
		case PORT_P3:
		
			if(led_cmd>0)
				P3 |=(mode_led_tab[work_mode].led_port_bit);			
			else 
				P3 &=~(mode_led_tab[work_mode].led_port_bit);			
			break;
	}
#ifdef EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL
	switch(mode_led_tab[work_mode].led_port_2){

		case PORT_P0:

			if(led_cmd>0)
				P0 |=(mode_led_tab[work_mode].led_port_bit_2);			
			else 
				P0 &=~(mode_led_tab[work_mode].led_port_bit_2);	
			break;
		case PORT_P1:

			if(led_cmd>0)
				P1 |=(mode_led_tab[work_mode].led_port_bit_2);			
			else 
				P1 &=~(mode_led_tab[work_mode].led_port_bit_2);			
			break;
		case PORT_P2:

			if(led_cmd>0)
				P2 |=(mode_led_tab[work_mode].led_port_bit_2);			
			else 
				P2 &=~(mode_led_tab[work_mode].led_port_bit_2);			
			break;
		case PORT_P3:
		
			if(led_cmd>0)
				P3 |=(mode_led_tab[work_mode].led_port_bit_2);			
			else 
				P3 &=~(mode_led_tab[work_mode].led_port_bit_2);			
			break;
	}
#endif
}
void set_play_flash(LED_FLASH_TYPE led_status)
{
	EA = 0;
	
#ifdef K202_WEISI_KL202_V001000000000000
	if(!led_enable_flag){
		led_status = LED_FLASH_STOP;
	}
#endif
     
	if(last_led_work_mode!=work_mode)
	{
		turn_off_last_working_led();
		last_led_work_mode = work_mode;
	}
	
	if(led_status ==LED_FLASH_ON){
		LED_Flash_mode = 0xF6;
	}
	else if(led_status ==LED_FLASH_VERY_FAST){
		LED_Flash_mode = 36;
	}
	else if(led_status ==LED_FLASH_FAST){
		LED_Flash_mode = 50;
	}
	else if(led_status ==LED_FLASH_NOR){
		LED_Flash_mode = 250;
	}
	else if(led_status ==LED_FLASH_STOP){
		LED_Flash_mode = 0xFF;
	}
	EA =1;
}
#ifndef NO_PLAY_STATUS_LED
static xd_u16 LED_cnt=0;
#endif
void play_led_flash()
{
#if 0//defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
#ifndef USE_ADKEY_FOR_AUX_HP_DETECTION
       static u8   earphone_cnt=0;
#endif
#endif

	static bool led_bit=0;

#ifndef NO_PLAY_STATUS_LED

#if defined(PLAY_STATUS_LED_SHARE_WITH_IIC_SCL)
	if(iic_busy)return;
#endif

	LED_cnt++;
	
	if(LED_Flash_mode ==0xFF){	//LED_FLASH_STOP

		led_set_new_method(OFF_LEVEL);
	}
	else if(LED_Flash_mode == 0xF6){	//LED_FLASH_ON

		led_set_new_method(ON_LEVEL);
	}
	else  if((LED_cnt % LED_Flash_mode)==0){

		led_bit =~led_bit;
		led_set_new_method(led_bit);
	}
	
#endif	
#if 0//defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)

#ifndef USE_ADKEY_FOR_AUX_HP_DETECTION

	//4 复用GPIO P07
#if !defined(USE_IR_VPP_PORT_FOR_DETECTION)
#if !defined(NO_PLAY_STATUS_LED)
	#if defined(INDEPENDENT_EARPHONE_DETECT_GPIO)
		EARPHONE_DETECT_GPIO=1;
	#else
		if(EARPHONE_DETECT_GPIO==0)return;
	#endif
#else
	EARPHONE_DETECT_GPIO=1;
#endif
#endif

	earphone_detect_in();
	_nop_();
	if(EARPHONE_DETECT_GPIO==0)
	{
		if(earphone_cnt ++>20)
			earphone_plugged_flag =1;
	}
	else{
		earphone_cnt =0;
		earphone_plugged_flag =0;
	}
#ifndef NO_PLAY_STATUS_LED	
    	play_led_seg_out();
#endif
#endif
#endif		
}

#else

#if defined(TWO_PLAY_LED_IN_USE)
extern u8 play_status;
bool led_open_enable = 0;
#endif
#if defined(TWO_PLAY_LED_IN_USE)
static xd_u8 LED_Flash_mode_2 =0xFF;
void set_play_flash_no2(LED_FLASH_TYPE led_status)
{
	//EA = 0;		
	if(led_status ==LED_FLASH_ON){
		LED_Flash_mode_2 = 0xF6;
	}
	else if(led_status ==LED_FLASH_VERY_FAST){
		LED_Flash_mode_2 = 36;
	}
	else if(led_status ==LED_FLASH_FAST){
		LED_Flash_mode_2 = 50;
	}
	else if(led_status ==LED_FLASH_NOR){
		LED_Flash_mode_2 = 250;
	}
	else if(led_status ==LED_FLASH_STOP){
		LED_Flash_mode_2 = 0xFF;
	}
	//EA =1;
}
#endif
u8 get_led_flash_mode()
{
	return LED_Flash_mode;
}
void restore_led_flash_mod(u8 led_mod)
{
	LED_Flash_mode = led_mod;
}
void set_play_flash(LED_FLASH_TYPE led_status)
{
	EA = 0;
#if defined(TWO_PLAY_LED_IN_USE)
	if(led_open_enable){

#if defined(K000_JK_HY_SM001_V001)
		goto __LED_HANDLE;
#endif

		    set_play_flash_no2(LED_FLASH_STOP);
		    led_status = LED_FLASH_ON;	
			
	}
	else{
		
#if defined(K722_YJH_722_V001)
		if(work_mode == SYS_MP3DECODE_USB){
			
			if(play_status){
			    set_play_flash_no2(LED_FLASH_STOP);
			}
			else{
			    set_play_flash_no2(LED_FLASH_FAST);
			    led_status = LED_FLASH_ON;
			}
		}
		else if(work_mode == SYS_MP3DECODE_SD){

			if(play_status){
			    set_play_flash_no2(led_status);
			    led_status = LED_FLASH_STOP;
			}
			else{
			    set_play_flash_no2(LED_FLASH_FAST);
			    led_status = LED_FLASH_ON;
			}
		}
		else if(work_mode ==SYS_FMREV){
		    set_play_flash_no2(led_status);
		    led_status = LED_FLASH_STOP;		
		}
		else if(work_mode == SYS_AUX){

		    set_play_flash_no2(LED_FLASH_STOP);
		}
		else{
			
		    set_play_flash_no2(LED_FLASH_STOP);
		    led_status = LED_FLASH_STOP;		
		}
		
#elif defined(K000_JK_HY_SM001_V001)
__LED_HANDLE:
		if(work_mode <=SYS_MP3DECODE_SD){


			if(((get_device_online_status()&0x01)>0)){

				if(last_plug_dev==BIT(SDMMC)){
					
					if((led_status==LED_FLASH_NOR)){
						//last_plug_dev=0;
					    	set_play_flash_no2(LED_FLASH_NOR);

					}
				}
				else{
				    set_play_flash_no2(LED_FLASH_ON);

				}

			}
			else{
			    set_play_flash_no2(LED_FLASH_STOP);

			}

			if(((get_device_online_status()&0x02)>0)){

				if(last_plug_dev==BIT(USB_DISK)){
					//if(((led_status==LED_FLASH_NOR))){
						//last_plug_dev=0;
					    	led_status=LED_FLASH_NOR;

					//}
				}
				else{

					led_status=LED_FLASH_ON;

				}
			}
			else{
				    led_status=LED_FLASH_STOP;

			}

		}
		else if(work_mode ==SYS_FMREV){

		    	set_play_flash_no2(led_status);
			led_status=LED_FLASH_STOP;
		}
		
#elif defined(K583_ZX_583_V001)

		if(work_mode < SYS_MP3DECODE_SD){

			if(play_status){
			    set_play_flash_no2(LED_FLASH_ON);
			}
			else{
			    set_play_flash_no2(LED_FLASH_NOR);
			}

		    led_status = LED_FLASH_STOP;
			
		}
		else if(work_mode ==SYS_FMREV){
			
		    set_play_flash_no2(led_status);
		}
		else if(work_mode == SYS_AUX){

		    set_play_flash_no2(LED_FLASH_STOP);
		}
#endif

	}
#endif
	if(led_status ==LED_FLASH_ON){
		LED_Flash_mode = 0xF6;
	}
	else if(led_status ==LED_FLASH_VERY_FAST){
		LED_Flash_mode = 36;
	}
	else if(led_status ==LED_FLASH_FAST){
#if 1//def K2012_MY_M90_V001
		LED_Flash_mode = 120;
#else
		LED_Flash_mode = 50;
#endif
	}
	else if(led_status ==LED_FLASH_NOR){
		LED_Flash_mode = 250;
	}
	else if(led_status ==LED_FLASH_SLOW){
		LED_Flash_mode = 0xF8;
	}	
	else if(led_status ==LED_FLASH_STOP){
		LED_Flash_mode = 0xFF;
	}
	EA =1;
}
#ifndef NO_PLAY_STATUS_LED
static xd_u16 LED_cnt=0;
#endif
void play_led_flash()
{

#if defined(SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION)||defined(SYS_LED_PROTECTION_UNTILL_PWR_ON)
	if(sys_pwr_on_led_protect_bit)return;
#endif

#if defined(CHARGE_STATE_FOR_LED_PROTECTION)
	if(sys_led_protect_bit)return;
#endif
#if 0//defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
#ifndef USE_ADKEY_FOR_AUX_HP_DETECTION
       static u8   earphone_cnt=0;
#endif
#endif
#ifndef NO_PLAY_STATUS_LED

#ifdef SKIP_PLAY_STATUS_LED_SPARK
	if((LED_Flash_mode!=0xFF)&&(LED_Flash_mode!=0xF6))
		return;
#endif
#if defined(PLAY_STATUS_LED_SHARE_WITH_IIC_SCL)
	if(iic_busy)return;
#endif

	LED_cnt++;

#ifdef LED_FLASH_ALL_THE_TIME
	if(LED_cnt==80){
		PLAY_STATUS_PORT = OFF_LEVEL;
		PLAY_STATUS_PORT2 = ON_LEVEL;
	}
	else if(LED_cnt==160){

		LED_cnt=0;
		PLAY_STATUS_PORT = ON_LEVEL;
		PLAY_STATUS_PORT2 = OFF_LEVEL;
	}
#endif
	if(LED_Flash_mode ==0xFF){	//LED_FLASH_STOP

		PLAY_STATUS_PORT = OFF_LEVEL;
#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
		PLAY_STATUS_PORT2 = ON_LEVEL;
#endif		
	}
	else if(LED_Flash_mode == 0xF6){	//LED_FLASH_ON

		PLAY_STATUS_PORT = ON_LEVEL;
#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
		PLAY_STATUS_PORT2 = OFF_LEVEL;
#endif		
		
	}
	else if(LED_Flash_mode==0xF8){

		if(LED_cnt>(LED_Flash_mode<<1)){
			LED_cnt=0;
			PLAY_STATUS_PORT=~PLAY_STATUS_PORT;
#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
			PLAY_STATUS_PORT2=~PLAY_STATUS_PORT2;
#endif		
			
		}

	}	
	else  if((LED_cnt % LED_Flash_mode)==0){

		PLAY_STATUS_PORT=~PLAY_STATUS_PORT;
#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
			PLAY_STATUS_PORT2=~PLAY_STATUS_PORT2;
#endif				
	}
	
#if defined(TWO_PLAY_LED_IN_USE)
	if(LED_Flash_mode_2 ==0xFF){	//LED_FLASH_STOP
			
		PLAY_STATUS_PORT_NO2 = OFF_LEVEL;	
	}
	else if(LED_Flash_mode_2 == 0xF6){	//LED_FLASH_ON
			
		PLAY_STATUS_PORT_NO2 = ON_LEVEL;
	}
	else if(LED_Flash_mode==0xF8){

		if(LED_cnt>(LED_Flash_mode_2<<1)){
			LED_cnt=0;
			PLAY_STATUS_PORT_NO2=~PLAY_STATUS_PORT_NO2;
		}

	}
	else  if((LED_cnt % LED_Flash_mode_2)==0){

		PLAY_STATUS_PORT_NO2=~PLAY_STATUS_PORT_NO2;
	}
	
#endif

#endif	
#if 0//defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)

#ifndef USE_ADKEY_FOR_AUX_HP_DETECTION

	//4 复用GPIO P07
#if !defined(USE_IR_VPP_PORT_FOR_DETECTION)
#if (!defined(NO_PLAY_STATUS_LED))||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
	#if defined(INDEPENDENT_EARPHONE_DETECT_GPIO)
		EARPHONE_DETECT_GPIO=1;
	#else
		if(EARPHONE_DETECT_GPIO==0)return;
	#endif
#else
	EARPHONE_DETECT_GPIO=1;
#endif
#endif

	earphone_detect_in();
	_nop_();
	if(EARPHONE_DETECT_GPIO==0)
	{
		if(earphone_cnt ++>20)
			earphone_plugged_flag =1;
	}
	else{
		earphone_cnt =0;
		earphone_plugged_flag =0;
	}
#ifndef NO_PLAY_STATUS_LED		
    	play_led_seg_out();
#endif
#endif
#endif		
}
#endif

#ifdef DEVICE_ONLINE_LED_INDICATOR
void device_online_led_ind(void)
{
	P0DIR &= ~(BIT(2));P0PU |= BIT(2);
	
	if((get_device_online_status()&0x03)>0){

		P02  = 1;
	}
	else{
		P02  = 0;
	}
}
#endif
#if defined(SPECTRUM_FUNC_ENABLE)

extern void Disp_roll_mode_Num(void);

xd_u16 spect_buffer[10] _at_ 0xdd0; 
bool spectrum_lock=0;
xd_u8 spec_power=0;
extern u8 ReadLFSR();
//extern void clear_spectrum_buf(void);
extern void spectrum_pattern(u16 *spect_buf);
extern void spect_pattern_disp_reflesh(u8  spec_fresh);
#ifdef SPERCTRUM_FROM_AUX_ADC_SAMPLE
//bool adc_spectrum_enable=0;
#endif

#ifdef PARTTERN_ROLLING_ACTIVATOR_FUNC
void parttern_rolling_activator(void);
#endif

u8 select_disp_rolling_mode=0;

#ifdef USE_MULTI_SPECTRUM_MODE
xd_u8 spectrum_mode=0;
u8 _code spect_mode_tab[5][4]=
{
    {2, 4, 6 , 8,},
    {0, 1, 2 , 3,},
    {5, 6, 7 , 8,},
    {2, 5, 2 , 5,},
    {6, 8, 6 , 8,},
};
void select_spectrum_mode(void)
{

	spectrum_mode++;
	if(spectrum_mode>((u8)((sizeof(spect_mode_tab))/4)-1)){

		spectrum_mode=0;
		
	}
	select_disp_rolling_mode = spectrum_mode;
     	//printf("---->select_spectrum_mode  %d, \r\n",(u16)spectrum_mode);
		
}
#endif

#ifdef PARTTERN_ROLLING_ACTIVATOR_FUNC	
extern u8 disp_rolling_mode,disp_rolling_bar;
void select_spectrum_mode(void)
{
	select_disp_rolling_mode++;
	
	if(select_disp_rolling_mode>4){
		
		set_spectrum_lock(0);
		select_disp_rolling_mode=0;
	}

	disp_rolling_mode = select_disp_rolling_mode;
	disp_rolling_bar =0;
	//if(select_disp_rolling_mode>0){

	//	set_spectrum_lock(1);
	//}
     	//printf("---->select_disp_rolling_mode  %d, \r\n",(u16)select_disp_rolling_mode);
}
#endif
#if 0
void clear_spectrum_buf(void)
{

}
#endif
u8 get_spect_power(void)
{
	return spec_power;
}
u8 i=0,spect_buf[2]={0};
u8 get_spect_limit(u8 spect_energy)
{
     	//printf("---->get_spect_limit  %d, \r\n",(u16)spect_energy);
	if(i==0){
		i=1;
	}
	else{
		i=0;
	}
	spect_buf[i]=spect_energy;

	if(spect_buf[0]>spect_buf[1]){

		return ((spect_buf[0]-spect_buf[1])%6);
	}
	else{
		return ((spect_buf[1]-spect_buf[0])%6);

	}
	
#if 1
#if 0
	u8 idx=0;
	for(idx=0;idx<sizeof(spect_level_tab);idx++){

		if(spect_energy <=spect_level_tab[idx]){

			return idx;
		}
	}
#endif	
#else
	if(spect_energy>30){
		return 5;
	}
	else if(spect_energy>22){
		return 4;
	}
	else if(spect_energy>12){
		return 3;
	}
	else if(spect_energy>6){
		return 2;
	}
	else{
		return 1;
	}
#endif
}
#if 0
void update_spect_buffer(u8 spect_limit)
{
	//printf("__----update_spect_buffer  %d, \r\n",(u16)spect_limit);
	//spect_pattern_disp_reflesh(spect_limit);
}
#endif
void set_spectrum_lock(bool lock)
{
	spectrum_lock = lock;
}
void get_random_spect_data()
{
	u8 i=0;
	for(i=0;i<10;i++){
		spect_buffer[i] =(u16)((ReadLFSR()/10));
	}
}
void Disp_Spect_Update(u16 *spect_buf)
{
	//u8 i;
       u16 spect_line=0;

	//clear_spectrum_buf();

#ifdef USE_MULTI_SPECTRUM_MODE
	spect_line = (spect_buf[spect_mode_tab[spectrum_mode][0]]+spect_buf[spect_mode_tab[spectrum_mode][1]]+spect_buf[spect_mode_tab[spectrum_mode][2]]+spect_buf[spect_mode_tab[spectrum_mode][3]])/4;
#else
	spect_line = (spect_buf[4]+spect_buf[8]+spect_buf[6]+spect_buf[2])/4;
#endif	

	spect_line =(spect_line*my_music_vol)/MAX_VOL;
		
	//printf("__----spectrum_pattern  %d, \r\n",spect_line);
	//spec_powerupdate_spect_buffer(get_spect_limit(spect_line));
	spec_power = get_spect_limit(spect_line);
	spect_pattern_disp_reflesh(DISP_RUN_SPECT);

	//printf("__----spectrum_pattern  %d, \r\n",(u16)spec_power);
		
}
void get_spectrum_data(void)
{

#ifdef PARTTERN_ROLLING_ACTIVATOR_FUNC	
	parttern_rolling_activator();
#endif

	if(spectrum_lock/*||get_super_mute_lock()*/){
		//clear_spectrum_buf();
		spect_pattern_disp_reflesh(DISP_STOP_SPECT);
		return;
	}
	else if(get_super_mute_lock()){
		//clear_spectrum_buf();
		return;
	}
#ifdef PARTTERN_ROLLING_ACTIVATOR_FUNC	
	else if(select_disp_rolling_mode>0){
		//clear_spectrum_buf();
		spect_pattern_disp_reflesh(DISP_SPECT_ROLLING);
		return;
	}	
#endif	
#ifdef USE_RTC_FUNCTION	
	if(work_mode>=SYS_RTC){
		return;
	}
#endif	
	if((work_mode==SYS_MP3DECODE_SD)||(work_mode==SYS_MP3DECODE_USB)){

#ifdef SPERCTRUM_FROM_AUX_ADC_SAMPLE
		 //adc_spectrum_enable=0;    
#endif

		freqavg(spect_buffer);

	}
	else{

#ifdef SPERCTRUM_FROM_AUX_ADC_SAMPLE

		 //adc_spectrum_enable=1;    

#else
		get_random_spect_data();
#endif

	}

	Disp_Spect_Update(spect_buffer);		

}
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
extern void lcd_backlight_ctrl(bool on);

xd_u8 backlight_timer=0;
void Disp_BL_time_out()
{
	if(backlight_timer>0){

		backlight_timer--;
		if(backlight_timer==0){
    			lcd_backlight_ctrl(FALSE);
		}
	}
}
void Disp_BL_turn_on()
{
	backlight_timer=30;
	lcd_backlight_ctrl(TRUE);
}
#endif
#ifdef LED_ROLLING_WITH_MIC_DETETION
void led_rolling_gpio_init()
{
	P0DIR |=(BIT(7));
	P0PU &=~(BIT(7));
	P0PD  |=(BIT(7));

	P3DIR&=~(BIT(4));
	P3PU |=BIT(4);	

	P0DIR&=~(BIT(2));
	P0PU |=BIT(2);	
	
	P0DIR&=~(BIT(4));
	P0PU |=BIT(4);	


	P34 =0;
	P04 =0;	
	P02 =0;		
}
void led_rolling_with_mic_det()
{
	static u8 rolling_timer=0,rolling_intarvel=0,led_idx=0;

	rolling_timer++;

	//return;

	if(rolling_timer%10==0){

		if(!P07){
			rolling_intarvel=32;
		}
		else{
			rolling_intarvel=250;
		}
	}
	
	if(rolling_timer==rolling_intarvel){

		rolling_timer=0;
		led_idx++;
		
		if(led_idx>3)led_idx=0;
	}
	
	if(led_idx==0){

		P34 =1;
		P04 =0;	
		P02 =0;	
	}
	else if(led_idx==1){

		P34 =0;	
		P04 =0;	
		P02 =1;
	}
	else if(led_idx==2){

		P34 =0;
		P02 =0;	
		P04 =1;	
	}
	else{
		P34 =0;
		P04 =0;	
		P02 =0;	
	}
}
#endif
void Disp_Init(void)
{
    init_disp();
#ifndef NO_PLAY_STATUS_LED

#if defined(NEW_CUSTOMIZED_LED_METHOD)
	new_led_gpio_init();
#else

    play_led_seg_out();

#if defined(K1028_WOKA_1028_APPLE_V001)||defined(INVERT_LED_IN_USE)
	play_led_seg_out2();
#endif

#if defined(TWO_PLAY_LED_IN_USE)
    play_led_seg_out_NO2();
#endif
 
 #endif
#endif

#ifdef LED_ROLLING_WITH_MIC_DETETION
	led_rolling_gpio_init();
#endif
}
void Disp_Init_2(void)
{
#if defined(USE_LCD_DRV_HT1621)
	lcd_ht1621_init();
#endif
#ifdef DISP_BACKLIGHT_AUTO_SAVE_POWER
	Disp_BL_turn_on();
#endif

}
void Clear_Disp_Buf(void)
{
	disp_buf_clear();
}
void Disp_Update(void)
{
#if defined( LED_GPIO_DRV)
	updateLED();
#elif defined(LED_DRV_USE_SM1628)
	update_led_buf();
#elif defined(USE_LCD_DRV_HT1621)
	UpdateLcd_HT_1621_Buf();
#elif defined(USE_LCD_DRV_TM1721)
	UpdateLcd_TM1721_Buf();
#elif defined(LCD_GPIO_DRV)
	lcd_buf_icon_disp_update();
#elif defined(LED_1651_DRV)
	disp_scan_1651();
#endif
#if defined(USE_SPECTRUM_PARTTERN)
	Disp_Patern();
#endif

#ifdef DEVICE_ONLINE_LED_INDICATOR
	device_online_led_ind();
#endif
}
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
xd_u8 led_flash_tpye_poll=0;
void led_screen_flash()
{
	if(led_flash_tpye_poll==0)return;
	
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
	if(led_flash_tpye_poll==1){		
		if(mute_on_flash_enable){
			Clear_Disp_Buf();
		}
	}
#endif
#if defined(PAUSE_FLASH_WHOLE_SCREEN)
	if(led_flash_tpye_poll==2){		
		if(pause_flash_enable){
			Clear_Disp_Buf();
		}
	}
#endif
#if defined(MP3_PUASE_FLASH_FIGURE)
	if(led_flash_tpye_poll==2){		
		if(pause_flash_enable){
			disp_buf_figure_buf();
		}
	}
#endif
}
#endif

#if defined(USE_BAT_MANAGEMENT)
extern void Bat_icon_chk();
#endif
#if defined(EXTENED_LED_NUM_SCAN)
extern void set_extend_led_buf_icon();
#endif	
void Update_customed_buf()
{
#if defined(USE_BAT_MANAGEMENT)
	Bat_icon_chk();
#endif
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
 	led_screen_flash();
 #endif

#ifdef LED_DRV_MUTE_ON_FLASH_WHOLE_SCREEN
	led_drv_spark_all();
#endif

#if defined(EXTENED_LED_NUM_SCAN)
	set_extend_led_buf_icon();
#endif

#ifdef LED_ROLLING_WITH_MIC_DETETION
	led_rolling_with_mic_det();
#endif
}
void Disp_Scan(void)
{

   play_led_flash();	

   Update_customed_buf();
   
#ifdef NO_LED_DISPLAY	
	//return;
#else

#if defined( LED_GPIO_DRV)
	LED_scan();
#elif defined( LED_DRV_USE_SM1628)

#elif defined(LCD_GPIO_DRV)
	lcd_gpio_scan();
#endif

#endif

}
void Disp_Con(u8 LCDinterf)
{
	return_cnt = 0;
	
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
	if(LCDinterf!=DISP_RTC_POINT)
		time_show_return_cnt=0;
#endif	
	curr_menu = LCDinterf;

       if(DISP_NULL == LCDinterf)
	{
	    return;
	}  

	if((LCDinterf&CLS_BUF_MAGIC_NUM)>0){
		LCDinterf &=~ CLS_BUF_MAGIC_NUM;
	}
	else{

		Clear_Disp_Buf();
	}

	printf("-----> return_cnt %x \r\n",(u16)curr_menu);

	printf("----->Disp ON %x \r\n",(u16)LCDinterf);

	switch(LCDinterf)
	{
	case DISP_NULL:
		Disp_Null();
	    	break;
	case DISP_CLR:
		Disp_CLR();
	    	break;			
	case DISP_DWORD_NUMBER:
	     	Disp_Num();
	 	break;
	case DISP_FILENUM:					   
	    	Disp_Filenum();
		break;
	case DISP_NOFILE:
		Disp_Nofile();
	    	break;
	case DISP_NODEVICE:
		Disp_Nodevice();
	    	break;
	case DISP_STOP:
	    	Disp_Stop();	
	    	break;
	case DISP_PLAY:
	    	Disp_Play();	
	    	break;			
	case DISP_PAUSE:
		Disp_Pause();
		break;
	case DISP_FILE_NAME:
		Disp_File_Name();
		break;		
	case DISP_VOL:
	    	Disp_Vol();
	    	break;
	case DISP_EQ:
	    	Disp_Eq();
	    	break;
#ifdef SUPPORT_PT2313		
	case DISP_TREBLE:
	    	Disp_Treble();
	    	break;
	case DISP_BASS:
	    	Disp_Bass();
	    	break;
	case DISP_LONDESS:
	    	Disp_loudness();
	    	break;		
	case DISP_BALENCE:
	    	Disp_Balence();
	    	break;
	case DISP_FADE:
	    	Disp_Fade();
	    	break;		
#ifdef SUPPORT_M62429			
	case DISP_SW_VOL:
	    	Disp_Sw_Vol();
	    	break;				
	case DISP_MIC_VOL:
	    	Disp_Mic_Vol();
	    	break;	
	case DISP_ECHO:
	    	Disp_Echo();
	    	break;				
#endif						
#endif						
	case DISP_POWER_UP:
	    	Disp_Power_up();
	    	break;
	case DISP_PLAYMODE:
	    	Disp_Playmode();   
	   	break;
	case DISP_WAIT:
	   	Disp_Waiting();
	   	break;				 
	case DISP_USBDEV:
	    	Disp_USB_Slave();
	   	break;
	case DISP_FREQ:
	   	Disp_Freq();
	  	break;
    	case DISP_CH_NO:
	  	Disp_CH_NO();		
		break;
    	case DISP_SCAN_NO:
	 	Disp_Scan_NO();		
		break;	
#ifdef DISP_SCH_AT_FM_SCAN		
    	case DISP_SCH:
	 	Disp_Sch();		
		break;			
#endif		
#ifdef DISP_DEV_STR_BEFOR_PLAY		
	case DISP_CUR_DEV:
		Disp_curr_Dev();
		break;
#endif		
      	case DISP_AUX:
        	Disp_AUX();
     	 	break;				
#if defined(IPONE_DOCK_FUNC_ENABLE)
    	case DISP_IPOD:
        	Disp_IPOD();
     	 	break;	
#endif			
#if defined(BLUE_TOOTH_FUNC)
    	case DISP_BLUE_TOOTH:
        	Disp_BT();
     	 	break;	
#ifdef BLUE_TOOTH_DISP_VOL_DIR			
    	case DISP_BLUETOOTH_VOL:
        	Disp_BT_Vol();
     	 	break;
#endif			
#endif		
    	case DISP_START:
	 	Disp_Start();
	 	break;
#if defined(MP3_DISP_LOAD_STRING)		
    	case DISP_LOAD:
	 	Disp_Load();
	 	break;		
#endif
    	case DISP_ERROR:
	 	Disp_Error();
	 	break;		
    	case DISP_PWR_OFF:
	 	Disp_PwrOFF();
		break;
#ifdef USE_TIMER_POWER_OFF_FUNC
    	case DISP_PWR_TIMER:
	 	Disp_Timer_OFF();
		break;	
#endif
#if RTC_ENABLE
	case DISP_RTC_POINT:
        	//Disp_RTC_POINT();
        	Disp_RTC();		
		break;
#ifdef USE_RTC_YEAR_FUNCTION	
    	case DISP_RTC_DATE:
        	Disp_RTC_Date();
        	break;
#elif defined(NEW_RTC_SETTING_CTRL)
    	case DISP_RTC_DATE:
        	Disp_RTC_Date();
        	break;
#endif
#ifdef USE_MICPHONE_GPIO_DETECTION
    	case DISP_MIC:
        	Disp_Mic();
        	break;		
#endif			
    	case DISP_RTC:
        	Disp_RTC();
        	break;		
    	case DISP_RTC_PWD:
        	break;
    	case DISP_ALM_UP:
        	Disp_Alm_Up();
        	break;
#endif	 
#if defined(SPECTRUM_FUNC_ENABLE)
	case DISP_ROLLING_MODE:
	 Disp_roll_mode_Num();
	 	break;
#endif		
    	default:break;
    }

    Disp_Update();

}
