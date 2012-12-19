/*--------------------------------------------------------------------------*/
/**@file    msgfor_hot.c
   @brief   HOT 消息处理模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "msgfor_hot.h"
#include "rtc_mode.h"
#include "rtc_cpu.h"
#include "PT2313.h"
#include "config.h"
#include "mp3mode.h"

extern u8 _idata music_vol;  
u8 _idata my_music_vol=0;
extern u8 given_device;
extern u16 given_file_number;
extern _xdata SYS_WORK_MODE work_mode;
extern u16 cfilenum;
extern u8 eq_mode;
extern bool aux_online;
extern bool IR_KEY_Detect;
extern u8 play_status,device_active;
extern _xdata u8 rtc_mode;
extern _xdata u8 alm_flag;
extern _xdata u8 rtc_set;
extern _xdata u8 alm_set;
extern u8 bdata device_online;
xd_u8 IR_Type=0;
extern u16 get_fm_id();
extern void enter_fm_rev(void);
extern void FM_Chip_Set_Vol(u8 fm_vol);
extern void fm_chip_gpio_ctrl(bool fm_ctrl_flag);
extern void fm_rev_powerdown(void);
extern xd_u8 curr_menu;
extern void set_play_flash(u8 led_status);
#ifdef USE_MICPHONE_GPIO_DETECTION
extern bool get_mic_online_status(void);
#endif

#ifdef AC_SLAVE_ENABLE
extern void DSA_init(void);
extern void DSA_if_hdlr(void);
extern bool DSA_GETHERING_DATA_ENABLE_BIT;
#endif

#ifdef VOL_ADJ_SPARK_LED
bool vol_adj_spark_bit=0;
#endif

#ifdef USB_SD_DEV_PLUG_MEM
xd_u8 last_plug_dev=0;
#endif

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
extern bool dev_first_plugged_flag;
#endif

#if defined(WKUP_PIN_USE_ENABLE)||defined(MUTE_PORT_USE_WKUP)||defined(PWR_CTRL_WKUP)
extern void wkup_pin_ctrl(bool dir);
#endif
#ifdef PWM3_IN_USE
void pwm_setting(u8 level_setting);
#endif
#ifdef FLASH_LIGHT_FUNC
xd_u8 flash_level=0;
#endif
#ifdef RADIO_AM_WM_ENABLE
extern bool radio_mode;
extern void FMAM_Mode_Switch_Profile(u8 fm_wm);
extern bool is_AMFM_online(void);
#endif

#if defined(KEY_100_ENABLE)||defined(KEY_10_ENABLE)
xd_u8 key_100_flag=0;
#endif
bool pwr_up_flag=0;
#ifdef K800_MingYang_800_V001		
static bool mos_ctrl =0;
#endif
static bool supper_mute_lock=0;
#if defined(USE_SPECTRUM_PARTTERN)
static bool lcd_play_pattern_lock=0;
#endif
#ifdef MATRIX_KEY_ENABLE
bool key_scan_en=1;
#endif
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
bool new_vol_feature=0;
u8 last_disp_menu=0;
#endif
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
extern xd_u8 time_show_return_cnt; 
#endif
#ifdef ALARM_SEL_SOURCE		
extern xd_u8 alm_source;
#endif

#ifdef USE_MICPHONE_GPIO_DETECTION
extern bool mic_online;
#endif

#ifdef USE_CUSTOMIED_GPIO_KEY
void gpio_key_scan_one_or_two();
extern bool gpio_key_scan_bit;
#endif

#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
extern bool custom_first_time_pwr_flag;
#endif

#if defined(CHARGER_DETECT_INDICATOR)
extern bool charger_in_flag;
#endif

#ifdef DEVICE_SEL_MANUAL_ONLY
xd_u8 device_selected=0;
#endif

#ifdef VOL_ADJ_SPARK_LED
xd_u8 last_led_play_mod=0;
#endif

#if defined(SPECTRUM_FUNC_ENABLE)
bool spectrum_reflesh_en;
#endif

#if defined(USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM)
xd_u8 reset_key_cnt=0;
#endif
#include "gpio_config.h"
#if 0
#ifdef MUTE_PORT_USE_P01
#define SET_MUTE_PORT_DIR()		P0DIR &= ~0x02
#define SET_MUTE_PORT_PU() 			P0PU |= 0x02
#define MUTE_PORT_HIGH()				P01  =1
#define MUTE_PORT_LOW()				P01  =0
#else //MUTE_PORT_USE_P04
#define SET_MUTE_PORT_DIR()		P0DIR &= ~0x10
#define SET_MUTE_PORT_PU() 			P0PU |= 0x10
#define MUTE_PORT_HIGH()				P04  =1
#define MUTE_PORT_LOW()				P04  =0
#endif
#endif

#ifdef SUPPORT_PT2313
xd_u8 audio_effect_state=0;
#endif

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
bool earphone_plugged_flag =0;
#endif


#if defined(AUX_MODE_HOT_KEY_ENABLE)||defined(MUSIC_MODE_HOT_KEY_ENABLE)||defined(RADIO_MODE_HOT_KEY_ENABLE)||defined(RTC_MODE_HOT_KEY_ENABLE)
static bool mode_hot_key_normal_protect=0;
void set_mode_hotkey_protect(bool protec)
{
	mode_hot_key_normal_protect=protec;
}
bool get_mod_hotkey_protect_status()
{
	return mode_hot_key_normal_protect;
}
#endif

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
extern xd_u8 led_flash_tpye_poll;
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
bool mute_on_flash_enable=0;
#endif

#if defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
bool pause_flash_enable=0;
#endif
void set_led_flash_tpye(u8 type_reg)
{
	led_flash_tpye_poll = type_reg;
}
void Led_flash_screen_hdlr()
{
		if(led_flash_tpye_poll==0){

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)			
			if(mute_on_flash_enable){
				mute_on_flash_enable =0;
	            		put_msg_fifo(INFO_RESTORE_SCREEN);				
			}
#endif			
#if defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
			if(pause_flash_enable){
				pause_flash_enable =0;
		       	put_msg_fifo(INFO_RESTORE_SCREEN);				
			}
#endif
			return;
		}

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)

		if(led_flash_tpye_poll==1){
			if(get_super_mute_lock()){
				mute_on_flash_enable=~mute_on_flash_enable;
				if(!mute_on_flash_enable)
	            		put_msg_fifo(INFO_RESTORE_SCREEN);				
			}
			else{
				if(mute_on_flash_enable){
					mute_on_flash_enable =0;
	            			put_msg_fifo(INFO_RESTORE_SCREEN);				
				}
			}
		}
#endif		
#if defined(PAUSE_FLASH_WHOLE_SCREEN)
		if(led_flash_tpye_poll==2){
		
				if(play_status == MUSIC_PAUSE){
					pause_flash_enable=~pause_flash_enable;
					if(!pause_flash_enable)
		            		put_msg_fifo(INFO_RESTORE_SCREEN);				
				}
				else{
					if(pause_flash_enable){
						pause_flash_enable =0;
		            			put_msg_fifo(INFO_RESTORE_SCREEN);				
					}
				}
		}
#endif
#if defined(MP3_PUASE_FLASH_FIGURE)

		if(led_flash_tpye_poll==2){

			if(work_mode < SYS_FMREV){
				
				if((!play_status)&&((device_online&0x03)>0)){
					pause_flash_enable=~pause_flash_enable;
					if(!pause_flash_enable)
		            		put_msg_fifo(INFO_RESTORE_SCREEN);				
				}
				else{
					if(pause_flash_enable){
						pause_flash_enable =0;
		            			put_msg_fifo(INFO_RESTORE_SCREEN);				
					}
				}
			}
		}
#endif
}
void led_flash_screen_bg()
{
	if(led_flash_tpye_poll==0)return;

	if(led_flash_tpye_poll==1){
		if(curr_menu!=DISP_VOL)
		 Disp_Con(DISP_VOL);
	}
	else if(led_flash_tpye_poll==2){
		if(curr_menu!=DISP_PAUSE)
		 Disp_Con(DISP_PAUSE);
	}
}
#endif
void dac_highz_output_enable(void)
{
    DACCON1 &= ~(BIT(7));
    delay_10ms(50);
    DACCON1 |= BIT(6);
    //delay_10ms(2);
    DACCON0 = 0x5;
    DACCON2 = 3;
}
#if defined(ONE_WIRE_TUNE_ENABLE)

#define ONE_WIRE_CTRL_PORT_HIGH()		P01  =1
#define ONE_WIRE_CTRL_PORT_LOW()		P01  =0

void one_wire_delay(u16 d_t)
{
	while(d_t-->0);
}
void init_one_wire_port()
{
	P0DIR &= ~(BIT(4));
	P0PU |= (BIT(4));
}
void one_wire_ctrl_if(u8 pulse_num)
{
	init_one_wire_port();

	//printf("one_wire_ctrl_if \r\n");
	
	do{
		ONE_WIRE_CTRL_PORT_LOW();
		one_wire_delay(30);
		ONE_WIRE_CTRL_PORT_HIGH();
		one_wire_delay(30);
	}
	while(pulse_num-->0);

	ONE_WIRE_CTRL_PORT_HIGH();
	one_wire_delay(20);	
}
#endif

#if defined(CUSTOMIZED_KEY_FUNC_ENABLE)
bool gpio_ctrl_f=0;
void gpio_ctrl_if(bool ctrl_f)
{
#ifdef K0000_YH_082_V001
	DACCON0|=0x80; 
	P2DIR &= ~(BIT(7));
	P2PU |= (BIT(7));
	if(ctrl_f){
		P27 =1;
	}
	else{
		P27=0;
	}
#elif defined(K0000_BT_CHT909_V003)
	P1DIR &= ~(BIT(3));
	P1PU |= (BIT(3));
	if(ctrl_f){
		P13 =1;
	}
	else{
		P13=0;
	}
#elif defined(K0000_JK_PORTABLE_CHARGER_V001)

	P0DIR &= ~(BIT(3));
	P0PU |= (BIT(3));
	
	if(ctrl_f){
#ifdef USB_SD_PORTABLE_BAT_CHARGER
		cell_output_charge_enable(1);
#endif
		P03 =1;
	}
	else{
#ifdef USB_SD_PORTABLE_BAT_CHARGER
		cell_output_charge_enable(0);
#endif	
		P03=0;
	}
#else
	P0DIR &= ~(BIT(7));
	P0PU |= (BIT(7));
	if(ctrl_f){
		P07 =1;
	}
	else{
		P07=0;
	}
#endif	
}
#endif
u8 aux_ch_reg=0;
void aux_channel_crosstalk_improve(u8 ch_num)
{
	aux_ch_reg=ch_num;
	//printf("-------->%aux_ch_reg  %d \r\n",(u16)aux_ch_reg);

#ifdef UART_ENABLE
		if(ch_num == DAC_AMUX0){
			sys_printf(" AUX0_SELECTED_P24_P25");
		}
		else{
			sys_printf(" AUX1_SELECTED_P26_P27");
		}
#endif

#ifndef UART_ENABLE


#if !defined(FM_BY_PASS)||defined(IPONE_INDEPENDENT_MODE)
		if(ch_num == DAC_AMUX0){
			DACCON0 &=~0x40;
		     	P2DIR |=( (BIT(4))|(BIT(5)));
		    	P2PU &=~( (BIT(4))|(BIT(5)));
		    	//P2 &=~( (BIT(6))|(BIT(7)));
		}
		else if(ch_num == DAC_AMUX1){

#if !defined(AUX_P26_IN_USE)&&!defined(AUX_P26_IN_USE)
			DACCON0 &=~0x80;
		     	P2DIR |=( (BIT(6))|(BIT(7)));
		    	P2PU &=~( (BIT(6))|(BIT(7)));
		    	//P2 &=~( (BIT(6))|(BIT(7)));
#endif		    	
		}
#endif		

    		dac_out_select(ch_num);	//4

#if !defined(FM_BY_PASS)||defined(IPONE_INDEPENDENT_MODE)
		if(ch_num == DAC_AMUX0){	//4AUX0_P24_P25

#if !defined(AUX_P26_IN_USE)&&!defined(AUX_P26_IN_USE)
			DACCON0|=0x80;
		     	P2DIR &=~( (BIT(6))|(BIT(7)));
		    	P2PU |=( (BIT(6))|(BIT(7)));
		    	P2 &=~( (BIT(6))|(BIT(7)));
#endif
		}
		else if(ch_num == DAC_AMUX1){//4AUX0_P26_P27
		
			DACCON0|=0x40;
		     	P2DIR &=~( (BIT(4))|(BIT(5)));
		    	P2PU |=( (BIT(4))|(BIT(5)));
		    	P2 &=~( (BIT(4))|(BIT(5)));
		}
#endif

#endif
}
void main_vol(u8 vol)
{
#ifdef UART_ENABLE
	printf("-------->  sys set main_vol  %d \r\n",(u16)vol);
#endif

	music_vol = vol;
	dac_mute_control(0, 1);
	main_vol_set(0, SET_USE_CURRENT_VOL);
}
void my_main_vol(u8 my_vol)
{
#if defined( VOLUME_CUSTOMER_DEFINE)||defined(VOLUME_CUSTOMER_DEFINE_16)

	u16 vol_temp=0;
	vol_temp = (VOL_LIMIT*my_vol);
	vol_temp =(vol_temp/MAX_VOL_SHOW);
	//printf("-------------------->%dmy_main_vol  %d \r\n",(u16)my_vol,vol_temp);

#if defined(FM_BY_PASS)
	if(work_mode != SYS_FMREV)
	{
		    main_vol(vol_temp);
	}
	else{
		FM_Chip_Set_Vol(my_vol);
	}
#else
	    main_vol(vol_temp);
#endif

#elif defined(SUPPORT_PT2313)

	if(my_vol==0){
		main_vol(0);
		PT2313_Config(my_vol,VOL_ADJ);

	}
	else{
		main_vol(30);	
		PT2313_Config(my_vol,VOL_ADJ);
	 	PT2313_Config(0xff,BAL_ADJ);

	}		
#elif defined(NEW_CUSTOMED_VOLUME_DIVIDED_METHOD)
	u16 vol_temp=0,k,b;

	if(my_vol<=VOL_POINT_ONE){
		/* y = kx*/
		vol_temp =(u16)((VOL_POINT_A*my_vol)/VOL_POINT_ONE);
	}
	else if(my_vol<=VOL_POINT_TWO){
		/* y = kx+b*/
		//k =(u16)((VOL_POINT_B -VOL_POINT_A)/(VOL_POINT_TWO -VOL_POINT_ONE));
		b =(u16)(VOL_POINT_B-(((VOL_POINT_B -VOL_POINT_A)*VOL_POINT_TWO)/(VOL_POINT_TWO -VOL_POINT_ONE)));
		vol_temp =(u16)((((VOL_POINT_B -VOL_POINT_A)*my_vol)/(VOL_POINT_TWO -VOL_POINT_ONE))+b);
		
	}
	else{
		/* y = kx+b*/
		//k =(u16)((MAX_VOL_SHOW -VOL_POINT_B)/(MAX_VOL_SHOW -VOL_POINT_TWO));
		b =(u16)(VOL_POINT_B-(((VOL_POINT_B -VOL_POINT_A)*VOL_POINT_TWO)/(VOL_POINT_TWO -VOL_POINT_ONE)));
		vol_temp =(u16)((((VOL_POINT_B -VOL_POINT_A)*my_vol)/(VOL_POINT_TWO -VOL_POINT_ONE))+b);
	}
	//printf("-------------------->%dmy_main_vol  %d \r\n",(u16)my_vol,(u16)vol_temp);

#if defined(FM_BY_PASS)
	if(work_mode != SYS_FMREV)
	{
		    main_vol(vol_temp);
	}
	else{
		FM_Chip_Set_Vol(my_vol);
	}
#else
	    main_vol(vol_temp);
#endif

#elif defined( VOLUME_CUSTOMER_DEFINE_1)
	u16 vol_temp=0;
	if(my_vol == 0){
		
		vol_temp =0;
	}
	else{
		vol_temp = (190*my_vol)/(MAX_VOL_SHOW-1);
		vol_temp =(vol_temp+ 107)/10;
	}
	//printf("-------------------->%d my_main_vol  %d \r\n",(u16)my_vol,vol_temp);
	    main_vol((u8)vol_temp);
#elif defined(FM_BY_PASS)

#ifdef ADC_DETECT_LINE_IN
	if((!aux_online)&&(work_mode==SYS_AUX))return;
#endif

	if(work_mode != SYS_FMREV)
	{
		if(my_vol>VOL_LIMIT){
			
		    main_vol(VOL_LIMIT);
		}
		else{
		    main_vol(my_vol);
		}
	}
	else{
		FM_Chip_Set_Vol(my_vol);
	}
#else
	if(my_vol>VOL_LIMIT){
		
	    main_vol(VOL_LIMIT);
	}
	else{
	    main_vol(my_vol);
	}
#endif	
}

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)//||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
static bool plugged_flag=0;
void check_earphone_plugged(void)
{

	if(plugged_flag == earphone_plugged_flag){
		return;
	}
	else{
		plugged_flag =earphone_plugged_flag;
	}
	
	if(earphone_plugged_flag){	// plugged
#if 0//defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)

		       if (!aux_online){
		            put_msg_lifo(MSG_AUX_IN);
		            aux_online = 1;
			     sys_printf(" ----MSG_AUX_IN ");						
		       }
#else

#if defined(USE_HEADHPONE_DISABLE_FUNC)
			P17 = 1;
#else		
			Mute_Ext_PA(MUTE);
#endif

#endif
	}
	else{					// unplugged
#if 0//defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
		        if (aux_online){
		            put_msg_lifo(MSG_AUX_OUT);
		            aux_online = 0;
			     sys_printf(" ----MSG_AUX_OUT ");					
		        }
#else

#if defined(USE_HEADHPONE_DISABLE_FUNC)
			P17 = 0;
#else		
			Mute_Ext_PA(UNMUTE);
#endif

#endif
	}
}
#endif

#if defined(USE_SPECTRUM_PARTTERN)
bool get_lcd_flash_lock()
{
	return lcd_play_pattern_lock;
}
void set_lcd_flash_lock(bool flag)
{
	lcd_play_pattern_lock = flag;
}
#endif

bool get_super_mute_lock()
{
	return supper_mute_lock;
}
void clear_super_mute_lock()
{
	supper_mute_lock =0;
}

void Mute_Ext_PA(MUTE_TYPE M_Type)
{
	static bool mute_flag=0;

#ifdef USE_MICPHONE_GPIO_DETECTION
	if(get_mic_online_status())return;
#endif

	if(supper_mute_lock)my_main_vol(0);

	if(M_Type == AUTO){
		if(supper_mute_lock)return;

		mute_flag =~mute_flag;
	
		if(mute_flag){
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)

		if(IR_Type  == NO_FM_CHIP){

			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();
			MUTE_PORT_HIGH();
		}
		else{
#if defined(USE_FM_GPIO)			
			fm_chip_gpio_ctrl(1);
#endif
		}
#elif defined(MUTE_PORT_USE_WKUP)
			wkup_pin_ctrl(1);	//P03  =MUTE_LEVEL					
#else
			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();
			MUTE_PORT_HIGH();
#endif
			sys_printf("MUTE PA");
	  	}
		else{
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)

		if(IR_Type  == NO_FM_CHIP){

			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();			
			MUTE_PORT_LOW();
		}
		else{
#if defined(USE_FM_GPIO)			
			fm_chip_gpio_ctrl(0);
#endif
		}
#elif defined(MUTE_PORT_USE_WKUP)
			wkup_pin_ctrl(0);	//P03  =UNMUTE_LEVEL			
#else
			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();			
			MUTE_PORT_LOW();
#endif
			sys_printf("UNMUTE PA");
			
		}
	}
	else if(M_Type == MUTE){
		if(supper_mute_lock)return;
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)

	if(IR_Type  == NO_FM_CHIP){

		SET_MUTE_PORT_DIR();
		SET_MUTE_PORT_PU();	
		MUTE_PORT_HIGH();
	}
	else{
#if defined(USE_FM_GPIO)		
		fm_chip_gpio_ctrl(1);
#endif
	}
#elif defined(MUTE_PORT_USE_WKUP)
		wkup_pin_ctrl(1);	//P03  =MUTE_LEVEL		
#else
		SET_MUTE_PORT_DIR();
		SET_MUTE_PORT_PU();	
		MUTE_PORT_HIGH();
#endif
		mute_flag = 1;
		sys_printf("MUTE PA");
	}
	else if(M_Type == UNMUTE){

	#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
		if(earphone_plugged_flag)return;
	#endif
		if(supper_mute_lock)return;
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)

	if(IR_Type  == NO_FM_CHIP){

		SET_MUTE_PORT_DIR();
		SET_MUTE_PORT_PU();
		MUTE_PORT_LOW();
	}
	else{
#if defined(USE_FM_GPIO)
		fm_chip_gpio_ctrl(0);
#endif
	}
#elif defined(MUTE_PORT_USE_WKUP)
		wkup_pin_ctrl(0);	//P03  =UNMUTE_LEVEL		
#else
		SET_MUTE_PORT_DIR();
		SET_MUTE_PORT_PU();
		MUTE_PORT_LOW();
#endif
		mute_flag =0;
		sys_printf("UNMUTE PA");
		
	}
	else if(M_Type == SUPERMUTE){

		mute_flag =~mute_flag;
	       
		if(mute_flag){
			
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)		

		if(IR_Type  == NO_FM_CHIP){

			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();
			MUTE_PORT_HIGH();
		}
		else{
#if defined(USE_FM_GPIO)			
			fm_chip_gpio_ctrl(1);						
#endif
		}
#elif defined(MUTE_PORT_USE_WKUP)
			wkup_pin_ctrl(1);	//P03  =MUTE_LEVEL

#else
			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();
			MUTE_PORT_HIGH();
#endif

			supper_mute_lock  = 1;	
		       my_main_vol(0);
#if defined(K000_HG_898_V001)
	 	Disp_Con(DISP_VOL);
#endif			   
#if defined(USE_MUTE_LED_INDICATOR)
		 set_play_flash(LED_FLASH_FAST);
#endif
	  	}
		else{
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)

	if(IR_Type  == NO_FM_CHIP){
		
			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();			
			MUTE_PORT_LOW();
	}
	else{
#if defined(USE_FM_GPIO)						
			fm_chip_gpio_ctrl(0);
#endif
	}
#elif defined(MUTE_PORT_USE_WKUP)
			wkup_pin_ctrl(0);	//P03  =UNMUTE_LEVEL
#else
			SET_MUTE_PORT_DIR();
			SET_MUTE_PORT_PU();			
			MUTE_PORT_LOW();
#endif
			supper_mute_lock  = 0;	
		       my_main_vol(my_music_vol);
#if defined(USE_MUTE_LED_INDICATOR)
		 set_play_flash(LED_FLASH_ON);
#endif		   
		}
	}

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
		if(supper_mute_lock){
			set_led_flash_tpye(1);
		}
		else{
			set_led_flash_tpye(0);
		}
#endif		

#if defined(K0000_GW_118B_V001)||defined(K0000_GW_ZX015_V001)
	if(mute_flag){
		P02 = 1;	   
	}
	else{
		P02 = 0;	   
	}
#endif

}
#if defined(USE_MANUAL_IDLE_FUNC)||defined(IPONE_INDEPENDENT_MODE)||defined(RADIO_AM_WM_ENABLE)||defined(BLUE_TOOTH_FUNC)
#define MAX_FUNC_LIST 		IDLE+1
#else
#define MAX_FUNC_LIST 		IDLE
#endif
static _xdata u16 Sys_Func_List=0;
u8 last_work_mode=0;

#if defined(IPONE_DOCK_FUNC_ENABLE)
#if defined(IPHONE_DETECT_IN_USE)
extern bool iphone_status;
#endif
#endif

void Add_Func_To_List(DEV_ON_LIST Dev)
{
	Sys_Func_List |=BIT(Dev);
	//printf(" --->Add_Func_To_List %x \r\n",(u16)Sys_Func_List);

}
void Remov_Func_From_List(DEV_ON_LIST Dev)
{
#ifdef FORCE_MOUNT_SD_CARD_DEV
	if(Dev==SD_DEV){
		return;
	}
#endif
	Sys_Func_List &=~(BIT(Dev));
	//printf(" --->Remov_Func_From_List %x \r\n",(u16)Sys_Func_List);
	
}
void Set_Curr_Func(SYS_WORK_MODE curr_mod)
{
	work_mode = curr_mod;	
	Sys_Func_List =((curr_mod<<8)|(Sys_Func_List&0x00FF));	
	//printf(" --->Set_Curr_Func %x \r\n",(u16)Sys_Func_List);
	
}
void Init_Func_List()
{
	//sys_printf("Init_Func_List");
	Sys_Func_List=0;
	
#ifndef NOT_MOUNT_USB_SD_DEV
	if((get_device_online_status()&0x02))
		Add_Func_To_List(USB_DEV);

	if((get_device_online_status()&0x01))
		Add_Func_To_List(SD_DEV);
#endif

#ifdef FORCE_MOUNT_SD_CARD_DEV
		Add_Func_To_List(SD_DEV);
#endif

#ifndef NO_FM_CHIP_ON_BOARD
       if(get_fm_id() ==0xFFFF){	//NO FM 
		IR_Type  = NO_FM_CHIP;
		
#ifdef UART_ENABLE
       	Add_Func_To_List(FM_DEV);
#endif
		
    	}
    	else{
		IR_Type  = WITH_FM_CHIP; 

#ifndef NOT_MOUNT_FM_DEV		
       	Add_Func_To_List(FM_DEV);
#ifdef RADIO_AM_WM_ENABLE
		if(is_AMFM_online())
	       	Add_Func_To_List(AM_DEV);
#endif
#endif
		//enter_fm_rev();  
		fm_rev_powerdown();
    	}
#endif

#ifndef NOT_USE_LINE_IN_FUNC

#ifdef USE_LINE_IN_DETECT_FUNC
#ifdef AUX_DETECT_FUNC_WITH_MANUAL_SEL
	Add_Func_To_List(AUX_DEV);
#else
	delay_10ms(20);
	if(aux_online)
		Add_Func_To_List(AUX_DEV);
#endif	
#else	
#ifndef DONT_MOUNT_AUX_FUNC
		Add_Func_To_List(AUX_DEV);
#endif
#endif

#if defined(USE_LINE_IN_GPIO_SEL_MODE)
	AUX_GPIO_INIT();
	delay_10ms(1);
	if(AUX_GPIO_READ){
		Add_Func_To_List(AUX_DEV);
	}
	else{
		Remov_Func_From_List(AUX_DEV);
	}
#endif
#endif


#if defined(IPONE_INDEPENDENT_MODE)
		Add_Func_To_List(IPH_DEV);
#endif
#ifdef USE_RTC_FUNCTION
		Add_Func_To_List(RTC_DEV);
#ifdef DONT_MOUNT_RTC_FUNC
		Remov_Func_From_List(RTC_DEV);
#endif
#endif

#ifdef BLUE_TOOTH_FUNC
	Add_Func_To_List(BT_DEV);
#endif

#if defined(USE_BT_GPIO_SEL_MODE)
	BT_GPIO_SEL_INIT();
	_nop_();
	_nop_();
	if(!BT_GPIO_SEL_READ){
		Add_Func_To_List(BT_DEV);
#if defined(SYS_DEFAULT_IN_BLUETOOTH_MODE)
		Set_Curr_Func(SYS_BT);
#endif				
	}
	else{
		Remov_Func_From_List(BT_DEV);
	}
#endif

#ifdef USE_MANUAL_IDLE_FUNC
		Add_Func_To_List(IDLE);
#endif

#if defined(IPONE_DOCK_FUNC_ENABLE)
#if defined(IPHONE_DETECT_IN_USE)
#if defined(IPHONE_DOCKING_PRO)
	if(iphone_status){
		Set_Curr_Func(SYS_IPH);
	}
	else{
		Remov_Func_From_List(IPH_DEV);
	}
#endif	
#endif
#endif

}
SYS_WORK_MODE Next_Func()
{
	u8 i;
	//printf(" -111-->Sys_Func_List %x \r\n",(u16)Sys_Func_List);
	//printf(" -222-->CURR FUNC %x \r\n",(u16)((Sys_Func_List&0xFF00)));

	if((Sys_Func_List&0x0FF)>0)
	{
		for(i=(((Sys_Func_List&0xFF00)>>8)+1);i<MAX_FUNC_LIST;i++){
			//printf(" --%x->Next_Func --->BIT  %x \r\n",(u16)i,(u16)(BIT(i)));
			if((Sys_Func_List&(BIT(i)))>0){
				return i;
			}
		}				
		for(i=0;i<=((Sys_Func_List&0xFF0)>>8);i++)
			if((Sys_Func_List&(BIT(i)))>0){
				return i;
		}
	}
	
	return SYS_IDLE;
}
#ifdef GPIO_SWITCH_SELECT_MODE
bool gpio_select_enable=0;
xd_u8 gpio_level_flag=0;
bool gpio_select_mode(void)
{
#ifdef K2036_WK_2036_V001

	
	if(work_mode == SYS_USBDEVICE){

		return 1;
	}
	
	WKUPPND|=BIT(6);
	_nop_();
	_nop_();
	
	if((WKUPPND&BIT(7))>0){

		if(gpio_level_flag==0){		//3RISING EDGE LEVEL

			gpio_level_flag = 0x01;

			if(work_mode != SYS_FMREV){

				Set_Curr_Func(SYS_FMREV);
				set_play_flash(LED_FLASH_ON);
				return 0;
			}
		}		
	}
	else{

		if(gpio_level_flag==0x01){	//2 FALLING EDGE LEVEL

			gpio_level_flag = 0x00;

			if(work_mode > SYS_MP3DECODE_SD){

				if((get_device_online_status()&0x03)>0){
					
					Set_Curr_Func(SYS_MP3DECODE_USB);
					return 0;
				}
				else{
					if(aux_online){

						if(work_mode != SYS_AUX){
							Set_Curr_Func(SYS_AUX);
							return 0;
						}
					}
					else if(work_mode != SYS_IDLE){
						Add_Func_To_List(IDLE);
						Set_Curr_Func(SYS_IDLE);
						put_msg_lifo(INFO_NO_DEV);
						return 0;
					}
				}
			}
		}
	}
	return 1;
#elif defined(K1192_FW_60_V001)	

	WKUPPND|=BIT(6);	
	_nop_();
	_nop_();
	if(WKUPPND&BIT(7)){

		if(work_mode == SYS_AUX){
			Set_Curr_Func(SYS_MP3DECODE_USB);
			return 0;
		}			
	}
	else{		
		if(work_mode != SYS_AUX){
			Set_Curr_Func(SYS_AUX);
			set_play_flash(LED_FLASH_ON);
			return 0;
		}

	}
#else
#if 0
	P2DIR &=~(BIT(3));
	P2 |=(BIT(3));
	P2PU |=(BIT(3));
	P2DIR |=(BIT(3));
#endif
	P0DIR &=~(BIT(2));
	P0 |=(BIT(2));
	P0PU |=(BIT(2));
	P0DIR |=(BIT(2));
	_nop_();
	_nop_();
	if(P02 ==0){

		if(work_mode == SYS_FMREV){
			Set_Curr_Func(SYS_MP3DECODE_USB);
			return 0;
		}			
	}
	else{		
		if(work_mode != SYS_FMREV){
			Set_Curr_Func(SYS_FMREV);
			set_play_flash(LED_FLASH_ON);
			return 0;
		}

	}
	return 1;
#endif
	
}
#endif
#ifdef LED_MODE_INDICATOR_ENABLE
void LED_MODE_INDICATOR()
{
	LED_Indicator_init();
	
	if(work_mode ==SYS_MP3DECODE_USB){
		LED_MODE_USB = 1;
		LED_MODE_SD= 0;
		LED_MODE_FM= 0;
	}
	else if(work_mode ==SYS_MP3DECODE_SD){
		LED_MODE_USB = 0;
		LED_MODE_SD= 1;
		LED_MODE_FM= 0;
	}
	else if(work_mode ==SYS_FMREV){
		LED_MODE_USB = 0;
		LED_MODE_SD= 0;
		LED_MODE_FM=1;
	}	
}
#endif
#if defined(KEY_PRESS_LED_INDICATOR)
extern void set_play_flash(u8 led_status);
void key_press_led_indicator(u8 key_t)
{
	if((key_t!=0x1F)&&(key_t!=0xff)){
		
		last_led_play_mod = get_led_flash_mode();
		//printf( "---->key_press_led_indicator %x \r\n",(u16)last_led_play_mod);
		set_play_flash(LED_FLASH_VERY_FAST);
		delay_10ms(6);
		restore_led_flash_mod(last_led_play_mod);		
	}
}
#elif defined(CUSTOM_KEY_FEATURE_USE)
void custom_key_hdlr(u8 key_t)
{
	if((key_t!=0x1F)&&(key_t!=0xff)){

		if((key_t == INFO_MUTE)||(key_t == (INFO_MUTE |KEY_SHORT_UP))){
			return;
		}
		
		if(supper_mute_lock){
			clear_super_mute_lock();
			Mute_Ext_PA(SUPERMUTE);

		}
	}
}
#endif

#if defined(USE_TIMER_POWER_OFF_FUNC)
u8 timer_pwr_idx=0,timer_disp=0;
u16 timer_pwr_cnt=0;
void timer_pwr_setting()
{
	timer_pwr_idx++;
	if(timer_pwr_idx>6)timer_pwr_idx=0;
	timer_pwr_cnt =0;

	timer_disp=timer_pwr_idx*10;
	Disp_Con(DISP_PWR_TIMER);
	delay_10ms(200);
}
void timer_pwr_off_hdlr()
{
	if(timer_pwr_idx>0){
		timer_pwr_cnt++;
	//printf( "---->timer_pwr_off_hdlr %x \r\n",(u16)timer_pwr_cnt);

		if(timer_pwr_cnt>=(timer_pwr_idx*2*60)){
			timer_pwr_idx =0;
			timer_pwr_cnt =0;
			//printf( "---->INFO_TIMER_OFF %x \r\n",(u16)timer_pwr_cnt);

            		//put_msg_lifo(INFO_CH_DOWN|KEY_SHORT_UP);
            		put_msg_lifo(INFO_TIMER_OFF);
		}	
	}
}
#endif

#if defined(CUSTOM_FUNC_POLLING)
xd_u8 lam_led_flag=0;
bool custom_func_tick=0;
extern bool alm_sw;
void custom_func_polling()
{
	DACCON0|=0xC0;
	P2DIR &=~(BIT(4)|(BIT(5)));
	P2PU |= (BIT(4)|(BIT(5)));
		
	if(alm_sw){
		P24 = 1;
	}
	else{
		P24 =0;
	}

       if(lam_led_flag>0){

		P25 = 1;
	}
	else{
		P25 = 0;
	}
	

}
#endif


#ifdef SUPPORT_PT2313
void clr_aud_effect_state()
{
	audio_effect_state=0;
}
void audio_effect_hdlr(u8 hdlr_cmd)
{
	//printf(" audio_effect_hdlr %x \r\n",(u16)audio_effect_state);
	if(audio_effect_state ==CONFIG_VOL){

	#if  1
		if(hdlr_cmd ==0x02){

			if (my_music_vol)
	            my_music_vol--;		
		}
		else if(hdlr_cmd ==0x01){
        		my_music_vol += 1;
		}

	        if (my_music_vol > MAX_VOL)
	        {
	            my_music_vol = MAX_VOL;
	        }
		 if(my_music_vol == MIN_VOL){
		 	
 			Mute_Ext_PA(MUTE);
		 }
		 else{

 			Mute_Ext_PA(UNMUTE);
			clear_super_mute_lock();
		 }
		 
        	 write_info(MEM_VOL,my_music_vol);
	 	 my_main_vol(my_music_vol);	
		 Disp_Con(DISP_VOL);
		 
		#endif
	}
	else if(audio_effect_state ==CONFIG_TRE){
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(hdlr_cmd,TRELBE_ADJ);
#endif					
	 	Disp_Con(DISP_TREBLE);
	}
	else if(audio_effect_state ==CONFIG_BAS){
		
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(hdlr_cmd,BASS_ADJ);
#endif			
	 	Disp_Con(DISP_BASS);
	}
	else if(audio_effect_state ==CONFIG_BAL){
		
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(hdlr_cmd,BAL_ADJ);
#endif		
	 	Disp_Con(DISP_BALENCE);

	}	
	else if(audio_effect_state ==CONFIG_EQ){

		if(hdlr_cmd ==0x02){
			eq_mode++;

			if (eq_mode > USER)
	        	{
	            		eq_mode = NORMAL;
	        	}
		}
		else if(hdlr_cmd ==0x01){
			eq_mode--;

			if ((eq_mode > USER))
	        	{
	            		eq_mode = USER;
	        	}			
		}
	//printf(" eq_mode %x \r\n",(u16)eq_mode);

        	write_info(MEM_EQ_MODE,eq_mode);
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(0xFF,EQ_ADJ);
#endif
        	//set_eq(eq_mode);
        	Disp_Con(DISP_EQ);
	}
	else if(audio_effect_state ==CONFIG_LUD){
		
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(0xFF,LOUD_ADJ);
#endif		
	 	Disp_Con(DISP_LONDESS);

	}
	else if(audio_effect_state ==CONFIG_FAD){
		
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(hdlr_cmd,FADE_ADJ);
#endif		
	 	Disp_Con(DISP_FADE);

	}	
}
#endif		

/*----------------------------------------------------------------------------*/
/**@brief   几个任务都会用到的消息集中处理的函数
   @param   key： 需要处理的消息
   @return  0：需要切换工作模式;
   @note    unsigned char I2C_sendbyte(unsigned char I2Cdata)
*/
/*----------------------------------------------------------------------------*/
u8 ap_handle_hotkey(u8 key)
{
	SYS_WORK_MODE mode_reg=0;
#if RTC_ENABLE
    if (alm_flag == 1)
    {
        alm_flag = 2;
        fond_alm_clk();
#ifdef ALARM_SEL_SOURCE		
	 if(alm_source ==ALM_SOUR_BEEP){
			Set_Curr_Func(SYS_RTC);
	 }
	 else  if(alm_source ==ALM_SOUR_USB){
			Set_Curr_Func(SYS_MP3DECODE_USB);	 	
	 }
	 else  if(alm_source ==ALM_SOUR_FM){
		Set_Curr_Func(SYS_FMREV);
	 }
	 return 0;
#endif	 	
#ifdef RTC_ALRM_MEM_LAST_WORK_MODE
	last_work_mode = work_mode;
#endif
        if (work_mode != SYS_RTC)
        {
            work_mode = SYS_RTC;
            return 0;
        }
    }
#endif
#if defined(CUSTOM_FUNC_POLLING)
	custom_func_polling();
#endif

#ifdef AC_SLAVE_ENABLE
	if(DSA_GETHERING_DATA_ENABLE_BIT){
		DSA_GETHERING_DATA_ENABLE_BIT =0;
		DSA_if_hdlr();
	}
#endif

#ifdef MATRIX_KEY_ENABLE
	if(key_scan_en){
		key_scan_en =0;
		key_matrix_scan();
	}
#endif
#ifdef USE_CUSTOMIED_GPIO_KEY
	if(gpio_key_scan_bit){
		gpio_key_scan_bit=0;
		gpio_key_scan_one_or_two();
	}
#endif

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
	check_earphone_plugged();
#endif

#ifdef GPIO_SWITCH_SELECT_MODE
	if(gpio_select_enable){
		gpio_select_enable=0;
		if(!gpio_select_mode())return 0;

	}
	
#ifdef K2036_WK_2036_V001
	if(work_mode==SYS_FMREV){
		if((key ==MSG_SDMMC_IN)||(key ==MSG_USB_DISK_IN)){
			key = 0x00;
		}
	}
#else
	if(work_mode==SYS_FMREV){
		if((key ==MSG_AUX_IN)||(key ==MSG_SDMMC_IN)||(key ==MSG_USB_DISK_IN)){
			key = 0x00;
		}
	}
#endif

#endif

#if defined(SPECTRUM_FUNC_ENABLE)    
	if(spectrum_reflesh_en){
		EA =0;
		spectrum_reflesh_en =0;
		get_spectrum_data();
		EA =1;
	}
#endif

#if 0
	if(key!=0xff)
	printf( "---->ap_handle_hotkey %x \r\n",(u16)key);
#endif

    switch (key)
    {
#if USB_DEVICE_OTG
    case MSG_USB_PC_IN:
        if (work_mode != SYS_USBDEVICE)
        {
            work_mode = SYS_USBDEVICE;
            return 0;
        }
        break;
#endif
#if defined(MINI_DIGIT_BOX)        
	case INFO_1|KEY_LONG:
	     Set_Curr_Func(RTC_DEV);
            rtc_mode = RTC_SET_MODE;
            rtc_set=3; 
	     return 0;	
		break;
	case INFO_2|KEY_LONG:

	     Set_Curr_Func(RTC_DEV);
            rtc_mode = ALM_SET_MODE;
            alm_set=0;
            return 0;	
		break;
	case INFO_6|KEY_LONG:

	     Set_Curr_Func(RTC_DEV);
            rtc_mode = ALM_SET_MODE;
            alm_set=1;
            return 0;	
		break;
	case INFO_3|KEY_LONG:
		timer_pwr_setting();
		break;	
#endif

#if defined(USE_TIMER_POWER_OFF_FUNC)
	case INFO_EQ_UP|KEY_LONG:
		timer_pwr_setting();
		break;	
#endif		
#ifdef USE_USB_HOTPLUG_FUNC
        case MSG_USB_PC_OUT:
	     set_usb_hotplug_protect(0);
		break;
	case INFO_PC_HOTPLUG:

		last_work_mode =  work_mode;
	       work_mode = SYS_USBDEVICE;
		return 0;
#endif

#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)||defined(MP3_PUASE_FLASH_FIGURE)||defined(PAUSE_FLASH_WHOLE_SCREEN)
    case INFO_RESTORE_SCREEN:
		Disp_Con(curr_menu);
	break;
#endif	

#ifdef AUX_MODE_HOT_KEY_ENABLE
#ifdef AUX_MODE_HOT_KEY_USE_PLAY_LONG
    case INFO_PLAY | KEY_LONG:
#else
    case INFO_AUX_MOD | KEY_SHORT_UP:
#endif		
        if (work_mode != SYS_AUX)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif        
	     Set_Curr_Func(AUX_DEV);
            return 0;
        }
        break;
#endif

#ifdef BLUE_TOOTH_FUNC

#ifdef BT_MODE_HOT_KEY_ENABLE
    case INFO_BT_MOD | KEY_SHORT_UP:
        if (work_mode != SYS_BT)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif        
	     Set_Curr_Func(BT_DEV);
            return 0;
        }
        break;
#endif
#endif

#ifdef MUSIC_MODE_HOT_KEY_ENABLE
    case INFO_MP3_MOD | KEY_SHORT_UP:
        if (work_mode > SYS_MP3DECODE_SD)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif                
	     Set_Curr_Func(USB_DEV);
            return 0;
        }
#ifdef MUSIC_MODE_HOT_KEY_SHORT_FOR_USB_SD_SEL
        put_msg_lifo(INFO_EQ_DOWN| KEY_SHORT_UP);
#endif
        break;
#endif
		
#ifdef RADIO_MODE_HOT_KEY_ENABLE	
    case INFO_FM_MOD | KEY_SHORT_UP:
		
#ifdef RADIO_AM_WM_ENABLE
        if (work_mode == SYS_AMREV){
		Set_Curr_Func(SYS_FMREV);			
	     	FMAM_Mode_Switch_Profile(SYS_FMREV);
		break;
	}
#endif		

        if (work_mode != SYS_FMREV)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif   
	     set_mode_hotkey_protect(1);
	     Set_Curr_Func(SYS_FMREV);
#ifdef RADIO_AM_WM_ENABLE
	     FMAM_Mode_Switch_Profile(SYS_FMREV);
#endif		 
            return 0;
        }
        break;
		
#ifdef RADIO_AM_WM_ENABLE
    case INFO_WM_MOD | KEY_SHORT_UP:
#ifdef RADIO_AM_WM_ENABLE
        if (work_mode == SYS_FMREV){
	       Set_Curr_Func(SYS_AMREV);			
	     	FMAM_Mode_Switch_Profile(SYS_AMREV);
		break;
	}
#endif		
        if (work_mode != SYS_AMREV)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif   
	     set_mode_hotkey_protect(1);
	     Set_Curr_Func(SYS_AMREV);
#ifdef RADIO_AM_WM_ENABLE
	     FMAM_Mode_Switch_Profile(SYS_AMREV);
#endif		 		 
            return 0;
        }
        break;
#endif

#endif

#if defined(RTC_MODE_HOT_KEY_ENABLE)	
#ifdef CUSTOM_KEY_LONG_FOR_RTC_HOTKEY
    case INFO_CUS_KEY_1 | KEY_LONG:		
#elif defined(MODE_KEY_LONG_FOR_RTC_HOTKEY)
    case INFO_MODE| KEY_LONG:		
#endif
    case INFO_RTC_MOD | KEY_SHORT_UP:
        if (work_mode != SYS_RTC)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif                
	     Set_Curr_Func(RTC_DEV);
            return 0;
        }
        break;		
#endif

#ifdef USE_MICPHONE_GPIO_DETECTION
    case MSG_MIC_IN :
		Mute_Ext_PA(UNMUTE);
              mic_online = 1;
		break;
    case MSG_MIC_OUT:
#ifdef USE_RTC_FUNCTION
		if(work_mode<SYS_RTC)
#endif			
		if(play_status == MUSIC_PAUSE)
			Mute_Ext_PA(MUTE);
		break;
#endif

    case MSG_USB_DISK_OUT:                           		
	Remov_Func_From_List(USB_DEV);
	
#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)
	plugged_flag=0;	
#endif
#endif
	
#ifdef DEVICE_ON_LINE_LED_IND

	if((get_device_online_status()&0x01)>0){
		given_device=BIT(SDMMC);
		
	}
#ifdef USB_SD_DEV_PLUG_MEM
	 last_plug_dev=0;
#endif
	
	set_play_flash(LED_FLASH_STOP);
#endif
	
        break;
    case MSG_SDMMC_OUT:
	Remov_Func_From_List(SD_DEV);
#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)
	plugged_flag=0;	
#endif
#endif

#ifdef DEVICE_ON_LINE_LED_IND

	if((get_device_online_status()&0x02)>0){
		given_device=BIT(USB_DISK);
	}
#ifdef USB_SD_DEV_PLUG_MEM
	 last_plug_dev=0;
#endif

	
	set_play_flash(LED_FLASH_STOP);
#endif	
        break;

#if !defined(NOT_USE_LINE_IN_FUNC)||defined(LINE_IN_DETECT_SHARE_LED_STATUS_PORT)
#ifndef ADC_DETECT_LINE_IN
    case MSG_AUX_IN :
		
#ifdef LINE_DETECT_INDEPENDENT_MODE
#ifdef  USE_POWER_KEY
	    set_play_flash(LED_FLASH_STOP);
#if defined(PWR_CTRL_WKUP)
	    wkup_pin_ctrl(0);
#else
	    power_ctl(0);
#endif
#endif

#endif
	Add_Func_To_List(AUX_DEV);
        if (work_mode != SYS_USBDEVICE)
        {
#ifdef GPIO_SWITCH_SELECT_MODE
	    last_work_mode = work_mode;
#endif        
            work_mode = SYS_AUX;
            return 0;
        }
        break;

    case MSG_AUX_OUT :
	Remov_Func_From_List(AUX_DEV);

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)
	plugged_flag=0;	
#endif
#endif
	
        if (SYS_AUX == work_mode)
        {
#ifdef GPIO_SWITCH_SELECT_MODE
	     Set_Curr_Func(last_work_mode);
            return 0;
#endif        
#if defined(SYS_POWER_ON_DEFAULT_IN_BT_AUX_ALTERNATIVE_MODE)
	     Set_Curr_Func(SYS_BT);
#else
            work_mode = SYS_MP3DECODE_USB;
#endif
            return 0;
        }
        break;
#endif
#endif

#if defined(IPONE_INDEPENDENT_MODE)&&defined(IPHONE_DETECT_IN_USE)
    case MSG_IPOD_IN :
	last_work_mode = work_mode;
	Add_Func_To_List(IPH_DEV);
        if (work_mode != SYS_USBDEVICE)
        {
#ifdef USE_USB_HOTPLUG_FUNC
	    if(work_mode == SYS_USBDEVICE)
	     set_usb_hotplug_protect(1);
#endif                        
            work_mode = SYS_IPH;
            return 0;
        }
        break;

    case MSG_IPOD_OUT :
	Remov_Func_From_List(IPH_DEV);
        if (SYS_IPH == work_mode)
        {
            work_mode = last_work_mode;
	     if(work_mode == SYS_IDLE){
			put_msg_lifo(INFO_NO_DEV);
	     }
            return 0;
        }
        break;
#endif

    case MSG_SDMMC_IN :
	 Add_Func_To_List(SD_DEV);
#ifdef AC_SLAVE_ENABLE
	DSA_init();
#endif	

#ifdef USB_SD_DEV_PLUG_MEM
	if((get_device_online_status()&0x02)>0){
	 	last_plug_dev=BIT(SDMMC);
	}
	else{
	        given_device = BIT(SDMMC);

	}
#endif

#ifdef DEVICE_ON_LINE_LED_IND
		set_play_flash(LED_FLASH_NOR);
#endif

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
	if((get_device_online_status()&0x01)==0)
		dev_first_plugged_flag=1;
#endif			

#ifdef DEVICE_PLUG_N_PLAY_DISBALE_AUX_MODE
	 if((work_mode == SYS_AUX)){
		break;
	 }
#endif

#ifdef DEVICE_SEL_MANUAL_ONLY
	 if((device_selected== BIT(SDMMC))&&(work_mode == SYS_MP3DECODE_SD))
#endif
	 {	

#ifdef DEVICE_AUTO_PLAY_IN_CURR_MODE_ONLY
        if ((work_mode == SYS_MP3DECODE_SD) )
        {
       	given_device = BIT(SDMMC);
	        given_file_number = 1;	
	        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
		 break;
        }
#endif

	 
#ifndef DISABLE_DEVICE_HOT_PLUG_AND_PLAY	 
        given_device = BIT(SDMMC);
        given_file_number = 1;
        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
        if ((work_mode != SYS_MP3DECODE_SD)
#ifndef SD_CARD_PLUG_ENABLE_IN_USB_PC_MODE			
		&& (work_mode != SYS_USBDEVICE)
#endif		
		)
        {
#if defined(DISP_DEV_STR_BEFOR_PLAY)
	      Disp_Con(DISP_CUR_DEV);
#endif		       
		Set_Curr_Func(SYS_MP3DECODE_SD);
            return 0;
        }
#endif				
	}
        break;

    case MSG_USB_DISK_IN  :
	 Add_Func_To_List(USB_DEV);	
#ifdef AC_SLAVE_ENABLE
	DSA_init();
#endif	 

#ifdef USB_SD_DEV_PLUG_MEM
	if((get_device_online_status()&0x01)>0){
		
	 	last_plug_dev=BIT(USB_DISK);
	}
	else{

	        given_device = BIT(USB_DISK);
	}
#endif

#ifdef DEVICE_ON_LINE_LED_IND
		set_play_flash(LED_FLASH_NOR);
#endif

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
	if((get_device_online_status()&0x02)==0)
		dev_first_plugged_flag=1;
#endif			

#ifdef DEVICE_PLUG_N_PLAY_DISBALE_AUX_MODE
	 if((work_mode == SYS_AUX)){
		break;
	 }
#endif
#ifdef DEVICE_SEL_MANUAL_ONLY
	 if((device_selected== BIT(USB_DISK))&&(work_mode == SYS_MP3DECODE_USB))
#endif
	 {
#ifdef DEVICE_AUTO_PLAY_IN_CURR_MODE_ONLY
        if ((work_mode == SYS_MP3DECODE_USB) )
        {
	        given_device = BIT(USB_DISK);
	        given_file_number = 1;	
	        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
		 break;
        }
#endif

#ifndef DISABLE_DEVICE_HOT_PLUG_AND_PLAY
        given_device = BIT(USB_DISK);
        given_file_number = 1;	
        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
        if ((work_mode != SYS_MP3DECODE_USB) && (work_mode != SYS_USBDEVICE))
        {
#ifdef USE_USB_HOTPLUG_FUNC
	     set_usb_hotplug_protect(1);
#endif                                
#if defined(DISP_DEV_STR_BEFOR_PLAY)
	      Disp_Con(DISP_CUR_DEV);
#endif		
            work_mode = SYS_MP3DECODE_USB;
            return 0;
        }
#endif		
	}
        break;
		
#if defined(USE_LONG_PLAY_KEY_TO_SWITCH_MODE)
        case INFO_PLAY | KEY_LONG :
#elif defined(USE_LONG_PLAY_MODE_KEY_TO_SWITCH_MODE)			
        case INFO_PLAY_MODE | KEY_LONG :
#elif defined(USE_POWER_KEY_TO_SWITCH_MODE)			
        case INFO_POWER| KEY_SHORT_UP :
#ifdef USE_IR_POWER_KEY_TO_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			goto _SYS_GO_IN_POWER_OFF;	
		}
#endif

#endif
    case INFO_MODE | KEY_SHORT_UP:
		
        if (work_mode == SYS_USBDEVICE){

	     #ifdef ENABLE_MODE_KEY_AT_USB_AUDIO
			return 0;
	     #else
            		break;
	     #endif
		 
       }
	mode_reg =Next_Func();
        //printf(" ----->Next_Func %x --- \r\n",(u16)mode_reg);
        
	if(work_mode ==mode_reg){
		break;
	}
	else{

#if 1//defined(LINE_IN_PLAY_KEY_PAUSE)
	        play_status =MUSIC_STOP;
#endif		
		work_mode = mode_reg;
		 clear_super_mute_lock();
#if defined(USE_SPECTRUM_PARTTERN)		 
		 set_lcd_flash_lock(UNLOCK);
#endif
	}
#if defined(FORCE_GO_TO_MP3_MODE)
	if(work_mode==SYS_IDLE){

		work_mode=SYS_MP3DECODE_USB;
	}
#endif

//__MODE_SKIP:

		flush_all_msg();
#if defined(NEW_VOLUME_KEY_FEATURE)||defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)

		last_disp_menu=DISP_NULL;
		if(new_vol_feature){		
			new_vol_feature =0;
		}
#endif				

        	//printf(" ----->INFO_MODE %x -- \r\n",(u16)work_mode);
		
		if(work_mode==SYS_MP3DECODE_USB){

#ifdef DEVICE_SEL_MANUAL_ONLY
			device_selected=BIT(USB_DISK);
#endif			
			given_device = BIT(USB_DISK);
			given_file_number = 1;
			put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
		}
		else if(work_mode==SYS_MP3DECODE_SD){

#ifdef DEVICE_SEL_MANUAL_ONLY
			device_selected=BIT(SDMMC);
#endif			
			given_device = BIT(SDMMC);
			given_file_number = 1;
			put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);

		}
		else if(work_mode==SYS_FMREV){

#if defined(USE_GPIO_DETECT_EARPHONE_PLUGGED)
#if defined(MUTE_GPIO_FM_GPIO_COMPATIBALE)
			plugged_flag=0;	
#endif
#endif
			
#ifdef RADIO_AM_WM_ENABLE
			FMAM_Mode_Switch_Profile(SYS_FMREV);
#endif
	 	}
#ifdef RADIO_AM_WM_ENABLE
		else if(work_mode==SYS_AMREV){
		
			work_mode = mode_reg;
			Set_Curr_Func(SYS_AMREV);
			FMAM_Mode_Switch_Profile(SYS_AMREV);
			break;
		}
#endif    		
	 	else if(work_mode==SYS_AUX){

	   	 	//aux_online = 1;
		}
#if defined(IPONE_INDEPENDENT_MODE)
	 	else if(work_mode==SYS_IPH){

	   	 	//aux_online = 1;
		}
#endif
#if defined(USE_RTC_FUNCTION)
		else if(work_mode==SYS_RTC){

	    		//aux_online = 0;
		}
#endif		
		else if(work_mode==SYS_IDLE){
			put_msg_lifo(INFO_NO_DEV);
		}
        return 0;

#if defined(NEW_VOLUME_KEY_FEATURE)
    	 case INFO_VOL_MINUS | KEY_SHORT_UP :
		new_vol_feature=~new_vol_feature;
		if(new_vol_feature){

			last_disp_menu =curr_menu;
			Disp_Con(DISP_VOL);
		}
		else{

			Disp_Con(last_disp_menu);
		}
		break;
        case INFO_NEXT_FIL:
        case INFO_NEXT_FIL | KEY_HOLD:
#elif defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)

    	 case INFO_CUS_KEY_1 | KEY_SHORT_UP :
#ifdef USE_RTC_FUNCTION	 	
		if(work_mode == SYS_RTC)break;
#endif		
		new_vol_feature=~new_vol_feature;
		if(new_vol_feature){

			last_disp_menu =curr_menu;
			Disp_Con(DISP_VOL);
		}
		else{

			//if(last_disp_menu!=DISP_NULL)
			Disp_Con(last_disp_menu);
		}
		break;
    case INFO_VOL_PLUS:		
    case INFO_VOL_PLUS | KEY_HOLD :
		if(!new_vol_feature){
			break;
		}
#else

    case INFO_VOL_PLUS:
    case INFO_VOL_PLUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)		
    case INFO_NEXT_FIL| KEY_HOLD :
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif

#endif

#ifdef RTC_VOL_FIXIED
	if(work_mode == SYS_RTC)break;	
#endif

#ifdef SUPPORT_PT2313
	if((audio_effect_state>0)){
		audio_effect_hdlr(0x01);
		flush_low_msg();	
		break;
	}
#endif
	if(work_mode == SYS_IDLE)break;

        my_music_vol += 2;

#if defined(NEW_VOLUME_KEY_FEATURE)
        case INFO_PREV_FIL:
        case INFO_PREV_FIL | KEY_HOLD:	
#else
    case INFO_VOL_MINUS:
    case INFO_VOL_MINUS | KEY_HOLD :
#if !defined(INDEPENDENT_VOLUME_KEY)				
    case INFO_PREV_FIL| KEY_HOLD :
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif
#endif

#if defined(VOL_TUNE_NEW_VOLUME_KEY_FEATURE)
		if(!new_vol_feature){
			break;
		}
#endif

	if(work_mode == SYS_IDLE)break;

#ifdef SUPPORT_PT2313	
	if((audio_effect_state>0)){
		audio_effect_hdlr(0x02);
		flush_low_msg();
		break;
	}
#endif
#ifdef RTC_VOL_FIXIED
	if(work_mode == SYS_RTC)break;	
#endif

        if (my_music_vol)
            my_music_vol--;
#ifdef CUSTOM_DEFINE_ADPORT_FOR_VOLUME_ADJ
    	case INFO_ADVOL_ADJ:

#ifdef UART_ENABLE
	printf("use_adkey_port_for_volume_adj   -->  %d  \r\n",(u16)((my_music_vol)));
#endif

#endif

#ifdef VOL_ADJ_SPARK_LED

	if(!vol_adj_spark_bit){
		vol_adj_spark_bit=1;
		last_led_play_mod = get_led_flash_mode();
	}
	set_play_flash(LED_FLASH_VERY_FAST);
#endif
	 clear_super_mute_lock();

        if (my_music_vol > MAX_VOL)
        {
            my_music_vol = MAX_VOL;
        }
	 if(my_music_vol == MIN_VOL){
	 	
		Mute_Ext_PA(MUTE);
	 }
	 else{

		#if defined(K109_SW001D_V001)
		if(work_mode <SYS_FMREV){
			if(!play_status){
				Mute_Ext_PA(MUTE);
			}
			else{
				Mute_Ext_PA(UNMUTE);
			}
		}
		else{
			Mute_Ext_PA(UNMUTE);
		}
		#else		
		Mute_Ext_PA(UNMUTE);
		#endif
	 }

        write_info(MEM_VOL,my_music_vol);
		
	 my_main_vol(my_music_vol);	
	 
	 Disp_Con(DISP_VOL);
        break;

#if defined(USE_TIMER_POWER_OFF_FUNC)
	case INFO_TIMER_OFF:
		timer_pwr_off();
		break;
#endif

#ifdef  USE_POWER_KEY	
#ifdef USE_IR_LONG_POWER_KEY_TO_FAKE_POWER_OFF

    case INFO_POWER | KEY_LONG:

		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			goto _SYS_GO_IN_POWER_OFF;	
		}
		break;
#endif

    case INFO_POWER | KEY_HOLD:
#if defined(CHARGER_DETECT_INDICATOR)
#ifdef PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
	if(charger_in_flag)break;
#elif defined(PWR_OFF_GOTO_RTC_MODE_WHEN_CHARGER_PLUGGED)
	if(charger_in_flag){
		Set_Curr_Func(SYS_RTC);
		return 0;
	}
#endif
#endif

#ifdef USE_IR_LONG_POWER_KEY_TO_FAKE_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif

        sys_power_down();
        break;
#endif

#ifdef POWE_KEY_PLAY_KEY_IN_ONE_KEY

    case INFO_CH_DOWN| KEY_SHORT_UP:
	if(IR_Type == WITH_FM_CHIP)break;
	
    case INFO_PLAY| KEY_LONG:

#ifdef USE_IR_LONG_POWER_KEY_TO_FAKE_POWER_OFF
		if(IR_KEY_Detect){
			IR_KEY_Detect =0;
			break;
		}
#endif
		
#if defined(POWER_KEY_LONG_POWER_OFF)		
    case INFO_POWER| KEY_LONG:
#else	

#ifndef  USE_POWER_KEY	
    case INFO_POWER | KEY_SHORT_UP :	
#endif	

#if defined(IR_POWER_KEY_SHORT_TRUE_POWER_OFF)
    case INFO_POWER | KEY_SHORT_UP :	
#endif

#endif	


#else

    case INFO_CH_DOWN| KEY_SHORT_UP:
		
		if(IR_Type == WITH_FM_CHIP)break;
#if defined(USE_PWR_KEY_LONG_PWR_ON)	
    case INFO_POWER | KEY_LONG :
		break;
#else
#if !defined(USE_POWER_KEY_TO_SWITCH_MODE)				
    case INFO_POWER | KEY_SHORT_UP :
#endif		
#endif	

#endif	


_SYS_GO_IN_POWER_OFF:

#ifdef USE_PLAY_KEY_TO_POWER_OFF
    	case INFO_PLAY| KEY_LONG:
#endif

#if defined(USE_LONG_MODE_FOR_POWER_KEY)
        case INFO_MODE | KEY_LONG :
#if defined(DEFAULT_GO_TO_CUSTOM_MODE)
		custom_first_time_pwr_flag=1;
#endif
			
#endif			
#ifdef  USE_POWER_KEY
#ifdef POWER_KEY_SHORT_PWR_DOWN
        sys_power_down();
#elif defined(IR_POWER_KEY_SHORT_TRUE_POWER_OFF)
	sys_pwr_off();
#else
	Mute_Ext_PA(MUTE);
	work_mode =SYS_IDLE;
       put_msg_fifo(INFO_SYS_IDLE);
       pwr_up_flag =1;		   					
       return 0;
#endif
        break;
#else
		Mute_Ext_PA(MUTE);
		work_mode =SYS_IDLE;
       	put_msg_fifo(INFO_SYS_IDLE);
       	pwr_up_flag =1;		   					
       	return 0;
#endif

#if !defined(MULTI_MEDIA_BOX)

    case INFO_0 | KEY_SHORT_UP :
    case INFO_1 | KEY_SHORT_UP :
    case INFO_2 | KEY_SHORT_UP :
    case INFO_3 | KEY_SHORT_UP :
    case INFO_4 | KEY_SHORT_UP :
    case INFO_5 | KEY_SHORT_UP :
    case INFO_6 | KEY_SHORT_UP :
    case INFO_7 | KEY_SHORT_UP :
    case INFO_8 | KEY_SHORT_UP :
    case INFO_9 | KEY_SHORT_UP :
        if ((work_mode == SYS_MP3DECODE_USB)||(work_mode == SYS_MP3DECODE_SD) || (work_mode == SYS_FMREV))
        {
            key &= 0x1f;
			
	     if((cfilenum==0)&&(key==0))break;
			
#if defined(KEY_100_ENABLE)||defined(KEY_10_ENABLE)
            if(cfilenum==0)
	     {
		 key_100_flag = 0x00;
	     }
	     if(key_100_flag ==0xFF){

			cfilenum += key;
			key_100_flag = 0xFE;
	     }
	     else if(key_100_flag ==0xFE){
		 	
			cfilenum += (cfilenum%10)*10-(cfilenum%10)+key;
			key_100_flag = 0x00;
	     }
	     else 
#endif		 	
	     {
	     		if((cfilenum)>6553){
				cfilenum = 0x0000;			
			}
				
			cfilenum = cfilenum *10 + key;
#if defined(KEY_100_ENABLE)||defined(KEY_10_ENABLE)		
			key_100_flag = 0x00;			
#endif
#if 1
	            if (cfilenum > 9999)
	            {
		              cfilenum = 0;			
				cfilenum = cfilenum *10 + key;
		     }
#endif
			
	     }
            Disp_Con(DISP_DWORD_NUMBER);
        }
        break;
#endif

#if defined(MULTI_MEDIA_BOX)
    case INFO_SUB_PLUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(1,BASS_ADJ);
	 	Disp_Con(DISP_BASS);
#endif							
		break;
    case INFO_SUB_MINUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(2,BASS_ADJ);
	 	Disp_Con(DISP_BASS);
#endif									
		break;		
    case INFO_TRE_PLUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(1,TRELBE_ADJ);
	 	Disp_Con(DISP_TREBLE);
#endif							
		break;		
    case INFO_TRE_MINUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(2,TRELBE_ADJ);
	 	Disp_Con(DISP_TREBLE);
#endif									
		break;		
    case INFO_SW_PLUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(1,BASS_ADJ);
	 	Disp_Con(DISP_BASS);
#endif					
		break;		
    case INFO_SW_MINUS | KEY_SHORT_UP :
#ifdef SUPPORT_PT2313	
	 	PT2313_Config(2,BASS_ADJ);
	 	Disp_Con(DISP_BASS);
#endif							
		break;	

    case INFO_EQ_UP | KEY_SHORT_UP :
		audio_effect_state =CONFIG_EQ;
		audio_effect_hdlr(0xFF);
		break;
		
    case INFO_EQ_CLASS | KEY_SHORT_UP :
		audio_effect_state =CONFIG_EQ;
         	eq_mode = CLASSIC;
		audio_effect_hdlr(0xFF);
		break;	

    case INFO_EQ_JAZZ | KEY_SHORT_UP :
		audio_effect_state =CONFIG_EQ;
         	eq_mode = JAZZ;		
		audio_effect_hdlr(0xFF);
		break;	

    case INFO_EQ_ROCK| KEY_SHORT_UP :
		audio_effect_state =CONFIG_EQ;
         	eq_mode = ROCK;		
		audio_effect_hdlr(0xFF);
		break;	

    case INFO_EQ_NORMAL| KEY_SHORT_UP :
		audio_effect_state =CONFIG_EQ;
         	eq_mode = NORMAL;		
		audio_effect_hdlr(0xFF);
		break;			
		
#endif
#ifdef KEY_100_ENABLE		
   case INFO_100 |KEY_SHORT_UP :

	if(work_mode < SYS_AUX){

       	cfilenum += 100;
		key_100_flag =0xFF;
       	Disp_Con(DISP_DWORD_NUMBER);
   	}
	break;
#endif
#ifdef KEY_200_ENABLE
        case INFO_200 | KEY_SHORT_UP :
	if(work_mode < SYS_AUX){

       	cfilenum += 200;
		key_100_flag =0xFF;
       	Disp_Con(DISP_DWORD_NUMBER);
   	}
	 break;
        case INFO_10_PLUS | KEY_SHORT_UP :
	if(work_mode < SYS_AUX){

       	cfilenum += 10;
       	Disp_Con(DISP_DWORD_NUMBER);
   	}
	 break;	 
#endif
#ifdef KEY_10_ENABLE
        case INFO_100 | KEY_SHORT_UP :
	if(work_mode < SYS_AUX){

       	cfilenum += 10;
		key_100_flag =0xFF;		
       	Disp_Con(DISP_DWORD_NUMBER);
   	}
	 break;	 
#endif

#if defined(USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM)

#if defined(K2013_JIELONG_2013_V001)
	case INFO_CUS_KEY_1|KEY_SHORT_UP:
		 given_file_number =1;
	        put_msg_lifo(INIT_PLAY);
	break;

#else
        case INFO_PLAY | KEY_HOLD:
#if 1//defined(K188_YJH_188_V003)
		if(reset_key_cnt++>12)
		{
			reset_key_cnt=0;
			given_file_number =1;
			put_msg_lifo(INIT_PLAY);
		}		
		break;
#endif		

#endif
#endif

#if !defined(MULTI_MEDIA_BOX)

#if defined(EQ_ADJ_USE_STOP_KEY_LONG)
    case INFO_STOP | KEY_LONG:
#elif defined(EQ_ADJ_USE_MODE_KEY_LONG)
    case INFO_MODE | KEY_LONG:		
#endif
    case INFO_EQ_UP | KEY_SHORT_UP :

#if defined(SUPPORT_PT2313)
#ifdef USE_PT_2313_EQ_ONLY
	audio_effect_state =CONFIG_EQ;
	audio_effect_hdlr(0x2);
	break;
#else
	if(audio_effect_state++>=CONFIG_VOL)
		audio_effect_state=0x01;
	
	audio_effect_hdlr(0xFF);
	flush_low_msg();	
	break;
#endif	
#endif	

	if(work_mode>SYS_MP3DECODE_SD)break;
#if 0//defined(K188_YJH_188_V001)
	 given_file_number =1;
        put_msg_lifo(INIT_PLAY);
	break;
#endif		
        eq_mode++;
#if defined(K170_ZK_170_V001)||defined(K0000_GW_238_V001)	
        if (eq_mode > USER)
#elif defined(K535_DingChuangXin_803E_3_V001)
        if (eq_mode > JAZZ)
#else			
        if (eq_mode > CLASSIC)
#endif			
        {
            eq_mode = NORMAL;
        }
        //write_info(MEM_EQ_MODE,eq_mode);
        set_eq(eq_mode);
        Disp_Con(DISP_EQ);

        break;
#endif				

#ifdef EQ_LONG_PRESS_FOR_FM_MP3_SEL
    	case INFO_EQ_DOWN| KEY_LONG:

		if(IR_Type == NO_FM_CHIP)break;

		if(work_mode!= SYS_FMREV){

			Set_Curr_Func(SYS_FMREV);
			return 0;
		}
		else{
			
			Set_Curr_Func(SYS_MP3DECODE_USB);
			return 0;
		}
		break;
#endif		
	//4 EQ DOWN for special use		
    	case INFO_EQ_DOWN| KEY_SHORT_UP :

#ifdef IR_INFO_EQ_DOWN_FOR_INTRO_MODE
		if(IR_KEY_Detect){
#ifdef PLAY_MODE_USE_INTRO_MODE
			init_intro_play_mode();
#endif
			break;
		}
#endif
#ifdef MP3_MODE_EQ_DOWN_DO_NOTHING
			break;
#endif

#ifdef UART_ENABLE
		printf("  SEL  INFO_EQ_DOWN %x  \r\n ",(u16)work_mode);
#endif
		if(work_mode==SYS_MP3DECODE_SD){

			if((get_device_online_status()&0x02)){
#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
				dev_first_plugged_flag=1;
#endif			
#ifdef USB_SD_DEV_PLUG_MEM

				device_active=BIT(USB_DISK);
			 	last_plug_dev=BIT(SDMMC);
				set_play_flash(LED_FLASH_NOR);
				
#endif

				 sys_printf("  SEL  SYS_MP3DECODE_USB");
				 Mute_Ext_PA(MUTE);
				 Set_Curr_Func(SYS_MP3DECODE_USB);
			        given_device = BIT(USB_DISK);
			        given_file_number = 1;
			        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
					
				 if(work_mode <=SYS_MP3DECODE_SD)
				 	break;
				 else
			        	return 0;
			}
		}
		else if(work_mode==SYS_MP3DECODE_USB){

			if((get_device_online_status()&0x01)){

#ifdef USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
				dev_first_plugged_flag=1;
#endif	
#ifdef USB_SD_DEV_PLUG_MEM
				device_active=BIT(SDMMC);
			 	last_plug_dev=BIT(USB_DISK);
				set_play_flash(LED_FLASH_NOR);				
#endif
				 sys_printf("  SEL  SYS_MP3DECODE_SD");


				 Mute_Ext_PA(MUTE); 
				 Set_Curr_Func(SYS_MP3DECODE_SD);
			        given_device = BIT(SDMMC);
			        given_file_number = 1;
			        put_msg_lifo(SEL_GIVEN_DEVICE_GIVEN_FILE);
					
				 if(work_mode <=SYS_MP3DECODE_SD)
				 	break;
				 else					
			        return 0;
			}		
		}			
	break;
#if 1//defined(IR_REMOTER_WITH_POWER_MUTE_PRINT)
	case INFO_MUTE |KEY_SHORT_UP:
#if defined(IR_MUTE_USE_NORMAL)
		Mute_Ext_PA(MUTE);
#else
		Mute_Ext_PA(SUPERMUTE);

#endif
#if defined(MUTE_ON_FLASH_WHOLE_SCREEN)
#if defined(MP3_PUASE_FLASH_FIGURE)
		set_led_flash_tpye(1);
		if(work_mode < SYS_FMREV){	
			if((!play_status)&&(!get_super_mute_lock())){
				Disp_Con(DISP_PAUSE);
				set_led_flash_tpye(2);
				break;
			}
		       Disp_Con(DISP_VOL);
		}
#endif		
#endif				
#if defined(K722_YJH_722_V001)
  //          play_status = !play_status;
#endif
	break;
#endif	
	case INFO_CH_UP|KEY_SHORT_UP:

		if(IR_Type == WITH_FM_CHIP)break;
		Mute_Ext_PA(SUPERMUTE);
	break;
#if defined(ONE_WIRE_TUNE_ENABLE)
	case INFO_MODE|KEY_LONG:
		one_wire_ctrl_if(0);
		break;
#endif

#if defined(CUSTOMIZED_KEY_FUNC_ENABLE)
	case INFO_CUS_KEY_1|KEY_SHORT_UP:
#if defined(K820_LHD_820_V001)

		if(work_mode != SYS_RTC){
			Set_Curr_Func(SYS_RTC);
			return 0;
		}
		else{
			Set_Curr_Func(SYS_MP3DECODE_SD);
			return 0;
		}
#else
		gpio_ctrl_f=~gpio_ctrl_f;
		gpio_ctrl_if(gpio_ctrl_f);
#endif		
		break;
#endif

#if defined(MANUAL_SWITCH_TIME_DISPLAY)
	case INFO_CUS_KEY_1|KEY_SHORT_UP:
#if defined(TIME_FORCE_SHOW_ON_SCREEN)
            	if (time_show_return_cnt==0xff){
			time_show_return_cnt = 0x00;
		}
		else{
			time_show_return_cnt = 0xff;
		}
#endif			
		break;
#endif

#if defined(USE_LONG_MODE_FOR_CUSTOM_FUNC)
	case INFO_MODE|KEY_HOLD:

#ifdef K800_MingYang_800_V001		
			mos_ctrl =~mos_ctrl;
			P0DIR &= ~(BIT(2));
			P0PU |= BIT(2);P3DIR |= (BIT(4));
			P3PU &= ~(BIT(4));
			P3PD&= ~(BIT(4));
			if(mos_ctrl){
				P02 = 1;	
			}
			else{
				P02 = 0;	
			}
			flush_low_msg();
			delay_10ms(120);
#endif			
		break;
#endif

#ifdef FLASH_LIGHT_FUNC

	case INFO_CUS_KEY_1|KEY_SHORT_UP:

		if(lam_led_flag==0)break;
		
		flash_level++;
		if(flash_level>10)
			flash_level =10;
		//sys_printf(" pwm_setting +++ ");
		pwm_setting(flash_level);		
		break;
	case INFO_CUS_KEY_2|KEY_SHORT_UP:

		if(lam_led_flag==0)break;
		
		flash_level--;

		if(flash_level==0)
			flash_level =1;
		
		//sys_printf(" pwm_setting --- ");

		pwm_setting(flash_level);		
		
		break;		
	case INFO_CUS_KEY_1|KEY_LONG:
	
		//sys_printf(" INFO_CUS_KEY_111 --- KEY_LONG");

		if(lam_led_flag==0){

			flash_level = 6;
			lam_led_flag =0XFF;
		}
		else{
			flash_level = 0;
			lam_led_flag=0;
		}

		pwm_setting(flash_level);

		break;		
	case INFO_CUS_KEY_2|KEY_LONG:

		//sys_printf(" INFO_CUS_KEY_222 --- KEY_LONG");

		P0DIR &= ~(BIT(2));
		P0PU |= (BIT(2));		
		P02 =~P02;
			
		break;
#endif
    }

    return 1;
}
